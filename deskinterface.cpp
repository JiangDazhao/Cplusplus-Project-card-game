#include "deskinterface.h"
#include <QPixmap>

DeskInterface::DeskInterface(QWidget *parent):
    QGraphicsView (parent)
{
    gameendinterface1=new GameEndInterface1;
    gameendinterface2=new GameEndInterface2;
    //scene
        desk_scene = new QGraphicsScene;
        //player=new QMediaPlayer;
        desk_scene ->setSceneRect(0,0,WindowWidth,WindowHeight);

        //skip_btn
        skip_btn = new MyButton();
        skip_btn->pix_leave = new QPixmap(":/images/Widgets/skip.png");
        skip_btn->pix_cover = new QPixmap(":/images/Widgets/skip_blue.png");
        skip_btn->setIcon(*skip_btn->pix_leave);
        skip_btn->setIconSize(QSize(180,80));
        skip_btn->setFixedSize(130,30);
        skip_btn->move(880,670);
        skip =  desk_scene->addWidget(skip_btn);

        //setBackground
        Deskground=0;
       /* if(Deskground==1)deskdir=":/images/Background/carddesk1.png";
        if(Deskground==2)deskdir=":/images/Background/carddesk2.png";
        if(Deskground==3)deskdir=":/images/Background/carddesk3.png";
        if(Deskground==4)deskdir=":/images/Background/carddesk4.png";
        if(Deskground==5)deskdir=":/images/Background/carddesk5.png";
        else deskdir=":/images/Background/carddesk1.png";
        QPixmap *bkg = new QPixmap(deskdir);
        setAutoFillBackground(true);
        QPixmap nbkg = bkg->scaled(QSize(WindowWidth,WindowHeight));
        setBackgroundBrush(nbkg);*/
        //setbackmusic
        player=new QMediaPlayer();
        player->setMedia(QUrl("qrc:/music/Music/change.mp3"));
       player->setVolume(100);
        player->play();

        //handcard
        handcardn=0;
        lasthandcardn=0;
        connect(this,SIGNAL(start_printcenter()),this,SLOT(printcenter()));

        //myHP
         My_HPn=20;
         My_HP = new QGraphicsTextItem();
         My_HP->setPlainText(QString::number( My_HPn));
         My_HP->setDefaultTextColor(QColor(131,4,2));
         My_HP->setFont(QFont(0,25));
             My_HP->setPos(QPointF(1600, 650));
             desk_scene->addItem(My_HP);

             QGraphicsSimpleTextItem *simpleTextItem1 = new QGraphicsSimpleTextItem;

                 simpleTextItem1->setBrush(Qt::red);

                 simpleTextItem1->setText("HP:");

                 simpleTextItem1->setFont(QFont("华文琥珀", 25));

                 simpleTextItem1->setPos(QPointF(1500, 655));
                 desk_scene->addItem(simpleTextItem1);

         //myMP
                 My_MPn=20;
                My_MP = new QGraphicsTextItem();
                 My_MP->setPlainText(QString::number(My_MPn));
                 My_MP->setDefaultTextColor(QColor(0,0,255));
                 My_MP->setFont(QFont(0,25));
                    My_MP->setPos(QPointF(1600, 700));
                     desk_scene->addItem(My_MP);

             QGraphicsSimpleTextItem *simpleTextItem2 = new QGraphicsSimpleTextItem;

                 simpleTextItem2->setBrush(Qt::blue);

                 simpleTextItem2->setText("MP:");

                 simpleTextItem2->setFont(QFont("华文琥珀", 25));

                 simpleTextItem2->setPos(QPointF(1500, 705));
                 desk_scene->addItem(simpleTextItem2);

                 //aIHP
                 QGraphicsSimpleTextItem *simpleTextItem3 = new QGraphicsSimpleTextItem;

                     simpleTextItem3->setBrush(Qt::red);

                     simpleTextItem3->setText("HP:");

                     simpleTextItem3->setFont(QFont("华文琥珀", 25));

                     simpleTextItem3->setPos(QPointF(870, 210));
                     desk_scene->addItem(simpleTextItem3);

                  AI_HPn=20;
                  AI_HP = new QGraphicsTextItem();
                  AI_HP->setPlainText(QString::number(  AI_HPn));
                  AI_HP->setDefaultTextColor(QColor(131,4,2));
                  AI_HP->setFont(QFont(0,25));
                      AI_HP->setPos(QPointF(970, 205));
                      desk_scene->addItem(AI_HP);

                  //aiMP
                      QGraphicsSimpleTextItem *simpleTextItem4 = new QGraphicsSimpleTextItem;

                          simpleTextItem4->setBrush(Qt::blue);

                          simpleTextItem4->setText("MP:");

                          simpleTextItem4->setFont(QFont("华文琥珀", 25));

                          simpleTextItem4->setPos(QPointF(870, 255));
                          desk_scene->addItem(simpleTextItem4);

                          AI_MPn=20;
                         AI_MP = new QGraphicsTextItem();
                          AI_MP->setPlainText(QString::number(AI_MPn));
                          AI_MP->setDefaultTextColor(QColor(0,0,255));
                          AI_MP->setFont(QFont(0,25));
                             AI_MP->setPos(QPointF(970, 250));
                              desk_scene->addItem(AI_MP);
   //usedcardpool
         usedcardpooln=0;
        QGraphicsSimpleTextItem *simpleTextItem5 = new QGraphicsSimpleTextItem;

   simpleTextItem5->setBrush(Qt::yellow);

    simpleTextItem5->setText("废牌数：");

      simpleTextItem5->setFont(QFont("华文琥珀", 20));

     simpleTextItem5->setPos(QPointF(425, 525));
   desk_scene->addItem(simpleTextItem5);

 usedcardpooln=0;
  usedcardpool = new QGraphicsTextItem();
   usedcardpool->setPlainText(QString::number(usedcardpooln));
 usedcardpool->setDefaultTextColor(QColor(0,0,0));
    usedcardpool->setFont(QFont(0,25));
    usedcardpool->setPos(QPointF(545, 505));
   desk_scene->addItem(usedcardpool);
 //unusedcardpool
      unusedcardpooln=44;
      QGraphicsSimpleTextItem *simpleTextItem6 = new QGraphicsSimpleTextItem;

  simpleTextItem6->setBrush(Qt::yellow);

       simpleTextItem6->setText("未发牌数：");

     simpleTextItem6->setFont(QFont("华文琥珀", 20));

        simpleTextItem6->setPos(QPointF(1200, 525));
         desk_scene->addItem(simpleTextItem6);

        unusedcardpool = new QGraphicsTextItem();
           unusedcardpool->setPlainText(QString::number( unusedcardpooln));
             unusedcardpool->setDefaultTextColor(QColor(0,0,0));
          unusedcardpool->setFont(QFont(0,25));
     unusedcardpool->setPos(QPointF(1375, 505));
         desk_scene->addItem(unusedcardpool);
         //aihandcardn
         aihandcardn=0;
         QGraphicsSimpleTextItem *simpleTextItem7 = new QGraphicsSimpleTextItem;

     simpleTextItem7->setBrush(Qt::yellow);

          simpleTextItem7->setText("Card：");

        simpleTextItem7->setFont(QFont("华文琥珀", 20));

           simpleTextItem7->setPos(QPointF(850, 330));
            desk_scene->addItem(simpleTextItem7);

           aihand = new QGraphicsTextItem();
              aihand->setPlainText(QString::number( aihandcardn));
                aihand->setDefaultTextColor(QColor(0,0,0));
             aihand->setFont(QFont(0,25));
        aihand->setPos(QPointF(950, 325));
            desk_scene->addItem(aihand);
        //setScene
        setScene(desk_scene);
        resize(WindowWidth,WindowHeight);
        setWindowFlags(Qt::FramelessWindowHint);
    emit newgame.Start();
        set_desk();
    sendItem();
    printcard();
    if(newgame.AIFirst())emit start_printcenter();
}
void DeskInterface::set_desk(){
    //setBackground
    if(Deskground==1)deskdir=":/images/Background/carddesk1.png";
    if(Deskground==2)deskdir=":/images/Background/carddesk2.png";
    if(Deskground==3)deskdir=":/images/Background/carddesk3.png";
    if(Deskground==4)deskdir=":/images/Background/carddesk4.png";
    if(Deskground==5)deskdir=":/images/Background/carddesk5.png";
    else deskdir=":/images/Background/carddesk1.png";
    QPixmap *bkg = new QPixmap(deskdir);
    setAutoFillBackground(true);
    QPixmap nbkg = bkg->scaled(QSize(WindowWidth,WindowHeight));
    setBackgroundBrush(nbkg);
}


void DeskInterface::keyPressEvent(QKeyEvent * event){

    if (event->key()==Qt::Key_Escape){
            this->close();
            this->MusicOff();}
    if(event->key()==Qt::Key_B){
        this->close();
        this->MusicOff();
        emit back();
    }
}

void DeskInterface::Musicon(){
    player=new QMediaPlayer();
   player->setVolume(100);
   player->setMedia(QUrl("qrc:/music/Music/background_music/Gameof.mp3"));
    player->play();
}
void DeskInterface::MusicOff(){
    player->stop();
}
void DeskInterface::printcard(){
    deleteItem();
    My_HP->setPlainText(QString::number( My_HPn));
    My_MP->setPlainText(QString::number(My_MPn));
    AI_HP->setPlainText(QString::number(  AI_HPn));
    AI_MP->setPlainText(QString::number(AI_MPn));
    aihand->setPlainText(QString::number( aihandcardn));
    unusedcardpool->setPlainText(QString::number( unusedcardpooln));
    usedcardpool->setPlainText(QString::number(usedcardpooln));
    for(int i=0;i<handcardn;i++){
        lasthandcardn=handcardn;
        int x=20+i*210;
        card_btn[i]=new MyButton;
        card[i] = new QGraphicsWidget;
        card_btn[i]->pix_leave = new QPixmap(CardDir_leave[i]);
       card_btn[i]->pix_cover = new QPixmap(CardDir_cover[i]);
         card_btn[i]->pix_click = new QPixmap();
        card_btn[i]->setIcon(*card_btn[i]->pix_leave);
        card_btn[i]->setIconSize(QSize(270,405));
        card_btn[i]->setFixedSize(200,285);

        card_btn[i]->move(x,750);
        card[i] =  desk_scene->addWidget(card_btn[i]);
    }
}
void DeskInterface::deleteItem(){
    for(int i=0;i<lasthandcardn;i++){
        desk_scene->removeItem(card[i]);
    }
}

void DeskInterface::printcenter(){
    center_btn=new MyButton;
    center = new QGraphicsWidget;
    center_btn->pix_leave = new QPixmap(lastCardDir_leave);
   center_btn->pix_cover = new QPixmap(lastCardDir_cover);

    center_btn->setIcon(*center_btn->pix_leave);
    center_btn->setIconSize(QSize(270,405));
    center_btn->setFixedSize(200,285);

    center_btn->move(850,370);
    center =  desk_scene->addWidget(center_btn);
}
void DeskInterface::PlayCard(){

}
void DeskInterface::mousePressEvent(QMouseEvent *event)
{
    QGraphicsView::mousePressEvent(event);
    QPoint viewPos = event->pos();
    QPointF scenePos = mapToScene(viewPos);
    QGraphicsItem *selected = scene()->itemAt(scenePos,QTransform());
    int i;
    for (i=0;i<handcardn;i++) {
        if(card[i]==selected){
            clicked_card=i;
            //sendItem();
            newgame.sendCard_i(i);
            newgame.sendCard(handcard[i]);
            newgame.GamerTurn();
            sendItem();
            printcard();
            emit start_printcenter();
            if(result!=-1)draw_gameendinterface(result);
        }
    }
    if(selected==skip){
        newgame.PlayCardA();
        newgame.PlayCardA();
        AI_turn();
    }
}
void DeskInterface::AI_turn(){
    newgame.AITurn();
    sendItem();
    printcard();
    emit start_printcenter();
    //result=newgame.set_result();
   // draw_gameendinterface(result);
}
void DeskInterface::sendItem(){
    result=newgame.set_result();
    handcardn=newgame.set_handcardn();
    unusedcardpooln=newgame.set_unusedcardpooln();
    usedcardpooln=newgame.set_usedcardpooln();
    for(int i=0;i<handcardn;i++)handcard[i]=newgame.set_handcard(i);
    for(int i=0;i<handcardn;i++)CardDir_cover[i]=newgame.dir_cover(newgame.set_handcard(i));
    for(int i=0;i<handcardn;i++)CardDir_leave[i]=newgame.dir_leave(newgame.set_handcard(i));
    deskcard=newgame.set_deskcard();
    lastCardDir_leave=newgame.dir_leave(deskcard);
    lastCardDir_cover=newgame.dir_cover(deskcard);
    aihandcardn=newgame.set_aihandcardn();
    usedcardpooln=newgame.set_usedcardpooln();
    AI_MPn=newgame.set_AI_MP();
    AI_HPn=newgame.set_AI_HP();
    My_MPn=newgame.set_My_MP();
    My_HPn=newgame.set_My_HP();
}
void DeskInterface::draw_gameendinterface(int n){
    if(n==-1)return;
    if(n==1) {
        this->close();
        gameendinterface1->show();}
    if(n==0) {
        this->close();
        gameendinterface2->show();}

}
void DeskInterface::set_deskground(int n){
    Deskground=n;
}
void DeskInterface::set_deskdir(QString s){
    deskdir=s;
}
