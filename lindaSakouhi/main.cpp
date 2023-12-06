#include "connection.h"
#include "windowsakouhi.h"
#include "login.h"
#include <QApplication>
#include <QDebug>
#include <QCoreApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connection c;
     bool test=c.createconnect();
    Windowsakouhi w;
    login l;

    //l.show();
    if(test)
    {l.show();
        QMessageBox::critical(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    return a.exec();
}
