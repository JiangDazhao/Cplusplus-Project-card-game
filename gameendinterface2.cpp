#include "gameendinterface2.h"
#include <QPixmap>

GameEndInterface2::GameEndInterface2(QWidget *parent):
    QGraphicsView (parent)
{
    //scene
    end_scene = new QGraphicsScene;
    end_scene ->setSceneRect(0,0,WindowWidth,WindowHeight);

    //btn
    restart_game_btn = new MyButton;
    quit_game_btn = new MyButton;


    restart_game_btn->pix_leave = new QPixmap(":/images/Widgets/restart_game.png");
   restart_game_btn->pix_cover = new QPixmap(":/images/Widgets/restart_game_blue.png");
    restart_game_btn->setIcon(*restart_game_btn->pix_leave);
    restart_game_btn->setIconSize(QSize(180,80));
    restart_game_btn->setFixedSize(130,30);

    quit_game_btn->pix_leave = new QPixmap(":/images/Widgets/quit_game.png");
    quit_game_btn->pix_cover = new QPixmap(":/images/Widgets/quit_game_blue.png");
    quit_game_btn->setIcon(*quit_game_btn->pix_leave);
    quit_game_btn->setIconSize(QSize(180,80));
    quit_game_btn->setFixedSize(130,30);

    restart_game_btn->move(750,750);
    quit_game_btn->move(1050,750);

    quit_game =  end_scene->addWidget(quit_game_btn);
    restart_game =  end_scene->addWidget(restart_game_btn);

    //部件透明化
    this->setAttribute(Qt::WA_TranslucentBackground);
    //设置透明度
    QGraphicsOpacityEffect * opacityEffect = new QGraphicsOpacityEffect;
       setGraphicsEffect(opacityEffect);
       opacityEffect->setOpacity(0.8);

       //设置标题栏隐藏
      this->setWindowFlags(Qt::FramelessWindowHint);


    // setBackground(失败图片)
     QPixmap *bkg1 = new QPixmap(":/images/Widgets/defeat.png");
     setAutoFillBackground(true);
     QPixmap nbkg1 = bkg1->scaled(QSize(WindowWidth,WindowHeight));
     setBackgroundBrush(nbkg1);

     //setbackmusic

    //setScene
    setScene(end_scene);
    resize(WindowWidth,WindowHeight);
    setWindowFlags(Qt::FramelessWindowHint);
}
void GameEndInterface2::keyPressEvent(QKeyEvent * event){

    if (event->key()==Qt::Key_Escape){
            this->close();
            this->MusicOff();}
}
void GameEndInterface2::Musicon(){
    player=new QMediaPlayer();
   player->setVolume(100);
   player->setMedia(QUrl("qrc:/music/Music/background_music/RISE.mp3"));
    player->play();
}
void GameEndInterface2::MusicOff(){
    player->stop();
}

