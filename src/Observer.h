#include <QtWidgets>
#include <crow/nodes/subscriber_node.h>
#include <crow/address.h>

class Observer : public QWidget
{
    Q_OBJECT

    std::vector<std::shared_ptr<crow::subscriber_node>> subscribers;

    public:
        Observer(QWidget *parent = nullptr);
        ~Observer() = default;

    void add_subscriber(igris::buffer theme);
    void update_theme(igris::buffer data, crow::subscriber_node& node);
};