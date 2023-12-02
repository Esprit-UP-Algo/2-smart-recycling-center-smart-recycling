#include "commande.h"
#include<QString>
#include<QObject>
#include <iostream>
#include"QDate"
#include<QSqlQuery>
#include<QtDebug>


Commande::Commande()
{
    NUMERO_DE_COMMANDE=0;
    TOTAL_DE_COMMANDE=0;
    REFERENCE=0;
    DATE_DE_LIVRASION=QDate();
    NATIONALITE="";
}
Commande::Commande(int NUMERO_DE_COMMANDE,QDate DATE_DE_LIVRASION,double REFERENCE,int TOTAL_DE_COMMANDE,QString NATIONALITE)
{
    this->NUMERO_DE_COMMANDE=NUMERO_DE_COMMANDE;
    this->DATE_DE_LIVRASION=DATE_DE_LIVRASION;
    this->REFERENCE=REFERENCE;
    this->TOTAL_DE_COMMANDE=TOTAL_DE_COMMANDE;
    this->NATIONALITE=NATIONALITE;

}

bool Commande::ajouter()
 {  QSqlQuery query;
    QString NUMERO_DE_COMMANDE_string=QString::number(NUMERO_DE_COMMANDE);
    QString REFERENCE_string=QString::number(REFERENCE);
    QString TOTAL_DE_COMMANDE_string=QString::number(TOTAL_DE_COMMANDE);

        query.prepare("insert into COMMANDE(NUMERO_DE_COMMANDE,DATE_DE_LIVRASION,REFERENCE,TOTAL_DE_COMMANDE,NATIONALITE)""values(:NUMERO_DE_COMMANDE,:DATE_DE_LIVRASION,:REFERENCE,:TOTAL_DE_COMMANDE,:NATIONALITE)");
    query.bindValue(":NUMERO_DE_COMMANDE",NUMERO_DE_COMMANDE_string);
    query.bindValue(":DATE_DE_LIVRASION",DATE_DE_LIVRASION);
    query.bindValue(":REFERENCE",REFERENCE_string);
    query.bindValue(":TOTAL_DE_COMMANDE",TOTAL_DE_COMMANDE_string);
    query.bindValue(":NATIONALITE",NATIONALITE);
    return query.exec();
 }

bool Commande::supprimer(int NUMERO_DE_COMMANDE)
{
    QSqlQuery query;
    query.prepare("Delete from COMMANDE where NUMERO_DE_COMMANDE=:NUMERO_DE_COMMANDE");
query.bindValue(0,NUMERO_DE_COMMANDE);

return query.exec();

}

QSqlQueryModel *Commande::afficher()
{
    QSqlQueryModel *model=new QSqlQueryModel();
   model->setQuery("select * from COMMANDE");
   model->setHeaderData(0,Qt::Horizontal,QObject::tr("NUMERO_DE_COMMANDE"));
   model->setHeaderData(1,Qt::Horizontal,QObject::tr("DATE_DE_LIVRASION"));
   model->setHeaderData(2,Qt::Horizontal,QObject::tr("REFERENCE"));
   model->setHeaderData(3,Qt::Horizontal,QObject::tr("TOTAL_DE_COMMANDE"));
   model->setHeaderData(4,Qt::Horizontal,QObject::tr("NATIONALITE"));


return model;
}

bool Commande::modifier(int NUMERO_DE_COMMANDE )
{
    QSqlQuery query;
    QString x= QString::number(NUMERO_DE_COMMANDE);
    QString REFERENCE_string=QString::number(REFERENCE) ;
    QString TOTAL_DE_COMMANDE_string=QString::number(TOTAL_DE_COMMANDE);

    query.prepare("Update COMMANDE set  DATE_DE_LIVRASION =:DATE_DE_LIVRASION , REFERENCE = :REFERENCE, TOTAL_DE_COMMANDE = :TOTAL_DE_COMMANDE   where NUMERO_DE_COMMANDE =:NUMERO_DE_COMMANDE ");
    query.bindValue(":NUMERO_DE_COMMANDE",x);
    query.bindValue(":DATE_DE_LIVRASION",DATE_DE_LIVRASION);
    query.bindValue(":REFERENCE", REFERENCE);
    query.bindValue(":TOTAL_DE_COMMANDE",TOTAL_DE_COMMANDE );
    query.bindValue(":NATIONALITE",NATIONALITE );



    return    query.exec();

}

QSqlQueryModel *Commande::triee()
{

    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from COMMANDE ORDER BY NUMERO_DE_COMMANDE ASC");

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("NUMERO_DE_COMMANDE"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("DATE_DE_LIVRASION"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("REFERENCE"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("TOTAL_DE_COMMANDE"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("NATIONALITE"));


    return model;
}


void Commande::recherche(QTableView * tab_commande ,int NUMERO_DE_COMMANDE )
{
    QSqlQueryModel *model= new QSqlQueryModel();
    QString id_string=QString::number(NUMERO_DE_COMMANDE);



    QSqlQuery *query=new QSqlQuery;
    query->prepare("select * from COMMANDE where NUMERO_DE_COMMANDE like '%"+id_string+"%' ;");


    query->exec();
    model->setQuery(*query);
    tab_commande->setModel(model);
    tab_commande->show();

}

QSqlQueryModel *Commande::historique()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from COMMANDE ORDER BY NUMERO_DE_COMMANDE ASC");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUMERO_DE_COMMANDE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATE_DE_LIVRASION"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("REFERENCE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("TOTAL_DE_COMMANDE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("NATIONALITE"));

    return model;
}

