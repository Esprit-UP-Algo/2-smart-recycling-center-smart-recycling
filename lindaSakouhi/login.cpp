#include "login.h"
#include "ui_login.h"
#include<QMessageBox>
//#include "arduino.h"
#include "ui_login.h"
#include "login.h"
#include "connection.h"
#include "windowsakouhi.h"
//#include "arduino.h"
//#include"widget.h"
#include "employe.h"
//#include "oublier.h"
#include "integration.h"
#include "QDate"
login::login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::login)
{
 ui->setupUi(this);
 ui->tab_employe->setModel(E.afficher());
       /* int ret = A.connect_arduino();
        switch (ret) {
        case 0:
            qDebug() << "Arduino est disponible et connecté à : " << A.getarduino_port_name();
            break;
        case 1:
            qDebug() << "Arduino est disponible mais non connecté à : " << A.getarduino_port_name();
            break;
        case -1:
            qDebug() << "Arduino n'est pas disponible";
            break;
        }

        QObject::connect(A.getserial(), SIGNAL(readyRead()), this, SLOT(update_label()));
*/
  serial = new QSerialPort(this);
       serial->setPortName("COM11"); // Change to the appropriate port
       serial->setBaudRate(QSerialPort::Baud9600);
       if (serial->open(QIODevice::ReadWrite)) {
           connect(serial, SIGNAL(readyRead()), this, SLOT(readData()));
       } else {
           qDebug() << "Error opening serial port:" << serial->errorString();
       }
  }
login::~login()
{
    delete ui;
}

/*QSerialPort* login::getserial() {
    return A.getserial();
}*/



/* void login::update_label()
{ QByteArray data = A.getserial()->readAll();
    QString receivedData = QString::fromUtf8(data);

    if (!receivedData.isEmpty()) {
        // Supposons que les données série contiennent uniquement l'UID
        QString badgeCode = receivedData.trimmed();
        qDebug() << badgeCode;



        QSqlQuery query;
        query.prepare("SELECT * FROM EMPLOYE WHERE RFID=:badgeCode ");
        query.bindValue(":badgeCode", badgeCode);
        QString badgeCode1 = receivedData;
               badgeCode1.remove(QChar(' '));

        if (query.exec() && query.next()) {
            QMessageBox::information(nullptr, QObject::tr("OK"),
                QObject::tr("Login réussi avec succès.\n"
                            "Cliquez sur Annuler pour quitter."), QMessageBox::Cancel);
            this->hide();
                        MaClasse *auth = new MaClasse;
                        auth->show();

                         // Mettre à jour l'écran LCD avec l'identifiant

        } else {
            QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                QObject::tr("Veuillez vérifier le badge.\n"
                            "Cliquez sur Annuler pour quitter."), QMessageBox::Cancel);
        }
    }


      }
*/

/*void login::on_pushButton_clicked()
{
    QString id = ui->lineEdit_username->text();
       QString mdp = ui->lineEdit_password->text();
      QSqlQuery query;
      //query.prepare("SELECT * FROM employe WHERE IDENTIFIANT=:idy");
       //  query.bindValue(":idy",idi);

         if ( id=="1234567" && mdp=="yy00")
      {
          QMessageBox::information(this, QObject::tr("Login is open"),
                      QObject::tr("Username and passord is correct.\n"
                                  "open."), QMessageBox::Cancel);

          this->hide();
                      integration *auth = new integration;
                      auth->show();
      }
       else {
          QMessageBox::warning(this, QObject::tr("Login is not  open"),
                      QObject::tr("Username and passord is uncorrect.\n"
                                  "try again."), QMessageBox::Cancel);
      }
}*/
/*void login::on_pushButton_clicked()
{
        // Récupérer le nom d'utilisateur et le mot de passe entrés par l'utilisateur
        QString username = lineEdit_username->text();
        QString password = lineEdit_password->text();

        // Vérifier la connexion
        if (verifierConnexion(username, password)) {
            // Connexion réussie, afficher l'interface principale
            QMessageBox::information(this, "Login Successful", "Welcome to Windowsakouhi!");
        } else {
            // Échec de la connexion, afficher un message d'erreur
            QMessageBox::warning(this, "Login Failed", "Employee not found or incorrect password");
        }
    }*/
/*void login::on_pushButton_2_clicked(QTableView*  employe)
{
    QString identifiant = ui->lineEdit_username->text();

    // Vérifier si l'identifiant est présent dans le tableau des employés
    bool utilisateurTrouve = false;
    Employe E1;  // Déplacer la création de l'objet à l'extérieur de la boucle
    for (int row = 0; row < employe->model()->rowCount(); ++row) {
        QString identifiantDansTableau = employe->model()->data(employe->model()->index(row, 0), Qt::DisplayRole).toString();

        if (identifiantDansTableau == identifiant) {
            utilisateurTrouve = true;

            // Obtenir les questions de sécurité
            QString question1 = employe->model()->data(employe->model()->index(row, 10), Qt::DisplayRole).toString();
            QString question2 = employe->model()->data(employe->model()->index(row, 11), Qt::DisplayRole).toString();
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
}*/

void login::on_pushButton_clicked()
{
    QString identifiant = ui->lineEdit_username->text();
        QString motDePasse = ui->lineEdit_password->text();

        // Effectuer la recherche dans le tableau des employés
        bool utilisateurTrouve = false;
        //QLabel * l=ui->label_21;
       // QLabel * l2=ui->label_22;

        for (int row = 0; row < ui->tab_employe->model()->rowCount(); ++row) {
            QString identifiantDansTableau = ui->tab_employe->model()->data(ui->tab_employe->model()->index(row, 0), Qt::DisplayRole).toString();
            QString motDePasseDansTableau = ui->tab_employe->model()->data(ui->tab_employe->model()->index(row,1), Qt::DisplayRole).toString();


            if (identifiantDansTableau == identifiant) {
                utilisateurTrouve = true;

                if (motDePasseDansTableau == motDePasse) {
                    // Identifiant et mot de passe corrects
                    QMessageBox::information(this, "Login Success", "Login successful.");
                    this->hide();
                                integration *auth = new integration;
                                auth->show();

                    // Effectuez d'autres actions nécessaires après la connexion réussie.
                    //l->setFixedSize(1,1);
                    //l2->setFixedSize(1,1);

                } else {
                    // Mot de passe incorrect
                    QMessageBox::warning(this, "Login Failed", "Incorrect password.");


                    //                    l->setFixedSize(10000,10000);
                   // l2->setFixedSize(10000,10000);


                }



                break;  // Sortir de la boucle après avoir trouvé l'utilisateur
            }
        }

        if (!utilisateurTrouve) {
            // Identifiant introuvable
            QMessageBox::warning(this, "Login Failed", "User not found.");
          //  l->setFixedSize(10000,10000);
          //  l2->setFixedSize(10000,10000);

        }

}

void login::on_pushButton_2_clicked()
{
    QString identifiant = ui->lineEdit_username->text();

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
                QString nome = ui->tab_employe->model()->data(ui->tab_employe->model()->index(row, 2), Qt::DisplayRole).toString();
                QString prenome = ui->tab_employe->model()->data(ui->tab_employe->model()->index(row, 3), Qt::DisplayRole).toString();
                QDate naissance = ui->tab_employe->model()->data(ui->tab_employe->model()->index(row, 4), Qt::DisplayRole).toDate();
                int telephone = ui->tab_employe->model()->data(ui->tab_employe->model()->index(row, 5), Qt::DisplayRole).toInt();
                QString familiale = ui->tab_employe->model()->data(ui->tab_employe->model()->index(row, 6), Qt::DisplayRole).toString();

                int enfant = ui->tab_employe->model()->data(ui->tab_employe->model()->index(row, 7), Qt::DisplayRole).toInt();
                QString postee = ui->tab_employe->model()->data(ui->tab_employe->model()->index(row, 8), Qt::DisplayRole).toString();
                QDate embauche = ui->tab_employe->model()->data(ui->tab_employe->model()->index(row, 9), Qt::DisplayRole).toDate();
                QString rfid = ui->tab_employe->model()->data(ui->tab_employe->model()->index(row, 12), Qt::DisplayRole).toString();
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
                    E1.setnom(nome);
                    E1.setprenom(prenome);
                    E1.setstatue_familiale(familiale);
                    E1.setposte(nome);
                    E1.setdate_d_embauche(embauche);
                    E1.setnum_telephone(telephone);
                    E1.setq1(question1);
                    E1.setq2(question2);
                    E1.setdate_de_naissance(naissance);
                    E1.setrfid(rfid);
                    E1.setnbre_enfant(enfant);
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

void login::readData()
{
    QByteArray data = serial->readAll();
    QByteArray search = "4E";
    QByteArray second = "A3";

    // Process the data as needed, e.g., display it in the QTextEdit

    int index = data.indexOf(search);
    int ha=data.indexOf(second);


    int id1=1;
    int id2=2;

    if (index != -1) {


        ui->lineEdit_username->setText(QString::number(id1));
        ui->lineEdit_password->setText(search);

    }
    else if(ha != -1)
    {
        ui->lineEdit_username->setText(QString::number(id2));
        ui->lineEdit_password->setText(second);
    }
}
