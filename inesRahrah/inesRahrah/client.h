#ifndef CLIENT_H
#define CLIENT_H
#include<QString>
#include<QSqlQueryModel>
#include <QDate>
#include <QRegularExpression>


class Client
{
public:
    Client();
    Client(int,QString,QString,QString,int);
    int getcode_fiscale();
    QString getmail();
    QString getadresse();
     int getnbrcommande();
      double getreduction();








    QString getsexe();
    void setcode_fiscale(int);
    void setmail(QString);
    void setadresse(QString);
    void setnbrcommande(int);
    void setreduction(double);


    void setsexe(QString);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier();
    QSqlQueryModel *trierParCodeFiscale();
    QSqlQueryModel* afficherStatistiques();
    void exporterTextEnPNG(const QString &text, const QString &fileName);
    //double rechercherClient(int)const;

    bool updateReductionByCodeFiscale(int , double);
   QMap<QString, int> calculateOrderIntervalsPercentages() const;
   double calculerEtSauvegarderReduction(int codeFiscale);
   QMap<QString, QString> getClientDataById(int codeFiscale);











private:
    int code_fiscale,nbrcommande;
    double reduction;
    QString mail,adresse,sexe;
     bool reductionApplied;


};

#endif // CLIENT_H
