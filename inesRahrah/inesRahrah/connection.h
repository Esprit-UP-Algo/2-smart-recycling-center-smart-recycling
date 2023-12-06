#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSerialPort>


class Connection
{
public:
    Connection();
    bool createconnect();
     //QSqlDatabase getDatabase() const;



private:
      QSqlDatabase db;
    QSerialPort *serialPort;
};

#endif // CONNECTION_H
