#include "connection.h"
#include<QDebug>






Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Source_Projet2A");
db.setUserName("LINDA1");//inserer nom de l'utilisateur
db.setPassword("linda");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}

