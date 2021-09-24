#include"gamestart.h"
Gamestart::Gamestart(){
    gamer=Gameplayer(0);
    AI=Gameplayer(0);
    Turntime=60;
    Gametime=0;
    firstsign=0;
    Clicked_sign=0;
    turnsign=1;
    lastCardID=1;
    CardID=1;
    result=-1;
    yu_mu=0;
    tan_nang_wu_qie=Card(1,4);
    tan_nang_wu_qie.setImageDir(":/images/CardImage/tan_nang_wu_qie.png");
    an_du_chen_cang=Card(2,0);
    an_du_chen_cang.setImageDir(":/images/CardImage/an_du_chen_cang.png");
    yu_mu_hun_zhu=Card(3,6);
    yu_mu_hun_zhu.setImageDir(":/images/CardImage/yu_mu_hun_zhu.png");
    ming_xuan_yi_xian=Card(4,0);
    ming_xuan_yi_xian.setImageDir(":/images/CardImage/ming_xuan_yi_xian.png");
    liang_ji_fan_zhuan=Card(5,6);
    liang_ji_fan_zhuan.setImageDir(":/images/CardImage/liang_ji_fan_zhuan.png");
    po_fu_chen_zhou=Card(6,1);
    po_fu_chen_zhou.setImageDir(":/images/CardImage/po_fu_chen_zhou.png");
    yi_yi_dai_lao=Card(7,2);
    yi_yi_dai_lao.setImageDir(":/images/CardImage/yi_yi_dai_lao.png");
    gu_ruo_jin_tang=Card(8,5);
    gu_ruo_jin_tang.setImageDir(":/images/CardImage/gu_ruo_jin_tang.png");
    qiang_shen_fa_ming=Card(9,2);
    qiang_shen_fa_ming.setImageDir(":/images/CardImage/qiang_shen_fa_ming.png");
    dian_guang_huo_shi=Card(10,5);
    dian_guang_huo_shi.setImageDir(":/images/CardImage/dian_guang_huo_shi.png");
    she_ming_yi_ji=Card(11,2);
    she_ming_yi_ji.setImageDir(":/images/CardImage/she_ming_yi_ji.png");
    miao_shou_hui_chun=Card(12,2);
    miao_shou_hui_chun.setImageDir(":/images/CardImage/miao_shou_hui_chun.png");
    xuan_hu_ji_shi=Card(13,5);
    xuan_hu_ji_shi.setImageDir(":/images/CardImage/xuan_hu_ji_shi.png");
    qi_si_hui_sheng=Card(14,0);
    qi_si_hui_sheng.setImageDir(":/images/CardImage/qi_si_hui_sheng.png");
    //
    connect(this,SIGNAL(Start()),this,SLOT(WhoFirst()));
    //connect(this,SIGNAL(FirstPlay()),this,SLOT(GameStart()));
    //connect(this,SIGNAL(PlayCard()),this,SLOT(WhoTurn()));
};
int Gamestart::set_unusedcardpooln(){
    return cardpool.getCardNumber();
}
int Gamestart::set_handcardn(){
    return gamer.getCardNumber();
}
int Gamestart::set_handcard(int i){
    return gamer.getCard(i);
}
int Gamestart::set_aihandcardn(){
    return AI.getCardNumber();
}
int Gamestart::set_deskcard(){
    return lastCardID;
}
int Gamestart::set_usedcardpooln(){
    return carddust.get_Card_Number();
}
int Gamestart::set_AI_HP(){
    return AI.getHP();
}
int Gamestart::set_AI_MP(){
    return AI.getMP();
}
int Gamestart::set_My_HP(){
    return gamer.getHP();
}
int Gamestart::set_My_MP(){
    return gamer.getMP();
}
int Gamestart::set_result(){
    return result;
}
bool Gamestart::AIFirst(){
    if(firstsign)return true;
    else return false;
}
void Gamestart::sendCard(int n){
    sendCardID=n;
}
void Gamestart::sendCard_i(int i){
    sendCardNumber=i;
}
void Gamestart::PlayCardA(){
    if(!cardpool.isEmpty())AI.setCard(cardpool.DealCard());
}
void Gamestart::PlayCardG(){
    if(!cardpool.isEmpty())gamer.setCard(cardpool.DealCard());
}

void Gamestart::WhoFirst(){
    firstsign=cardpool.getRand()%2;
    if(firstsign){
        for(int i=0;i<4;i++)PlayCardA();
        for(int i=0;i<6;i++)PlayCardG();
        AIPlayCard();
    }
    else{
        for(int i=0;i<4;i++)PlayCardG();
        for(int i=0;i<6;i++)PlayCardA();
    }
}
int Gamestart::get_AI_card(){
    CardNumber=cardpool.getRand()%(AI.getCardNumber());
    return AI.getCard(CardNumber);
}
void Gamestart::GameRun(){
    if(AI.getHP()==0)result=1;
    if (gamer.getHP()==0) result=0;
    if (cardpool.isEmpty()) {
        if(AI.getHP()>gamer.getHP())result=0;
        else {
            result=1;
        }
    }
    if(AI.getHP()>0&&gamer.getHP()>0&&!cardpool.isEmpty()){
        result=-1;
    }
}
void Gamestart::GameEnd(){
    emit End();
}
void Gamestart::AITurn(){
    PlayCardA();
    AI.increaseMP(2);
    CardID=get_AI_card();
    AIPlayCard();
    PlayCardG();
    PlayCardG();
    gamer.increaseMP(2);
    GameRun();
}
void Gamestart::GamerTurn(){
    //PlayCardG();
    CardID=sendCardID;
    gamerPlayCard();
    GameRun();
}
void Gamestart::gamerPlayCard(){
    switch(CardID){
    case 1:
        gamer.setCard(AI.getCard(AI.getCardNumber()-1));
        AI.loseCard();
        gamer.setCard(AI.getCard(AI.getCardNumber()-1));
        AI.loseCard();
        gamer.setCard(sendCardNumber,gamer.getCard(gamer.getCardNumber()-1));
        gamer.loseCard();
        lastCardID=CardID;
        carddust.set_Card();
        break;
    case 2:
        gamer.increaseMP(2);
        gamer.setCard(sendCardNumber,gamer.getCard(gamer.getCardNumber()-1));
        gamer.loseCard();
        lastCardID=CardID;
        carddust.set_Card();
        if(AI.getMP()>2){
            AI.reduceMP(2);
        }
        else {
            AI.setMP(0);
        }
        break;
    case 3:
        if(gamer.getMP()>=6)
        {
            CardID=cardpool.getRand()%14+1;
            gamerPlayCard();
        }
        else {
            //不可出牌
        }
        break;
    case 4:
        //不可出牌
        break;
    case 5:
        CardID=lastCardID;
        gamerPlayCard();
        break;
    case 6:
        if(gamer.getMP()>=1){
            gamer.reduceHP(5);
            gamer.increaseMP(9);
            gamer.setCard(sendCardNumber,gamer.getCard(gamer.getCardNumber()-1));
            gamer.loseCard();
            lastCardID=CardID;
            carddust.set_Card();
        }
        else {
            //法力不足
        }
        break;
    case 7:
        //被动释放
        break;
    case 8:
        if(gamer.getMP()>=5){
            AI.increaseHP(3);
            gamer.reduceMP(5);
            gamer.setCard(sendCardNumber,gamer.getCard(gamer.getCardNumber()-1));
            gamer.loseCard();
            lastCardID=CardID;
            carddust.set_Card();
        }
        else {
            //法力不足
        }
        break;
    case 9:
        if(gamer.getMP()>=2){
            AI.reduceHP(2);
            gamer.reduceMP(2);
            gamer.setCard(sendCardNumber,gamer.getCard(gamer.getCardNumber()-1));
            gamer.loseCard();
            lastCardID=CardID;
            carddust.set_Card();
        }
        else {
            //法力不足
        }
        break;
    case 10:
        if(gamer.getMP()>=5){
            gamer.reduceMP(5);
            AI.reduceHP(5);
            gamer.setCard(sendCardNumber,gamer.getCard(gamer.getCardNumber()-1));
            gamer.loseCard();
            lastCardID=CardID;
            carddust.set_Card();
        }
        else {
            //法力不足
        }
        break;
    case 11:
        if(gamer.getMP()>=2){
            AI.reduceHP(4);
            gamer.reduceHP(1);
            gamer.reduceMP(2);
            gamer.setCard(sendCardNumber,gamer.getCard(gamer.getCardNumber()-1));
            gamer.loseCard();
            lastCardID=CardID;
            carddust.set_Card();
        }
        else {
            //法力不足
        }
        break;
    case 12:
        if(gamer.getMP()>=2){
            gamer.increaseHP(2);
            gamer.reduceMP(2);
            gamer.setCard(sendCardNumber,gamer.getCard(gamer.getCardNumber()-1));
            gamer.loseCard();
            lastCardID=CardID;
            carddust.set_Card();
        }
        else {
            //法力不足
        }
        break;
    case 13:
        if(gamer.getMP()>=5){
            gamer.increaseHP(5);
            gamer.reduceMP(5);
            gamer.setCard(sendCardNumber,gamer.getCard(gamer.getCardNumber()-1));
            gamer.loseCard();
            lastCardID=CardID;
            carddust.set_Card();
        }
        break;
    case 14:
        //不可出牌
        break;
    }
}
void Gamestart::AIPlayCard(){
    switch(CardID){
    case 1:
        if(AI.getMP()>=4){
            AI.reduceMP(4);
            AI.setCard(gamer.getCard(gamer.getCardNumber()));
            gamer.loseCard();
            AI.setCard(gamer.getCard(gamer.getCardNumber()));
            gamer.loseCard();
            AI.setCard(CardNumber,AI.getCard(AI.getCardNumber()-1));
            AI.loseCard();
            lastCardID=CardID;
            carddust.set_Card();
        }
        else {
            //法力不足
        }
        break;
    case 2:
        AI.increaseMP(2);
        AI.setCard(CardNumber,AI.getCard(AI.getCardNumber()-1));
        AI.loseCard();
        lastCardID=CardID;
        carddust.set_Card();
        if(gamer.getMP()>2){
            gamer.reduceMP(2);
        }
        else {
            gamer.setMP(0);
        }
        break;
    case 3:
        if(gamer.getMP()>=6)
        {
            CardID=cardpool.getRand()%14+1;
            AIPlayCard();
        }
        else {
            //不可出牌
        }
        break;
    case 4:
        //不可出牌
        break;
    case 5:
        CardID=lastCardID;
        AIPlayCard();
        break;
    case 6:
        if(AI.getMP()>=1){
            AI.reduceHP(5);
            AI.increaseMP(9);
            AI.setCard(CardNumber,AI.getCard(AI.getCardNumber()-1));
            AI.loseCard();
            lastCardID=CardID;
            carddust.set_Card();
        }
        else {
            //法力不足
        }
        break;
    case 7:
        //被动释放
        break;
    case 8:
        if(AI.getMP()>=5){
            gamer.increaseHP(3);
            AI.reduceMP(5);
            AI.setCard(CardNumber,AI.getCard(AI.getCardNumber()-1));
            AI.loseCard();
            lastCardID=CardID;
            carddust.set_Card();
        }
        else {
            //法力不足
        }
        break;
    case 9:
        if(AI.getMP()>=2){
            gamer.reduceHP(2);
            AI.reduceMP(2);
            AI.setCard(CardNumber,AI.getCard(AI.getCardNumber()-1));
            AI.loseCard();
            lastCardID=CardID;
            carddust.set_Card();
        }
        else {
            //法力不足
        }
        break;
    case 10:
        if(AI.getMP()>=5){
            AI.reduceMP(5);
            gamer.reduceHP(5);
            AI.setCard(CardNumber,AI.getCard(AI.getCardNumber()-1));
            AI.loseCard();
            lastCardID=CardID;
            carddust.set_Card();
        }
        else {
            //法力不足
        }
        break;
    case 11:
        if(AI.getMP()>=2){
            gamer.reduceHP(4);
            AI.reduceHP(1);
            AI.reduceMP(2);
            AI.setCard(CardNumber,AI.getCard(AI.getCardNumber()-1));
            AI.loseCard();
            lastCardID=CardID;
            carddust.set_Card();
        }
        else {
            //法力不足
        }
        break;
    case 12:
        if(AI.getMP()>=2){
            AI.increaseHP(2);
            AI.reduceMP(2);
            AI.setCard(CardNumber,AI.getCard(AI.getCardNumber()-1));
            AI.loseCard();
            lastCardID=CardID;
            carddust.set_Card();
        }
        else {
            //法力不足
        }
        break;
    case 13:
        if(AI.getMP()>=5){
            AI.increaseHP(5);
            AI.reduceMP(5);
            AI.setCard(CardNumber,AI.getCard(AI.getCardNumber()-1));
            AI.loseCard();
            lastCardID=CardID;
            carddust.set_Card();
        }
        break;
    case 14:
        //不可出牌
        break;
    }
}
QString Gamestart::dir_leave(int n){
    switch(n){
    case 1:
        return ":/images/CardImage/tan_nang_wu_qie.png";

    case 2:
        return ":/images/CardImage/an_du_chen_cang.png";

    case 3:
        return ":/images/CardImage/yu_mu_hun_zhu.png";

    case 4:
        return ":/images/CardImage/ming_xuan_yi_xian.png";

    case 5:
        return ":/images/CardImage/liang_ji_fan_zhuan.png";

    case 6:
        return ":/images/CardImage/po_fu_chen_zhou.png";

    case 7:
        return ":/images/CardImage/yi_yi_dai_lao.png";

    case 8:
        return ":/images/CardImage/gu_ruo_jin_tang.png";

    case 9:
        return ":/images/CardImage/qiang_shen_fa_ming.png";

    case 10:
        return ":/images/CardImage/dian_guang_huo_shi.png";

    case 11:
        return ":/images/CardImage/she_ming_yi_ji.png";

    case 12:
        return ":/images/CardImage/miao_shou_hui_chun.png";

    case 13:
        return ":/images/CardImage/xuan_hu_ji_shi.png";

    case 14:
        return ":/images/CardImage/qi_si_hui_sheng.png";
    default:
        return"error";
    }
}
QString Gamestart::dir_cover(int n){
    switch(n){
    case 1:
        return ":/images/CardImage/tan_nang_wu_qie_dian_ji.png";

    case 2:
        return ":/images/CardImage/an_du_chen_cang_dian_ji.png";

    case 3:
        return ":/images/CardImage/yu_mu_hun_zhu_dian_ji.png";

    case 4:
        return ":/images/CardImage/ming_xuan_yi_xian_dian_ji.png";

    case 5:
        return ":/images/CardImage/liang_ji_fan_zhuan_dian_ji.png";

    case 6:
        return ":/images/CardImage/po_fu_chen_zhou_dian_ji.png";

    case 7:
        return ":/images/CardImage/yi_yi_dai_lao_dian_ji.png";

    case 8:
        return ":/images/CardImage/gu_ruo_jin_tang_dian_ji.png";

    case 9:
        return ":/images/CardImage/qiang_shen_fa_ming_dian_ji.png";

    case 10:
        return ":/images/CardImage/dian_guang_huo_shi_dian_ji.png";

    case 11:
        return ":/images/CardImage/she_ming_yi_ji_dian_ji.png";

    case 12:
        return ":/images/CardImage/miao_shou_hui_chun_dian_ji.png";

    case 13:
        return ":/images/CardImage/xuan_hu_ji_shi_dian_ji.png";

    case 14:
        return ":/images/CardImage/qi_si_hui_sheng_dian_ji.png";
    default:
        return "error";
    }
}
Gamestart::~Gamestart(){
}
