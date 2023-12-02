#include "stat_co.h"
#include "ui_stat_co.h"
#include<QDebug>
#include<QSqlQuery>

stat_co::stat_co(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::stat_co)
{
    ui->setupUi(this);
}

stat_co::~stat_co()
{
    delete ui;
}
void stat_co::make_nationalite()
{
    qDebug();
    int total;
    int nat_tn =0 ;
    int nat_fr = 0;
    QString Nat_tn;
    QString Nat_fr;
    QSqlQuery q;

    q.prepare("SELECT COUNT(*) FROM COMMANDE WHERE NATIONALITE ='tunisiennes'");
    q.exec();
    q.first();
    nat_tn = q.value(0).toInt();

    q.prepare("SELECT COUNT(*) FROM COMMANDE WHERE NATIONALITE ='francaises'");
    q.exec();
    q.first();
    nat_fr = q.value(0).toInt();

    q.prepare("SELECT COUNT(*) FROM COMMANDE");
    q.exec();
    q.first();
    total = q.value(0).toInt();

    double percent_nat_fr = ((double)nat_fr / (double)total) * 100;
    double percent_nat_tn = 100 - percent_nat_fr;

    Nat_tn = QString::number(percent_nat_tn);
    Nat_fr = QString::number(percent_nat_fr);

    QPieSeries *series = new QPieSeries();
    series->append("TUNISIAN NATIONALITY " + Nat_tn + "%", percent_nat_tn);
    series->append("FRENCH NATIONALITY " + Nat_fr + "%", percent_nat_fr);

    QPieSlice *slice0 = series->slices().at(0);
    slice0->setLabelVisible();

    QPieSlice *slice1 = series->slices().at(1);
    slice1->setExploded();
    slice1->setLabelVisible();
    slice1->setPen(QPen(Qt::red, 2));
    slice1->setBrush(Qt::blue);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Statistics on COMMANDE nationalities");
    chart->legend()->show();

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    ui->verticalLayout->addWidget(chartView);

    qDebug() << "pst";
}
