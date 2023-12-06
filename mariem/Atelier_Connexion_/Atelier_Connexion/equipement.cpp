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
#include <QList>
#include <QMap>




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

   model->setQuery("select * from equipement order by dateachat");
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

/*QSqlQueryModel* Equipement::afficherEntretienAVenir()
{
    Equipement e;
    // Obtenir la date actuelle
    QDate currentDate = QDate::currentDate();
    QString reference;
    int  periodicite;
     QDate  dateDernierEntretien;




    // Calculer la date de l'entretien à venir
    QDate dateEntretienAVenir = dateDernierEntretien.addMonths(periodicite);

    // Créer un modèle de requête SQL pour récupérer les données
   // QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQueryModel* entretienModel = new QSqlQueryModel();
        if (!entretienModel) {
            qDebug() << "Failed to create QSqlQueryModel.";
            return nullptr;

    // Exécuter la requête pour obtenir les données d'entretien à venir
    QSqlQuery query;
    query.prepare("SELECT reference, periodicite, currentDate ,dateDernierEntretien, :dateEntretienAVenir AS dateEntretienAVenir "
                  "FROM equipement "
                  "WHERE reference = :reference");
    query.bindValue(":dateEntretienAVenir", dateEntretienAVenir);
    query.bindValue(":reference", reference);

    if (!query.exec()) {
        qDebug() << "Error in SQL query: " << query.lastError().text();
        return entretienModel;
    }

    // Définir les en-têtes du modèle
    entretienModel->setHeaderData(0, Qt::Horizontal, QObject::tr("Référence"));
    entretienModel->setHeaderData(1, Qt::Horizontal, QObject::tr("Périodicité"));
     entretienModel->setHeaderData(2, Qt::Horizontal, QObject::tr("currentDate"));
    entretienModel->setHeaderData(3, Qt::Horizontal, QObject::tr("datedernierentretien"));
    entretienModel->setHeaderData(4, Qt::Horizontal, QObject::tr("Entretien à venir"));

    // Récupérer les données de la requête et les ajouter au modèle
    entretienModel->setQuery(query);

    // Afficher le modèle dans un tableau ou autre interface utilisateur
    // ...

}}*/

bool Equipement::checkQuantityReachedTen(int productId)
{
    QSqlQuery query;
    query.prepare("SELECT quantity FROM produit WHERE id = :id");
    query.bindValue(":id", productId);

    if (query.exec() && query.next())
    {
        int quantity = query.value("quantity").toInt();

        // Check if the quantity reaches 10
        if (quantity >= 10)
        {
            return true; // Quantity reached 10 or more
        }
        else
        {
            return false; // Quantity is less than 10
        }
    }
    else
    {
        // Handle the case where the query execution failed or no result found
        qDebug() << "Error checking quantity:" << query.lastError().text();
        return false;
    }
}
bool Equipement::incrementQuantityById(int productId)
{
    QSqlQuery query;
    query.prepare("UPDATE produit SET quantity = quantity + 1 WHERE id = :id");
    query.bindValue(":id", productId);

    if (query.exec())
    {
        qDebug() << "Quantity incremented successfully.";
        return true;
    }
    else
    {
        qDebug() << "Error updating quantity:" << query.lastError().text();
        return false;
    }
}









