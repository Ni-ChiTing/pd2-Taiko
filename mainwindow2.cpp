#include "mainwindow2.h"
#include "ui_mainwindow2.h"
#include "diff.h"
#include "hit.h"
#include "score.h"
#include <ctime>
#include <cstdlib>
#include "mainwindow.h"
#include <QWidget>
#include <QString>
#include <QMessageBox>
#include <QKeyEvent>

MainWindow2::MainWindow2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow2),tt(new QTimer),cc(new QTimer)
{
    ui->setupUi(this);
    MainWindow2::setFocusPolicy(Qt::StrongFocus);
    connect(tt,SIGNAL(timeout()),this,SLOT(timecount()));
    srand(time(NULL));
    sc=new score(this);
    connect(this,SIGNAL(timeend()),this,SLOT(resultshow()));
    connect(sc,SIGNAL(closes()),this,SLOT(mainshow()));
    connect(sc,SIGNAL(newgame()),this,SLOT(gamestart()));
    connect(sc,SIGNAL(ok()),this,SLOT(mainshow()));

}

MainWindow2::~MainWindow2()
{
    delete ui;
    delete scene;
    delete view;
    delete cc;
    delete tt;
    delete music1;

}
void MainWindow2::gamestart()
{
 note.clear();
 add_hits();
 totaltime=0;
 scores=0;
 music1->setMedia(QUrl("qrc:/sound/sound/medium.wav"));
 music1->play();
  ui->lcdNumber_2->display(scores);
    ui->lcdNumber->display(30);
 scene = new QGraphicsScene(0, 0, 800, 600);
 view = new QGraphicsView(ui->widget);
 view->setScene(scene);
 view->show();
 cc->start(7);
 QString a=dif;
 int b=a.toInt();
 if(b==1)
 {
 tt->start(1000);
 }

 if(b==2)
 {
 tt->start(500);
 }

 if(b==3)
 {
 tt->start(500);
 }

}
void MainWindow2::add_hits()
{
    QString a=dif;
    int b=a.toInt();
    for (int i=0;i<60;++i)
    {
       n_note=new hit(b,rand()%4,500*i);

       note.push_back(n_note);

    }
    ath=note.begin();
    cur=note.begin();
}
void  MainWindow2::setlevel(QString lv)
{
    ui->label_5->setText(lv);
    dif=ui->label_5->text();
     this->gamestart();
}
void MainWindow2::timecount()
{
    QString a=dif;
    int b=a.toInt();

    if(b==1)
    {
    totaltime=totaltime+10;
    if(totaltime%10==0)
    {
        ui->lcdNumber->display(30-totaltime/10);
    }

    if(totaltime<300){
    if(cur!=note.end()){
        scene->addItem(*cur);
        connect(cc,SIGNAL(timeout()), *cur, SLOT(move()));
        connect(*cur,SIGNAL(deletehit()),this,SLOT(hitdelete()));
        cur++;
    }
    }
    else
      {
         emit timeend();
        tt->stop();
    }
    }
    if(b==2)
    {
    totaltime=totaltime+5;
    if(totaltime%10==0)
    {
        ui->lcdNumber->display(30-totaltime/10);
    }

    if(totaltime<300){
    if(cur!=note.end()){
        scene->addItem(*cur);
        connect(cc,SIGNAL(timeout()), (*cur), SLOT(move()));
        connect(*cur,SIGNAL(deletehit()),this,SLOT(hitdelete()));
        cur++;
    }
    }
    else
      {
         emit timeend();
        tt->stop();
    }
    }
    if(b==3)
    {
    totaltime=totaltime+5;
    if(totaltime%10==0)
    {
        ui->lcdNumber->display(30-totaltime/10);
    }

    if(totaltime<300){
    if(cur!=note.end()){
        scene->addItem(*cur);
        connect(cc,SIGNAL(timeout()), (*cur), SLOT(move()));
        connect(*cur,SIGNAL(deletehit()),this,SLOT(hitdelete()));
         cur++;
    }
    }
    else
      {
        emit timeend();
        tt->stop();
    }
    }
}
void MainWindow2::keyPressEvent(QKeyEvent *event)
{
if(ath==note.end())
{
    return;
}
    QMediaPlayer* music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/sound/tia.wav"));
    if((*ath)->x()<220){
    if(event->key() == Qt::Key_Q)
    {
        if((*ath)->returntype()==1)
        {

        int a=(*ath)->x();
        int b=(*ath)->returntype();
        countscore(a,b);
        music->play();
        delete (*ath);
        ath++;
        if(totaltime==0){
        if(cur==ath)
        {
            sc=new score(this);
            sc->show();
        }
        }
        }
    }
    if(event->key()== Qt::Key_W)
    {
        if((*ath)->returntype()==2)
        {
        int a=(*ath)->x();
        int b=(*ath)->returntype();
        countscore(a,b);
        music->play();
        delete (*ath);
        ath++;
        if(totaltime==0){
        if(cur==ath)
        {
            sc=new score(this);
            sc->show();
        }
        }
        }
    }
    if(event->key() == Qt::Key_O)
    {

        if((*ath)->returntype()==3)
        {

            int a=(*ath)->x();
            int b=(*ath)->returntype();
        countscore(a,b);
        music->play();
        delete (*ath);

        ath++;
        }
    }

    if(event->key() == Qt::Key_P)
    {
        if((*ath)->returntype()==0)
        {
        int a=(*ath)->x();
        int b=(*ath)->returntype();

        countscore(a,b);
        music->play();
        delete (*ath);
        ath++;
        }
    }

}
}
void MainWindow2::hitdelete()
{
    if(ath!=note.end())
    {
        ath++;

    }
}
void MainWindow2::countscore(int c,int d)
{
    int a;

        a=170-c;
        if(a<0)
        {a=-a;
        }
        if(a<=10)
        {
            if(d==1)
            {
                scores=scores+25;
            }
            if(d==2)
            {
                scores=scores+50;
            }
            if(d==3)
            {
                scores=scores+100;
            }
            if(d==0)
            {
                scores=scores+75;
            }
        }
        if(a>10){
            if(a<=30)
            {
                if(d==1)
                {
                    scores=scores+10;
                }
                if(d==2)
                {
                    scores=scores+35;
                }
                if(d==3)
                {
                    scores=scores+85;
                }
                if(d==0)
                {
                    scores=scores+60;
                }
        }
        }
        if(a>30){
            if(a<=50)
            {
                if(d==1)
                {
                    scores=scores+5;
                }
                if(d==2)
                {
                    scores=scores+15;
                }
                if(d==3)
                {
                    scores=scores+35;
                }
                if(d==0)
                {
                    scores=scores+20;
                }
        }
        }
     ui->lcdNumber_2->display(scores);

}
void MainWindow2::resultshow()
{
    QString a=QString::number(scores);
    music1->stop();
    sc->setscore(a);
    sc->show();
}
void MainWindow2::mainshow()
{
    emit onMainClosed();
    this->close();
}
