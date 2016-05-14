#include "option.h"
#include "ui_option.h"
#include "diff.h"
option::option(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::option)
{
    ui->setupUi(this);

}

option::~option()
{

    delete music12;
    delete ui;

}

void option::on_pushButton_clicked()
{
    emit onoptionClosed();
    if(di!=1)
        {
        if(di!=2)
        {
            if(di!=3)
            {
                di=1;
            }
        }
    }
    emit sendlevel(di);
    if(om==1)
    {
        emit mison();
    }
    if(om==2)
    {
        emit misoff();
    }
    close();
}

void option::on_pushButton_2_clicked()
{
    diff1=new diff(this);
    diff1->show();
    connect(diff1,SIGNAL(sendlevel(int)),this,SLOT(getlevel(int)));
    connect(diff1, SIGNAL(ondiffClosed()), this, SLOT(show()));
    this->hide();
}
void option::getlevel(int a)
{
    di=a;
}

void option::on_pushButton_3_clicked()
{
    music12=new music(this);
    music12->show();
    this->hide();
    connect(music12,SIGNAL(itclose()),this,SLOT(show()));
    connect(music12,SIGNAL(offmusic(int)),this,SLOT(musicoff(int)));
    connect(music12,SIGNAL(onmusic(int)),this,SLOT(musicon(int)));
}
void option::musicon(int c)
{
    om=c;
}
void option::musicoff(int b)
{
    om=b;
}
