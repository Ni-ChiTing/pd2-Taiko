#include "hit.h"
#include <ctime>
hit::hit(int speed,int type,int t)
{
    tp=type;
    sd=speed;
    style();
    settime(t);

}
void hit::style()
{
    if(tp==1)
    {
        setPixmap(QPixmap(":/pic/pic/note3.png"));//red
        setPos(800,150);
    }
    if(tp==2)
    {
        setPixmap(QPixmap(":/pic/pic/note2.png"));//blue
        setPos(800,150);
    }
    if(tp==3)
    {
        setPixmap(QPixmap(":/pic/pic/note1.png"));//worm
        setPos(800,150);
    }
    if(tp==0)
    {
        setPixmap(QPixmap(":/pic/pic/note.png"));//yellow
        setPos(800,150);
    }
}
int hit::returntype()
{
    return tp;
}
void hit::move()
{
    if(sd==1)
    {
    if(x() > 120) {
            setPos(x()-1, y());
        }

     else {

            emit deletehit();
         delete this;
       }
    }
    if(sd==2)
    {
    if(x() > 120) {
            setPos(x()-3, y());
        }

     else {

         emit deletehit();
           delete this;
       }
    }
    if(sd==3)
    {
    if(x() > 120) {
            setPos(x()-5, y());
        }

     else {

         emit deletehit();
        delete this;
       }
    }

}
void hit::settime(int t)
{
    time=t;
}
int hit::gettime()
{
    return time;
}

