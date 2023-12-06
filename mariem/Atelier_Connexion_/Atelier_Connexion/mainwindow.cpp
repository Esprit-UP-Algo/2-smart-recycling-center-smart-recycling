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
#include "integration.h"
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



QT_CHARTS_USE_NAMESPACE




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tab_equipement->setModel(e.afficher());
    ui->le_na->setValidator(new QRegExpValidator(QRegExp("\\d+"), this));
    //ui->le_y->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+"), this));
    //ui->comboBox->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+"), this));
    ui->le_r->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+"), this));

    Equipement e;
      if(ui->le_r->text().isEmpty()||/*ui->le_y->text().isEmpty()||ui->le_e->text().isEmpty()||*/ui->le_d->text().isEmpty()||ui->le_da->text().isEmpty()||ui->le_na->text().isEmpty()) {
              QMessageBox::critical(nullptr, QObject::tr("Erreur"),
              QObject::tr("Information manquante.\n""Achevez la complétion."), QMessageBox::Cancel);}
      else{
      bool test=e.ajouter();
      if (test){
          ui->tab_equipement->setModel(e.afficher());
          QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Ajout effectué \n"),QMessageBox::Cancel);
      }
      else QMessageBox::critical(nullptr,QObject::tr("Not OK"), QObject::tr("Ajout non effectué\n"),QMessageBox::Cancel);
   }

    int ret=A.connect_arduino();
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
        break;
    case(1):qDebug()<<"arduino is available but not connected to :"<< A.getarduino_port_name();
        break;
    case(-1):qDebug()<< "arduino is not available:" <<A.getarduino_port_name();

    }
    QObject::connect(A.getserial(),SIGNAL(readyRead()), this , SLOT(update_label()));
    marquerJoursFeries(ui->calendrierWidget);
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
     QString type = ui->comboBox1->currentText();
    //QString type=ui->le_y->text();
    QDate disponibilite =ui->le_d->date();

      QString etat=ui->comboBox->currentText();
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
    QString type=ui->comboBox1->currentText();
     QDate disponibilite =ui->le_d->date();
      QString etat=ui->comboBox->currentText();
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
    QString TypeRecherche = ui->comboBox1->currentText();

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

         QSqlQuery q1, q2, q3, q4, q5;
         qreal tot = 0, c1 = 0, c2 = 0, c3 = 0, c4 = 0;

         q1.prepare("SELECT etat FROM equipement");
         q1.exec();
         q2.prepare("SELECT etat FROM equipement WHERE etat='Marche'");
         q2.exec();
         q3.prepare("SELECT etat FROM equipement WHERE etat='Panne'");
         q3.exec();
         q4.prepare("SELECT etat FROM equipement WHERE etat='Attente'");
         q4.exec();
         q5.prepare("SELECT etat FROM equipement WHERE etat='Autre'");
         q5.exec();  // Ajout de la préparation et de l'exécution de la requête q5

         while (q1.next()) { tot++; }
         while (q2.next()) { c1++; }
         while (q3.next()) { c2++; }
         while (q4.next()) { c3++; }
         while (q5.next()) { c4++; }

         c1 = (c1 * 100) / tot;
         c2 = (c2 * 100) / tot;
         c3 = (c3 * 100) / tot;
         c4 = (c4 * 100) / tot;

         QString etat1 = "Marche = " + QString::number(c1) + "%";
         QString etat2 = "Panne = " + QString::number(c2) + "%";
         QString etat3 = "Attente = " + QString::number(c3) + "%";
         QString etat4 = "Autre = " + QString::number(c4) + "%";  // Ajout de l'état 'Autre'

         // Création des pie series
         QPieSeries *series = new QPieSeries();
         series->append(etat1, c1);
         series->append(etat2, c2);
         series->append(etat3, c3);
         series->append(etat4, c4);  //

         // Création d'un chart
         QChart *chart = new QChart();
         chart->setTitle("Les résultats:");
         chart->addSeries(series);
         chart->legend()->show();
         chart->setBackgroundBrush(QColor(252, 236, 218, 0));

         // Affichage du chart
         QChartView *chartView = new QChartView(chart, ui->graphicsView);
         chartView->setRenderHint(QPainter::Antialiasing);
         chartView->setMinimumSize(400, 400);
         chartView->show();
     }







 //ARDUINO
#include <QInputDialog>

void MainWindow::update_label()
{
    // Ask the user for the product ID
    bool ok;
    int productId = QInputDialog::getInt(this, "Enter Product ID", "Product ID:", 15, 1, 1000, 1, &ok);

    if (!ok)
    {
        // User canceled input or entered an invalid value
        qDebug() << "User canceled or entered an invalid product ID.";
        return;
    }

    QString data = A.read_from_arduino();

    if (data == "1")
    {
        // Call the function to increment by 1 the product quantity
        bool isIncrementSuccessful = e.incrementQuantityById(productId);

        if (isIncrementSuccessful)
        {
            qDebug() << "Quantity incremented by 1.";

            // Check if the product quantity has reached 10
            bool hasReachedTen = e.checkQuantityReachedTen(productId);

            if (hasReachedTen)
            {
                // Send '2' to Arduino if the product quantity has reached 10
                A.write_to_arduino("2");
            }
        }
        else
        {
            qDebug() << "Error incrementing quantity.";
        }
    }
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

// CALENDRIER

  void MainWindow::marquerJoursFeries(QCalendarWidget *calendrier) {
      // Liste des jours fériés (à remplir avec vos propres dates et raisons)
      QMap<QDate, QString> joursFeries;
      joursFeries.insert(QDate(2023, 1, 1), "Jour de l'an");
      joursFeries.insert(QDate(2023, 5, 1), "Fête du Travail");
      joursFeries.insert(QDate(2023, 7, 14), "Fête Nationale");

      // Appliquer le style aux jours fériés
      QTextCharFormat format;
      format.setBackground(QBrush(QColor("red")));

      for (auto it = joursFeries.begin(); it != joursFeries.end(); ++it) {
          QDate jourFerie = it.key();
          QString raison = it.value();

          calendrier->setDateTextFormat(jourFerie, format);

          // Assurez-vous que le calendrier est configuré pour être sélectionnable
          calendrier->setSelectionMode(QCalendarWidget::SingleSelection);

          // Connectez le signal clicked au slot correspondant pour afficher la raison
          connect(calendrier, &QCalendarWidget::clicked, [=](const QDate &date) {
              if (date == jourFerie) {
                  ui->textEditRaison->setText(raison);
              }
          });
      }
  }
  void MainWindow::on_pb_back_clicked()
  {
      integration *e = new integration;
      e ->show();
      hide();

  }










