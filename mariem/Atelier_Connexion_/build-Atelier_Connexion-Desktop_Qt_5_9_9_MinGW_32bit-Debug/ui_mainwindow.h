/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab_2;
    QLabel *label_ref;
    QLabel *label_3;
    QLabel *label_6;
    QLabel *label_5;
    QLabel *label_8;
    QLabel *label_7;
    QPushButton *pb_ajouter;
    QLineEdit *le_r;
    QLineEdit *le_na;
    QPushButton *pb_modifier;
    QPushButton *pb_supprimer;
    QDateEdit *le_d;
    QDateEdit *le_da;
    QComboBox *comboBox1;
    QPushButton *pb_chercher;
    QLabel *label;
    QPushButton *PDF;
    QPushButton *statistiquesButton;
    QPushButton *pb_actualiser;
    QPushButton *pb_tri;
    QLabel *label_4;
    QTabWidget *tabWidget_2;
    QWidget *tab_3;
    QTableView *tab_equipement;
    QWidget *tab_5;
    QGraphicsView *graphicsView;
    QWidget *tab_4;
    QCalendarWidget *calendrierWidget;
    QTextEdit *textEditRaison;
    QComboBox *comboBox;
    QWidget *tab;
    QLabel *label_2;
    QLabel *label_11;
    QLabel *label_12;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label_14;
    QLabel *label_15;
    QDateEdit *dateEdit;
    QPushButton *pushButtonAfficherEntretien;
    QTableView *tableViewEntretien;
    QLabel *label_16;
    QDateEdit *dateEdit_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1194, 679);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(-10, 0, 1151, 641));
        tabWidget->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        label_ref = new QLabel(tab_2);
        label_ref->setObjectName(QStringLiteral("label_ref"));
        label_ref->setGeometry(QRect(10, 110, 91, 16));
        label_ref->setStyleSheet(QLatin1String("font: 8pt \"8514oem\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(76, 99, 19);\n"
"font: 8pt \"MS Shell Dlg 2\";\n"
"font: 75 8pt \"8514oem\";"));
        label_3 = new QLabel(tab_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 210, 141, 16));
        label_3->setStyleSheet(QLatin1String("font: 8pt \"8514oem\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(76, 99, 19);\n"
"font: 8pt \"MS Shell Dlg 2\";\n"
"font: 75 8pt \"8514oem\";\n"
""));
        label_6 = new QLabel(tab_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 290, 131, 16));
        label_6->setStyleSheet(QLatin1String("font: 8pt \"8514oem\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(76, 99, 19);\n"
"font: 8pt \"MS Shell Dlg 2\";\n"
"font: 75 8pt \"8514oem\";\n"
""));
        label_5 = new QLabel(tab_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 160, 56, 16));
        label_5->setStyleSheet(QLatin1String("font: 8pt \"8514oem\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(76, 99, 19);\n"
"font: 8pt \"MS Shell Dlg 2\";\n"
"font: 75 8pt \"8514oem\";\n"
""));
        label_8 = new QLabel(tab_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 250, 56, 16));
        label_8->setStyleSheet(QLatin1String("font: 8pt \"8514oem\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(76, 99, 19);\n"
"font: 8pt \"MS Shell Dlg 2\";\n"
"font: 75 8pt \"8514oem\";\n"
""));
        label_7 = new QLabel(tab_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 330, 171, 20));
        label_7->setStyleSheet(QLatin1String("font: 8pt \"8514oem\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(76, 99, 19);\n"
"font: 8pt \"MS Shell Dlg 2\";\n"
"font: 75 8pt \"8514oem\";"));
        pb_ajouter = new QPushButton(tab_2);
        pb_ajouter->setObjectName(QStringLiteral("pb_ajouter"));
        pb_ajouter->setGeometry(QRect(40, 400, 51, 41));
        pb_ajouter->setStyleSheet(QLatin1String("font: 8pt \"8514oem\";\n"
"font: 8pt \"MS Shell Dlg 2\";\n"
"font: 75 8pt \"8514oem\";"));
        QIcon icon;
        icon.addFile(QStringLiteral("../../ajout-removebg-preview.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_ajouter->setIcon(icon);
        pb_ajouter->setIconSize(QSize(30, 30));
        le_r = new QLineEdit(tab_2);
        le_r->setObjectName(QStringLiteral("le_r"));
        le_r->setGeometry(QRect(200, 100, 113, 22));
        le_na = new QLineEdit(tab_2);
        le_na->setObjectName(QStringLiteral("le_na"));
        le_na->setGeometry(QRect(200, 330, 113, 22));
        pb_modifier = new QPushButton(tab_2);
        pb_modifier->setObjectName(QStringLiteral("pb_modifier"));
        pb_modifier->setGeometry(QRect(140, 460, 51, 41));
        pb_modifier->setStyleSheet(QLatin1String("font: 8pt \"8514oem\";\n"
"font: 8pt \"MS Shell Dlg 2\";\n"
"font: 75 8pt \"8514oem\";"));
        QIcon icon1;
        icon1.addFile(QStringLiteral("../../modif.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_modifier->setIcon(icon1);
        pb_modifier->setIconSize(QSize(30, 30));
        pb_supprimer = new QPushButton(tab_2);
        pb_supprimer->setObjectName(QStringLiteral("pb_supprimer"));
        pb_supprimer->setGeometry(QRect(140, 400, 51, 41));
        pb_supprimer->setStyleSheet(QLatin1String("font: 8pt \"8514oem\";\n"
"font: 8pt \"MS Shell Dlg 2\";\n"
"font: 75 8pt \"8514oem\";"));
        QIcon icon2;
        icon2.addFile(QStringLiteral("../../32178.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_supprimer->setIcon(icon2);
        le_d = new QDateEdit(tab_2);
        le_d->setObjectName(QStringLiteral("le_d"));
        le_d->setGeometry(QRect(200, 200, 110, 22));
        le_d->setDateTime(QDateTime(QDate(2000, 1, 4), QTime(0, 0, 0)));
        le_da = new QDateEdit(tab_2);
        le_da->setObjectName(QStringLiteral("le_da"));
        le_da->setGeometry(QRect(200, 290, 111, 22));
        le_da->setTime(QTime(12, 4, 0));
        comboBox1 = new QComboBox(tab_2);
        comboBox1->setObjectName(QStringLiteral("comboBox1"));
        comboBox1->setGeometry(QRect(200, 150, 111, 22));
        pb_chercher = new QPushButton(tab_2);
        pb_chercher->setObjectName(QStringLiteral("pb_chercher"));
        pb_chercher->setGeometry(QRect(40, 460, 51, 41));
        pb_chercher->setStyleSheet(QLatin1String("font: 8pt \"8514oem\";\n"
"font: 8pt \"MS Shell Dlg 2\";\n"
"font: 75 8pt \"8514oem\";"));
        QIcon icon3;
        icon3.addFile(QStringLiteral("../../recherche.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_chercher->setIcon(icon3);
        pb_chercher->setIconSize(QSize(40, 40));
        label = new QLabel(tab_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, -40, 1261, 721));
        label->setPixmap(QPixmap(QString::fromUtf8("../../ajouuuutttt.jpg")));
        PDF = new QPushButton(tab_2);
        PDF->setObjectName(QStringLiteral("PDF"));
        PDF->setGeometry(QRect(370, 20, 51, 41));
        PDF->setStyleSheet(QLatin1String("font: 8pt \"8514oem\";\n"
"font: 8pt \"MS Shell Dlg 2\";\n"
"font: 75 8pt \"8514oem\";"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/mariem/pdf.png"), QSize(), QIcon::Normal, QIcon::Off);
        PDF->setIcon(icon4);
        PDF->setIconSize(QSize(30, 30));
        statistiquesButton = new QPushButton(tab_2);
        statistiquesButton->setObjectName(QStringLiteral("statistiquesButton"));
        statistiquesButton->setGeometry(QRect(490, 20, 51, 41));
        statistiquesButton->setStyleSheet(QLatin1String("font: 8pt \"8514oem\";\n"
"font: 8pt \"MS Shell Dlg 2\";\n"
"font: 75 8pt \"8514oem\";"));
        QIcon icon5;
        icon5.addFile(QStringLiteral("../../stat.png"), QSize(), QIcon::Normal, QIcon::Off);
        statistiquesButton->setIcon(icon5);
        statistiquesButton->setIconSize(QSize(30, 30));
        pb_actualiser = new QPushButton(tab_2);
        pb_actualiser->setObjectName(QStringLiteral("pb_actualiser"));
        pb_actualiser->setGeometry(QRect(430, 20, 51, 41));
        pb_actualiser->setStyleSheet(QLatin1String("font: 8pt \"8514oem\";\n"
"font: 8pt \"MS Shell Dlg 2\";\n"
"font: 75 8pt \"8514oem\";"));
        QIcon icon6;
        icon6.addFile(QStringLiteral("../../refresh.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_actualiser->setIcon(icon6);
        pb_actualiser->setIconSize(QSize(40, 40));
        pb_tri = new QPushButton(tab_2);
        pb_tri->setObjectName(QStringLiteral("pb_tri"));
        pb_tri->setGeometry(QRect(550, 20, 51, 41));
        pb_tri->setStyleSheet(QLatin1String("font: 8pt \"8514oem\";\n"
"font: 8pt \"MS Shell Dlg 2\";\n"
"font: 75 8pt \"8514oem\";"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/mariem/tri.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_tri->setIcon(icon7);
        pb_tri->setIconSize(QSize(30, 30));
        label_4 = new QLabel(tab_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(125, 30, 121, 41));
        label_4->setStyleSheet(QLatin1String("background-color: rgb(76, 99, 19);\n"
"font: italic 16pt \"Verdana\";\n"
"text-decoration: underline;\n"
"font: 75 22pt \"Bodoni MT\";\n"
"color: rgb(255, 255, 255);"));
        tabWidget_2 = new QTabWidget(tab_2);
        tabWidget_2->setObjectName(QStringLiteral("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(360, 80, 771, 491));
        tabWidget_2->setStyleSheet(QStringLiteral("background-color: rgb(76, 99, 19);"));
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        tab_equipement = new QTableView(tab_3);
        tab_equipement->setObjectName(QStringLiteral("tab_equipement"));
        tab_equipement->setGeometry(QRect(10, 10, 741, 341));
        tab_equipement->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        tabWidget_2->addTab(tab_3, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        graphicsView = new QGraphicsView(tab_5);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(10, 10, 511, 441));
        graphicsView->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        tabWidget_2->addTab(tab_5, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        calendrierWidget = new QCalendarWidget(tab_4);
        calendrierWidget->setObjectName(QStringLiteral("calendrierWidget"));
        calendrierWidget->setGeometry(QRect(50, 20, 361, 281));
        calendrierWidget->setStyleSheet(QStringLiteral("background-color: rgb(203, 228, 171);"));
        textEditRaison = new QTextEdit(tab_4);
        textEditRaison->setObjectName(QStringLiteral("textEditRaison"));
        textEditRaison->setGeometry(QRect(440, 150, 121, 31));
        textEditRaison->setStyleSheet(QLatin1String("background-color: rgb(203, 193, 140);\n"
"background-color: rgb(225, 225, 225);"));
        tabWidget_2->addTab(tab_4, QString());
        comboBox = new QComboBox(tab_2);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(200, 250, 111, 22));
        tabWidget->addTab(tab_2, QString());
        label->raise();
        label_ref->raise();
        label_3->raise();
        label_6->raise();
        label_5->raise();
        label_8->raise();
        label_7->raise();
        pb_ajouter->raise();
        le_r->raise();
        le_na->raise();
        pb_modifier->raise();
        pb_supprimer->raise();
        le_d->raise();
        le_da->raise();
        comboBox1->raise();
        pb_chercher->raise();
        PDF->raise();
        statistiquesButton->raise();
        pb_actualiser->raise();
        pb_tri->raise();
        label_4->raise();
        tabWidget_2->raise();
        comboBox->raise();
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(80, 70, 101, 16));
        label_2->setStyleSheet(QLatin1String("font: 8pt \"8514oem\";\n"
"font: 8pt \"MS Shell Dlg 2\";\n"
"font: 75 8pt \"8514oem\";"));
        label_11 = new QLabel(tab);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(50, 250, 261, 16));
        label_11->setStyleSheet(QLatin1String("font: 8pt \"8514oem\";\n"
"font: 8pt \"MS Shell Dlg 2\";\n"
"font: 75 8pt \"8514oem\";"));
        label_12 = new QLabel(tab);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(80, 140, 121, 16));
        label_12->setStyleSheet(QLatin1String("font: 8pt \"8514oem\";\n"
"font: 8pt \"MS Shell Dlg 2\";\n"
"font: 75 8pt \"8514oem\";"));
        lineEdit = new QLineEdit(tab);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(200, 70, 113, 22));
        lineEdit_2 = new QLineEdit(tab);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(210, 140, 113, 22));
        label_14 = new QLabel(tab);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(820, 370, 111, 81));
        label_14->setPixmap(QPixmap(QString::fromUtf8("../../380266158_927913728670530_3389847454208919423_n.png")));
        label_15 = new QLabel(tab);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(380, 420, 171, 16));
        label_15->setStyleSheet(QLatin1String("font: italic 12pt \"8514oem\";\n"
"color: rgb(85, 170, 0);"));
        dateEdit = new QDateEdit(tab);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setGeometry(QRect(330, 250, 110, 22));
        pushButtonAfficherEntretien = new QPushButton(tab);
        pushButtonAfficherEntretien->setObjectName(QStringLiteral("pushButtonAfficherEntretien"));
        pushButtonAfficherEntretien->setGeometry(QRect(230, 350, 93, 28));
        pushButtonAfficherEntretien->setStyleSheet(QLatin1String("font: 8pt \"8514oem\";\n"
"font: 8pt \"MS Shell Dlg 2\";\n"
"font: 75 8pt \"8514oem\";"));
        tableViewEntretien = new QTableView(tab);
        tableViewEntretien->setObjectName(QStringLiteral("tableViewEntretien"));
        tableViewEntretien->setGeometry(QRect(460, 70, 451, 241));
        tableViewEntretien->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_16 = new QLabel(tab);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(50, 200, 131, 16));
        label_16->setStyleSheet(QLatin1String("font: 8pt \"8514oem\";\n"
"font: 8pt \"MS Shell Dlg 2\";\n"
"font: 75 8pt \"8514oem\";"));
        dateEdit_2 = new QDateEdit(tab);
        dateEdit_2->setObjectName(QStringLiteral("dateEdit_2"));
        dateEdit_2->setGeometry(QRect(190, 200, 110, 22));
        tabWidget->addTab(tab, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1194, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);
        tabWidget_2->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Gestion des Equipements", Q_NULLPTR));
        label_ref->setText(QApplication::translate("MainWindow", "Reference", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "disponibilite", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "date d'achat", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "type", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "etat", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "Nbr Amortissement", Q_NULLPTR));
        pb_ajouter->setText(QString());
        pb_modifier->setText(QString());
        pb_supprimer->setText(QString());
        le_d->setDisplayFormat(QApplication::translate("MainWindow", "dd-MM-yyyy", Q_NULLPTR));
        comboBox1->clear();
        comboBox1->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "camion", Q_NULLPTR)
         << QApplication::translate("MainWindow", "machine_tri", Q_NULLPTR)
         << QApplication::translate("MainWindow", "machine_broyage", Q_NULLPTR)
         << QApplication::translate("MainWindow", "machine_stock", Q_NULLPTR)
        );
        pb_chercher->setText(QString());
        label->setText(QString());
        PDF->setText(QString());
        statistiquesButton->setText(QString());
        pb_actualiser->setText(QString());
        pb_tri->setText(QString());
        label_4->setText(QApplication::translate("MainWindow", "Formulaire", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_3), QApplication::translate("MainWindow", "afficher", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_5), QApplication::translate("MainWindow", "Statistique", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_4), QApplication::translate("MainWindow", "calendrier", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Marche", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Autre", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Attente", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Panne", Q_NULLPTR)
        );
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "ajouter machine", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "reference", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "Date de dernier entretien", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "periodicite", Q_NULLPTR));
        label_14->setText(QString());
        label_15->setText(QApplication::translate("MainWindow", "Green Renew App", Q_NULLPTR));
        pushButtonAfficherEntretien->setText(QApplication::translate("MainWindow", "afficher", Q_NULLPTR));
        label_16->setText(QApplication::translate("MainWindow", "Current Date", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Alerte", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
