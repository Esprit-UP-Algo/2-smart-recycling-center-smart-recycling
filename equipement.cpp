#include "equipement.h"
#include "connection.h"
#include <QString>
#include <QSqlQuery>
#include <QtDebug>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QObject>
#include<QtPrintSupport/QPrinter>
#include<QFileDialog>
#include<QTextDocument>
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
#include<QSizePolicy>
#include <QMainWindow>
#include <QChartView> // or the appropriate chart view header
#include <QPushButton>
#include <QtWidgets/QPushButton>




Equipement::Equipement()
{
    reference=" " ;
    type=" ";
    disponibilite = QDate::fromString("2000-01-01", "yyyy-MM-dd");
    etat=" ";
    dateachat = QDate::fromString("2000-01-01", "yyyy-MM-dd");
    NbrAnneeAmortissement=0;


}
Equipement::Equipement( QString reference, QString type , QDate disponibilite , QString etat, QDate dateachat ,int NbrAnneeAmortissement   )
{

    this->reference=reference;
    this->type=type;
    this->disponibilite=disponibilite;
    this->etat=etat;
    this->dateachat=dateachat;
    this->NbrAnneeAmortissement=NbrAnneeAmortissement;


}




QString Equipement::getreference()
{return reference;}
QString Equipement::gettype()
{return type;}
QDate Equipement::getdisponibilite()
{return disponibilite;}
QString Equipement::getetat()
{return etat;}
QDate Equipement::getdateachat()
{return dateachat ;}
int Equipement::getNbrAnneeAmortissement()
{return NbrAnneeAmortissement;}

void Equipement::setreference(QString reference)
{
    this->reference=reference;
}
void Equipement::settype(QString type)
{
    this->type=type;
}
void Equipement::setdisponibilite(QDate disponibilite)
{
    this->disponibilite=disponibilite;
}
void Equipement::setetat(QString etat)
{
    this->etat=etat;
}
void Equipement::setdateachat(QDate dateachat)
{
    this->dateachat=dateachat;
}
void Equipement::setNbrAnneeAmortissement(int NbrAnneeAmortissement)
{
    this->NbrAnneeAmortissement=NbrAnneeAmortissement;
}


bool Equipement::ajouter()
{
    bool test = false;
    QSqlQuery query;
    QString NbrAnneeAmortissement_string = QString::number(NbrAnneeAmortissement);

    query.prepare("INSERT INTO equipement (  reference,type,disponibilite,etat,dateachat ,NbrAnneeAmortissement) "
                  "VALUES ( :reference, :type, :disponibilite, :etat, :dateachat , :NbrAnneeAmortissement)");
    query.bindValue(":reference", reference);
    query.bindValue(":type", type);
    query.bindValue(":disponibilite", disponibilite);
    query.bindValue(":etat", etat);
    query.bindValue(":dateachat", dateachat);
    query.bindValue(":NbrAnneeAmortissement", NbrAnneeAmortissement);
    return query.exec();


    if (query.exec()) {
        test = true;
    } else {
        qDebug() << "Error: " << query.lastError().text();
    }

    return test;
}


QSqlQueryModel * Equipement::afficher()
{
QSqlQueryModel* model=new QSqlQueryModel();
if (!model)
{
    qDebug() << "Failed to create QSqlQueryModel.";
    return nullptr;
}



   model->setQuery("SELECT* FROM equipement ");
   if (model->lastError().isValid())
   {
       qDebug() << "Error in SQL query: " << model->lastError().text();
       return nullptr;
   }


   model->setHeaderData(0, Qt::Horizontal, QObject::tr("reference"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("type"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("disponibilite"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("etat"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("dateachat"));
   model->setHeaderData(5, Qt::Horizontal, QObject::tr("NbrAnneeAmortissement"));


return model;

}
bool Equipement:: supprimer(QString reference)
{
QSqlQuery query;
query.prepare("delete from equipement where reference=:reference");
query.bindValue(":reference",reference);
return query.exec();
}


bool Equipement::modifier()
{
    QSqlQuery query;

    QString res=QString::number(NbrAnneeAmortissement);
    query.prepare("UPDATE equipement SET reference=:reference ,  type=:type ,disponibilite=:disponibilite , etat= :etat , dateachat= :dateachat  WHERE NbrAnneeAmortissement=:NbrAnneeAmortissement");
    query.bindValue(":reference",reference);
    query.bindValue(":disponibilite",disponibilite);

    query.bindValue(":type",type);
    query.bindValue(":etat",etat);
    query.bindValue(":dateachat",dateachat);
    query.bindValue(":NbrAnneeAmortissement",res);


    return query.exec();
}
QSqlQueryModel * Equipement::tri()
{
    QSqlQueryModel * model= new QSqlQueryModel();

   model->setQuery("select * from equipement order by etat");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("reference"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("type"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("disponibilite"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("etat"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("dateachat"));
   model->setHeaderData(5, Qt::Horizontal, QObject::tr("NbrAnneeAmortissement"));


    return model;
}


QSqlQueryModel* Equipement::chercher(QString attribut, QString valeurRechercheType, QDate valeurRechercheDisponibilite, QString valeurRechercheEtat )
{
    QSqlQueryModel* model = new QSqlQueryModel();

    QSqlQuery query;

    // Update the SQL query based on the chosen attribut
    if (attribut == "Type") {
        query.prepare("SELECT * FROM equipement WHERE type=:type AND disponibilite=:disponibilite AND etat=:etat");
        query.bindValue(":type", valeurRechercheType);
        query.bindValue(":disponibilite", valeurRechercheDisponibilite);
        query.bindValue(":etat", valeurRechercheEtat);
    } else if (attribut == "Disponibilité") {
        // Update the query for Disponibilité
    } else if (attribut == "État") {
        // Update the query for État
    }

    if (!query.exec()) {
        qDebug() << "Error in SQL query: " << query.lastError().text();
        return nullptr;
    }

    model->setQuery(query);

    return model;}
//QSqlQueryModel * Equipement::afficherEntretienAVenir()

void Equipement::afficherEntretienAVenir( )
{
    Equipement e;
    // Obtenir la date actuelle
    QDate currentDate = QDate::currentDate();
    QString reference;
    int  periodicite;
     QDate  dateDernierEntretien;



    // Calculer la date de l'entretien à venir
    QDate dateEntretienAVenir = dateDernierEntretien.addYears(periodicite);

    // Créer un modèle de requête SQL pour récupérer les données
    QSqlQueryModel* model = new QSqlQueryModel();
    if (!model)
    {
        qDebug() << "Failed to create QSqlQueryModel.";
       // return;
    }

    // Exécuter la requête pour obtenir les données d'entretien à venir
    QSqlQuery query;
    query.prepare("SELECT reference, periodicite, dateDernierEntretien, :dateEntretienAVenir AS dateEntretienAVenir "
                  "FROM equipement "
                  "WHERE reference = :reference");
    query.bindValue(":dateEntretienAVenir", dateEntretienAVenir);
    query.bindValue(":reference", reference);

    if (!query.exec()) {
        qDebug() << "Error in SQL query: " << query.lastError().text();
        return;
    }

    // Définir les en-têtes du modèle
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Référence"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Périodicité"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Dernier entretien"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Entretien à venir"));

    // Récupérer les données de la requête et les ajouter au modèle
    model->setQuery(query);

    // Afficher le modèle dans un tableau ou autre interface utilisateur
    // ...
}


/*
void Equipement::alerteMaintenance() {
    QSqlQuery query;
    query.prepare("SELECT reference, dateachat, periodicite, dateDernierEntretien FROM equipement WHERE disponibilite = 'Disponible'");
    if (!query.exec()) {
        qDebug() << "Error in SQL query: " << query.lastError().text();
        return;
    }

    while (query.next()) {
        QString reference = query.value(0).toString();
        int periodicite = query.value(1).toInt();
        QDate dateDernierEntretien =query.value(2).toDate();

        // Calculate upcoming maintenance dates based on periodicity and last maintenance date
        // Highlight these dates in the calendar
        // Display a list of upcoming maintenance with the highlighted calendar

        // Example calculation (you may need to adjust based on your specific requirements)
        QDate lastMaintenanceDate = QDate::fromString(query.value(4).toString(), "yyyy-MM-dd");
        QDate currentDate = QDate::currentDate();
        QDate nextMaintenanceDate = lastMaintenanceDate.addMonths(periodicite);

        // Check if the next maintenance date is approaching
        if (currentDate.addDays(7) >= nextMaintenanceDate) {
            qDebug() << "Alert: Maintenance due for equipement " << reference << " on " << nextMaintenanceDate.toString("yyyy-MM-dd");
        }
    }
}*/










