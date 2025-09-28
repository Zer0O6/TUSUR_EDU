#include "MainWindow.h"
#include <QtWidgets/QApplication>
#include <math.h>


using namespace std;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow window;
    window.show();
    return app.exec();
}
