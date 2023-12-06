#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include <QCoreApplication>

#include <QSystemTrayIcon>
#include<QString>
class notification
{
public:
    notification();
    void notification_ajoutcommandes();

    void notification_supprimercommandes();

    void notification_modifiercommandes();

void notification_failed();


};



#endif // NOTIFICATION_H
