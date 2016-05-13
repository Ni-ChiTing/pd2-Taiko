#ifndef INRTRODUCTION_H
#define INRTRODUCTION_H

#include <QDialog>

namespace Ui {
class Inrtroduction;
}

class Inrtroduction : public QDialog
{
    Q_OBJECT

public:
    explicit Inrtroduction(QWidget *parent = 0);
    ~Inrtroduction();
signals:
    void intclose();
private slots:
    void on_pushButton_clicked();

private:
    Ui::Inrtroduction *ui;
};

#endif // INRTRODUCTION_H
