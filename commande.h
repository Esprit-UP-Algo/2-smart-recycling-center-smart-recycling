#ifndef COMMANDE_H
#define COMMANDE_H
#include<QSqlQuery>
#include<QSqlQueryModel>
#include"QDate"
#include"QString"
#include<QTableView>

class Commande
{
public:
    Commande();
    Commande(int,QDate,double,int,QString);
    int getNUMERO_DE_COMMANDE() {return NUMERO_DE_COMMANDE ;}
    QDate getDATE_DE_LIVRASION() {return DATE_DE_LIVRASION  ;}
    double getREFERENCE() {return REFERENCE;}
    int getTOTAL_DE_COMMANDE() {return TOTAL_DE_COMMANDE;}
    QString getNATIONALITE() {return NATIONALITE;}

    void setNUMERO_DE_COMMANDE(int NUMERO_DE_COMMANDE ){this->NUMERO_DE_COMMANDE=NUMERO_DE_COMMANDE;}
    void setDATE_DE_LIVRASION(QDate DATE_DE_LIVRASION){this->DATE_DE_LIVRASION=DATE_DE_LIVRASION;}
    void setREFERENCE(double REFERENCE){this->REFERENCE=REFERENCE;}
    void setTOTAL_DE_COMMANDE(int TOTAL_DE_COMMANDE){this->TOTAL_DE_COMMANDE=TOTAL_DE_COMMANDE;}
    void setNATIONALITE(QString NATIONALITE ){this->NATIONALITE=NATIONALITE;}

    bool ajouter();
    QSqlQueryModel *afficher();
    bool supprimer(int );
    bool modifier(int NUMERO_DE_COMMANDE);
    QSqlQueryModel *triee();
   void recherche(QTableView *tab_commande,int);
    QSqlQueryModel *historique();

private:

        int NUMERO_DE_COMMANDE,TOTAL_DE_COMMANDE;
        double REFERENCE;
        QDate DATE_DE_LIVRASION;
        QString NATIONALITE;

};

#endif // COMMANDE_H
