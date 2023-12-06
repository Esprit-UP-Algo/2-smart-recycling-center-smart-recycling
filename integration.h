#ifndef INTEGRATION_H
#define INTEGRATION_H
#include "mariem/Atelier_Connexion_/Atelier_Connexion/mainwindow.h"
#include "amine/Atelier_Connexion/aminef.h"
#include "nadhir/gestion_commandes.h"
#include "inesRahrah/inesRahrah/client.h"
#include "inesRahrah/inesRahrah/windowines.h"
#include "mariem/Atelier_Connexion_/Atelier_Connexion/connection.h"
#include "lindaSakouhi/windowsakouhi.h"
#include "lindaSakouhi/login.h"
#include "lindaSakouhi/employe.h"


#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class integration; }
QT_END_NAMESPACE

class integration : public QMainWindow
{
    Q_OBJECT

public:
    integration(QWidget *parent = nullptr);
    ~integration();
private slots:
   void on_pb_equip_clicked();
   void on_pb_produit_clicked();
   //void on_pb_commande_clicked();
   void on_pb_client_clicked();
   void on_pb_employe_clicked();


   void on_pb_commande_clicked();

private:
    Ui::integration *ui;
    MainWindow *Equipement;
    //MainWindow *Produit;
    aminef *Produit;
    Windowines * client;
    Windowsakouhi *Employe;
    login *login;
    gestion_commandes *Commande;

    // Windownadhir*Commande;

};
#endif // INTEGRATION_H
