#ifndef HIT_H
#define HIT_H

#include <QObject>
#include <QGraphicsPixmapItem>
class hit: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
   public:
    hit(int speed,int type,int t);

   public slots:
    void move();
    void style();
    void settime(int t);

    int gettime();
    int returntype();
signals:
        void deletehit();
   private:
    int time;
    int tp;
    int sd;



};

#endif // HIT_H
