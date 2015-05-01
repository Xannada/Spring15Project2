#include "MainHeader.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LandingWin w;
    w.show();

    return a.exec();
}
