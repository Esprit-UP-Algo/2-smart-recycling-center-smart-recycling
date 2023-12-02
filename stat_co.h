#ifndef STAT_CO_H
#define STAT_CO_H

#include <QDialog>
#include<QtCharts>
#include<QChartView>
#include<QPieSeries>
#include<QPieSlice>


namespace Ui {
class stat_co;
}

class stat_co : public QDialog
{
    Q_OBJECT

public:
    explicit stat_co(QWidget *parent = nullptr); 
    void make_nationalite();
    ~stat_co();

private:
    Ui::stat_co *ui;
};

#endif // STAT_CO_H
