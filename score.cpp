#include "score.h"
#include "ui_score.h"
#include "QMessageBox"
#include "QFile"
#include "iostream"
#include <QTextStream>
#include <QVector>
#include <Qdir>
score::score(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::score)
{
    ui->setupUi(this);
}

score::~score()
{
    delete ui;
}
void score::setscore(QString a)
{
    ui->label_3->setText(a);
}

void score::on_pushButton_3_clicked()
{
    emit closes();
    this->close();
}

void score::on_pushButton_2_clicked()
{
    emit newgame();
    this->close();
}

void score::on_pushButton_clicked()
{
    QDir dir;
    QString path2=dir.currentPath()+"/rank.txt";
    int n=0;
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
    QVector<QString>mrank(100);
     QVector<QString>mname(100);
     QVector<QString>mscore(100);
        if(ui->lineEdit->text()==NULL)
        {
            QMessageBox::information(this,"Warning","Please input name",QMessageBox::Yes);
        }
        if(ui->lineEdit->text()!=NULL)
        {

            aa=ui->lineEdit->text();
            bb=ui->label_3->text();
            int irank,iscore,nscore,nrank,flag=0,c=1;

            QFile ofile(path2);
            if(!ofile.open(QIODevice::ReadOnly|QFile::Text))
            {
                 QMessageBox::information(this,"Error","Can not open",QMessageBox::Yes);
                 this->close();
            }
            QTextStream in(&ofile);
            QString mtext=in.readLine();
            while(!in.atEnd())
            {
                for(n=0;;n++){
                mtext=in.readLine();
                mrank[n]=mtext.split("\t\t").at(0);
                mname[n]=mtext.split("\t\t").at(1);
                mscore[n]=mtext.split("\t\t").at(2);
                iscore=mscore[n].toInt();
                irank=mrank[n].toInt();
                nscore=bb.toInt();
                if(iscore<nscore)
                {
                    nrank=irank;
                    flag=1;
                    break;
                }
                if(iscore==nscore)
                {
                    nrank=irank;
                    flag=2;
                    break;
                }
                if(in.atEnd())
                {
                    break;
                }
                }
                if(flag==1)
                {
                    QString i,j,k;
                    i=QString::number(irank+1,10);
                    j=mname[n];
                    k=mscore[n];
                    mrank[n]=QString::number(nrank,10);
                    mname[n]=aa;
                    mscore[n]=bb;
                    n=n+1;
                    mrank[n]=i;
                    mname[n]=j;
                    mscore[n]=k;
                    n=n+1;
                    break;
                }
                if(flag==2)
                {
                    n=n+1;
                    mrank[n]=QString::number(nrank,10);
                    mname[n]=aa;
                    mscore[n]=bb;
                    n=n+1;
                    break;
                }


            }
            if(flag==0)
            {
                QMessageBox::information(this,"Error",QString::number(n,10),QMessageBox::Yes);
                n=n+1;
                nrank=n;
                mrank[n]=QString::number(nrank+1,10);
                mname[n]=aa;
                mscore[n]=bb;
                n=n+1;
                QMessageBox::information(this,"Error",mrank[n],QMessageBox::Yes);
            }
                if(flag==1)
                 while(!in.atEnd())
                {
                    mtext=in.readLine();
                    mrank[n]=mtext.split("\t\t").at(0);
                    mname[n]=mtext.split("\t\t").at(1);
                    mscore[n]=mtext.split("\t\t").at(2);
                    irank=mrank[n].toInt();
                    irank=irank+1;
                    mrank[n]=QString::number(irank,10);
                    n=n+1;
                    if(n>99)
                    {
                        break;
                    }
                }
                if(flag==2)
                {
                    while(!in.atEnd())
                    {
                        mtext=in.readLine();
                        mrank[n]=mtext.split("\t\t").at(0);
                        mname[n]=mtext.split("\t\t").at(1);
                        mscore[n]=mtext.split("\t\t").at(2);
                        irank=mrank[n].toInt();
                        iscore=mscore[n].toInt();
                        if(iscore==nscore)
                        {
                            c=c+1;
                            flag=3;
                            n=n+1;
                            continue;
                        }
                        if(flag==3)
                        {
                            if(iscore<nscore)
                            {
                                irank=irank+c;
                                mrank[n]=QString::number(irank,10);
                                n=n+1;
                                flag=0;
                            }
                        }
                        if(flag!=3)
                        {
                            if(iscore<nscore)
                            {
                                irank=irank+1;
                                mrank[n]=QString::number(irank,10);
                                 n=n+1;
                            }
                        }
                        if(n>99)
                        {
                            break;
                        }

                    }
                }
                ofile.flush();
                ofile.close();


            }

            if(ui->lineEdit->text()!=NULL)
            {

                    QFile ifile(path2);
                    if(!ifile.open(QIODevice::WriteOnly|QFile::Text))
                    {
                         QMessageBox::information(this,"Error","Can not open",QMessageBox::Yes);
                         this->close();
                    }
                     QTextStream out(&ifile);
                    if(mrank[0]==NULL)
                    {
                        out<<"Rank"<<"\t\t"<<"Name"<<"\t\t"<<"Score"<<endl;
                        out<<"1"<<"\t\t"<<aa<<"\t\t"<<bb<<endl;
                    }
                    else
                    {
                         out<<"Rank"<<"\t\t"<<"Name"<<"\t\t"<<"Score"<<endl;
                         for(int count=0;count<n;count++)
                         {
                             out<<mrank[count]<<"\t\t"<< mname[count]<<"\t\t"<<mscore[count]<<endl;
                         }
                    }
                    ifile.flush();
                    ifile.close();
                    emit ok();
                    this->close();

            }

}
