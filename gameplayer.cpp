#include"gameplayer.h"
Gameplayer::Gameplayer(int number):cardNumber(number){
    setHP(20);
    setMP(10);
    maxHP=20;
    maxMP=20;
}
Gameplayer::Gameplayer(){
    setHP(20);
    setMP(20);
    setCardNumber(0);
    for(int i=0;i<9;i++)setCard(0);
}
void Gameplayer::setHP(int number){
    HP=number;
}
int Gameplayer::getHP(){
   return HP;
}
void Gameplayer::reduceHP(int number){
    if(HP>=number)HP=HP-number;
    else {
         HP=0;
    }
}
void Gameplayer::increaseHP(int number){
    if(HP+number>=20)HP=20;
    else {
        HP=HP+number;
    }
}
void Gameplayer::setMP(int number){
    MP=number;
}
int Gameplayer::getMP(){
    return MP;
}
void Gameplayer::reduceMP(int number){
    if(MP>=number)MP=MP-number;
    else {
         MP=0;
    }
}
void Gameplayer::increaseMP(int number){
    if(MP+number>=20)MP=20;
    else {
        MP=MP+number;
    }
}
void Gameplayer::setCardNumber(int number){
    cardNumber=number;
}
int Gameplayer::getCardNumber(){
    return cardNumber;
}
void Gameplayer::setCard(int number){
    if(cardNumber>=8)return;
    card[cardNumber]=number;
    cardNumber++;
}
void Gameplayer::setCard(int i, int number){
    card[i]=number;
}
int Gameplayer::getCard(int i){
   return card[i];
}
void Gameplayer::loseCard(){
    cardNumber--;
    card[cardNumber]=0;
}
Gameplayer::~Gameplayer(){

}
