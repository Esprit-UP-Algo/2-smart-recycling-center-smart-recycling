#ifndef WINDOWALI_H
#define WINDOWALI_H

#include <QMainWindow>
#include "client.h"
#include <QRegularExpression>
#include <QDate>
#include <QtCharts>
#include <QPieSeries>
#include <QPieSlice>
#include "arduino.h"
#include "lcdcontroller.h"
namespace Ui {
class Windowali;
}

class Windowali : public QMainWindow
{
    Q_OBJECT

public:
    explicit Windowali(QWidget *parent = nullptr);
    ~Windowali();
private slots:
    void on_le_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_modifier_clicked();



    void on_trier_clicked();

    void on_le_chercher_clicked();


    void on_le_PDF_clicked();


     void on_le_stat_clicked();






     void on_PNG_clicked();

    void on_pb_reduction_clicked();
    void exportFactureToPNG(const QString &filename);

    void on_afficheur_clicked();
    void sendMail();
        void mailSent(QString);
        void browse();


private:
    Ui::Windowali *ui;
      Client C;
    QChartView *chartView;
     QPieSeries *pieSeries;
     QByteArray data; // variable contenant les données reçues
     QStringList files;

         QSortFilterProxyModel *proxyModel;

       Arduino A; //
 LCDController *lcdController;
};



#endif // MAINWINDOW_H
