#include "aboutgameinterface.h"
#include <QPixmap>
AboutGameInterface::AboutGameInterface(QWidget *parent):
    QGraphicsView (parent)
{
    //scene
    m_scene = new QGraphicsScene;
    m_scene ->setSceneRect(0,0,WindowWidth,WindowHeight);

    //btn**需要设置返回welcomeinterface的槽
    back_btn = new MyButton();
    back_btn->pix_leave = new QPixmap(":/images/Widgets/back.png");
    back_btn->pix_cover = new QPixmap(":/images/Widgets/back_blue.png");
    back_btn->setIcon(*back_btn->pix_leave);
    back_btn->setIconSize(QSize(180,80));
    back_btn->setFixedSize(130,30);
    back = m_scene->addWidget(back_btn);
    back_btn->move(1600,800);


    back_btn->pix_leave = new QPixmap(":/images/Widgets/back.png");
    back_btn->pix_cover = new QPixmap(":/images/Widgets/back_blue.png");
    back_btn->setIcon(*back_btn->pix_leave);
    back_btn->setIconSize(QSize(180,80));
    back_btn->setFixedSize(130,30);//！！！！！！！！！！还没有设计方位

    //还需要添加文字！！！！！！！！！！！！！！
    QGraphicsSimpleTextItem *simpleTextItem1 = new QGraphicsSimpleTextItem;

        simpleTextItem1->setBrush(Qt::red);

        simpleTextItem1->setText("游戏介绍：《Twisted_fate》中文名：命运之牌。 ");

        simpleTextItem1->setFont(QFont("华文琥珀", 25));

      simpleTextItem1->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
        simpleTextItem1->setPos(QPointF(250, 250));
        m_scene->addItem(simpleTextItem1);
    //换行
        QGraphicsSimpleTextItem *simpleTextItem2 = new QGraphicsSimpleTextItem;

            simpleTextItem2->setBrush(Qt::red);

            simpleTextItem2->setText("1.本游戏共有14种、60张卡牌，卡牌按照类别又可分为攻击、防御、回复、奥秘、获取牌。 ");

            simpleTextItem2->setFont(QFont("华文琥珀", 20));

          simpleTextItem2->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
            simpleTextItem2->setPos(QPointF(250, 300));
            m_scene->addItem(simpleTextItem2);

            QGraphicsSimpleTextItem *simpleTextItem3 = new QGraphicsSimpleTextItem;

                simpleTextItem3->setBrush(Qt::red);

                simpleTextItem3->setText("2.第一回合先手得4张牌，后手得6张牌，以后每回合各发一张牌。出牌会消耗魔力，每回合");

                simpleTextItem3->setFont(QFont("华文琥珀", 20));

              simpleTextItem3->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
                simpleTextItem3->setPos(QPointF(250, 350));
                m_scene->addItem(simpleTextItem3);

                QGraphicsSimpleTextItem *simpleTextItem4 = new QGraphicsSimpleTextItem;

                    simpleTextItem4->setBrush(Qt::red);

                    simpleTextItem4->setText("回复5点魔力。");

                    simpleTextItem4->setFont(QFont("华文琥珀", 20));

                  simpleTextItem4->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
                    simpleTextItem4->setPos(QPointF(250, 400));
                    m_scene->addItem(simpleTextItem4);

                    QGraphicsSimpleTextItem *simpleTextItem5 = new QGraphicsSimpleTextItem;

                        simpleTextItem5->setBrush(Qt::red);

                        simpleTextItem5->setText("3.本回合出牌阶段，对方不能出牌（除需判定的手牌需对方响应外）。不同卡牌对魔力的");

                        simpleTextItem5->setFont(QFont("华文琥珀", 20));

                      simpleTextItem5->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
                        simpleTextItem5->setPos(QPointF(250, 450));
                        m_scene->addItem(simpleTextItem5);

                        QGraphicsSimpleTextItem *simpleTextItem6 = new QGraphicsSimpleTextItem;

                            simpleTextItem6->setBrush(Qt::red);

                            simpleTextItem6->setText("消耗也不同，合理选择出牌组合，才能对对手造成最大伤害，血量先为零的一方失败。");

                            simpleTextItem6->setFont(QFont("华文琥珀", 20));

                          simpleTextItem6->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
                            simpleTextItem6->setPos(QPointF(250, 500));
                            m_scene->addItem(simpleTextItem6);

    //setBackground
    QPixmap *bkg = new QPixmap(":/images/Background/guanyuyouxi.png");
    setAutoFillBackground(true);
    QPixmap nbkg = bkg->scaled(QSize(WindowWidth,WindowHeight));
    setBackgroundBrush(nbkg);
    //setbackmusic
    player=new QMediaPlayer();
    player->setMedia(QUrl("qrc:/music/Music/change.mp3"));
   player->setVolume(100);
    player->play();
    //setScene
    setScene(m_scene);
    resize(WindowWidth,WindowHeight);
    setWindowFlags(Qt::FramelessWindowHint);

}
void AboutGameInterface::keyPressEvent(QKeyEvent * event){

    if (event->key()==Qt::Key_Escape){
            this->close();
        this->MusicOff();
    }
}
void AboutGameInterface::Musicon(){
    player=new QMediaPlayer();
   player->setVolume(100);
   player->setMedia(QUrl("qrc:/music/Music/background_music/Promise.mp3"));
    player->play();
}
void AboutGameInterface::MusicOff(){
    player->stop();
}


