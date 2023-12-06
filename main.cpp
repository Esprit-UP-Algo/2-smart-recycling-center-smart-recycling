#include "integration.h"
#include "mariem/Atelier_Connexion_/Atelier_Connexion/mainwindow.h"
#include "amine/Atelier_Connexion/produit.h"
#include "amine/Atelier_Connexion/aminef.h"
#include "mariem/Atelier_Connexion_/Atelier_Connexion/connection.h"
#include "inesRahrah/inesRahrah/client.h"
#include "inesRahrah/inesRahrah/windowines.h"
#include "inesRahrah/inesRahrah/smtp.h"
#include <QLoggingCategory>
#include <QSslSocket>
#include <QList>
#include <QMessageBox>
#include "lindaSakouhi/login.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Client c;
    Equipement e;
    //Commande co;
    Employe E;
     qDebug();
    aminef w;
    Produit p;
    integration i;
    //Commande c;
    Connection C;
    bool test=C.createconnect();

    login l;
    l.show();
    if(test)
    {
        /*QMessageBox::critical(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);*/

}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    return a.exec();
}
