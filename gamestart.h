#ifndef GAMESTART_H
#define GAMESTART_H
#include"card.h"
#include"dealcard.h"
#include"gameplayer.h"
#include<QTime>
class Gamestart:public QObject{
    Q_OBJECT
private:
    int Turntime;
    int Gametime;
    int CardLibrary[65];
    int firstsign;
    int turnsign;
    int CardID;
    int lastCardID;
    int Clicked_sign;
    int yu_mu;
    int sendCardID;
    int sendCardNumber;
    int result;
    int CardNumber;
public:
    Gamestart();
    //

        Gameplayer gamer;
        Gameplayer AI;
    //
        CardPool cardpool;
        CardDesk carddesk;
        CardDust carddust;
    void sendItem();
    void getItem(int number);
    void setGametime();
    int getGametime();
    int getTurntime();
    int getCard();
    void getCardID(int i);
    void GameRun();
    void GameEnd();
    int set_unusedcardpooln();
    int set_result();
    int set_handcardn();
    int set_handcard(int i);
    int set_aihandcardn();
    int set_deskcard();
    int set_usedcardpooln();
    int set_AI_MP();
    int set_AI_HP();
    int set_My_MP();
    int set_My_HP();
    void sendCard(int n);
    void sendCard_i(int i);

    void AITurn();
    void GamerTurn();
    void AIPlayCard();
    void gamerPlayCard();
    int get_AI_card();
    void PlayCardA();
    void PlayCardG();
    bool AIFirst();
    QString dir_leave(int n);
    QString dir_cover(int n);
    Card tan_nang_wu_qie;
    Card an_du_chen_cang;
    Card yu_mu_hun_zhu;
    Card ming_xuan_yi_xian;
    Card liang_ji_fan_zhuan;
    Card po_fu_chen_zhou;
    Card yi_yi_dai_lao;
    Card gu_ruo_jin_tang;
    Card qiang_shen_fa_ming;
    Card dian_guang_huo_shi;
    Card she_ming_yi_ji;
    Card miao_shou_hui_chun;
    Card xuan_hu_ji_shi;
    Card qi_si_hui_sheng;
    ~Gamestart();
signals:
    void Start();
    void End();
    void TimeStart();
    void PlayCard();
private slots:
    void WhoFirst();
};
#endif // GAMESTART_H

