#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <mainwindow2.h>
#include<rank.h>
#include <option.h>
#include <QMovie>
#include <QMouseEvent>
#include <QMediaPlayer>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MainWindow::setMouseTracking("ture");
    movie =new QMovie(":/pic/pic/0004.gif");
    ui->label_3->setMovie(movie);
    movie->start();
    music->setMedia(QUrl("qrc:/sound/sound/hard.wav"));
    music->play();
}

MainWindow::~MainWindow()
{
    delete mainwindow2;
    delete rank1;
    delete option1;
    delete intr;
    delete ui;
    delete music;
    delete movie;
}

void MainWindow::on_start_clicked()
{
    mainwindow2=new MainWindow2(this);
    music->stop();
    mainwindow2->show();
    mainwindow2->setlevel(ui->label->text());

    this->hide();
    connect(mainwindow2,SIGNAL(onMainClosed()),this,SLOT(show()));
}

void MainWindow::on_rank_clicked()
{
    rank1=new rank(this);
    rank1->show();
    this->hide();
    connect(rank1, SIGNAL(onRankClosed()), this, SLOT(show()));

}
void MainWindow::getlevel(int a)
{
   ui->label->setText(QString::number(a,10));
}

void MainWindow::rankClose()
{
    this->show();
}

void MainWindow::on_option_clicked()
{
    option1=new option(this);
    option1->show();
    this->hide();
     connect(option1,SIGNAL(sendlevel(int)),this,SLOT(getlevel(int)));
    connect(option1, SIGNAL(onoptionClosed()), this, SLOT(show()));
    connect(option1,SIGNAL(mison()),this,SLOT(misicon()));
       connect(option1,SIGNAL(misoff()),this,SLOT(misicoff()));
}

void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
    int XX=e->x();
    int YY=e->y();
    QPoint p(XX,YY);
    if(XX>=665)
        {
            if(XX<=750)
            {

            if(YY>=170)
               {
                if(YY<=195)
                {
                  movie->stop();

                }
                else
                {
                    movie->start();
                }
                }
            else
            {
                movie->start();
            }
            }
            else
            {
               movie->start();
            }

        }
        else
        {
            movie->start();
        }
}


void MainWindow::on_introduction_clicked()
{
intr=new Inrtroduction(this);
intr->show();
this->hide();
connect(intr,SIGNAL(intclose()),this,SLOT(show()));
}

void MainWindow::on_Exit_clicked()
{
    this->close();
}
void MainWindow::misicon()
{
    music->play();
}
void MainWindow::misicoff()
{
    music->stop();
}
