#ifndef APPRUN_H
#define APPRUN_H
#include"welcomeinterface.h"
#include"aboutgameinterface.h"
#include"aboutusinterface.h"
#include"gamestart.h"
#include"dealcard.h"
#include"choosegameinterface.h"
#include"deskinterface.h"
#include <QTime>
class AppRun:public QObject{
Q_OBJECT
public:
    AppRun();
    WelcomeInterface *welcomeinterface;
    AboutUsInterface *aboutusinterface;
    AboutGameInterface *aboutgameinterface;
    ChooseGameInterface *choosegameinterface;
    DeskInterface*deskinterface;
    GameEndInterface1*gameendinterface1;
    GameEndInterface2*gameendinterface2;
signals:
void Start();
void back();
private slots:
    void draw_welcomeinterface();
    void draw_aboutusinterface();
    void draw_aboutgameinterface();
    void draw_choosegameinterface();

    void close_choosegameinterface();
    void close_aboutusinterface();
    void close_aboutgameinterface();

    void GameEnd();
    void GameStart();
    void NewGame();
    void Setdesk1();
    void Setdesk2();
    void Setdesk3();
    void Setdesk4();
    void Setdesk5();

};

#endif // APPRUN_H
