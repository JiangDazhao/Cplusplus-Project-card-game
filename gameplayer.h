#ifndef GAMEPLAYER_H
#define GAMEPLAYER_H
#include<QObject>

class Gameplayer{
private:
    int HP;
    int maxHP;
    int MP;
    int maxMP;
    int cardNumber;
    int card[10];
public:
    Gameplayer(int number);
    Gameplayer();
    void setHP(int number);
    int getHP();
    void reduceHP(int number);
    void increaseHP(int number);
    void setMP(int number);
    int getMP();
    void reduceMP(int number);
    void increaseMP(int number);
    void setCardNumber(int number);
    int getCardNumber();
    void setCard(int number);
    void setCard(int i,int number);
    int getCard(int i);
    void loseCard();
    ~Gameplayer();
};
class EasyAI:public Gameplayer{

};
class SimpleAI:public Gameplayer{

};
class DifficultAI:public Gameplayer{

};

#endif // GAMEPLAYER_H

