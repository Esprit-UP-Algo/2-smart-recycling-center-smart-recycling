#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"commande.h"
#include <QMessageBox>
#include<QIntValidator>
#include<QDebug>
#include "pdf.h"
#include<stat_co.h>
//#include "calendar.h"
#include<QSqlQueryModel>
#include<QTableView>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_numCom->setValidator(new QIntValidator(0, 9999999, this));
     ui->tab_commande->setModel(C.afficher());
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()

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
     msgBOX.setText("Ajout aves succes.");
 else
     msgBOX.setText("Echec de suppression");
 msgBOX.exec();
 ui->tab_commande->setModel(C.afficher());
 ui->tab_commande->setModel(C.historique());
}

void MainWindow::on_pb_supprimer_clicked()
{


    Commande C2;
    C2.setNUMERO_DE_COMMANDE(ui->le_numCom_sup->text().toInt());
            bool test=C2.supprimer(C2.getNUMERO_DE_COMMANDE());
            QMessageBox msgBox;

            if (test)
                msgBox.setText("suppression aves succes.");
            else
                msgBox.setText("Echec de suppression");
            msgBox.exec();
            ui->tab_commande->setModel(C.afficher());
}


void MainWindow::on_pb_modifier_clicked()
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






void MainWindow::on_le_rechercher_cursorPositionChanged(int arg1, int arg2)
{
            Commande C;
            int NUMERO_DE_COMMANDE= ui->le_rechercher->text().toInt();

          C.recherche(ui->tab_commande,NUMERO_DE_COMMANDE);
            if (ui->le_rechercher->text().isEmpty())
            {
                ui->tab_commande->setModel(C.afficher());
            }
    }


void MainWindow::on_pb_trier_clicked()
{
    Commande C;
      ui->tab_commande->setModel(C.triee());
}



void MainWindow::on_pdf_commande_clicked()
{
    pdf p;
      p.setModal(true);
      p.exec();
      qDebug()<<"pdf window open";
}





void MainWindow::on_stat_commande_clicked()
{
    stat_co *w = new stat_co();
                   w->make_nationalite();
                   w->show();
                   qDebug()<<"stat window open";
}



/*void MainWindow::on_calendar_commande_clicked()
{
    calendar  *c = new calendar (this);
                c->setDeliveryDates(DATE_DE_LIVRISION);
}
CustomCalendarWidget *calendarWidget = new CustomCalendarWidget(this);
calendarWidget->setDeliveryDates(deliveryDates); // Set the delivery dates here
*/
