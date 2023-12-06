#include "windowines.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Windowines w;
    w.show();
    return a.exec();
}
