#include <Observer.h>

Observer::Observer(QWidget *parent) : QWidget(parent)
{
    setMinimumSize(200, 200);
    setWindowTitle("VisualZone");
}

void Observer::add_subscriber(igris::buffer theme) 
{
    subscribers.push_back(crow::subscriber_node(crow::crowker_address(), theme));
}