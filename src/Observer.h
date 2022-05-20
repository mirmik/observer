#include <QtWidgets>

class Observer : public QWidget
{
    Q_OBJECT

    public:
        Observer(QWidget *parent = nullptr);
        ~Observer() = default;
};