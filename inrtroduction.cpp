#include "inrtroduction.h"
#include "ui_inrtroduction.h"

Inrtroduction::Inrtroduction(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Inrtroduction)
{
    ui->setupUi(this);
}

Inrtroduction::~Inrtroduction()
{
    delete ui;
}

void Inrtroduction::on_pushButton_clicked()
{
   emit intclose();
    this->close();
}
