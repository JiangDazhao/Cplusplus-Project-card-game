#include "choosegameinterface.h"
#include <QPixmap>

ChooseGameInterface::ChooseGameInterface(QWidget *parent):
    QGraphicsView (parent)
{
    //scene
    m_scene = new QGraphicsScene;
    m_scene ->setSceneRect(0,0,WindowWidth,WindowHeight);

    //btn
    rumen_btn = new MyButton();
    jinjie_btn = new MyButton;
    kunnan_btn = new MyButton;
    zhuanjia_btn = new MyButton;
    fengkuang_btn = new MyButton;

    rumen = new QGraphicsWidget;
    jinjie = new QGraphicsWidget;
    kunnan = new QGraphicsWidget;
     zhuanjia = new QGraphicsWidget;
     fengkuang = new QGraphicsWidget;

    rumen_btn->pix_leave = new QPixmap(":/images/Widgets/rumen.png");
    rumen_btn->pix_cover = new QPixmap(":/images/Widgets/rumen_blue.png");
    rumen_btn->setIcon(*rumen_btn->pix_leave);
    rumen_btn->setIconSize(QSize(180,80));
    rumen_btn->setFixedSize(130,30);

    jinjie_btn->pix_leave = new QPixmap(":/images/Widgets/jinjie.png");
   jinjie_btn->pix_cover = new QPixmap(":/images/Widgets/jinjie_blue.png");
    jinjie_btn->setIcon(*jinjie_btn->pix_leave);
    jinjie_btn->setIconSize(QSize(180,80));
    jinjie_btn->setFixedSize(130,30);

    kunnan_btn->pix_leave = new QPixmap(":/images/Widgets/kunnan.png");
    kunnan_btn->pix_cover= new QPixmap(":/images/Widgets/kunnan_blue.png");
    kunnan_btn->setIcon(*kunnan_btn->pix_leave);
    kunnan_btn->setIconSize(QSize(180,80));
    kunnan_btn->setFixedSize(130,30);

    zhuanjia_btn->pix_leave = new QPixmap(":/images/Widgets/zhuanjia.png");
   zhuanjia_btn->pix_cover = new QPixmap(":/images/Widgets/zhuanjia_blue.png");
    zhuanjia_btn->setIcon(*zhuanjia_btn->pix_leave);
    zhuanjia_btn->setIconSize(QSize(180,80));
    zhuanjia_btn->setFixedSize(130,30);


    fengkuang_btn->pix_leave = new QPixmap(":/images/Widgets/fengkuang.png");
   fengkuang_btn->pix_cover = new QPixmap(":/images/Widgets/fengkuang_blue.png");
    fengkuang_btn->setIcon(*fengkuang_btn->pix_leave);
    fengkuang_btn->setIconSize(QSize(180,80));
    fengkuang_btn->setFixedSize(130,30);

    fengkuang_btn->move(900,700);
    zhuanjia_btn->move(900,550);
    kunnan_btn->move(900,400);
    jinjie_btn->move(900,250);
    rumen_btn->move(900,100);

    rumen =  m_scene->addWidget(rumen_btn);
    zhuanjia =  m_scene->addWidget(zhuanjia_btn);
    kunnan = m_scene->addWidget(kunnan_btn);
    jinjie = m_scene->addWidget(jinjie_btn);
    fengkuang = m_scene->addWidget(fengkuang_btn);
    //setBackground
    QPixmap *bkg = new QPixmap(":/images/Background/choosegameinterface.png");
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
void ChooseGameInterface::keyPressEvent(QKeyEvent * event){

    if (event->key()==Qt::Key_Escape){
            this->close();
            this->MusicOff();}
}
void ChooseGameInterface::Musicon(){
    player=new QMediaPlayer();
   player->setVolume(100);
   player->setMedia(QUrl("qrc:/music/Music/background_music/Immediate.mp3"));
    player->play();
}
void ChooseGameInterface::MusicOff(){
    player->stop();
}

