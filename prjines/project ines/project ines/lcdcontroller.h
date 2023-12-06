#ifndef LCDCONTROLLER_H
#define LCDCONTROLLER_H
#include "connection.h"
#include <QObject>
#include <QSerialPort>

class LCDController : public QObject
{
    Q_OBJECT

public:
    LCDController(QObject *parent = nullptr);
    ~LCDController();

public slots:
    void readData();
    void sendHelloWorld();
     void afficherCodeFiscaleByEmail(const QString &email);
    //void displayMessage(const QString &message);

private:
    QSerialPort *serialPort;
};

#endif // LCDCONTROLLER_H
