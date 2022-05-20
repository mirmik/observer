#include <Observer.h>

Observer::Observer(QWidget *parent) : QWidget(parent)
{
    setMinimumSize(200, 200);
    setWindowTitle("Observer");

    add_subscriber("test");
}

void Observer::add_subscriber(igris::buffer theme) 
{
    nos::println("add_subscriber");
    auto node = std::make_shared<crow::subscriber_node>(crow::crowker_address(), theme, 
        igris::make_delegate(&Observer::update_theme, this));
    node->bind();
    node->install_keepalive(2000);

    subscribers.push_back(node);
}

void Observer::update_theme(igris::buffer data, crow::subscriber_node& node) 
{
    nos::println("update_theme", data);
}