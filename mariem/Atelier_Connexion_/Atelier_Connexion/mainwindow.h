#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "equipement.h"
#include<QComboBox>
#include"arduino.h"


namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT


public:

    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();





private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_actualiser_clicked();

     void on_pb_modifier_clicked();
     void on_pb_tri_clicked();
     void  on_pb_chercher_clicked();
     void on_PDF_clicked();
     void on_statistiquesButton_clicked();
     //void onAlertButtonClicked();
     //void on_pushButtonAfficherEntretien_clicked();
     void update_label();
     void on_pb_on_Clicked();
     void on_pb_off_Clicked();
     void on_pb_plus_Clicked();
     void on_pb_moins_Clicked();
     void marquerJoursFeries(QCalendarWidget *calendrier);
      void on_pb_back_clicked();








private:
    Ui::MainWindow *ui;
    Equipement e;

    QComboBox *comboBoxAttribut;
    QVBoxLayout *mainLayout;
     Equipement *statsWindow;
     QWidget *mainWidget;
      QWidget *statsWidget;
      QByteArray data;
      arduino A;






};
#endif // MAINWINDOW_H
