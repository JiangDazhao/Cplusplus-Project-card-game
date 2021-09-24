#ifndef GAMEENDINTERFACE_H
#define GAMEENDINTERFACE_H
#include<QGraphicsView>
#include"mybutton.h"
#include<QMediaPlayer>
#include<QGraphicsScene>
#include<QString>
#include<QPalette>
#include<QGraphicsWidget>
#include <QGraphicsProxyWidget>
#include<QGraphicsOpacityEffect>
#define WindowWidth 1915
#define WindowHeight 1075

class GameEndInterface:public QGraphicsView{
    Q_OBJECT
private:
    QString MusicDir;
    QString ImageDir;
public:

    explicit GameEndInterface(QWidget *parent = 0);

     QGraphicsScene *end_scene;
    void setMusicDir();
    QString getMusicDir();
    void setImageDir();
    QString getImageDir();
    MyButton *restart_game_btn;
    MyButton *quit_game_btn;
    QGraphicsWidget *restart_game;
    QGraphicsWidget *quit_game;
    QMediaPlayer*player;
    void Musicon();
    void MusicOff();
protected:
    void keyPressEvent(QKeyEvent *event); //键盘按下ESC退出
};

#endif // GAMEENDINTERFACE_H
