#ifndef CHOOSEGAMEINTERFACE_H
#define CHOOSEGAMEINTERFACE_H

#include <QGraphicsView>
#include <QGraphicsWidget>
#include <QGraphicsScene>
#include "mybutton.h"
#include <QGraphicsProxyWidget>
#include<QtMultimedia/QMediaPlayer>

#define WindowWidth 1915
#define WindowHeight 1075

class ChooseGameInterface :public QGraphicsView
{
    Q_OBJECT

public:

    explicit ChooseGameInterface(QWidget *parent = 0);

    QGraphicsScene *m_scene;
    MyButton *rumen_btn;
    MyButton *jinjie_btn;
    MyButton *kunnan_btn;
    MyButton *zhuanjia_btn;
    MyButton *fengkuang_btn;
    QGraphicsWidget *rumen;
    QGraphicsWidget *jinjie;
    QGraphicsWidget *kunnan;
    QGraphicsWidget *zhuanjia;
    QGraphicsWidget *fengkuang;
    QMediaPlayer*player;
    void Musicon();
    void MusicOff();
protected:
    void keyPressEvent(QKeyEvent *event); //键盘按下ESC退出
};
#endif // CHOOSEGAMEINTERFACE_H
