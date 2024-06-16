#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    pixeleditor px;
    px.show();
    return a.exec();
}
