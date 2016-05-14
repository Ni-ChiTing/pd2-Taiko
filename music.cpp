#include "music.h"
#include "ui_music.h"

music::music(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::music)
{
    ui->setupUi(this);
}

music::~music()
{
    delete ui;
}

void music::on_pushButton_clicked()
{
    if(ui->radioButton->isChecked())
    {
        emit onmusic(1);
        this->close();
}
    if(ui->radioButton_2->isChecked())
{
    emit offmusic(2);

    this->close();
}
emit itclose();
}
