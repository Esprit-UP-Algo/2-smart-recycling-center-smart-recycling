#include "windowines.h"
#include "ui_windowines.h"
#include "integration.h"
#include "client.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QString>
#include<QSqlQueryModel>
#include <QDate>
#include<QSqlQuery>
#include <QRegularExpression>
#include <QApplication>
#include <QPdfWriter>
#include <QPrinter>
#include <QPainter>
#include <QProcess>
#include <QDesktopServices>
#include <QFileDialog>
#include <QScreen>
#include <QPixmap>
#include <QFile>
#include <QTextStream>
#include <QMap>
#include "lcdcontroller.h"
#include "smtp.h"


Windowines::Windowines(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Windowines),
      lcdController(nullptr)
{
    ui->setupUi(this);
    lcdController= new LCDController(this);

    // pieSeries = new QPieSeries();
chartView = new QChartView(this);
 chartView->setRenderHint(QPainter::Antialiasing);
 chartView->setParent(ui->horizontalFrame);
chartView->setFixedSize(800, 400);//600

connect(ui->le_stat, &QPushButton::clicked, this, &Windowines::on_le_stat_clicked);

 // Créer une expression régulière pour valider l'adresse e-mail
QRegularExpression emailRegex("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");

 // Créer un QRegularExpressionValidator avec l'expression régulière
 QRegularExpressionValidator* emailValidator = new QRegularExpressionValidator(emailRegex, this);

 // Appliquer le validateur à votre champ d'adresse e-mail
 ui->le_mail->setValidator(emailValidator);


connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));
connect(ui->browseBtn, SIGNAL(clicked()), this, SLOT(browse()));



ui->cd->setValidator (new QIntValidator(0, 999, this));
ui->le_nbr->setValidator (new QIntValidator(0, 99, this));




 QRegularExpressionValidator* sexeValidator = new QRegularExpressionValidator(
             QRegularExpression("^[hf]$", QRegularExpression::CaseInsensitiveOption), this);
 ui->le_sexe->setValidator(sexeValidator);

ui->tab_client->setModel(C.afficher());


}

Windowines::~Windowines()
{
    delete ui;
}

void Windowines::on_le_ajouter_clicked()
{

    int code_fiscale=ui->cd->text().toInt();
    QString mail=ui->le_mail->text();
     QString adresse=ui->le_adresse->text();

      QString sexe=ui->le_sexe->text();
       int nbrcommande=ui->le_nbr->text().toInt();


                  Client C(code_fiscale,mail,adresse,sexe,nbrcommande);
                  bool test = C.ajouter();
                  QMessageBox msgBox;
                  if (test) {
                      msgBox.setText("Ajout avec succès");
                      ui->tab_client->setModel(C.afficher());
                  } else {
                      msgBox.setText("Échec d'ajout");
                  }
                  msgBox.exec();


}

void Windowines::on_pb_supprimer_clicked()
{
    Client C; C.setcode_fiscale(ui->le_supp_code->text().toInt());
    bool test=C.supprimer(C.getcode_fiscale());
    QMessageBox msgBox;
    if(test){
        msgBox.setText("Suppression avec success.");
        ui->tab_client->setModel(C.afficher());}
    else
        msgBox.setText("Echec de suppression");
    msgBox.exec();
}

void Windowines::on_pb_modifier_clicked()
{

    int code_fiscale=ui->cd->text().toInt();
    QString mail=ui->le_mail->text();
     QString adresse=ui->le_adresse->text();

       QString sexe=ui->le_sexe->text();
       int nbrcommande=ui->le_nbr->text().toInt();
       //int reduction=ui->le_reduction->text().toInt();

       Client C(code_fiscale,mail,adresse,sexe,nbrcommande);
       bool test=C.modifier();
       if (test){
           ui->tab_client->setModel(C.afficher());
           QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Modification effectuée \n"),QMessageBox::Cancel);
       }
       else QMessageBox::critical(nullptr,QObject::tr("Not OK"), QObject::tr("Modification non effectuée\n"),QMessageBox::Cancel);


}


void Windowines::on_trier_clicked()
{
    ui->tab_client->setModel(C.trierParCodeFiscale());

}

void Windowines::on_le_chercher_clicked()
{




    QString emailToSearch = ui->le_email->text();

        QSqlQuery query;
        query.prepare("SELECT * FROM client WHERE mail = :emailToSearch");
        query.bindValue(":emailToSearch", emailToSearch);

        if (query.exec() && query.next()) {
            QString mail = query.value(1).toString();
            QString adresse = query.value(2).toString();

            QSqlQueryModel *model = new QSqlQueryModel();
            model->setQuery("SELECT * FROM client WHERE mail = '" + emailToSearch + "'");
            ui->tab_client->setModel(model);

            // Afficher le code fiscal sur l'afficheur LCD
            lcdController->afficherCodeFiscaleByEmail(emailToSearch);

            QMessageBox::information(this, "Client trouvé", "Coordonnées du client affichées.");
        } else {
            QMessageBox::warning(this, "Client non trouvé", "Aucun client trouvé avec cette adresse e-mail.");
        }















    /*QString emailToSearch = ui->le_email->text();


        QSqlQuery query;
        query.prepare("SELECT * FROM client WHERE mail = :emailToSearch");
        query.bindValue(":emailToSearch", emailToSearch);

        if (query.exec() && query.next()) {

            QString mail = query.value(1).toString();
            //QString date1erContact = query.value(2).toString();
            QString adresse = query.value(2).toString();


            QSqlQueryModel* model = new QSqlQueryModel();
            model->setQuery("SELECT * FROM client WHERE mail = '" + emailToSearch + "'");
            ui->tab_client->setModel(model);

            QMessageBox::information(this, "Client trouvé", "Coordonnées du client affichées.");
        } else {

            QMessageBox::warning(this, "Client non trouvé", "Aucun client trouvé avec cette adresse e-mail.");
        }*/

    }









void Windowines::on_le_PDF_clicked()
{
    QString cheminFichier = QFileDialog::getSaveFileName(this, "Enregistrer le PDF", QString(), "Fichiers PDF (*.pdf)");

               if (cheminFichier.isEmpty()) {
                   // L'utilisateur a annulé la boîte de dialogue de sauvegarde ou a fermé la fenêtre
                   return;
               }

               // Créer un objet QPrinter avec le format PDF
               QPrinter printer(QPrinter::HighResolution);
               printer.setOutputFormat(QPrinter::PdfFormat);
               printer.setOutputFileName(cheminFichier);

               // Créer un objet QPainter pour dessiner sur le QPrinter
               QPainter painter(&printer);

               // Imprimer le contenu du tableau sur le QPainter
               ui->tab_client->render(&painter);

               // Le fichier PDF est créé automatiquement lorsque l'objet QPrinter est détruit (à la sortie de cette fonction)
               // Vous n'avez pas besoin de fermer le fichier manuellement


}



void Windowines::on_le_stat_clicked()
{
   /* QPieSeries *series = new QPieSeries();

        QSqlQueryModel *statModel = C.afficherStatistiques();

        int femmeCount = statModel->data(statModel->index(0, 0)).toInt();
        int hommeCount = statModel->data(statModel->index(0, 1)).toInt();

        double total = femmeCount + hommeCount;
        double femmePercentage = (total != 0) ? (femmeCount / total) * 100 : 0;
        double hommePercentage = (total != 0) ? (hommeCount / total) * 100 : 0;

        series->append("Femme " + QString::number(femmePercentage) + "%", femmeCount);
        series->append("Homme " + QString::number(hommePercentage) + "%", hommeCount);

        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setAnimationOptions(QChart::SeriesAnimations);
        chart->setTitle("Gender Chart");
        chart->setTheme(QChart::ChartThemeBlueCerulean);

        // Affichage du nombre total d'hommes et de femmes
        QLabel *labelHomme = new QLabel("Hommes : " + QString::number(hommeCount), this);
        QLabel *labelFemme = new QLabel("Femmes : " + QString::number(femmeCount), this);

        QVBoxLayout *layout = new QVBoxLayout();
        layout->addWidget(labelHomme);
        layout->addWidget(labelFemme);

        // Ajout du layout à votre fenêtre
        ui->verticalLayout->addLayout(layout);

        chartView->setChart(chart);*/




    // Obtenir les pourcentages pour chaque intervalle en utilisant la fonction de la classe Client
    Client C;
        QMap<QString, int> percentages = C.calculateOrderIntervalsPercentages();

        QPieSeries *series = new QPieSeries();

        for (auto it = percentages.begin(); it != percentages.end(); ++it) {
            series->append(it.key() + " " + QString::number(it.value()) + "%", it.value());
        }

        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("Statistiques des commandes de client");

        chartView->setChart(chart);

        // Afficher également les pourcentages dans un message
        QString message;
        for (auto it = percentages.begin(); it != percentages.end(); ++it) {
            message += QString("%1 clients ont %2\n").arg(it.value()).arg(it.key());
        }
        QMessageBox::information(this, "Statistiques des commandes", message);




}



void Windowines::exportFactureToPNG(const QString &filename)
{   Client client;
    int code = ui->png->text().toInt();
    QSqlQuery selectQuery;
    selectQuery.prepare("SELECT c.codefiscale, c.nbrcommande, c.mail, c.adresse, c.reduction, cmd.totalcommande "
                            "FROM client AS c "
                            "JOIN commande AS cmd ON c.codefiscale = cmd.codefiscale "
                            "WHERE c.codefiscale = :codefiscale");
    selectQuery.bindValue(":codefiscale", code);

    if (selectQuery.exec() && selectQuery.next() && selectQuery.isValid()) {
        QString code_fiscale = selectQuery.value("codefiscale").toString();
        QString nombre_commande = selectQuery.value("nbrcommande").toString();
        QString adresse_mail = selectQuery.value("mail").toString();
        QString adresse = selectQuery.value("adresse").toString();
       QString reduction = selectQuery.value("reduction").toString();
      QString prix_commande = selectQuery.value("totalcommande").toString();

        QWidget myWidget;
        QVBoxLayout *layout = new QVBoxLayout(&myWidget);

        QLabel *contentLabel = new QLabel("\n\n\n\n Cette facture correspond à : " + (code_fiscale) + "\n\n\n  "
                                         "Le nombre de commande est :" + (nombre_commande) + "\n\n\n"
                                         "L'adresse mail est :" + (adresse_mail) + "\n\n\n"
                                         "L'adresse :" + (adresse) + "\n\n\n"
                                         "Avec une reduction de :" + (reduction) + "\n\n\n"
                                         "le montant de votre facture est :" + (prix_commande) + "\n\n\n"

                                         "\n\n\n\n\n"
                                         "notre signature ici                        votre signature ici\n\n\n\n\n\n\n");

        layout->addWidget(contentLabel);

        QPixmap screenshot = myWidget.grab();
        screenshot.save(filename, "PNG");
    }
}

















void Windowines::on_PNG_clicked()
{

    QString fileName = QFileDialog::getSaveFileName(this, "Enregistrer le texte en PNG", "", "Images (*.png)");

       if (!fileName.isEmpty()) {
           exportFactureToPNG(fileName);
           QMessageBox::information(this, "Exportation réussie", "La facture a été exportée avec succès en format PNG.");
       }
}











void Windowines::on_pb_reduction_clicked()
{
    Client C;
        int codeFiscale = ui->le_fiscale->text().toInt();
        double reduction = C.calculerEtSauvegarderReduction(codeFiscale);

        if (reduction >= 0.0) {
            // Mettez à jour la réduction dans la base de données
           // if (C.updateReductionByCodeFiscale(codeFiscale, reduction)) {
                // Rafraîchissez la vue des clients
                ui->tab_client->setModel(C.afficher());

                QMessageBox::information(this, "Réduction calculée", QString("Le client a une réduction de %1%").arg(reduction * 100));}
             else
                QMessageBox::warning(this, "Erreur de mise à jour", "Impossible de mettre à jour la réduction dans la base de données.");

        // else
            //QMessageBox::warning(this, "Client non trouvé", "Aucun client trouvé avec ce code fiscal.");






}

void Windowines::on_afficheur_clicked()
{
    int clientCode = ui->le_client->text().toInt(); // Modifier en fonction de votre interface
       QMap<QString, QString> clientData = C.getClientDataById(clientCode);

       if (!clientData.isEmpty()) {
           QByteArray dataToSend;

           // Formatez les données pour les envoyer à l'afficheur LCD
           dataToSend += "Client: " + clientData["code_fiscale"].toUtf8() + "\n";
           dataToSend += "Mail: " + clientData["mail"].toUtf8() + "\n";
           dataToSend += "Adresse: " + clientData["adresse"].toUtf8() + "\n";
           // Ajoutez d'autres données selon vos besoins

          // A.write_to_arduino(dataToSend);
       } else {
           qDebug() << "Client not found";
       }
}




void Windowines::browse()
{
    files.clear();

    QFileDialog dialog(this);
    dialog.setDirectory(QDir::homePath());
    dialog.setFileMode(QFileDialog::ExistingFiles);

    if (dialog.exec())
        files = dialog.selectedFiles();

    QString fileListString;
    foreach(QString file, files)
        fileListString.append( "\"" + QFileInfo(file).fileName() + "\" " );

    ui->file->setText( fileListString );

}




void Windowines::sendMail()
{
    Smtp * smtp = new Smtp("ines.rahrah@esprit.tn", ui->paswd->text(), ui->server->text(), ui->port->text().toInt());
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    if( !files.isEmpty() )
        smtp->sendMail("ines.rahrah@esprit.tn", ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText(), files );
    else
        smtp->sendMail("ines.rahrah@esprit.tn", ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());
}

void Windowines::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );}
void Windowines::on_pb_back2_clicked()
{
    integration *c = new integration;
    c ->show();
    hide();

}
