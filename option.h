#ifndef OPTION_H
#define OPTION_H

#include <QMainWindow>
#include <diff.h>
namespace Ui {
class option;
}

class option : public QMainWindow
{
    Q_OBJECT

public:
    explicit option(QWidget *parent = 0);
    ~option();

signals:
    void onoptionClosed();
    void sendlevel(int);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();
    void getlevel(int a);

private:
    Ui::option *ui;
    diff *diff1;
    int di;
};

#endif // OPTION_H
