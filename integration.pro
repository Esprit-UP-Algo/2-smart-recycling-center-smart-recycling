QT       += core gui sql
QT += core
QT += charts
QT += widgets
QT +=core gui printsupport
QT +=serialport
QT += core gui network
QT       += core gui


#LIBS += -L$$PWD / -lssleay32
#LIBS += -L$$PWD / -llibeay32



greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    amine/Atelier_Connexion/ChatManager.cpp \
    amine/Atelier_Connexion/aminef.cpp \
    amine/Atelier_Connexion/chatdialog.cpp \
    amine/Atelier_Connexion/produit.cpp \
    #ines/project ines/project ines/client.cpp \
    #ines/project ines/project ines/connection.cpp \
    #ines/project ines/project ines/smtp.cpp \
    #ines/project ines/project ines/windowali.cpp \
    inesRahrah/inesRahrah/client.cpp \
    inesRahrah/inesRahrah/lcdcontroller.cpp \
    inesRahrah/inesRahrah/smtp.cpp \
    inesRahrah/inesRahrah/windowines.cpp \
    lindaSakouhi/employe.cpp \
    lindaSakouhi/login.cpp \
    lindaSakouhi/windowsakouhi.cpp \
    main.cpp \
    integration.cpp \
    mariem/Atelier_Connexion_/Atelier_Connexion/arduino.cpp \
    mariem/Atelier_Connexion_/Atelier_Connexion/connection.cpp \
    mariem/Atelier_Connexion_/Atelier_Connexion/equipement.cpp \
    mariem/Atelier_Connexion_/Atelier_Connexion/mainwindow.cpp \
    nadhir/commande.cpp \
    nadhir/gestion_commandes.cpp \
    nadhir/notifications.cpp \
    nadhir/qcustomplot.cpp \
    nadhir/statistic.cpp
   # nadhir/nadhiirr/Atelier_Connexion/Atelier_Connexion/commande.cpp \
   # nadhir/nadhiirr/Atelier_Connexion/Atelier_Connexion/pdf.cpp \
   # nadhir/nadhiirr/Atelier_Connexion/Atelier_Connexion/windownadhir.cpp
    # prjines/project ines/project ines/client.cpp \
    #prjines/project ines/project ines/smtp.cpp \
    #prjines/project ines/project ines/windowali.cpp
     #projetInes/connection.cpp
   # nadhir/Atelier_Connexion dh/Atelier_Connexion/Atelier_Connexion/commande.cpp \
    #nadhir/Atelier_Connexion dh/Atelier_Connexion/Atelier_Connexion/pdf.cpp \
    #nadhir/Atelier_Connexion dh/Atelier_Connexion/Atelier_Connexion/windownadhir.cpp

HEADERS += \
    amine/Atelier_Connexion/ChatManager.h \
    amine/Atelier_Connexion/aminef.h \
    amine/Atelier_Connexion/chatdialog.h \
    amine/Atelier_Connexion/produit.h \
    #ines/project ines/project ines/client.h \
    #ines/project ines/project ines/connection.h \
    #ines/project ines/project ines/smtp.h \
    #ines/project ines/project ines/windowali.h \
    inesRahrah/inesRahrah/client.h \
    inesRahrah/inesRahrah/lcdcontroller.h \
    inesRahrah/inesRahrah/smtp.h \
    inesRahrah/inesRahrah/windowines.h \
    integration.h \
    lindaSakouhi/employe.h \
    lindaSakouhi/login.h \
    lindaSakouhi/windowsakouhi.h \
    mariem/Atelier_Connexion_/Atelier_Connexion/arduino.h \
    mariem/Atelier_Connexion_/Atelier_Connexion/connection.h \
    mariem/Atelier_Connexion_/Atelier_Connexion/equipement.h \
    mariem/Atelier_Connexion_/Atelier_Connexion/mainwindow.h \
    nadhir/commande.h \
    nadhir/gestion_commandes.h \
    nadhir/notifications.h \
    nadhir/qcustomplot.h \
    nadhir/statistic.h
    #nadhir/nadhiirr/Atelier_Connexion/Atelier_Connexion/commande.h \
    #nadhir/nadhiirr/Atelier_Connexion/Atelier_Connexion/pdf.h \
    #nadhir/nadhiirr/Atelier_Connexion/Atelier_Connexion/windownadhir.h
    #prjines/project ines/project ines/client.h \
    #prjines/project ines/project ines/smtp.h \
    #prjines/project ines/project ines/windowali.h
    #projetInes/connection.h
    #nadhir/Atelier_Connexion dh/Atelier_Connexion/Atelier_Connexion/commande.h \
    #nadhir/Atelier_Connexion dh/Atelier_Connexion/Atelier_Connexion/pdf.h \
    #nadhir/Atelier_Connexion dh/Atelier_Connexion/Atelier_Connexion/windownadhir.h

FORMS += \
    amine/Atelier_Connexion/aminef.ui \
    #ines/project ines/project ines/windowali.ui \
    inesRahrah/inesRahrah/windowines.ui \
    integration.ui \
    lindaSakouhi/login.ui \
    lindaSakouhi/windowsakouhi.ui \
    mariem/Atelier_Connexion_/Atelier_Connexion/mainwindow.ui \
    nadhir/gestion_commandes.ui \
    nadhir/statistic.ui
   # nadhir/nadhiirr/Atelier_Connexion/Atelier_Connexion/pdf.ui \
   # nadhir/nadhiirr/Atelier_Connexion/Atelier_Connexion/windownadhir.ui
   # nadhir/Atelier_Connexion dh/Atelier_Connexion/Atelier_Connexion/pdf.ui \
   # nadhir/Atelier_Connexion dh/Atelier_Connexion/Atelier_Connexion/windownadhir.ui
   # prjines/project ines/project ines/windowali.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    mariem/Atelier_Connexion_/Atelier_Connexion/mariem.qrc \
    nadhir/Resource.qrc \
    nadhir/image.qrc
    #nadhir/Atelier_Connexion dh/Atelier_Connexion/Atelier_Connexion/photos.qrc

SUBDIRS += \
   # ines/project ines/project ines/inesint.pro \
    mariem/Atelier_Connexion_/Atelier_Connexion/Atelier_Connexion.pro

DISTFILES += \
    #ines/project ines/project ines/libeay32.dll \
    inesRahrah/inesRahrah/libeay32.dll \
    inesRahrah/inesRahrah/ssleay32.dll \
    mariem/Atelier_Connexion_/Atelier_Connexion/Atelier_Connexion.pro.user \
    nadhir/icon_valide.png
