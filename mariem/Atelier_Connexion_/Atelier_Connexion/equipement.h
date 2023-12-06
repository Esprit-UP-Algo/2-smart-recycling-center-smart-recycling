#ifndef EQUIPEMENT_H
#define EQUIPEMENT_H
#include<QString>
#include<QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
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
#include <QMainWindow>
#include <QCalendarWidget>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QMap>
#include <QSqlRecord>



class Equipement: public QObject {
    Q_OBJECT


public:

    Equipement();
    Equipement (QString, QString , QDate , QString , QDate , int );
    QString getreference();
    QString gettype();
    QDate getdisponibilite();
    QString getetat();
    QDate getdateachat();
    int getNbrAnneeAmortissement();
    void setreference(QString reference);
    void settype(QString type);
    void setdisponibilite(QDate disponibilite);
    void setetat(QString etat);
    void setdateachat(QDate dateachat);
    void setNbrAnneeAmortissement(int NbrAnneeAmortissement);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(QString reference );
    QString reference;

    bool modifier();
    QSqlQueryModel* tri();
    QString referencechercher;
    QSqlQueryModel* chercher(QString attribut, QString valeurRechercheType, QDate valeurRechercheDisponibilite, QString valeurRechercheEtat );


    bool  checkQuantityReachedTen(int productId);
    bool  incrementQuantityById(int productId);


private:
    QString type ,  etat   ;
    QDate disponibilite , dateachat ;
    int NbrAnneeAmortissement;
     QComboBox *comboBoxAttribut;
     QVBoxLayout *mainLayout;
      Equipement *statsWindow;
      QWidget *mainWidget;
       QWidget *statsWidget;









};

#endif // EQUIPEMENT_H
