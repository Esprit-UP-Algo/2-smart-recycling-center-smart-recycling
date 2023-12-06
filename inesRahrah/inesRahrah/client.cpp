#include "client.h"
#include<QSqlQuery>
#include<QtDebug>
#include<QSqlQueryModel>
#include<QObject>
#include <QString>
#include <QRegularExpression>
#include <QDebug>
#include <QDate>
#include <QPrinter>
#include <QPainter>
#include <QProcess>
#include <QtWidgets>

#include <QUrl>
#include <QFile>
#include <QTextStream>
#include <QPixmap>
#include <QFileDialog>
#include <QMap>
#include <QVariant>


Client::Client()
{
code_fiscale=0; mail=""; adresse="";sexe="",nbrcommande=0,reduction=0.0;


}



Client::Client(int a,QString b,QString c,QString e,int f)
{
    this->code_fiscale=a;
    this->mail=b;
    this->adresse=c;

    this->sexe=e;
    this->nbrcommande=f;
    //this->reduction=g;


}



double Client::getreduction(){return reduction; }
int Client::getcode_fiscale(){return code_fiscale; }
int Client::getnbrcommande(){return nbrcommande; }
QString Client::getmail(){return mail; }

QString Client::getadresse(){return adresse; }
QString Client::getsexe(){return adresse; }
void Client::setcode_fiscale(int a){this->code_fiscale=a;}
void Client::setnbrcommande(int f){this->nbrcommande=f;}
void Client::setreduction(double g){this->reduction=g;}
void Client::setmail(QString b){this->mail=b;}
void Client::setsexe(QString e){this->sexe=e;}

void Client::setadresse(QString d){this->adresse=d;}
bool Client::ajouter()
{



    QSqlQuery query;
    QString code_string= QString::number(code_fiscale);
     QString nbrcommande_string= QString::number(nbrcommande);
     QString reduction_string = QString::number(reduction);

          query.prepare("INSERT INTO client (codefiscale, mail, adresse,sexe,nbrcommande,reduction)"
                        "VALUES (:code, :mail_adress, :adress,:sexe,:nbrcommande,:reduction)");
          query.bindValue(0, code_string);
          query.bindValue(1, mail);
          query.bindValue(2, adresse);

           query.bindValue(3, sexe);
           query.bindValue(4, nbrcommande_string);
            //query.bindValue(5, reduction_string);

          return query.exec();






















}





bool Client::supprimer(int code_fiscale)
{
    QSqlQuery query;
    QString code_string= QString::number(code_fiscale);
          query.prepare("DELETE FROM client WHERE codefiscale=:codefiscale");
          query.bindValue(":codefiscale", code_string);

          return query.exec();


}






bool Client::modifier(){
    QSqlQuery query;
    QString code_string= QString::number(code_fiscale);
    QString nbrcommande_string= QString::number(nbrcommande);
    QString reduction_string = QString::number(reduction);

    query.prepare("UPDATE client SET codefiscale=:codefiscale, mail=:mail, adresse=:adresse,sexe=:sexe,nbrcommande=:nbrcommande WHERE codefiscale=:codefiscale");

    query.bindValue(":codefiscale", code_string);
    query.bindValue(":mail", mail);
    query.bindValue(":adresse", adresse);

      query.bindValue(":sexe", sexe);
       query.bindValue(":nbrcommande", nbrcommande_string);
       //query.bindValue(":reduction", reduction_string);


    return query.exec();

}



QSqlQueryModel * Client::trierParCodeFiscale()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM client ORDER BY codefiscale");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("codefiscale"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("mail"));

    model->setHeaderData(2, Qt::Horizontal, QObject::tr("adresse"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("sexe"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("nbrcommande"));

    return model;
}



QSqlQueryModel *Client::afficherStatistiques()
{
    QSqlQueryModel *model = new QSqlQueryModel();

    QSqlQuery query;
    query.prepare("SELECT COUNT(CASE WHEN sexe='f' THEN 1 END) as femmeCount, COUNT(CASE WHEN sexe='h' THEN 1 END) as hommeCount FROM client");

    if (query.exec() && query.next()) {
        model->setQuery(query);
    }

    return model;
}














void Client::exporterTextEnPNG(const QString &text, const QString &fileName)
{

    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat); // Utiliser le format PDF pour éviter la perte de qualité
    printer.setOutputFileName(fileName);

    // Utiliser QPainter pour dessiner le texte sur la page de l'imprimante
    QPainter painter(&printer);
    painter.drawText(10, 10, text);

    // Terminer la peinture
    painter.end();
}










double Client::calculerEtSauvegarderReduction(int codeFiscale)
{
    QSqlQuery query;
    query.prepare("SELECT nbrcommande, reduction FROM client WHERE codefiscale = :codefiscale");
    query.bindValue(":codefiscale", codeFiscale);

    if (query.exec() && query.next()) {
        int nbrCommande = query.value(0).toInt();

        // Ajoutez la condition pour que la réduction ne s'applique que si le nombre de commandes dépasse 1
        if (nbrCommande > 1) {
            const double reductionParCommande = 0.09; // Ajustez le taux de réduction selon vos besoins
            double reduction = nbrCommande * reductionParCommande;

            // Mettez à jour la réduction dans la base de données
            query.prepare("UPDATE client SET reduction = :reduction WHERE codefiscale = :codefiscale");
            query.bindValue(":reduction", reduction);
            query.bindValue(":codefiscale", codeFiscale);

            if (!query.exec()) {
                qDebug() << "Erreur lors de la mise à jour de la réduction dans la base de données.";
            }

            return reduction;
        } else {
            // Retourne 0 si le nombre de commandes est inférieur ou égal à 1
            return 0.0;
        }
    }

    return -1.0; // Retourne -1 si le client n'est pas trouvé
}
















/*double Client::calculerReduction(int codeFiscale)
{
    QSqlQuery query;
       query.prepare("SELECT nbrcommande, reduction FROM client WHERE codefiscale = :codefiscale");
       query.bindValue(":codefiscale", codeFiscale);

       if (query.exec() && query.next()) {
           int nbrCommande = query.value(0).toInt();

           // Ajoutez la condition pour que la réduction ne s'applique que si le nombre de commandes dépasse 1
           if (nbrCommande > 1) {
               const double reductionParCommande = 0.09; // Ajustez le taux de réduction selon vos besoins
               double reduction = nbrCommande * reductionParCommande;

               // Mettez à jour la réduction dans la base de données
               query.prepare("UPDATE client SET reduction = :reduction WHERE codefiscale = :codefiscale");
               query.bindValue(":reduction", reduction);
               query.bindValue(":codefiscale", codeFiscale);

               if (!query.exec()) {
                   qDebug() << "Erreur lors de la mise à jour de la réduction dans la base de données.";
               }

               return reduction;
           } else {
               // Retourne 0 si le nombre de commandes est inférieur ou égal à 1
               return 0.0;
           }
       }

       return -1.0; // Retourne -1 si le client n'est pas trouvé
}*/





QMap<QString, int> Client::calculateOrderIntervalsPercentages() const
{
    QMap<QString, int> percentages;

    // Effectuer la requête SQL pour obtenir le nombre de clients dans chaque intervalle
    QSqlQueryModel model;
    model.setQuery("SELECT COUNT(*) FROM client WHERE nbrcommande >= 1 AND nbrcommande <= 2");
    double count12 = model.data(model.index(0, 0)).toDouble();

    model.setQuery("SELECT COUNT(*) FROM client WHERE nbrcommande >= 2 AND nbrcommande <= 3");
    double count23 = model.data(model.index(0, 0)).toDouble();

    model.setQuery("SELECT COUNT(*) FROM client WHERE nbrcommande >= 3 AND nbrcommande <= 4");
    double count34 = model.data(model.index(0, 0)).toDouble();

    // Calculer les pourcentages
    double totalClients = count12 + count23 + count34;

    if (totalClients > 0) {
        percentages["[1-2] commandes"] = (count12 / totalClients) * 100.0;
        percentages["[2-3] commandes"] = (count23 / totalClients) * 100.0;
        percentages["[3-4] commandes"] = (count34 / totalClients) * 100.0;
    }

    return percentages;
}






QMap<QString, QString> Client::getClientDataById(int codeFiscale)
{
    QMap<QString, QString> clientData;

    QSqlQuery query;
    query.prepare("SELECT * FROM client WHERE codefiscale = :codefiscale");
    query.bindValue(":codefiscale", codeFiscale);

    if (query.exec() && query.next()) {
        clientData["code_fiscale"] = query.value(0).toString();
        clientData["mail"] = query.value(1).toString();
        clientData["adresse"] = query.value(2).toString();
        clientData["sexe"] = query.value(3).toString();
        clientData["nbrcommande"] = query.value(4).toString();
        clientData["reduction"] = query.value(5).toString();
    }

    return clientData;
}


























QSqlQueryModel * Client::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();


     model->setQuery("SELECT* FROM client");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("code fiscale"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("mail"));

       model->setHeaderData(2, Qt::Horizontal, QObject::tr("adresse"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("sexe"));
         model->setHeaderData(4, Qt::Horizontal, QObject::tr("nbrcommande"));
          model->setHeaderData(5, Qt::Horizontal, QObject::tr("reduction"));


    return model;
}



