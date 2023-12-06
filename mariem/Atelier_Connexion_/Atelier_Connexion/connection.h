#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include<QDebug>
#include <QMessageBox>
#include "main.cpp"

class Connection
{
    QSqlDatabase db;
public:
    Connection();
    bool createconnect();
    void closeconnection();
};

#endif // CONNECTION_H
