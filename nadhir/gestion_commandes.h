#ifndef GESTION_COMMANDES_H
#define GESTION_COMMANDES_H
#include"commande.h"
#include <QMainWindow>
#include "statistic.h"
#include "notifications.h"
QT_BEGIN_NAMESPACE
namespace Ui { class gestion_commandes; }
QT_END_NAMESPACE

class gestion_commandes : public QMainWindow
{
    Q_OBJECT

public:
    gestion_commandes(QWidget *parent = nullptr);
    ~gestion_commandes();

private slots:
    void on_pb_ajouter_clicked();

   void on_pb_supprimer_clicked();

    void on_pb_modifier_clicked();

    void on_le_rechercher_cursorPositionChanged(int arg1, int arg2);

    void on_pb_trier_clicked();



   // void on_pushButton_clicked();

    void on_stat_commande_clicked();





    void on_pdf_commande_clicked();
    void on_pb_back4_clicked();

private:
    Ui::gestion_commandes *ui;
    Commande C;
    Statistic *statistic;
    notification notification;
};
#endif // GESTION_COMMANDES_H

