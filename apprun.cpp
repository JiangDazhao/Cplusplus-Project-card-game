#include"apprun.h"
AppRun::AppRun(){

     welcomeinterface=new WelcomeInterface;
     aboutusinterface=new AboutUsInterface;
     aboutgameinterface=new AboutGameInterface;
     choosegameinterface=new ChooseGameInterface;
     deskinterface=new DeskInterface;
     //welcomeinterface
     connect(this,SIGNAL(Start()),this,SLOT(draw_welcomeinterface()));
     connect(welcomeinterface->start_btn,SIGNAL(clicked()),
             this,SLOT(GameStart()));
     connect(welcomeinterface->choose_game_btn,SIGNAL(clicked()),
             this,SLOT(draw_choosegameinterface()));
     connect(welcomeinterface->about_us_btn,SIGNAL(clicked()),
             this,SLOT(draw_aboutusinterface()));
     connect(welcomeinterface->about_game_btn,SIGNAL(clicked()),
             this,SLOT(draw_aboutgameinterface()));
     //choosegameinterface
     connect(choosegameinterface->rumen_btn,SIGNAL(clicked()),
             this,SLOT(Setdesk1()));
     connect(choosegameinterface->rumen_btn,SIGNAL(clicked()),
              this,SLOT(GameStart()));

      connect(choosegameinterface->rumen_btn,SIGNAL(clicked()),
              this,SLOT(close_choosegameinterface()));

      connect(choosegameinterface->jinjie_btn,SIGNAL(clicked()),
              this,SLOT(Setdesk2()));
      connect(choosegameinterface->jinjie_btn,SIGNAL(clicked()),
              this,SLOT(GameStart()));
      connect(choosegameinterface->jinjie_btn,SIGNAL(clicked()),
              this,SLOT(close_choosegameinterface()));


      connect(choosegameinterface->kunnan_btn,SIGNAL(clicked()),
              this,SLOT(GameStart()));
      connect(choosegameinterface->kunnan_btn,SIGNAL(clicked()),
              this,SLOT(close_choosegameinterface()));
      connect(choosegameinterface->kunnan_btn,SIGNAL(clicked()),
              this,SLOT(Setdesk3()));

      connect(choosegameinterface->zhuanjia_btn,SIGNAL(clicked()),
              this,SLOT(GameStart()));
      connect(choosegameinterface->zhuanjia_btn,SIGNAL(clicked()),
              this,SLOT(close_choosegameinterface()));
      connect(choosegameinterface->zhuanjia_btn,SIGNAL(clicked()),
              this,SLOT(Setdesk4()));

      connect(choosegameinterface->fengkuang_btn,SIGNAL(clicked()),
              this,SLOT(GameStart()));
      connect(choosegameinterface->fengkuang_btn,SIGNAL(clicked()),
              this,SLOT(close_choosegameinterface()));
      connect(choosegameinterface->fengkuang_btn,SIGNAL(clicked()),
              this,SLOT(Setdesk5()));

     //deskinterface
          connect(deskinterface,SIGNAL(back()),this,SLOT(draw_welcomeinterface()));
     //aboutgameinterface
     connect(aboutgameinterface->back_btn,SIGNAL(clicked()),
             this,SLOT(close_aboutgameinterface()));
     //aboutusinterface
     connect(aboutusinterface->back_btn,SIGNAL(clicked()),
             this,SLOT(close_aboutusinterface()));
     //gameendinterface
     connect(deskinterface->gameendinterface1->restart_game_btn,SIGNAL(clicked()),this,SLOT(NewGame()));
     connect(deskinterface->gameendinterface1->quit_game_btn,SIGNAL(clicked()),this,SLOT(GameEnd()));
     connect(deskinterface->gameendinterface2->restart_game_btn,SIGNAL(clicked()),this,SLOT(NewGame()));
     connect(deskinterface->gameendinterface2->quit_game_btn,SIGNAL(clicked()),this,SLOT(GameEnd()));
}
void AppRun::draw_welcomeinterface(){
    welcomeinterface->show();
    welcomeinterface->Musicon();
}
void AppRun::draw_choosegameinterface(){
    choosegameinterface->show();
    choosegameinterface->showFullScreen ();
}
void AppRun::draw_aboutusinterface(){
    aboutusinterface->show();
    aboutusinterface->showFullScreen ();
    aboutusinterface->Musicon();
    welcomeinterface->MusicOff();
}
void AppRun::draw_aboutgameinterface(){
    aboutgameinterface->show();
    aboutgameinterface->showFullScreen ();
    aboutgameinterface->Musicon();
    welcomeinterface->MusicOff();
}

void AppRun::close_choosegameinterface(){
    choosegameinterface->close();
    choosegameinterface->MusicOff();
}
void AppRun::close_aboutusinterface(){
    aboutusinterface->close();
     aboutusinterface->MusicOff();
}
void AppRun::close_aboutgameinterface(){
    aboutgameinterface->close();
     aboutgameinterface->MusicOff();
}

void AppRun::GameStart(){
    welcomeinterface->close();
    welcomeinterface->MusicOff();
    deskinterface->show();//emit newgame.Start();
    deskinterface->showFullScreen ();
    deskinterface->Musicon();
}
void AppRun::NewGame(){
    delete deskinterface;
    deskinterface=new DeskInterface;
    deskinterface->show();//emit newgame.Start();
    deskinterface->showFullScreen ();
    deskinterface->Musicon();
}
void AppRun::GameEnd(){
    deskinterface->gameendinterface1->close();
    deskinterface->gameendinterface2->close();
    draw_welcomeinterface();
}
void AppRun::Setdesk1(){
    deskinterface->set_deskground(1);
}
void AppRun::Setdesk2(){
    deskinterface->set_deskground(2);
}
void AppRun::Setdesk3(){
    deskinterface->set_deskground(3);
}
void AppRun::Setdesk4(){
    deskinterface->set_deskground(4);
}
void AppRun::Setdesk5(){
    deskinterface->set_deskground(5);
}

