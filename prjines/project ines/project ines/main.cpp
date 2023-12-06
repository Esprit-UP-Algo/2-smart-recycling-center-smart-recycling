#include "windowali.h"
#include <QApplication>
#include <QMessageBox>
#include <QString>
#include "connection.h"
#include <QDebug>
#include <QCoreApplication>
#include <QSerialPort>
#include <QSerialPortInfo>
#include "connection.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
     Connection c;



    bool test=c.createconnect();
    Windowali w;




    if(test)
    {w.show();
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
