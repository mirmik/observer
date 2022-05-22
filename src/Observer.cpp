#include <Observer.h>
#include <crow/nodes/pubsub_defs.h>

Observer::Observer(QWidget *parent) : QWidget(parent)
{
    setMinimumSize(200, 200);
    setWindowTitle("Observer");

    //add_subscriber("test");

    vlayout = new QVBoxLayout(this);
    chart = new rabbit::qtchart;

    vlayout->addWidget(chart);
    setLayout(vlayout);

    //start_generator();
    //set_theme("sin");
}

Observer::Observer(QString theme, QWidget *parent) : Observer(parent)
{
    set_theme(theme.toStdString());
    //last_update = std::chrono::system_clock::now();
}

void Observer::set_theme(std::string theme)
{
    auto current_time = std::chrono::system_clock::now();
    auto current_time_ms = std::chrono::duration_cast<std::chrono::milliseconds>(current_time.time_since_epoch());
    start_generator_time = current_time_ms.count();
    add_subscriber(theme);
}

void Observer::add_subscriber(igris::buffer theme) 
{
    auto node = std::make_shared<crow::subscriber_node>(crow::crowker_address(), theme, 
        igris::make_delegate(&Observer::update_theme, this));
    node->bind();
    node->install_keepalive(2000);

    subscribers.push_back(node);
}

void Observer::update_theme(igris::buffer data, crow::subscriber_node& node) 
{
    //auto current_time = std::chrono::system_clock::now();
    //auto current_time_ms = std::chrono::duration_cast<std::chrono::milliseconds>(current_time.time_since_epoch());
    //auto time = current_time_ms.count() - start_generator_time;

    //float ydata = atof(data.data());
    int64_t xstamp;
    float ydata;
    crow::load_timestamped_object(data, &xstamp, &ydata);

    if (start_generator_time == 0) 
    {
        start_generator_time = xstamp;
    }

    nos::println(xstamp, ydata);
    chart->add_data((xstamp-start_generator_time)/1000.0f, ydata);

    /*nos::println("add_data");

    if (current_time - last_update > std::chrono::milliseconds(30))
    {
        chart->update();
        last_update = current_time;
    }*/
}

void Observer::start_generator() 
{
    auto current_time = std::chrono::system_clock::now();
    auto current_time_ms = std::chrono::duration_cast<std::chrono::milliseconds>(current_time.time_since_epoch());
    start_generator_time = current_time_ms.count();

    generator_timer = new QTimer(this);
    connect(generator_timer, &QTimer::timeout, this, &Observer::generate_data);
    generator_timer->start(10);
}

void Observer::generate_data() 
{
    auto current_time = std::chrono::system_clock::now();
    auto current_time_ms = std::chrono::duration_cast<std::chrono::milliseconds>(current_time.time_since_epoch());
    auto time = current_time_ms.count() - start_generator_time;

    auto signal = sin((float)time / 100.0) * sin((float)time / 5000.0);
    auto xdata = (float)time / 1000.0 / 10.0 - 1;
    auto ydata = signal; 
    chart->add_data(xdata, ydata);
    chart->update();
}

void Observer::mousePressEvent(QMouseEvent *event) 
{
    return QWidget::mousePressEvent(event);
}

void Observer::wheelEvent(QWheelEvent *event) 
{
    auto delta = event->angleDelta();
    if (delta.y() > 0)
        chart->multiply_xscale(1.1);
    else
        chart->multiply_xscale(1.0/1.1);
}