#ifndef WELCOMEINTERFACE_H
#define WELCOMEINTERFACE_H

#include <QGraphicsView>
#include <QGraphicsWidget>
#include <QGraphicsScene>
#include "mybutton.h"
#include <QGraphicsProxyWidget>
#include<QtMultimedia/QMediaPlayer>
#include<QMediaPlaylist>

#define WindowWidth 1915
#define WindowHeight 1075

class WelcomeInterface :public QGraphicsView
{
    Q_OBJECT

public:

    explicit WelcomeInterface(QWidget *parent = 0);

    QGraphicsScene *m_scene;
    MyButton *start_btn;
    MyButton *about_game_btn;
    MyButton *choose_game_btn;
    MyButton *about_us_btn;
    QGraphicsWidget *start;
    QGraphicsWidget *about_game;
    QGraphicsWidget *choose_game;
    QGraphicsWidget *about_us;
    QMediaPlaylist*playlist;
    QMediaPlayer*player;
    void Musicon();
    void MusicOff();
protected:
    void keyPressEvent(QKeyEvent *event); //键盘按下ESC退出
};

#endif // WELCOMEINTERFACE_H
