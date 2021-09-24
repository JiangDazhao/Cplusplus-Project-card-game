#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QPushButton>
#include<QMouseEvent>
class MyButton:public QPushButton
{
    Q_OBJECT

public:
       MyButton();
    QPixmap *pix_cover;
    QPixmap *pix_leave;
    QPixmap*pix_click;
    QPixmap*pix_special;
    QString CardDir_leave;
protected:
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);
   // void mouseDoubleClickEvent(QMouseEvent*event);
//signals:
   // void start_printcenter();
//public slots:
   // void printcenter();
};

#endif // MYBUTTON_H
