#include <MainWindow.h>
#include <nos/print.h>
#include <ChartViewSettings.h>
#include <View.h>

MainWindow::MainWindow()
{
    mdiArea = new QMdiArea;
    horsplitter = new QSplitter;
    sources_table = new QListWidget;

    horsplitter->addWidget(mdiArea);
    horsplitter->addWidget(sources_table);

    //themeController = new ThemeController(this);
    setCentralWidget(horsplitter);

    //mdiArea->addSubWindow(new Observer);

    makeAction();
    makeToolBars();
    makeMenus();

    setWindowTitle(tr("Observer"));

    init_sources_table();
}

void MainWindow::init_sources_table() 
{
    update_soures_table();
}

void MainWindow::update_soures_table() 
{   
    std::vector<std::shared_ptr<Fiber>> fibers;
    for (auto& source: workspace.sources) 
    {
        sources_table->addItem(QString::fromStdString(source->source_info()));
        auto f = source->fibers();
        std::copy(f.begin(), f.end(), std::back_inserter(fibers));
    }

    for (auto& fiber: fibers)  
    {
        sources_table->addItem(QString::fromStdString(fiber->name()));
    }    
}

void MainWindow::makeToolBars() 
{
    toolbar = new QToolBar;
    addToolBar(Qt::LeftToolBarArea, toolbar);
    toolbar->addAction(newWindowAction);
    toolbar->addAction(newViewAction);
}

void MainWindow::makeAction()
{
    newWindowAction = new QAction(tr("&New"), this);
    newWindowAction->setShortcuts(QKeySequence::New);
    newWindowAction->setStatusTip(tr("Create a source"));
    connect(newWindowAction, &QAction::triggered, this, &MainWindow::newWindow);

    newViewAction = new QAction(tr("&NewView"), this);
    newViewAction->setShortcuts(QKeySequence::New);
    newViewAction->setStatusTip(tr("Create a new view"));
    connect(newViewAction, &QAction::triggered, this, &MainWindow::newView);

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

    auto observer = new ChartView;
    mdiArea->addSubWindow(observer);
    observer->show();
}

void MainWindow::addCsvSourceAction() 
{
    auto ret = QFileDialog::getOpenFileName();
    workspace.add_csv_source(ret.toStdString());
}

void MainWindow::newView() 
{
    ChartViewSettings view_settings(workspace.fibers());
    view_settings.exec();
}