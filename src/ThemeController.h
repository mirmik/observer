#include <QtCore>

#include <crow/nodes/requestor_node.h>
#include <crow/tower.h>

class ThemeController : public QObject
{
    Q_OBJECT

    private:
        crow::requestor_node requestor;

    public:
        ThemeController(QObject *parent = nullptr);
        ~ThemeController();

        void init_subscription();
        std::vector<std::string> get_theme_list();

        void start_crow_tower();
};