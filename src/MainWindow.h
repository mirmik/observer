#include <QtWidgets>
#include <Observer.h>
#include <ThemeController.h>

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        MainWindow();
        ~MainWindow() = default;

    private:
        void makeToolBars();
        void makeAction();
        void makeMenus();

    private slots:
        void newWindow();

    private:
        QMdiArea *mdiArea = nullptr;
        QToolBar *toolbar = nullptr;

        QAction *newWindowAction = nullptr;
        QAction *exitAction = nullptr;

        ThemeController *themeController = nullptr;
};