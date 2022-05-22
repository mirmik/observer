#include <QtWidgets>
#include <rabbit/chart/qtchart.h>
#include <crow/nodes/subscriber_node.h>
#include <crow/address.h>

class Observer : public QWidget
{
    Q_OBJECT

    std::vector<std::shared_ptr<crow::subscriber_node>> subscribers;
    rabbit::qtchart * chart;
    QVBoxLayout * vlayout;

    std::chrono::time_point<std::chrono::system_clock> last_update;

    QTimer * generator_timer;
    int64_t start_generator_time;

    public:
        Observer(QWidget *parent = nullptr);
        Observer(QString theme, QWidget *parent = nullptr);
        ~Observer() = default;

    void add_subscriber(igris::buffer theme);
    void update_theme(igris::buffer data, crow::subscriber_node& node);
    void start_generator();
    void generate_data();

    void set_theme(std::string theme);

    void mousePressEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);
};