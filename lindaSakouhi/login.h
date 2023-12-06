#ifndef LOGIN_H
#define LOGIN_H
#include "employe.h"
#include <QDialog>
#include<QString>
#include <QSqlQuery>
#include <QObject>
#include <QMainWindow>
#include <QSqlError>
#include <QTableView>
#include <QMessageBox>
#include <QInputDialog>
//#include "arduino.h"
#include<QSqlQueryModel>
#include<QSerialPort>
#include <QSerialPortInfo>
namespace Ui {
class login;
}

class login : public QMainWindow
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

private slots:
    //void on_pushButton_login_clicked();
   // void on_lineEdit_password_textChanged(const QString &text);
   void on_pushButton_clicked();
   void on_pushButton_2_clicked();
//QSerialPort* getserial();
    //void update_label();

  // void on_pushButton_2_clicked(QTableView * employe);

   // void on_pushButton_oublier_clicked();

    //void on_pushButton_clicked();
    void readData();

private:
    Ui::login *ui;
    //QSerialPort* serialPort;
    Employe E ;
        QByteArray data;
    //arduino A;
        // QByteArray data;
        QSerialPort *serial;

};

#endif // LOGIN_H
