#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>
#include <QTabWidget>
#include <QSqlQuery>
#include "connection.h"
#include "equipement.h"
#include <QStandardItemModel>
#include<QtPrintSupport/QPrinter>
#include<QFileDialog>
#include<QTextDocument>
#include <QPdfWriter>
#include <QPainter>
#include <QVBoxLayout>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QValueAxis>
QT_CHARTS_USE_NAMESPACE
#include <QWidget>
#include <QComboBox>
#include <QMessageBox>
#include <QIntValidator>
#include"QDate"
#include<QtDebug>
#include <QPrinter>
#include <QPainter>
#include <QFileDialog>
#include <QChart>
#include <QPieSeries>
#include <QPieSlice>
#include <QChartView>
#include <QInputDialog>
#include "arduino.h"







MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tab_equipement->setModel(e.afficher());
    int ret=A.connect_arduino();
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
        break;
    case(1):qDebug()<<"arduino is available but not connected to :"<< A.getarduino_port_name();
        break;
    case(-1):qDebug()<< "arduino is not available:" <<A.getarduino_port_name();

    }
    QObject::connect(A.getserial(),SIGNAL(readyRead()), this , SLOT(update_label()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
#include <QMessageBox>  // Include the necessary header

// ...


void MainWindow::on_pb_ajouter_clicked()
{
 qDebug();
    QString reference =ui->le_r->text();
    QString type=ui->le_y->text();
    QDate disponibilite =ui->le_d->date();

      QString etat=ui->le_e->text();
      QDate dateachat =ui->le_da->date();


      int NbrAnneeAmortissement=ui->le_na->text().toInt();

      Equipement e(reference , type , disponibilite , etat ,dateachat ,NbrAnneeAmortissement);

bool test=e.ajouter();
if (test){
    ui->tab_equipement->setModel(e.afficher());
    QMessageBox::information(nullptr, QObject::tr("ok"),
                QObject::tr("ajout avec success.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("not ok"),
                QObject::tr(" ajout non effectué.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}


void MainWindow::on_pb_supprimer_clicked()
{
    QString reference = ui->le_r->text ();
    Equipement e;
    bool test = e.supprimer( reference);

    if (test)
    {
        ui->tab_equipement->setModel(e.afficher());

        QMessageBox::information(this, QObject::tr("OK"),
            QObject::tr("Suppression effectuée\nClick OK to exit."), QMessageBox::Ok);
    }
    else
    {
        QMessageBox::information(this, QObject::tr("Not OK"),
            QObject::tr("Suppression non effectuée\nClick OK to exit."), QMessageBox::Ok);
    }
}


void MainWindow::on_pb_actualiser_clicked()
{
    Equipement e;
   ui->tab_equipement->setModel(e.afficher());
}
void MainWindow::on_pb_modifier_clicked()
{

    QString reference =ui->le_r->text();
    QString type=ui->le_y->text();
     QDate disponibilite =ui->le_d->date();
      QString etat=ui->le_e->text();
      QDate dateachat =ui->le_da->date();
      int NbrAnneeAmortissement=ui->le_na->text().toInt();

      Equipement e(reference , type , disponibilite , etat ,dateachat ,NbrAnneeAmortissement);

bool test=e.modifier();
QMessageBox msgBox;
if (test){
    ui->tab_equipement->setModel(e.afficher());
    QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Modification effectuée \n"),QMessageBox::Cancel);
           }
           else QMessageBox::critical(nullptr,QObject::tr("Not OK"), QObject::tr("Modification non effectuée\n"),QMessageBox::Cancel);

}
void MainWindow::on_pb_tri_clicked()
{
    ui->tab_equipement->setModel(e.tri());
}



void MainWindow::on_pb_chercher_clicked()
{
    QString TypeRecherche = ui->comboBox->currentText();

           QSqlQueryModel *model = new QSqlQueryModel;
           QSqlQuery query;

           // Écrire votre requête SQL pour la recherche en fonction du poste
           query.prepare("SELECT * FROM equipement WHERE type = :type");
           query.bindValue(":type", TypeRecherche);

           if (query.exec()) {
               model->setQuery(query);

               // Assurez-vous que les colonnes de votre tableau sont correctement configurées dans votre interface utilisateur (UI)
               ui->tab_equipement->setModel(model);
           } else {
               QMessageBox::critical(this, "Erreur", "Erreur lors de la recherche.");
           }

}

 void MainWindow::on_PDF_clicked()
{
     QString strStream;
       QTextStream out(&strStream);
       const int rowC=ui->tab_equipement->model()->rowCount();
       const int columnC=ui->tab_equipement->model()->columnCount();
       out <<  "<html>\n"
               "<head>\n"
               "<meta Content=\"Text/html; charset=Windows-1251\">\n"
               <<  QString("<title>%1</title>\n").arg("strTitle")
               <<  "</head>\n"
               "<body bgcolor=#ffffff link=#5000A0>\n"

               //     "<align='right'> " << datefich << "</align>"
               "<center> <H1>Liste des Equipement</H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";
       //headers
       out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
           for (int column = 0; column < columnC; column++)
               if (!ui->tab_equipement->isColumnHidden(column))
                   out << QString("<th>%1</th>").arg(ui->tab_equipement->model()->headerData(column, Qt::Horizontal).toString());
           out << "</tr></thead>\n";
       //data
           for (int row = 0; row < rowC; row++)
               {
                   out << "<tr> <td bkcolor=0>" << row + 1 << "</td>";
                   for (int column = 0; column < columnC; column++)
                   {
                       if (!ui->tab_equipement->isColumnHidden(column))
                       {
                           QString data = ui->tab_equipement->model()->data(ui->tab_equipement->model()->index(row, column)).toString().simplified();
                           out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                       }
                   }
                   out << "</tr>\n";
               }
           out <<  "</table> </center>\n"
                   "</body>\n"
                   "</html>\n";
           //getting file name
           QString fileName = QFileDialog::getSaveFileName((QWidget * )0, "Sauvegarder en PDF", QString(), "*.pdf");
               if (QFileInfo(fileName).suffix().isEmpty())
               {
                   fileName.append(".pdf");
               }

               QPrinter printer (QPrinter::PrinterResolution);
                   printer.setOutputFormat(QPrinter::PdfFormat);
                   printer.setPaperSize(QPrinter::A4);
                   printer.setOutputFileName(fileName);

                   QTextDocument doc;
                   doc.setHtml(strStream);
                   doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
                   doc.print(&printer);

 }

 void MainWindow::on_statistiquesButton_clicked()
 {
     // Définir l'indice de la colonne "etat" (remplacez par l'indice correct)
             const int index_de_la_colonne_etat = 4;

             // Récupérer les données des employés (etat)
             QMap<int, int> etatMap;

             // Remplacez cette boucle par la récupération des données de votre modèle ou de votre base de données
             for (int row = 0; row < ui->tab_equipement->model()->rowCount(); ++row) {
                 int etat = ui->tab_equipement->model()->data(ui->tab_equipement->model()->index(row, index_de_la_colonne_etat), Qt::DisplayRole).toInt();
                 etatMap[etat]++;
             }

             // Créer un objet QPieSeries
             QPieSeries *pieSeries = new QPieSeries();

             // Ajouter des tranches au graphique pour chaque etat
             for (auto it = etatMap.begin(); it != etatMap.end(); ++it) {
                 int etat = it.key();
                 int equipement = it.value();

                 // Calculer le pourcentage
                 double pourcentage = static_cast<double>(equipement) / ui->tab_equipement->model()->rowCount() * 100.0;

                 // Créer une tranche avec le pourcentage et l'etat
                 //QPieSlice *slice = new QPieSlice(QString("%1% employés avec %2 enfant(s)").arg(QString::number(pourcentage, 'f', 2)).arg(etat), pourcentage);
                 //QPieSlice *slice = new QPieSlice(QString("%1 % d'employés ont %2 enfant(s)").arg(QString::number(pourcentage, 'f', 2)).arg(etat), pourcentage);
                 QPieSlice *slice = new QPieSlice(QString("%1%  d'equipement ont %2 etat(s) \n ").arg(QString::number(pourcentage, 'f', 2)).arg(etat), pourcentage);

                 pieSeries->append(slice);
             }

             // Créer un graphique circulaire
             QChart *chart = new QChart();
             chart->addSeries(pieSeries);
             chart->setTitle("Répartition des pourcentages des employés en fonction d'etat");

             // Créer un afficheur de graphique
             QChartView *chartView = new QChartView(chart);

             // Afficher le graphique dans une nouvelle fenêtre avec un layout
             QVBoxLayout *layout = new QVBoxLayout;
             layout->addWidget(chartView);

             QWidget *chartWindow = new QWidget;
             chartWindow->setLayout(layout);
             chartWindow->resize(800, 600);
             chartWindow->show();
 }

 void MainWindow::on_pushButtonAfficherEntretien_clicked()
 {
     Equipement equipement;
     // Appeler la fonction pour afficher les données d'entretien à venir
     equipement.afficherEntretienAVenir();

     // Obtenir le modèle de données avec les résultats
     // equipement.afficherEntretienAVenir();

     // Afficher le modèle dans un tableau ou autre interface utilisateur
     ui->tableViewEntretien->model();
 }

/*
  void MainWindow::onAlertButtonClicked() {
      // Assuming equipement is an instance of your Equipement class
      e.alerteMaintenance();
  }*/



 //ARDUINO
  void MainWindow::update_label()
  {
      data=A.read_from_arduino();
      if(data=="1")
          ui->label->setText("ON");
      else if (data=="0")
          ui->label->setText("OFF");
  }
  void MainWindow::on_pb_on_Clicked()
  {
      A.write_to_arduino("1");
  }

  void MainWindow::on_pb_off_Clicked()
  {
      A.write_to_arduino("0");
  }
  void MainWindow::on_pb_plus_Clicked()
  {
      A.write_to_arduino("2");
  }
  void MainWindow::on_pb_moins_Clicked()
  {
      A.write_to_arduino("3");
  }








