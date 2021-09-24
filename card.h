#ifndef CARD_H
#define CARD_H
#include<QMediaPlayer>
#include<QMediaPlaylist>
#include <QGraphicsItem>
#include<QString>
class Card{
private:
    int MP;
    int ID;
    QString ImageDir;
public:
    Card(int number,int need);
    Card();
    int Effection();
    QString getImageDir();
    void setImageDir(QString dir);
    int getMP();
    ~Card();
};
#endif // CARD_H
