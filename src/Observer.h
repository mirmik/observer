#include <QtWidgets>
#include <crow/nodes/subscriber_node.h>

class Observer : public QWidget
{
    Q_OBJECT

    std::vector<crow::subscriber_node> subscribers;

    public:
        Observer(QWidget *parent = nullptr);
        ~Observer() = default;

    void add_subscriber(igris::buffer theme);
};