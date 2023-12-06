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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGroupBox *groupBox_2;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *cd;
    QLineEdit *le_mail;
    QLineEdit *le_adresse;
    QPushButton *le_ajouter;
    QPushButton *pb_modifier;
    QLineEdit *le_sexe;
    QLabel *label_2;
    QLineEdit *le_nbr;
    QLabel *label_4;
    QTableView *tab_client;
    QPushButton *trier;
    QPushButton *le_PDF;
    QLabel *label_3;
    QLineEdit *le_email;
    QPushButton *le_chercher;
    QLineEdit *le_client;
    QPushButton *afficheur;
    QLabel *label;
    QLineEdit *le_supp_code;
    QPushButton *pb_supprimer;
    QPushButton *le_stat;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_10;
    QWidget *tab4;
    QFrame *horizontalFrame;
    QHBoxLayout *horizontalLayout_2;
    QWidget *tab_4;
    QLabel *label_8;
    QLineEdit *le_fiscale;
    QPushButton *pb_reduction;
    QLineEdit *png;
    QPushButton *PNG;
    QLabel *label_9;
    QWidget *tab_5;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLineEdit *server;
    QLineEdit *port;
    QLineEdit *uname;
    QLineEdit *paswd;
    QLineEdit *rcpt;
    QLineEdit *subject;
    QPushButton *sendBtn;
    QPlainTextEdit *msg;
    QLabel *label_18;
    QLineEdit *file;
    QPushButton *browseBtn;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1151, 634);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setEnabled(true);
        tabWidget->setGeometry(QRect(40, 10, 1101, 571));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        groupBox_2 = new QGroupBox(tab);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(30, 0, 1051, 541));
        groupBox_2->setStyleSheet(QStringLiteral(""));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 60, 71, 16));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 100, 56, 16));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 140, 56, 16));
        cd = new QLineEdit(groupBox_2);
        cd->setObjectName(QStringLiteral("cd"));
        cd->setGeometry(QRect(140, 60, 113, 22));
        le_mail = new QLineEdit(groupBox_2);
        le_mail->setObjectName(QStringLiteral("le_mail"));
        le_mail->setGeometry(QRect(140, 100, 113, 22));
        le_adresse = new QLineEdit(groupBox_2);
        le_adresse->setObjectName(QStringLiteral("le_adresse"));
        le_adresse->setGeometry(QRect(140, 140, 113, 22));
        le_ajouter = new QPushButton(groupBox_2);
        le_ajouter->setObjectName(QStringLiteral("le_ajouter"));
        le_ajouter->setGeometry(QRect(30, 310, 93, 28));
        pb_modifier = new QPushButton(groupBox_2);
        pb_modifier->setObjectName(QStringLiteral("pb_modifier"));
        pb_modifier->setGeometry(QRect(150, 310, 93, 28));
        le_sexe = new QLineEdit(groupBox_2);
        le_sexe->setObjectName(QStringLiteral("le_sexe"));
        le_sexe->setGeometry(QRect(140, 190, 113, 22));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 190, 56, 16));
        le_nbr = new QLineEdit(groupBox_2);
        le_nbr->setObjectName(QStringLiteral("le_nbr"));
        le_nbr->setGeometry(QRect(140, 240, 113, 22));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(0, 240, 131, 20));
        tab_client = new QTableView(groupBox_2);
        tab_client->setObjectName(QStringLiteral("tab_client"));
        tab_client->setGeometry(QRect(350, 110, 651, 281));
        trier = new QPushButton(groupBox_2);
        trier->setObjectName(QStringLiteral("trier"));
        trier->setGeometry(QRect(30, 370, 93, 28));
        le_PDF = new QPushButton(groupBox_2);
        le_PDF->setObjectName(QStringLiteral("le_PDF"));
        le_PDF->setGeometry(QRect(150, 370, 93, 28));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 470, 211, 16));
        le_email = new QLineEdit(groupBox_2);
        le_email->setObjectName(QStringLiteral("le_email"));
        le_email->setGeometry(QRect(220, 470, 113, 22));
        le_chercher = new QPushButton(groupBox_2);
        le_chercher->setObjectName(QStringLiteral("le_chercher"));
        le_chercher->setGeometry(QRect(150, 490, 93, 28));
        le_client = new QLineEdit(groupBox_2);
        le_client->setObjectName(QStringLiteral("le_client"));
        le_client->setGeometry(QRect(440, 460, 113, 22));
        afficheur = new QPushButton(groupBox_2);
        afficheur->setObjectName(QStringLiteral("afficheur"));
        afficheur->setGeometry(QRect(460, 490, 93, 28));
        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(600, 460, 141, 20));
        le_supp_code = new QLineEdit(groupBox_2);
        le_supp_code->setObjectName(QStringLiteral("le_supp_code"));
        le_supp_code->setGeometry(QRect(750, 460, 113, 22));
        pb_supprimer = new QPushButton(groupBox_2);
        pb_supprimer->setObjectName(QStringLiteral("pb_supprimer"));
        pb_supprimer->setGeometry(QRect(690, 490, 93, 28));
        le_stat = new QPushButton(groupBox_2);
        le_stat->setObjectName(QStringLiteral("le_stat"));
        le_stat->setGeometry(QRect(400, 60, 93, 28));
        verticalLayoutWidget_2 = new QWidget(groupBox_2);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(570, 50, 221, 41));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(-20, -10, 1091, 591));
        label_10->setPixmap(QPixmap(QString::fromUtf8("../../images/background.jpg")));
        label_10->raise();
        label_5->raise();
        label_6->raise();
        label_7->raise();
        cd->raise();
        le_mail->raise();
        le_adresse->raise();
        le_ajouter->raise();
        pb_modifier->raise();
        le_sexe->raise();
        label_2->raise();
        le_nbr->raise();
        label_4->raise();
        tab_client->raise();
        trier->raise();
        le_PDF->raise();
        label_3->raise();
        le_email->raise();
        le_chercher->raise();
        le_client->raise();
        afficheur->raise();
        label->raise();
        le_supp_code->raise();
        pb_supprimer->raise();
        le_stat->raise();
        verticalLayoutWidget_2->raise();
        tabWidget->addTab(tab, QString());
        tab4 = new QWidget();
        tab4->setObjectName(QStringLiteral("tab4"));
        horizontalFrame = new QFrame(tab4);
        horizontalFrame->setObjectName(QStringLiteral("horizontalFrame"));
        horizontalFrame->setGeometry(QRect(10, 70, 801, 341));
        horizontalLayout_2 = new QHBoxLayout(horizontalFrame);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        tabWidget->addTab(tab4, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        label_8 = new QLabel(tab_4);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(200, 100, 131, 16));
        le_fiscale = new QLineEdit(tab_4);
        le_fiscale->setObjectName(QStringLiteral("le_fiscale"));
        le_fiscale->setGeometry(QRect(360, 100, 113, 22));
        pb_reduction = new QPushButton(tab_4);
        pb_reduction->setObjectName(QStringLiteral("pb_reduction"));
        pb_reduction->setGeometry(QRect(260, 170, 151, 28));
        png = new QLineEdit(tab_4);
        png->setObjectName(QStringLiteral("png"));
        png->setGeometry(QRect(360, 230, 113, 22));
        PNG = new QPushButton(tab_4);
        PNG->setObjectName(QStringLiteral("PNG"));
        PNG->setGeometry(QRect(290, 290, 93, 28));
        label_9 = new QLabel(tab_4);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(260, 230, 56, 16));
        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        label_11 = new QLabel(tab_5);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(60, 30, 91, 20));
        label_12 = new QLabel(tab_5);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(60, 80, 91, 20));
        label_13 = new QLabel(tab_5);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(60, 130, 91, 20));
        label_14 = new QLabel(tab_5);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(60, 180, 81, 20));
        label_15 = new QLabel(tab_5);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(60, 220, 81, 20));
        label_16 = new QLabel(tab_5);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(60, 270, 81, 20));
        label_17 = new QLabel(tab_5);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(45, 370, 81, 20));
        server = new QLineEdit(tab_5);
        server->setObjectName(QStringLiteral("server"));
        server->setGeometry(QRect(190, 30, 501, 21));
        port = new QLineEdit(tab_5);
        port->setObjectName(QStringLiteral("port"));
        port->setGeometry(QRect(190, 80, 511, 22));
        uname = new QLineEdit(tab_5);
        uname->setObjectName(QStringLiteral("uname"));
        uname->setGeometry(QRect(190, 130, 511, 22));
        paswd = new QLineEdit(tab_5);
        paswd->setObjectName(QStringLiteral("paswd"));
        paswd->setGeometry(QRect(180, 180, 511, 22));
        rcpt = new QLineEdit(tab_5);
        rcpt->setObjectName(QStringLiteral("rcpt"));
        rcpt->setGeometry(QRect(180, 220, 511, 22));
        subject = new QLineEdit(tab_5);
        subject->setObjectName(QStringLiteral("subject"));
        subject->setGeometry(QRect(180, 270, 511, 22));
        sendBtn = new QPushButton(tab_5);
        sendBtn->setObjectName(QStringLiteral("sendBtn"));
        sendBtn->setGeometry(QRect(750, 490, 93, 28));
        msg = new QPlainTextEdit(tab_5);
        msg->setObjectName(QStringLiteral("msg"));
        msg->setGeometry(QRect(180, 376, 521, 141));
        label_18 = new QLabel(tab_5);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(60, 320, 56, 16));
        file = new QLineEdit(tab_5);
        file->setObjectName(QStringLiteral("file"));
        file->setGeometry(QRect(170, 330, 511, 22));
        browseBtn = new QPushButton(tab_5);
        browseBtn->setObjectName(QStringLiteral("browseBtn"));
        browseBtn->setGeometry(QRect(720, 330, 93, 28));
        tabWidget->addTab(tab_5, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1151, 26));
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
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Ajout", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Code_fiscale", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "Mail", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "Adresse", Q_NULLPTR));
        le_ajouter->setText(QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        pb_modifier->setText(QApplication::translate("MainWindow", "modifier", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Sexe", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Nombre de commande", Q_NULLPTR));
        trier->setText(QApplication::translate("MainWindow", "trier", Q_NULLPTR));
        le_PDF->setText(QApplication::translate("MainWindow", "exporter PDF", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "rechercher selon l'adresse mail:", Q_NULLPTR));
        le_chercher->setText(QApplication::translate("MainWindow", "chercher", Q_NULLPTR));
        afficheur->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Code fiscale du client:", Q_NULLPTR));
        pb_supprimer->setText(QApplication::translate("MainWindow", "Supprimer", Q_NULLPTR));
        le_stat->setText(QApplication::translate("MainWindow", "statistiques", Q_NULLPTR));
        label_10->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Ajouter un client", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab4), QApplication::translate("MainWindow", "statistiques des commandes", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "Code fiscale du client:", Q_NULLPTR));
        pb_reduction->setText(QApplication::translate("MainWindow", "calculer reduction", Q_NULLPTR));
        PNG->setText(QApplication::translate("MainWindow", "exporter PNG", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "le code:", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "reduction et facture", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "stmp server:", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "Server port:", Q_NULLPTR));
        label_13->setText(QApplication::translate("MainWindow", "Username:", Q_NULLPTR));
        label_14->setText(QApplication::translate("MainWindow", "Password:", Q_NULLPTR));
        label_15->setText(QApplication::translate("MainWindow", "Recipant to:", Q_NULLPTR));
        label_16->setText(QApplication::translate("MainWindow", "Subject:", Q_NULLPTR));
        label_17->setText(QApplication::translate("MainWindow", "Message:", Q_NULLPTR));
        server->setText(QApplication::translate("MainWindow", "smtp.gmail.com", Q_NULLPTR));
        port->setText(QApplication::translate("MainWindow", "465", Q_NULLPTR));
        sendBtn->setText(QApplication::translate("MainWindow", "Send", Q_NULLPTR));
        label_18->setText(QApplication::translate("MainWindow", "Browse:", Q_NULLPTR));
        browseBtn->setText(QApplication::translate("MainWindow", "Browse...", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("MainWindow", "Email", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
