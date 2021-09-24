#include "mybutton.h"


MyButton::MyButton()
{
    setStyleSheet("QPushButton{color:red；background:black;border-radius:8px}");
}

void MyButton::enterEvent(QEvent *)
{
    setIcon(*pix_cover);
}

void MyButton::leaveEvent(QEvent *)
{
    setIcon(*pix_leave);
}
//void MyButton::mouseDoubleClickEvent(QMouseEvent *){
 //   connect(this,SIGNAL(start_printcenter()),this,SLOT(printcenter()));
  //  emit start_printcenter();
//}



