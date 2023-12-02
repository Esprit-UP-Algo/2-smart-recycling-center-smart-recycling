#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"commande.h"
#include <QMainWindow>
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

    void on_pb_modifier_clicked();

    void on_le_rechercher_cursorPositionChanged(int arg1, int arg2);

    void on_pb_trier_clicked();
    
    void on_pdf_commande_clicked();

   // void on_pushButton_clicked();

    void on_stat_commande_clicked();



    void on_calendar_commande_clicked();

private:
    Ui::MainWindow *ui;
    Commande C;
};

#endif // MAINWINDOW_H
