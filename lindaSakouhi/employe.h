
#ifndef EMPLOYE_H
//#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <QString>
#include <QSqlQueryModel>
#include<QString>
#include"QDate"
#include <QSortFilterProxyModel>
class Employe
{
public:
    Employe();
    Employe(int,int,int,QString ,QString,QString,QString,QDate,QString,QDate,QString,QString,QString);
    QString getnom();
    QString getprenom();
    QString getstatue_familiale();
    QString getmot_de_passe();
    QString getq1();
    QString getq2();
    QDate getdate_de_naissance();
    QString getposte();
    QDate getdate_d_embauche();
    QString getrfid();
    int getid();
    int getnum_telephone();
    int getnbre_enfant();
    void setnom (QString);
    void setprenom (QString);
    void setstatue_familiale (QString);
    void setmot_de_passe (QString);
    void setdate_de_naissance (QDate);
    void setposte (QString);
    void setdate_d_embauche (QDate);
    void setid (int);
    void setnum_telephone (int);
    void setnbre_enfant (int);
    void setq1 (QString);
    void setq2 (QString);
    void setrfid (QString);
    bool ajouter ();
    QSqlQueryModel*   afficher();
    bool supprimer (int);
    bool modifier();
   QSqlQueryModel * trieridentifiant();
   bool rechercher_RFID(QString rfid, QString& nom, QString& prenom);
   bool rechercher_RFID(unsigned int rfid, QString& nom, QString& prenom);
private :
    int id,num_telephone,nbre_enfant;
    QString nom,prenom,statue_familiale,mot_de_passe,poste,q1,q2,rfid;
    QDate date_de_naissance,date_d_embauche;

};

#endif // EMPLOYE_H
