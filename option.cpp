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
    delete ui;
    delete diff1;

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
