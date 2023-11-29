#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"employe.h"
#include <QMainWindow>
#include <QSortFilterProxyModel>
#include <QtCharts>
#include <QChartView>
#include <QPieSeries>
#include <QPieSlice>
#include <QPrinter>
#include <QPainter>
#include <QFileDialog>
#include "arduino.h"
#include<QSerialPort>
#include <QSerialPortInfo>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    // void  exportToPDF();




private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_modifier_clicked();

    void on_pb_chercher_clicked();


    void on_pb_trier_clicked();

    void on_pb_pdf_clicked();

    void on_pb_stat_clicked();


    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pb_sat2_clicked();
     void generatePieChart();

     //void on_btn_Connect_clicked();
      void update_label();
      //void Fonction_RFID();
     void readData();
private:
    Ui::MainWindow *ui;
    Employe E;
    QSortFilterProxyModel *dateSortModel;
    QChartView *chartView;
   // QByteArray data; // variable contenant les données reçues
    //QSerialPort serial;
    QByteArray data;
        QSerialPort *serial;

        Arduino A; // objet temporaire

};

#endif // MAINWINDOW_H
