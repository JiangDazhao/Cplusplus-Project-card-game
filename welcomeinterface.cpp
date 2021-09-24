#include "welcomeinterface.h"
#include <QPixmap>
#include<QMenu>

WelcomeInterface::WelcomeInterface(QWidget *parent):
    QGraphicsView (parent)
{
    //scene
    m_scene = new QGraphicsScene;
    m_scene ->setSceneRect(0,0,WindowWidth,WindowHeight);

    //btn
    start_btn = new MyButton();
    about_game_btn = new MyButton;
    choose_game_btn = new MyButton;
    about_us_btn = new MyButton;

    start = new QGraphicsWidget;
    about_game = new QGraphicsWidget;
     choose_game = new QGraphicsWidget;
     about_us = new QGraphicsWidget;


    start_btn->pix_leave = new QPixmap(":/images/Widgets/begin_game.png");
    start_btn->pix_cover = new QPixmap(":/images/Widgets/begin_game_blue.png");
    start_btn->setIcon(*start_btn->pix_leave);
    start_btn->setIconSize(QSize(180,80));
    start_btn->setFixedSize(130,30);

    about_game_btn->pix_leave = new QPixmap(":/images/Widgets/about_game.png");
   about_game_btn->pix_cover = new QPixmap(":/images/Widgets/about_game_blue.png");
    about_game_btn->setIcon(*about_game_btn->pix_leave);
    about_game_btn->setIconSize(QSize(180,80));
    about_game_btn->setFixedSize(130,30);

    choose_game_btn->pix_leave = new QPixmap(":/images/Widgets/choose_game.png");
    choose_game_btn->pix_cover= new QPixmap(":/images/Widgets/choose_game_blue.png");
    choose_game_btn->setIcon(*choose_game_btn->pix_leave);
    choose_game_btn->setIconSize(QSize(180,80));
    choose_game_btn->setFixedSize(130,30);

    about_us_btn->pix_leave = new QPixmap(":/images/Widgets/about_us.png");
   about_us_btn->pix_cover = new QPixmap(":/images/Widgets/about_us_blue.png");
    about_us_btn->setIcon(*about_us_btn->pix_leave);
    about_us_btn->setIconSize(QSize(180,80));
    about_us_btn->setFixedSize(130,30);

    about_us_btn->move(900,850);
    about_game_btn->move(900,750);
    choose_game_btn->move(900,650);
    start_btn->move(900,550);

    start =  m_scene->addWidget(start_btn);
    about_game =  m_scene->addWidget(about_game_btn);
    choose_game = m_scene->addWidget(choose_game_btn);
    about_us = m_scene->addWidget(about_us_btn);

    //setBackground
    QPixmap *bkg = new QPixmap(":/images/Background/Welcome.png");
    setAutoFillBackground(true);
    QPixmap nbkg = bkg->scaled(QSize(WindowWidth,WindowHeight));
    setBackgroundBrush(nbkg);
    //setScene
    setScene(m_scene);
    resize(WindowWidth,WindowHeight);
    setWindowFlags(Qt::FramelessWindowHint);
    showFullScreen ();
}
void WelcomeInterface::keyPressEvent(QKeyEvent * event){

    if (event->key()==Qt::Key_Escape){
            this->close();
            this->MusicOff();}
}
void WelcomeInterface::Musicon(){
    player=new QMediaPlayer();
   player->setVolume(100);
   player->setMedia(QUrl("qrc:/music/Music/background_music/change.mp3"));
    player->play();
}
void WelcomeInterface::MusicOff(){
    player->stop();
}

