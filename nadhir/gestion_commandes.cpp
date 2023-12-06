#include "gestion_commandes.h"
#include "ui_gestion_commandes.h"
#include"commande.h"
#include <QMessageBox>
#include<QIntValidator>
#include<QDebug>
#include "integration.h"


#include<QSqlQueryModel>
#include<QTableView>

gestion_commandes::gestion_commandes(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::gestion_commandes)
{
    ui->setupUi(this);
    ui->le_numCom->setValidator(new QIntValidator(0, 9999999, this));
     ui->tab_commande->setModel(C.afficher());
}

gestion_commandes::~gestion_commandes()
{
    delete ui;
}

void gestion_commandes::on_pb_ajouter_clicked()

    {
    qDebug();
      int NUMERO_DE_COMMANDE=ui->le_numCom->text().toInt();
      int REFERENCE=ui->le_ref->text().toInt();
      int TOTAL_DE_COMMANDE=ui->le_total->text().toInt();
      QDate DATE_DE_LIVRASION=ui->dateEdit->date();
       QString NATIONALITE=ui->le_nat->currentText();


Commande C(NUMERO_DE_COMMANDE,DATE_DE_LIVRASION,REFERENCE,TOTAL_DE_COMMANDE,NATIONALITE);
 bool test=C.ajouter();
 //bool test=C.ajouter();
  QMessageBox msgBOX;

 if (test)
 {
     notification.notification_ajoutcommandes();
     msgBOX.setText("Ajout aves succes.");}
 else
     msgBOX.setText("Echec de suppression");
 msgBOX.exec();
 ui->tab_commande->setModel(C.afficher());
 ui->tab_commande->setModel(C.historique());
}

void gestion_commandes::on_pb_supprimer_clicked()
{


    Commande C2;
    C2.setNUMERO_DE_COMMANDE(ui->le_numCom_sup->text().toInt());
            bool test=C2.supprimer(C2.getNUMERO_DE_COMMANDE());
            QMessageBox msgBox;

            if (test){
                notification.notification_supprimercommandes();
                msgBox.setText("suppression aves succes.");}
            else
                msgBox.setText("Echec de suppression");
            msgBox.exec();
            ui->tab_commande->setModel(C.afficher());
}


void gestion_commandes::on_pb_modifier_clicked()
{
     int NUMERO_DE_COMMANDE=ui->le_numCom->text().toInt() ;
     int REFERENCE=ui->le_ref->text().toInt();
     QDate DATE_DE_LIVRASION=ui->dateEdit->date();
     int TOTAL_DE_COMMANDE=ui->le_total->text().toInt();
     QString NATIONALITE=ui->le_nat->currentText();
          Commande C(NUMERO_DE_COMMANDE,DATE_DE_LIVRASION,REFERENCE,TOTAL_DE_COMMANDE,NATIONALITE);
               bool test=C.modifier(NUMERO_DE_COMMANDE);
               if (test)
               {
                   notification.notification_modifiercommandes();
                   ui->tab_commande->setModel(C.afficher()) ;
                          QMessageBox::information(nullptr, QObject::tr("OK"),
                                   QObject::tr("COMMANDE modifie .\n""clique Ok pour quitter"),QMessageBox::Ok);
                          ui->le_numCom->clear() ;
                          ui->le_ref->clear() ;
                          ui->le_total->clear() ;
                          ui->dateEdit->clear() ;
                          ui->le_nat->clear() ;

                }
                else
                          QMessageBox::critical(nullptr, QObject::tr("LE"),
                                   QObject::tr("NON  .\n""clique Ok pour quitter"),QMessageBox::Ok);




}






void gestion_commandes::on_le_rechercher_cursorPositionChanged(int arg1, int arg2)
{
            Commande C;
            int NUMERO_DE_COMMANDE= ui->le_rechercher->text().toInt();

          C.recherche(ui->tab_commande,NUMERO_DE_COMMANDE);
            if (ui->le_rechercher->text().isEmpty())
            {
                ui->tab_commande->setModel(C.afficher());
            }
    }


void gestion_commandes::on_pb_trier_clicked()
{
    Commande C;
      ui->tab_commande->setModel(C.triee());
}




void gestion_commandes::on_stat_commande_clicked()
{
    statistic = new class Statistic(this);
    statistic->setWindowTitle("smart recicling | Statistiques");
    statistic->show();
}





void gestion_commandes::on_pdf_commande_clicked()
{
    Commande f;
    f.telechargerPDF();

             QMessageBox::information(nullptr,QObject::tr("OK"),
                        QObject::tr("Téléchargement terminé"), QMessageBox::Cancel);
}
void gestion_commandes::on_pb_back4_clicked()
{

        integration *Commande = new integration;
        Commande ->show();
        hide();


}
