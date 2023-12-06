#include "integration.h"
#include "ui_integration.h"
#include "mariem/Atelier_Connexion_/Atelier_Connexion/equipement.h"
#include "mariem/Atelier_Connexion_/Atelier_Connexion/mainwindow.h"
#include "amine/Atelier_Connexion/aminef.h"
#include "amine/Atelier_Connexion/produit.h"

#include "inesRahrah/inesRahrah/client.h"
#include "inesRahrah/inesRahrah/windowines.h"
//#include "inesRahrah/inesRahrah/smtp.h"
#include "mariem/Atelier_Connexion_/Atelier_Connexion/connection.h"
#include "lindaSakouhi/login.h"
#include "lindaSakouhi/windowsakouhi.h"
#include "lindaSakouhi/employe.h"


integration::integration(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::integration)
{
    ui->setupUi(this);
}

integration::~integration()
{
    delete ui;
}
void integration::on_pb_equip_clicked()
{
    Equipement = new MainWindow(this);
    Equipement ->show();
}
void integration::on_pb_produit_clicked()
{
    Produit = new aminef(this);
    Produit ->show();
}
void integration::on_pb_client_clicked()
{
    client = new Windowines(this);
    client ->show();
}
void integration::on_pb_employe_clicked()
{
    Employe = new Windowsakouhi(this);
    Employe->show();

}
/*void integration::on_pb_commande_clicked()
{
    Commande = new Windownadhir(this);
    Commande ->show();
}*/



void integration::on_pb_commande_clicked()
{
    Commande = new gestion_commandes(this);
    Commande ->show();
}

