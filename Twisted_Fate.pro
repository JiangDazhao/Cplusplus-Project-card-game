#-------------------------------------------------
#
# Project created by QtCreator 2019-08-28T15:52:18
#
#-------------------------------------------------

QT       += core gui
QT       +=multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Twisted_Fate
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11
CONFIG += resources_big
SOURCES += \
        main.cpp \
    gameplayer.cpp \
    card.cpp \
    welcomeinterface.cpp \
    mybutton.cpp \
    dealcard.cpp \
    aboutusinterface.cpp \
    aboutgameinterface.cpp \
    choosegameinterface.cpp \
    deskinterface.cpp \
    apprun.cpp \
    gamestart.cpp \
    gameendinterface1.cpp \
    gameendinterface2.cpp

HEADERS += \
    card.h \
    welcomeinterface.h \
    gameplayer.h \
    mybutton.h \
    dealcard.h \
    aboutusinterface.h \
    aboutgameinterface.h \
    choosegameinterface.h \
    apprun.h \
    gamestart.h \
    deskinterface.h \
    gameendinterface1.h \
    gameendinterface2.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    src.qrc
