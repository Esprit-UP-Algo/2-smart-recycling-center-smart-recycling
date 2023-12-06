#include "connection.h"
#include "equipement.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>


Connection::Connection()
{

}

bool Connection::createconnect()
{
db= QSqlDatabase::addDatabase("QODBC");
bool test=false;
db.setDatabaseName("Source_Projet2A");
db.setUserName("mariem");//inserer nom de l'utilisateur
db.setPassword("mariem");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;
   return  test;
}
void Connection::closeconnection(){db.close();}
