#include "aboutusinterface.h"
#include <QPixmap>
AboutUsInterface::AboutUsInterface(QWidget *parent):
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
    //文字
    QGraphicsSimpleTextItem *simpleTextItem1 = new QGraphicsSimpleTextItem;

        simpleTextItem1->setBrush(Qt::red);

        simpleTextItem1->setText("设计人员：王迪  qq:1289580847  tel:19852858105 ");

        simpleTextItem1->setFont(QFont("华文琥珀", 25));

      simpleTextItem1->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
        simpleTextItem1->setPos(QPointF(250, 250));
        m_scene->addItem(simpleTextItem1);
    //换行
        QGraphicsSimpleTextItem *simpleTextItem2 = new QGraphicsSimpleTextItem;

            simpleTextItem2->setBrush(Qt::red);

            simpleTextItem2->setText("蒋旭钊  qq:1169872430  tel:1982500890 ");

            simpleTextItem2->setFont(QFont("华文琥珀", 25));

          simpleTextItem2->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
            simpleTextItem2->setPos(QPointF(250, 300));
            m_scene->addItem(simpleTextItem2);

            QGraphicsSimpleTextItem *simpleTextItem3 = new QGraphicsSimpleTextItem;

                simpleTextItem3->setBrush(Qt::red);

                simpleTextItem3->setText("李硕  qq:2366752533  tel:13027572400 ");

                simpleTextItem3->setFont(QFont("华文琥珀", 25));

              simpleTextItem3->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
                simpleTextItem3->setPos(QPointF(250, 350));
                m_scene->addItem(simpleTextItem3);

                QGraphicsSimpleTextItem *simpleTextItem4 = new QGraphicsSimpleTextItem;

                    simpleTextItem4->setBrush(Qt::red);

                    simpleTextItem4->setText("抵制不良游戏，拒绝盗版游戏。注意自我保护，谨防上当受骗。");

                    simpleTextItem4->setFont(QFont("华文琥珀", 35));

                  simpleTextItem4->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
                    simpleTextItem4->setPos(QPointF(250, 450));
                    m_scene->addItem(simpleTextItem4);

                    QGraphicsSimpleTextItem *simpleTextItem5 = new QGraphicsSimpleTextItem;

                        simpleTextItem5->setBrush(Qt::red);

                        simpleTextItem5->setText("适度游戏益脑，沉迷游戏伤身。合理安排时间，享受健康生活。");

                        simpleTextItem5->setFont(QFont("华文琥珀", 35));

                      simpleTextItem5->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
                        simpleTextItem5->setPos(QPointF(250, 550));
                        m_scene->addItem(simpleTextItem5);
    //setBackground
    QPixmap *bkg = new QPixmap(":/images/Background/guanyuwomen.png");
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
void AboutUsInterface::keyPressEvent(QKeyEvent * event){

    if (event->key()==Qt::Key_Escape){
            this->close();
            this->MusicOff();}
}
void AboutUsInterface::Musicon(){
    player=new QMediaPlayer();
   player->setVolume(100);
   player->setMedia(QUrl("qrc:/music/Music/background_music/Promise.mp3"));
    player->play();
}
void AboutUsInterface::MusicOff(){
    player->stop();
}
