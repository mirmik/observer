#include <MainWindow.h>
#include <nos/print.h>

MainWindow::MainWindow()
{
    mdiArea = new QMdiArea;
    themeController = new ThemeController(this);
    setCentralWidget(mdiArea);

    //mdiArea->addSubWindow(new Observer);

    makeAction();
    makeToolBars();
    makeMenus();

    setWindowTitle(tr("CrowObserver"));
}

void MainWindow::makeToolBars() 
{
    toolbar = new QToolBar;
    addToolBar(Qt::LeftToolBarArea, toolbar);
    toolbar->addAction(newWindowAction);
}

void MainWindow::makeAction()
{
    newWindowAction = new QAction(tr("&New"), this);
    newWindowAction->setShortcuts(QKeySequence::New);
    newWindowAction->setStatusTip(tr("Create a new file"));
    connect(newWindowAction, &QAction::triggered, this, &MainWindow::newWindow);

    exitAction = new QAction(tr("&Exit"), this);
    exitAction->setShortcuts(QKeySequence::Quit);
    exitAction->setStatusTip(tr("Exit the application"));
    connect(exitAction, &QAction::triggered, this, &QApplication::quit);
}

void MainWindow::makeMenus()
{
    QMenu *fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(exitAction);
}

void MainWindow::newWindow()
{
    auto theme = QInputDialog::getText(this, tr("Theme"), tr("Theme"));

    auto observer = new Observer(theme);
    mdiArea->addSubWindow(observer);
    observer->show();
}