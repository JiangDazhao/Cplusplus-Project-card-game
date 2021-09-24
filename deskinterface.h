#ifndef DESKINTERFACE_H
#define DESKINTERFACE_H
#include<QGraphicsView>
#include"mybutton.h"
#include<QMediaPlayer>
#include<QGraphicsScene>
#include<QGraphicsWidget>
#include <QGraphicsProxyWidget>
#include"gamestart.h"
#include"gameendinterface1.h"
#include"gameendinterface2.h"
#include<QLabel>
#include<QGraphicsItem>

#define WindowWidth 1915
#define WindowHeight 1075

class DeskInterface:public QGraphicsView{
    Q_OBJECT
private:
    int handcard[10];
    int unusedcardpooln;
    int handcardn;
    int lasthandcardn;
    int aihandcardn;
    int   deskcard;
    int usedcardpooln;
    int AI_MPn;
    int AI_HPn;
    int My_MPn;
    int My_HPn;
    int result;
    int cardid;
    int clicked_card;
    int Deskground;
    QString deskdir;
    QString CardDir_leave[10];
    QString CardDir_cover[10];
    QString lastCardDir_leave;
    QString lastCardDir_cover;
public:

    explicit DeskInterface(QWidget *parent = 0);

    QGraphicsTextItem*AI_HP;
    QGraphicsTextItem*AI_MP;
    QGraphicsTextItem*My_HP;
    QGraphicsTextItem*My_MP;
    QGraphicsTextItem*unusedcardpool;
    QGraphicsTextItem*usedcardpool;
    QGraphicsTextItem*aihand;
    QGraphicsScene *desk_scene;

    QMediaPlayer*player;
    MyButton *play_card_btn;
    MyButton *cancle_btn;
    MyButton*skip_btn;
    MyButton*card_btn[10];
    MyButton*center_btn;
    QGraphicsWidget *card[10];
    QGraphicsWidget *center;
    QGraphicsWidget*skip;
    GameEndInterface1 *gameendinterface1;
    GameEndInterface2*gameendinterface2;
    Gamestart newgame;
    void Musicon();
    void MusicOff();
    void sendItem();
    void deleteItem();
    void AI_turn();
    void printcard();
    void draw_gameendinterface(int n);
    void mousePressEvent(QMouseEvent *event);
    void set_deskground(int n);
    void set_deskdir(QString s);
    void set_desk();
protected:
    void keyPressEvent(QKeyEvent *event); //键盘按下ESC退出
signals:
    void start_printcenter();
    void back();
private slots:
    void PlayCard();
    void printcenter();
};

#endif // DESKINTERFACE_H
