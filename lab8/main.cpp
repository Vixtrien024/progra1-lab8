#include "lab8.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    lab8 window;
    window.show();
    return app.exec();
}
