#ifndef WINDOWINES_H
#define WINDOWINES_H
#include <QMainWindow>
#include "client.h"
#include <QRegularExpression>
#include <QDate>
#include <QtCharts>
#include <QPieSeries>
#include <QPieSlice>
#include "lcdcontroller.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Windowines; }
QT_END_NAMESPACE

class Windowines : public QMainWindow
{
    Q_OBJECT

public:
    Windowines(QWidget *parent = nullptr);
    ~Windowines();



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
        void on_pb_back2_clicked();











private:
    Ui::Windowines *ui;

    Client C;
    QChartView *chartView;
     QPieSeries *pieSeries;
     QByteArray data; // variable contenant les données reçues
     QStringList files;
     LCDController *lcdController;

         QSortFilterProxyModel *proxyModel;
};
#endif // WINDOWINES_H
