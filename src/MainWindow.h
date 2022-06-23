#include <QtWidgets>
//#include <Observer.h>
//#include <ThemeController.h>
#include <Workspace.h>

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QWidget * central_widget;
    QSplitter * horsplitter;
    QTableWidget * sources_table;

    private:
        Workspace workspace;

    public:
        MainWindow();
        ~MainWindow() = default;

    private:
        void makeToolBars();
        void makeAction();
        void makeMenus();
        void saveWorkspaceAction();
        void loadWorkspaceAction();

    private slots:
        void newWindow();
        void addCsvSourceAction();
        void addViewAction();

    private:
        QMdiArea *mdiArea = nullptr;
        QToolBar *toolbar = nullptr;

        QAction *newWindowAction = nullptr;
        QAction *exitAction = nullptr;

        //ThemeController *themeController = nullptr;
};