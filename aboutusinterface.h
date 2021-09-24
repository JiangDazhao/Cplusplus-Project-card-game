#ifndef ABOUTUSINTERFACE_H
#define ABOUTUSINTERFACE_H


#include <QGraphicsView>
#include <QGraphicsWidget>
#include <QGraphicsScene>
#include "mybutton.h"
#include <QGraphicsProxyWidget>
#include<QtMultimedia/QMediaPlayer>
#include<QGraphicsItem>


#define WindowWidth 1915
#define WindowHeight 1075

class AboutUsInterface :public QGraphicsView
{
    Q_OBJECT

public:

    explicit AboutUsInterface(QWidget *parent = 0);

    QGraphicsScene *m_scene;
    MyButton *back_btn;
    QMediaPlayer*player;
    QGraphicsWidget *back;
    void Musicon();
    void MusicOff();
protected:
    void keyPressEvent(QKeyEvent *event); //键盘按下ESC退出
};

#endif // ABOUTUSINTERFACE_H
