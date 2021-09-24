#include"card.h"
Card::Card(int number,int need):MP(need),ID(number){

}
Card::Card(){
    MP=4;
    ID=1;
}
int Card::Effection(){
    return ID;
}
QString Card::getImageDir(){
    return ImageDir;
}
void Card::setImageDir(QString dir){
     ImageDir=dir;
}
int Card::getMP(){
return MP;
}
Card::~Card(){

}
