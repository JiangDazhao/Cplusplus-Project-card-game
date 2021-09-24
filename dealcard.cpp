#include"dealcard.h"
void CardPool::setCardNumber(int number){
    CardNumber=number;
}
void CardPool::setCard(int i,int number){
    CardliBrary[i]=number;
}
int CardPool::getCardNumber(){
    return CardNumber;
}
void CardPool::deleteCard(int i){
    setCard(i,0);
}
bool CardPool::isAlive(int i){
    if(CardliBrary[i]==0)return false;
    else return true;
}
CardPool::CardPool(){
    setCardNumber(60);
    int cardteam[15]={0,3,4,6,1,2,4,5,5,8,4,5,8,4,1};
    int k = 1;
    int j  = 0;
    for(int i=1;i<61;i++){
        if(j<cardteam[k]){setCard(i,k);j++;}
        else{
            setCard(i,k+1);
            k++;j=1;
        }
    }
}
int CardPool::getRand(){
    QTime t;
    t= QTime::currentTime();
    qsrand(t.msec()+(unsigned int)t.second()*1000);
    int n = qrand()%60;
    if(n==0)return 60;
    else return n;
}
int CardPool::DealCard(){
    while(!isEmpty()){
        int m;
        int n;
        m=getRand();
        if(isAlive(m)){
            n=CardliBrary[m];
            CardliBrary[m]=0;
            CardNumber--;
            return n;
        }
    }
}
bool CardPool::isEmpty(){
    if(CardNumber==0)return true;
    else return false;
}
CardDust::CardDust(){
    Card_Number=0;
    setCardNumber(0);
    for(int i=0;i<60;i++)setCard(i,0);
}
void CardDust::set_Card(){
    Card_Number++;
}
int CardDust::get_Card_Number(){
    return Card_Number;
}
