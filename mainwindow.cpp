

#include <QSqlQuery>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employe.h"
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
#include <QtWidgets>
#include<QSerialPort>
#include <QSerialPortInfo>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->le_id->setValidator(new QIntValidator(0, 9999999, this));
    ui->le_num_telephone->setValidator(new QIntValidator(100, 99999999, this));
    ui->le_nbre_enfant->setValidator(new QIntValidator(0, 9, this));

    ui->tab_employe->setModel(E.afficher());
    dateSortModel = new QSortFilterProxyModel(this);
        dateSortModel->setSourceModel(E.afficher());
        //connect(ui->pb_pdf, &QPushButton::clicked, this, &MainWindow::on_pb_pdf_clicked);

      //  connect(ui->pb_stat, &QPushButton::clicked, this, &MainWindow::on_pb_stat_clicked);
        connect(ui->pb_stat, SIGNAL(clicked()), this, SLOT(on_pb_stat_clicked()));

        serial = new QSerialPort(this);
            serial->setPortName("COM4"); // Change to the appropriate port
            serial->setBaudRate(QSerialPort::Baud9600);
            if (serial->open(QIODevice::ReadWrite)) {
                connect(serial, SIGNAL(readyRead()), this, SLOT(readData()));
            } else {
                qDebug() << "Error opening serial port:" << serial->errorString();
            }

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::readData()
{
    QByteArray data = serial->readAll();
    QByteArray search = "A3";
    QByteArray second = "4E";

    // Process the data as needed, e.g., display it in the QTextEdit

    int index = data.indexOf(search);
    int ha=data.indexOf(second);


    int id1=1;
    int id2=2;

    if (index != -1) {


        ui->lineEdit_identifiant->setText(QString::number(id1));
        ui->lineEdit_motDePasse->setText(search);

    }
    else if(ha != -1)
    {
        ui->lineEdit_identifiant->setText(QString::number(id2));
        ui->lineEdit_motDePasse->setText(second);
    }
}
void MainWindow::on_pb_ajouter_clicked()
{

    int id=ui->le_id->text().toInt();
    int num_telephone=ui->le_num_telephone->text().toInt();
    int nbre_enfant=ui->le_nbre_enfant->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    QString statue_familiale=ui->le_statue_familiale->text();
    QString mot_de_passe=ui->le_mot_de_passe->text();
    QDate date_de_naissance=ui->le_date_de_naissance->date();
    QString poste=ui->le_poste->currentText();
    QDate date_d_embauche=ui->le_date_d_embauche->date();
    QString q1=ui->q1->text();
    QString q2=ui->q2->text();
    QString rfid=ui->le_rfid->text();

            Employe E(id, num_telephone, nbre_enfant, nom, prenom, statue_familiale, mot_de_passe, date_de_naissance, poste, date_d_embauche,q1,q2,rfid);
            bool test = E.ajouter();
            QMessageBox msgBox;
            if (test) {
                msgBox.setText("Ajout avec succès");
                ui->tab_employe->setModel(E.afficher());
            } else {
                msgBox.setText("Échec d'ajout");
            }
            msgBox.exec();

}

void MainWindow::on_pb_supprimer_clicked()
{
    Employe E1 ;
    E1.setid(ui->le_id_supp->text().toInt());
    bool test=E1.supprimer(E1.getid());
    QMessageBox msgBox;
    if (test)
    {msgBox.setText("Sup avec succes");
     ui->tab_employe ->setModel(E.afficher());
    }
    else
        msgBox.setText("Echec de suppression");
        msgBox.exec();
}

void MainWindow::on_pb_modifier_clicked()
{
    int id=ui->le_id->text().toInt();
    int num_telephone=ui->le_num_telephone->text().toInt();
    int nbre_enfant=ui->le_nbre_enfant->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    QString statue_familiale=ui->le_statue_familiale->text();
    QString mot_de_passe=ui->le_mot_de_passe->text();
    QDate date_de_naissance=ui->le_date_de_naissance->date();
    QString poste=ui->le_poste->currentText();
    QDate date_d_embauche=ui->le_date_d_embauche->date();
     QString q1=ui->q1->text();
     QString q2=ui->q2->text();
     QString rfid=ui->le_rfid->text();
      Employe E (id,num_telephone,nbre_enfant ,nom,prenom,statue_familiale,mot_de_passe,date_de_naissance,poste,date_d_embauche,q1,q2,rfid);
        bool test=E.modifier();
       if (test){
           ui->tab_employe ->setModel(E.afficher());
           QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Modification effectuée \n"),QMessageBox::Cancel);
       }
       else QMessageBox::critical(nullptr,QObject::tr("Not OK"), QObject::tr("Modification non effectuée\n"),QMessageBox::Cancel);
}


void MainWindow::on_pb_chercher_clicked()


    {
        QString posteRecherche = ui->comboBox->currentText();

        QSqlQueryModel *model = new QSqlQueryModel;
        QSqlQuery query;

        // Écrire votre requête SQL pour la recherche en fonction du poste
        query.prepare("SELECT * FROM employe WHERE POSTE = :poste");
        query.bindValue(":poste", posteRecherche);

        if (query.exec()) {
            model->setQuery(query);

            // Assurez-vous que les colonnes de votre tableau sont correctement configurées dans votre interface utilisateur (UI)
            ui->tab_employe->setModel(model);
        } else {
            QMessageBox::critical(this, "Erreur", "Erreur lors de la recherche.");
        }
    }





void MainWindow::on_pb_trier_clicked()
{

    // Tri du tableau selon la date de naissance dans l'ordre croissant
       // dateSortModel->sort(0, Qt::AscendingOrder);  // Assurez-vous que 4 représente la colonne de la date de naissance

        // Appliquer le modèle proxy trié à la vue
        //ui->tab_employe->setModel(dateSortModel);
    ui->tab_employe->setModel(E.trieridentifiant());
}

void MainWindow::on_pb_pdf_clicked()
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
           ui->tab_employe->render(&painter);

           // Le fichier PDF est créé automatiquement lorsque l'objet QPrinter est détruit (à la sortie de cette fonction)
           // Vous n'avez pas besoin de fermer le fichier manuellement
}

void MainWindow::on_pb_stat_clicked()
{
    // Définir l'indice de la colonne "nombre_enfants" (remplacez par l'indice correct)
        const int index_de_la_colonne_nombre_enfants = 7;

        // Récupérer les données des employés (nombre d'enfants)
        QMap<int, int> nombreEnfantsMap;

        // Remplacez cette boucle par la récupération des données de votre modèle ou de votre base de données
        for (int row = 0; row < ui->tab_employe->model()->rowCount(); ++row) {
            int nombreEnfants = ui->tab_employe->model()->data(ui->tab_employe->model()->index(row, index_de_la_colonne_nombre_enfants), Qt::DisplayRole).toInt();
            nombreEnfantsMap[nombreEnfants]++;
        }

        // Créer un objet QPieSeries
        QPieSeries *pieSeries = new QPieSeries();

        // Ajouter des tranches au graphique pour chaque nombre d'enfants
        for (auto it = nombreEnfantsMap.begin(); it != nombreEnfantsMap.end(); ++it) {
            int nombreEnfants = it.key();
            int nombreEmployes = it.value();

            // Calculer le pourcentage
            double pourcentage = static_cast<double>(nombreEmployes) / ui->tab_employe->model()->rowCount() * 100.0;

            // Créer une tranche avec le pourcentage et le nombre d'enfants
            //QPieSlice *slice = new QPieSlice(QString("%1% employés avec %2 enfant(s)").arg(QString::number(pourcentage, 'f', 2)).arg(nombreEnfants), pourcentage);
            //QPieSlice *slice = new QPieSlice(QString("%1 % d'employés ont %2 enfant(s)").arg(QString::number(pourcentage, 'f', 2)).arg(nombreEnfants), pourcentage);
            QPieSlice *slice = new QPieSlice(QString("%1%  d'employés ont %2 enfant(s) \n ").arg(QString::number(pourcentage, 'f', 2)).arg(nombreEnfants), pourcentage);

            pieSeries->append(slice);
        }

        // Créer un graphique circulaire
        QChart *chart = new QChart();
        chart->addSeries(pieSeries);
        chart->setTitle("Répartition des pourcentages des employés en fonction du nombre d'enfants");

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
/*void MainWindow::on_pushButton_clicked()
{
    QString identifiant = ui->lineEdit_identifiant->text();

    // RFID value to be read from the RFID sensor
    QString rfidValue = "b3c317fc"; // Replace with the actual RFID value read from the sensor

    bool utilisateurTrouve = false;
    QLabel *l = ui->label_21;
    QLabel *l2 = ui->label_22;

    for (int row = 0; row < ui->tab_employe->model()->rowCount(); ++row) {
        QString identifiantDansTableau = ui->tab_employe->model()->data(ui->tab_employe->model()->index(row, 0), Qt::DisplayRole).toString();
        QString rfidDansTableau = ui->tab_employe->model()->data(ui->tab_employe->model()->index(row, 1), Qt::DisplayRole).toString();

        if (identifiantDansTableau == identifiant && rfidDansTableau == rfidValue) {
            utilisateurTrouve = true;

            // Login successful
            QMessageBox::information(this, "Login Success", "Login successful.");
            // Perform additional actions after successful login.
            l->setFixedSize(1, 1);
            l2->setFixedSize(1, 1);

            break; // Exit the loop after finding the user
        }
    }

    if (!utilisateurTrouve) {
        // Username or RFID not found
        QMessageBox::warning(this, "Login Failed", "User not found or incorrect RFID.");
        l->setFixedSize(10000, 10000);
        l2->setFixedSize(10000, 10000);
    }
}*/

void MainWindow::on_pushButton_clicked()
{
    QString identifiant = ui->lineEdit_identifiant->text();
        QString motDePasse = ui->lineEdit_motDePasse->text();

        // Effectuer la recherche dans le tableau des employés
        bool utilisateurTrouve = false;
        QLabel * l=ui->label_21;
        QLabel * l2=ui->label_22;

        for (int row = 0; row < ui->tab_employe->model()->rowCount(); ++row) {
            QString identifiantDansTableau = ui->tab_employe->model()->data(ui->tab_employe->model()->index(row, 0), Qt::DisplayRole).toString();
            QString motDePasseDansTableau = ui->tab_employe->model()->data(ui->tab_employe->model()->index(row,1), Qt::DisplayRole).toString();


            if (identifiantDansTableau == identifiant) {
                utilisateurTrouve = true;

                if (motDePasseDansTableau == motDePasse) {
                    // Identifiant et mot de passe corrects
                    QMessageBox::information(this, "Login Success", "Login successful.");
                    // Effectuez d'autres actions nécessaires après la connexion réussie.
                    l->setFixedSize(1,1);
                    l2->setFixedSize(1,1);

                } else {
                    // Mot de passe incorrect
                    QMessageBox::warning(this, "Login Failed", "Incorrect password.");
                    l->setFixedSize(10000,10000);
                    l2->setFixedSize(10000,10000);


                }



                break;  // Sortir de la boucle après avoir trouvé l'utilisateur
            }
        }

        if (!utilisateurTrouve) {
            // Identifiant introuvable
            QMessageBox::warning(this, "Login Failed", "User not found.");
            l->setFixedSize(10000,10000);
            l2->setFixedSize(10000,10000);

        }

}
/*void MainWindow::on_pushButton_clicked()
{
    QString identifiant = ui->lineEdit_identifiant->text();
    QString motDePasse = ui->lineEdit_motDePasse->text();

    // RFID value to be read from the RFID sensor
    QString rfidValue = "b3c317fc"; // Replace with the actual RFID value read from the sensor

    bool utilisateurTrouve = false;
    QLabel *l = ui->label_21;
    QLabel *l2 = ui->label_22;

    for (int row = 0; row < ui->tab_employe->model()->rowCount(); ++row) {
        QString identifiantDansTableau = ui->tab_employe->model()->data(ui->tab_employe->model()->index(row, 0), Qt::DisplayRole).toString();
        QString motDePasseDansTableau = ui->tab_employe->model()->data(ui->tab_employe->model()->index(row, 1), Qt::DisplayRole).toString();
        QString rfidDansTableau = ui->tab_employe->model()->data(ui->tab_employe->model()->index(row, 2), Qt::DisplayRole).toString();

        if (identifiantDansTableau == identifiant) {
            utilisateurTrouve = true;

            if (motDePasseDansTableau == motDePasse) {
                // Username and password are correct
                // Now, check RFID
                if (rfidDansTableau == rfidValue) {
                    // RFID is correct
                    QMessageBox::information(this, "Login Success", "Login successful.");
                    // Perform additional actions after successful login.
                    l->setFixedSize(1, 1);
                    l2->setFixedSize(1, 1);
                } else {
                    // Incorrect RFID
                    QMessageBox::warning(this, "Login Failed", "Incorrect RFID.");
                    l->setFixedSize(10000, 10000);
                    l2->setFixedSize(10000, 10000);
                }
            } else {
                // Incorrect password
                QMessageBox::warning(this, "Login Failed", "Incorrect password.");
                l->setFixedSize(10000, 10000);
                l2->setFixedSize(10000, 10000);
            }

            break; // Exit the loop after finding the user
        }
    }

    if (!utilisateurTrouve) {
        // Username not found
        QMessageBox::warning(this, "Login Failed", "User not found.");
        l->setFixedSize(10000, 10000);
        l2->setFixedSize(10000, 10000);
    }
}*/


void MainWindow::on_pushButton_2_clicked()
{
    QString identifiant = ui->lineEdit_identifiant->text();

        // Vérifier si l'identifiant est présent dans le tableau des employés
        bool utilisateurTrouve = false;
        Employe E1;  // Déplacer la création de l'objet à l'extérieur de la boucle
        for (int row = 0; row < ui->tab_employe->model()->rowCount(); ++row) {
            QString identifiantDansTableau = ui->tab_employe->model()->data(ui->tab_employe->model()->index(row, 0), Qt::DisplayRole).toString();

            if (identifiantDansTableau == identifiant) {
                utilisateurTrouve = true;

                // Obtenir les questions de sécurité
                QString question1 = ui->tab_employe->model()->data(ui->tab_employe->model()->index(row, 10), Qt::DisplayRole).toString();
                QString question2 = ui->tab_employe->model()->data(ui->tab_employe->model()->index(row, 11), Qt::DisplayRole).toString();
                QString val ="répondre";
                // Demander les réponses à l'utilisateur
                QString reponse1 = QInputDialog::getText(this, val, "Quel est votre plat préféré ?");
                QString reponse2 = QInputDialog::getText(this, val, " Quel était le nom de votre école primaire ?");

                // Vérifier les réponses
                if (reponse1 == question1 && reponse2 == question2) {
                    // Réponses correctes, demander le nouveau mot de passe
                    QString nouveauMotDePasse = QInputDialog::getText(this, "Nouveau mot de passe", "Entrez votre nouveau mot de passe:");

                    E1.setid(identifiant.toInt());
                    E1.setmot_de_passe(nouveauMotDePasse);
                    bool modificationReussie = E1.modifier();

                    if (modificationReussie) {
                        QMessageBox::information(this, "Modification réussie", "Le mot de passe a été modifié avec succès.");
                    } else {
                        QMessageBox::warning(this, "Échec de la modification", "La modification du mot de passe a échoué.");
                    }
                } else {
                    // Réponses incorrectes
                    QMessageBox::warning(this, "Réponse incorrecte", "Les réponses aux questions de sécurité sont incorrectes.");
                }

                break;  // Sortir de la boucle après avoir trouvé l'utilisateur
            }
        }

        if (!utilisateurTrouve) {
            // Identifiant introuvable
            QMessageBox::warning(this, "Utilisateur introuvable", "L'identifiant n'a pas été trouvé dans le tableau des employés.");
        }
}
void MainWindow::generatePieChart()
{
    // Code pour générer le diagramme (le même que celui dans on_pb_stat2_clicked)
    // Créer un QPieSeries pour le diagramme circulaire
    QPieSeries *series = new QPieSeries();

    // Définir les intervalles d'ancienneté
    QVector<int> intervals = {1, 5, 10, 15};  // Vous pouvez ajuster ces valeurs selon vos besoins

    // Calculer le nombre d'employés dans chaque intervalle
    QVector<int> employeeCounts(intervals.size() + 1, 0);

    for (int row = 0; row < ui->tab_employe->model()->rowCount(); ++row) {
        QDate dateEmbauche = ui->tab_employe->model()->data(ui->tab_employe->model()->index(row,9), Qt::DisplayRole).toDate();
        int yearsOfService = QDate::currentDate().year() - dateEmbauche.year();

        // Trouver l'intervalle approprié
        int intervalIndex = 0;
        while (intervalIndex < intervals.size() && yearsOfService > intervals[intervalIndex]) {
            intervalIndex++;
        }

        // Incrémenter le compteur d'employés dans l'intervalle trouvé
        employeeCounts[intervalIndex]++;
    }

    // Calculer le pourcentage pour chaque intervalle
    int totalEmployees = ui->tab_employe->model()->rowCount();
    for (int i = 0; i < intervals.size() + 1; ++i) {
        qreal percentage = (qreal)employeeCounts[i] / totalEmployees * 100.0;
        QString label = (i < intervals.size()) ? QString("%1-%2 ans").arg((i == 0) ? 1 : intervals[i - 1] + 1).arg(intervals[i]) : QString("%1+ ans").arg((intervals.isEmpty()) ? 1 : intervals.last() + 1);

        // Ajouter le segment au QPieSeries
        series->append(label, percentage);
    }

    // Créer un QChart et l'ajouter à la vue
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Répartition des employés par ancienneté");
    chart->legend()->setAlignment(Qt::AlignRight);

    // Créer une vue QChartView et l'afficher
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Afficher la vue du graphique dans une nouvelle fenêtre
    QDialog *dialog = new QDialog(this);
    QVBoxLayout *layout = new QVBoxLayout(dialog);
    layout->addWidget(chartView);
    dialog->setLayout(layout);
    dialog->setWindowTitle("Statistiques d'ancienneté des employés");
    dialog->exec();

    // Mettez à jour la vue du graphique (chartView)
    chartView->update();
}

void MainWindow::on_pb_sat2_clicked()

{
    // Créer un QPieSeries pour le diagramme circulaire
    QPieSeries *series = new QPieSeries();

    // Définir les intervalles d'ancienneté
    QVector<int> intervals = {1, 5, 10, 15};  // Vous pouvez ajuster ces valeurs selon vos besoins

    // Calculer le nombre d'employés dans chaque intervalle
    QVector<int> employeeCounts(intervals.size() + 1, 0);

    for (int row = 0; row < ui->tab_employe->model()->rowCount(); ++row) {
        QDate dateEmbauche = ui->tab_employe->model()->data(ui->tab_employe->model()->index(row,9), Qt::DisplayRole).toDate();
        int yearsOfService = QDate::currentDate().year() - dateEmbauche.year();

        // Trouver l'intervalle approprié
        int intervalIndex = 0;
        while (intervalIndex < intervals.size() && yearsOfService > intervals[intervalIndex]) {
            intervalIndex++;
        }

        // Incrémenter le compteur d'employés dans l'intervalle trouvé
        employeeCounts[intervalIndex]++;
    }

    // Calculer le pourcentage pour chaque intervalle
    int totalEmployees = ui->tab_employe->model()->rowCount();
    for (int i = 0; i < intervals.size() + 1; ++i) {
        qreal percentage = (qreal)employeeCounts[i] / totalEmployees * 100.0;
        QString label = (i < intervals.size()) ? QString("%1-%2 ans").arg((i == 0) ? 1 : intervals[i - 1] + 1).arg(intervals[i]) : QString("%1+ ans").arg((intervals.isEmpty()) ? 1 : intervals.last() + 1);

        // Ajouter le segment au QPieSeries
        series->append(label, percentage);
    }

    // Créer un QChart et l'ajouter à la vue
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Répartition des employés par ancienneté");
    chart->legend()->setAlignment(Qt::AlignRight);

    // Créer une vue QChartView et l'afficher
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Afficher la vue du graphique dans une nouvelle fenêtre
    QDialog *dialog = new QDialog(this);
    dialog->setFixedSize(800, 600);
    QVBoxLayout *layout = new QVBoxLayout(dialog);
    layout->addWidget(chartView);
    dialog->setLayout(layout);
    dialog->setWindowTitle("Statistiques d'ancienneté des employés");
    dialog->exec();
    chartView->update();
}

void MainWindow::update_label()
{
    data = A.read_from_arduino();
    qDebug() << "Received data from Arduino: " << data;

    if (data.contains("A3 A0 83 C5"))
    {
        QMessageBox::information(this, "Arduino", "IDENTIFIANT RFID1", QMessageBox::Ok);
    }
    if (data.contains("634E52DD"))
    {
        QMessageBox::information(this, "Arduino", "IDENTIFIANT RFID2", QMessageBox::Ok);
    }
}
/*void MainWindow::Fonction_RFID()
{
    Employe c;
    QString rfid1 = "A3 A0 83 C5"; // Remplacez "valeur_rfid" par la valeur RFID que vous souhaitez rechercher
    QString rfid2 = "634E52DD";
    //unsigned int entierRfid1 = stoul(rfid1, nullptr, 16);


    QString nom;
    QString prenom;


    bool found1 = c.rechercher_RFID(rfid1, nom, prenom);
    bool found2 = c.rechercher_RFID(rfid2, nom, prenom);
    if (found1) {
        qDebug() << "rfidi: " << rfid1;
        QString message = "Nom: " + nom + "\nPrénom: " + prenom;
                QMessageBox::information(this, "Arduino", message, QMessageBox::Ok);


    }
    if (found2) {
        qDebug() << "rfid2: " << rfid2;
        QString message = "Nom: " + nom + "\nPrénom: " + prenom;
                QMessageBox::information(this, "Arduino", message, QMessageBox::Ok);


    }
    else {
        QMessageBox::information(this, "Arduino", "IDENTIFIANT RFID NON TROUVE", QMessageBox::Ok);
    }


}*/

/*void MainWindow::Fonction_RFID()
{
    Employe c;
    QString rfid1 = "b3c317fc"; // Replace with the RFID value you want to search for
    QString rfid2 = "53f48adc";

    // Convert QString RFID to integer
    bool conversionSuccess1, conversionSuccess2;
    unsigned int entierRfid1 = rfid1.toUInt(&conversionSuccess1, 16);
    unsigned int entierRfid2 = rfid2.toUInt(&conversionSuccess2, 16);

    if (!conversionSuccess1 || !conversionSuccess2) {
        // Handle conversion errors if any
        QMessageBox::information(this, "Arduino", "Error converting RFID to integer", QMessageBox::Ok);
        return;
    }

    QString nom;
    QString prenom;

    bool found1 = c.rechercher_RFID(entierRfid1, nom, prenom);
    bool found2 = c.rechercher_RFID(entierRfid2, nom, prenom);

    if (found1) {
        qDebug() << "rfid1: " << rfid1;
        QString message = "Nom: " + nom + "\nPrénom: " + prenom;
        QMessageBox::information(this, "Arduino", message, QMessageBox::Ok);
    }

    if (found2) {
        qDebug() << "rfid2: " << rfid2;
        QString message = "Nom: " + nom + "\nPrénom: " + prenom;
        QMessageBox::information(this, "Arduino", message, QMessageBox::Ok);
    }
    else {
        QMessageBox::information(this, "Arduino", "IDENTIFIANT RFID NON TROUVÉ", QMessageBox::Ok);
    }
}*/


