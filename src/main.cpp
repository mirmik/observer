#include <igris/dprint.h>
#include <nos/print.h>

#include <QtWidgets>
#include <MainWindow.h>

int main(int argc, char ** argv) 
{
	QApplication app(argc, argv);
    MainWindow w;
    w.show();
    return app.exec();
}