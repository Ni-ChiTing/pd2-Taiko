#include "diff.h"
#include "ui_diff.h"
#include <QTextStream>
diff::diff(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::diff)
{
    ui->setupUi(this);
}

diff::~diff()
{
    delete ui;

}

void diff::on_pushButton_clicked()
{

    QString p;
    if(ui->radioButton->isChecked())
    {
        p=ui->radioButton->text();
        level=p.split(" ").at(1);
        emit sendlevel(level.toInt());
        emit ondiffClosed();
        close();
    }
    if(ui->radioButton_2->isChecked())
    {
        p=ui->radioButton_2->text();
        level=p.split(" ").at(1);
        emit sendlevel(level.toInt());
        emit ondiffClosed();
        close();
    }
    if(ui->radioButton_3->isChecked())
    {
        p=ui->radioButton_3->text();
        level=p.split(" ").at(1);
        emit sendlevel(level.toInt());
        emit ondiffClosed();
        close();
    }

}

