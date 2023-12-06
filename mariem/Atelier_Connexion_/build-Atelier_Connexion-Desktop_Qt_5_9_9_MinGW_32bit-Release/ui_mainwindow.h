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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
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
    QLabel *label_4;
    QPushButton *pb_ajouter;
    QLineEdit *le_r;
    QLineEdit *le_y;
    QLineEdit *le_d;
    QLineEdit *le_e;
    QLineEdit *le_da;
    QLineEdit *le_na;
    QLabel *label;
    QWidget *tab_3;
    QTableView *tab_equipement;
    QPushButton *pb_actualiser;
    QLabel *label_9;
    QLabel *label_10;
    QWidget *tab_;
    QLabel *label_2;
    QLineEdit *le_supprimer;
    QPushButton *pb_supprimer;
    QLabel *label_11;
    QLabel *label_12;
    QWidget *tab;
    QLineEdit *le_nom_to_modify;
    QLabel *label_13;
    QLineEdit *la_ref;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLineEdit *la_new_r;
    QLineEdit *la_new_y;
    QLineEdit *la_new_d;
    QLabel *label_17;
    QLineEdit *la_new_e;
    QLabel *label_18;
    QLineEdit *la_new_da;
    QLabel *label_19;
    QLineEdit *la_new_na;
    QLabel *label_20;
    QLabel *label_21;
    QPushButton *pb_modifier;
    QPushButton *pb_fetch_data_for_modification;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(893, 541);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(40, 20, 811, 421));
        tabWidget->setStyleSheet(QStringLiteral("background-color: rgb(170, 170, 127);"));
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        label_ref = new QLabel(tab_2);
        label_ref->setObjectName(QStringLiteral("label_ref"));
        label_ref->setGeometry(QRect(100, 80, 161, 16));
        label_ref->setStyleSheet(QLatin1String("font: 8pt \"8514oem\";\n"
"font: 8pt \"MS Shell Dlg 2\";\n"
"font: 75 8pt \"8514oem\";"));
        label_3 = new QLabel(tab_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 150, 181, 16));
        label_3->setStyleSheet(QLatin1String("font: 8pt \"8514oem\";\n"
"font: 8pt \"MS Shell Dlg 2\";\n"
"font: 75 8pt \"8514oem\";"));
        label_6 = new QLabel(tab_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(140, 200, 131, 16));
        label_6->setStyleSheet(QLatin1String("font: 8pt \"8514oem\";\n"
"font: 8pt \"MS Shell Dlg 2\";\n"
"font: 75 8pt \"8514oem\";"));
        label_5 = new QLabel(tab_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(400, 70, 56, 16));
        label_5->setStyleSheet(QLatin1String("font: 8pt \"8514oem\";\n"
"font: 8pt \"MS Shell Dlg 2\";\n"
"font: 75 8pt \"8514oem\";"));
        label_8 = new QLabel(tab_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(370, 150, 56, 16));
        label_8->setStyleSheet(QLatin1String("font: 8pt \"8514oem\";\n"
"font: 8pt \"MS Shell Dlg 2\";\n"
"font: 75 8pt \"8514oem\";"));
        label_7 = new QLabel(tab_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(100, 260, 311, 16));
        label_7->setStyleSheet(QLatin1String("font: 8pt \"8514oem\";\n"
"font: 8pt \"MS Shell Dlg 2\";\n"
"font: 75 8pt \"8514oem\";"));
        label_4 = new QLabel(tab_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(320, 350, 171, 16));
        label_4->setStyleSheet(QLatin1String("font: italic 12pt \"8514oem\";\n"
"color: rgb(85, 170, 0);"));
        pb_ajouter = new QPushButton(tab_2);
        pb_ajouter->setObjectName(QStringLiteral("pb_ajouter"));
        pb_ajouter->setGeometry(QRect(660, 150, 93, 28));
        pb_ajouter->setStyleSheet(QLatin1String("font: 8pt \"8514oem\";\n"
"font: 8pt \"MS Shell Dlg 2\";\n"
"font: 75 8pt \"8514oem\";"));
        le_r = new QLineEdit(tab_2);
        le_r->setObjectName(QStringLiteral("le_r"));
        le_r->setGeometry(QRect(240, 70, 113, 22));
        le_y = new QLineEdit(tab_2);
        le_y->setObjectName(QStringLiteral("le_y"));
        le_y->setGeometry(QRect(490, 70, 113, 22));
        le_d = new QLineEdit(tab_2);
        le_d->setObjectName(QStringLiteral("le_d"));
        le_d->setGeometry(QRect(190, 150, 113, 22));
        le_e = new QLineEdit(tab_2);
        le_e->setObjectName(QStringLiteral("le_e"));
        le_e->setGeometry(QRect(470, 150, 113, 22));
        le_da = new QLineEdit(tab_2);
        le_da->setObjectName(QStringLiteral("le_da"));
        le_da->setGeometry(QRect(280, 200, 113, 22));
        le_na = new QLineEdit(tab_2);
        le_na->setObjectName(QStringLiteral("le_na"));
        le_na->setGeometry(QRect(470, 260, 113, 22));
        label = new QLabel(tab_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(690, 300, 111, 81));
        label->setPixmap(QPixmap(QString::fromUtf8("../../380266158_927913728670530_3389847454208919423_n.png")));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        tab_equipement = new QTableView(tab_3);
        tab_equipement->setObjectName(QStringLiteral("tab_equipement"));
        tab_equipement->setGeometry(QRect(60, 20, 691, 281));
        tab_equipement->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        pb_actualiser = new QPushButton(tab_3);
        pb_actualiser->setObjectName(QStringLiteral("pb_actualiser"));
        pb_actualiser->setGeometry(QRect(360, 310, 93, 28));
        label_9 = new QLabel(tab_3);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(690, 310, 121, 71));
        label_9->setPixmap(QPixmap(QString::fromUtf8("../../380266158_927913728670530_3389847454208919423_n.png")));
        label_10 = new QLabel(tab_3);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(310, 360, 181, 16));
        label_10->setStyleSheet(QLatin1String("font: italic 12pt \"8514oem\";\n"
"color: rgb(85, 170, 0);"));
        tabWidget->addTab(tab_3, QString());
        tab_ = new QWidget();
        tab_->setObjectName(QStringLiteral("tab_"));
        tab_->setContextMenuPolicy(Qt::DefaultContextMenu);
        label_2 = new QLabel(tab_);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(260, 110, 121, 20));
        label_2->setStyleSheet(QLatin1String("font: 8pt \"8514oem\";\n"
"font: 8pt \"MS Shell Dlg 2\";\n"
"font: 75 8pt \"8514oem\";"));
        le_supprimer = new QLineEdit(tab_);
        le_supprimer->setObjectName(QStringLiteral("le_supprimer"));
        le_supprimer->setGeometry(QRect(400, 110, 113, 22));
        le_supprimer->setContextMenuPolicy(Qt::NoContextMenu);
        pb_supprimer = new QPushButton(tab_);
        pb_supprimer->setObjectName(QStringLiteral("pb_supprimer"));
        pb_supprimer->setGeometry(QRect(360, 200, 93, 28));
        label_11 = new QLabel(tab_);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(320, 340, 181, 16));
        label_11->setStyleSheet(QLatin1String("font: italic 12pt \"8514oem\";\n"
"color: rgb(85, 170, 0);"));
        label_12 = new QLabel(tab_);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(680, 300, 121, 81));
        label_12->setPixmap(QPixmap(QString::fromUtf8("../../380266158_927913728670530_3389847454208919423_n.png")));
        tabWidget->addTab(tab_, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        le_nom_to_modify = new QLineEdit(tab);
        le_nom_to_modify->setObjectName(QStringLiteral("le_nom_to_modify"));
        le_nom_to_modify->setGeometry(QRect(310, 10, 113, 22));
        label_13 = new QLabel(tab);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(110, 70, 101, 16));
        label_13->setStyleSheet(QLatin1String("font: 8pt \"8514oem\";\n"
"font: 8pt \"MS Shell Dlg 2\";\n"
"font: 75 8pt \"8514oem\";"));
        la_ref = new QLineEdit(tab);
        la_ref->setObjectName(QStringLiteral("la_ref"));
        la_ref->setGeometry(QRect(270, 70, 113, 22));
        label_14 = new QLabel(tab);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(70, 130, 141, 16));
        label_14->setStyleSheet(QLatin1String("font: 8pt \"8514oem\";\n"
"font: 8pt \"MS Shell Dlg 2\";\n"
"font: 75 8pt \"8514oem\";"));
        label_15 = new QLabel(tab);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(480, 130, 81, 16));
        label_15->setStyleSheet(QLatin1String("font: 8pt \"8514oem\";\n"
"font: 8pt \"MS Shell Dlg 2\";\n"
"font: 75 8pt \"8514oem\";"));
        label_16 = new QLabel(tab);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(30, 200, 191, 16));
        label_16->setStyleSheet(QLatin1String("font: 8pt \"8514oem\";\n"
"font: 8pt \"MS Shell Dlg 2\";\n"
"font: 75 8pt \"8514oem\";"));
        la_new_r = new QLineEdit(tab);
        la_new_r->setObjectName(QStringLiteral("la_new_r"));
        la_new_r->setGeometry(QRect(270, 130, 113, 22));
        la_new_y = new QLineEdit(tab);
        la_new_y->setObjectName(QStringLiteral("la_new_y"));
        la_new_y->setGeometry(QRect(580, 130, 113, 22));
        la_new_d = new QLineEdit(tab);
        la_new_d->setObjectName(QStringLiteral("la_new_d"));
        la_new_d->setGeometry(QRect(240, 200, 113, 22));
        label_17 = new QLabel(tab);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(480, 200, 91, 16));
        label_17->setStyleSheet(QLatin1String("font: 8pt \"8514oem\";\n"
"font: 8pt \"MS Shell Dlg 2\";\n"
"font: 75 8pt \"8514oem\";"));
        la_new_e = new QLineEdit(tab);
        la_new_e->setObjectName(QStringLiteral("la_new_e"));
        la_new_e->setGeometry(QRect(590, 200, 113, 22));
        label_18 = new QLabel(tab);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(30, 270, 161, 16));
        label_18->setStyleSheet(QLatin1String("font: 8pt \"8514oem\";\n"
"font: 8pt \"MS Shell Dlg 2\";\n"
"font: 75 8pt \"8514oem\";"));
        la_new_da = new QLineEdit(tab);
        la_new_da->setObjectName(QStringLiteral("la_new_da"));
        la_new_da->setGeometry(QRect(200, 270, 113, 22));
        label_19 = new QLabel(tab);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(330, 270, 301, 16));
        label_19->setStyleSheet(QLatin1String("font: 8pt \"8514oem\";\n"
"font: 8pt \"MS Shell Dlg 2\";\n"
"font: 75 8pt \"8514oem\";"));
        la_new_na = new QLineEdit(tab);
        la_new_na->setObjectName(QStringLiteral("la_new_na"));
        la_new_na->setGeometry(QRect(640, 270, 113, 22));
        label_20 = new QLabel(tab);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(700, 300, 121, 101));
        label_20->setPixmap(QPixmap(QString::fromUtf8("../../380266158_927913728670530_3389847454208919423_n.png")));
        label_21 = new QLabel(tab);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(280, 360, 181, 20));
        label_21->setStyleSheet(QLatin1String("font: italic 12pt \"8514oem\";\n"
"color: rgb(85, 170, 0);"));
        pb_modifier = new QPushButton(tab);
        pb_modifier->setObjectName(QStringLiteral("pb_modifier"));
        pb_modifier->setGeometry(QRect(590, 320, 93, 28));
        pb_fetch_data_for_modification = new QPushButton(tab);
        pb_fetch_data_for_modification->setObjectName(QStringLiteral("pb_fetch_data_for_modification"));
        pb_fetch_data_for_modification->setGeometry(QRect(470, 70, 93, 28));
        tabWidget->addTab(tab, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 893, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Gestion des Clients", Q_NULLPTR));
        label_ref->setText(QApplication::translate("MainWindow", "Reference", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "disponibilite", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "date d'achat", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "type", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "etat", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "Nombre d'annee d'amortissement", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Green Renew App", Q_NULLPTR));
        pb_ajouter->setText(QApplication::translate("MainWindow", "ajouter", Q_NULLPTR));
        label->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "ajouter machine", Q_NULLPTR));
        pb_actualiser->setText(QApplication::translate("MainWindow", "actualiser", Q_NULLPTR));
        label_9->setText(QString());
        label_10->setText(QApplication::translate("MainWindow", "Green Renew app", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "afficher machine", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "refrence", Q_NULLPTR));
        pb_supprimer->setText(QApplication::translate("MainWindow", "supprimer", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "Green Renew App", Q_NULLPTR));
        label_12->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_), QApplication::translate("MainWindow", "supprimer machine", Q_NULLPTR));
        label_13->setText(QApplication::translate("MainWindow", "reference", Q_NULLPTR));
        label_14->setText(QApplication::translate("MainWindow", "New reference", Q_NULLPTR));
        label_15->setText(QApplication::translate("MainWindow", "New type", Q_NULLPTR));
        label_16->setText(QApplication::translate("MainWindow", " New disponibilite", Q_NULLPTR));
        label_17->setText(QApplication::translate("MainWindow", "New etat", Q_NULLPTR));
        label_18->setText(QApplication::translate("MainWindow", "New date d'achat", Q_NULLPTR));
        label_19->setText(QApplication::translate("MainWindow", "New Nombre Annee Amortissement", Q_NULLPTR));
        label_20->setText(QString());
        label_21->setText(QApplication::translate("MainWindow", "Green Renew App", Q_NULLPTR));
        pb_modifier->setText(QApplication::translate("MainWindow", "modifier", Q_NULLPTR));
        pb_fetch_data_for_modification->setText(QApplication::translate("MainWindow", "appear", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "modifier machine", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
