#include "rank.h"
#include "ui_rank.h"
#include "QMessageBox"
#include "QFile"
#include "iostream"
#include <QTextStream>
#include <QVector>
#include <qlistview.h>
#include <QGridLayout>
#include <mainwindow.h>
#include <QDir>
rank::rank(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::rank)
{
    ui->setupUi(this);
     QDir dir;
     QString path2=dir.currentPath()+"/rank.txt";
     QFile ocfile(path2);
     if(!ocfile.open(QIODevice::ReadOnly|QFile::Text))
     {
      QDir dir1;
      QFile file;
      file.setFileName("rank.txt");
      QDir::setCurrent(dir1.currentPath());
      file.open(QIODevice::WriteOnly|QFile::Text);
      QTextStream out(&file);
      out<<"Rank"<<"\t\t"<<"Name"<<"\t\t"<<"Score"<<endl;
     file.close();
     }
     ocfile.close();
     QFile ofile(path2);
     ofile.open(QIODevice::ReadOnly|QFile::Text);
     QTextStream in(&ofile);
     while(!in.atEnd())
     {
     QString mtext=in.readLine();
     ui->listWidget->addItem(mtext);
     }
     ofile.close();
     QGridLayout *layout=new QGridLayout;
     layout->addWidget(ui->listWidget,0,0);
     layout->addWidget(ui->pushButton,1,0);
     QWidget *window = new QWidget();
     window->setLayout(layout);
     setCentralWidget(window);
}

rank::~rank()
{
    delete ui;
}

void rank::on_pushButton_clicked()
{
    emit onRankClosed();
    close();
}
