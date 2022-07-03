#include <QtWidgets>
//#include <Observer.h>
//#include <ThemeController.h>
#include <Workspace.h>
#include <View.h>
#include <ViewAdaptor.h>

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QWidget * central_widget = nullptr;
    QSplitter * horsplitter = nullptr;
    QListWidget * sources_table = nullptr;

    QMdiArea *mdiArea = nullptr;
    QToolBar *toolbar = nullptr;

    QAction *newWindowAction = nullptr;
    QAction *newViewAction = nullptr;
    QAction *newTestViewAction = nullptr;
    QAction *exitAction = nullptr;

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

    void update_soures_table();
    void init_sources_table();

    ChartView* create_chart_view(ChartViewAdaptor& adaptor);

private slots:
    void newWindow();
    void addCsvSourceAction();
    void newView();
    void newTestView();
};