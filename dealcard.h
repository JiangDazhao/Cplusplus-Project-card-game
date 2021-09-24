#ifndef DEALCARD_H
#define DEALCARD_H
#include<QTime>
class CardPool{
private:
    int CardliBrary[65];
    int CardNumber;
public:
    CardPool();
    void setCardNumber(int number);
    int getCardNumber();
    void setCard(int i,int number);
    void deleteCard(int i);
    bool isAlive(int i);
    int getRand();
    int DealCard();
    bool isEmpty();
};
class CardDust:public CardPool{
private:
    int Card_Number;
public:
    CardDust();
    void set_Card();
    int get_Card_Number();
};
class CardDesk:public CardDust{
private:
    int CardID;
public:
    void setCardID();
    int getCardID();
};

#endif // DEALCARD_H
