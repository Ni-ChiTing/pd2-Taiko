#include "music.h"
#include "ui_music.h"
#include <QMessageBox>
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
        emit itclose();
        this->close();
}

    if(ui->radioButton_2->isChecked())
{
    emit offmusic(2);
emit itclose();
    this->close();
}
    emit itclose();
        this->close();
}
