#include "notifications.h"
#include "QApplication"
#include <QSystemTrayIcon>
#include<QString>
notification::notification()
{

}
void notification::notification_ajoutcommandes()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

   notifyIcon->setIcon(QIcon(":/new/prefix1/icon_valide.png"));
   notifyIcon->show();
    notifyIcon->showMessage("Gestion des commandes ","nouveau commandes est ajouté ",QSystemTrayIcon::Information,15000);
    srand (time(NULL));
}

void notification::notification_supprimercommandes(){
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

   notifyIcon->setIcon(QIcon(":/new/prefix1/icon_valide.png"));
   notifyIcon->show();
    notifyIcon->showMessage("Gestion des commandes","commandes est supprimé",QSystemTrayIcon::Information,15000);
srand (time(NULL));
}


void notification::notification_modifiercommandes(){
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

   notifyIcon->setIcon(QIcon(":/new/prefix1/icon_valide.png"));
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des commandes ","commandes est modifié",QSystemTrayIcon::Information,15000);
srand (time(NULL));
}


void notification::notification_failed(){
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

   //notifyIcon->setIcon(QIcon(":/new/prefix1/MyResources/computer-icons-avatar-user-login-avatar.jpg"));
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des commandes ","action failed",QSystemTrayIcon::Critical,15000);
srand (time(NULL));
}



















