#include "lcdcontroller.h"
#include "connection.h"
#include <QDebug>
#include <QTimer>
#include <QThread>
#include <QEventLoop>
#include <QSerialPortInfo>
#include <QSqlQuery>
#include<QSqlQueryModel>
#include "windowines.h"
#include "ui_windowines.h"


LCDController::LCDController(QObject *parent) : QObject(parent)
{
    // Initialize serial communication
    serialPort = new QSerialPort(this);
    serialPort->setPortName("COM9"); // Set your port name
    serialPort->setBaudRate(QSerialPort::Baud9600);
    serialPort->setDataBits(QSerialPort::Data8);
    serialPort->setParity(QSerialPort::NoParity);
    serialPort->setStopBits(QSerialPort::OneStop);

    if (!serialPort->open(QIODevice::ReadWrite))
    {
        qDebug() << "Error: Could not open serial port";
        return;
    }

    // Connect the readyRead signal to the slot that will handle data reception
    connect(serialPort, &QSerialPort::readyRead, this, &LCDController::readData);

    // Send "Hello, World!" to the LCD every 2 seconds
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &LCDController::sendHelloWorld);
    timer->start(2000);

}

LCDController::~LCDController()
{
    if (serialPort->isOpen())
               serialPort->close();

           delete serialPort;
}





void LCDController::readData()
{


    QByteArray data = serialPort->readAll();
    qDebug() << "Received data:" << data;
    //QByteArray data = serialPort->readAll();
      // qDebug() << "Received data:" << data;// Handle received data from the LCD - Add your logic here if needed
}
/*
void LCDController::displayMessage()
{
    // Send the message to the LCD
    QByteArray data = message.toUtf8() + '\n';  // Add a newline character if needed
    serialPort->write(data);
    qDebug() << "Sent data:" << data;
      QThread::msleep(500);
}*/





void LCDController::afficherCodeFiscaleByEmail(const QString &email)
{
    // Vérifier si serialPort est nullptr
       if (!serialPort) {
           qDebug() << "Error: Serial port is nullptr";
           return;
       }

       // Vérifier si le port série est ouvert
       if (!serialPort->isOpen()) {
           qDebug() << "Error: Serial port is not open";
           return;
       }

       QSqlQuery query;
       query.prepare("SELECT codefiscale FROM client WHERE mail = :email");
       query.bindValue(":email", email);

       if (query.exec() && query.next()) {
           int codeFiscale = query.value("codefiscale").toInt();

           QByteArray data = QString("Code fiscal du client (%1): %2").arg(email).arg(codeFiscale).toUtf8();

           // Utiliser le port série seulement si les vérifications passent
           serialPort->write(data);
           qDebug() << "Sent data:" << data;
       } else {
           qDebug() << "Error: Client not found or failed to execute query";
           qDebug() << "Database error:" << query.lastError().text();
       }
}









void LCDController::sendHelloWorld()
{
    /*QByteArray data = "Hello, World!";
        serialPort->write(data);
        qDebug() << "Sent data:" << data;*/






   /* QStringList emailList;
        emailList << "a" << "salah@gmail.com";

        // Now you have emailList with the predefined data
        qDebug() << "Emails:" << emailList;

        int x = 1;
        if (x < emailList.size())
        {
            QByteArray data = emailList[x].toUtf8();
            serialPort->write(data);
            qDebug() << "Sent data:" << data;
        }
        else
        {
            qDebug() << "Error: Index out of range";
        }*/





 //int codeFiscale = le_client->text().toInt();
   /* QSqlQuery query;
        query.prepare("SELECT mail FROM client WHERE codefiscale = :codefiscale");
        query.bindValue(":codefiscale", 156); // Remplacez VOTRE_VALEUR_DU_CODE_FISCALE par la valeur recherchée

        if (query.exec()) {
            QStringList emailList;

            while (query.next()) {
                QString mail = query.value("mail").toString();
                emailList.append(mail);
            }

            qDebug() << "Emails:" << emailList;

            // Afficher le mail seulement si la liste n'est pas vide
            if (!emailList.isEmpty()) {
                QByteArray data = emailList[0].toUtf8();
                serialPort->write(data);
                qDebug() << "Sent data:" << data;
            } else {
                qDebug() << "Error: No emails found";
            }
        } else {
            qDebug() << "Error: Failed to execute query";
            qDebug() << "Database error:" << query.lastError().text();
        }*/



















   /* QSqlQuery query("SELECT mail FROM client");

        if (query.exec())
        {
            QStringList emailList;

            while (query.next())
            {
                QString mail = query.value("mail").toString();
                emailList.append(mail);
            }

            qDebug() << "Emails:" << emailList;

            int x = 1;
            if (x < emailList.size())
            {
                QByteArray data = emailList[x].toUtf8();
                serialPort->write(data);
                qDebug() << "Sent data:" << data;
            }
            else
            {
                qDebug() << "Error: Index out of range";
            }
        }
        else
        {
            qDebug() << "Error: Failed to fetch data from the database";
            qDebug() << "Database error:" << query.lastError().text();
        }*/
    }



