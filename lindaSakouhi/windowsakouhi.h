#ifndef WINDOWSAKOUHI_H
#define WINDOWSAKOUHI_H

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
//#include "arduino.h"
#include<QSerialPort>
#include <QSerialPortInfo>


QT_BEGIN_NAMESPACE
namespace Ui { class Windowsakouhi; }
QT_END_NAMESPACE

class Windowsakouhi : public QMainWindow
{
    Q_OBJECT

public:
    Windowsakouhi(QWidget *parent = nullptr);
    ~Windowsakouhi();
private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_modifier_clicked();

    void on_pb_chercher_clicked();


    void on_pb_trier_clicked();

    void on_pb_pdf_clicked();

    void on_pb_stat_clicked();


    //void on_pushButton_clicked();

    //void on_pushButton_2_clicked();

    void on_pb_sat2_clicked();
    void on_pb_back3_clicked();
     void generatePieChart();

     //void on_btn_Connect_clicked();
      //void update_label();
      //void Fonction_RFID();
    // void readData();
private:
    Ui::Windowsakouhi *ui;
    Employe E;
    QSortFilterProxyModel *dateSortModel;
    QChartView *chartView;
   // QByteArray data; // variable contenant les données reçues
    //QSerialPort serial;
   // QByteArray data;
     //   QSerialPort *serial;

        //Arduino A; // objet temporaire
};
#endif // WINDOWSAKOUHI_H





