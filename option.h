#ifndef OPTION_H
#define OPTION_H

#include <QMainWindow>
#include <diff.h>
#include <music.h>
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
    void mison();
    void misoff();
private slots:
    void on_pushButton_clicked();
    void musicon(int c);
    void musicoff(int b);
    void on_pushButton_2_clicked();
    void getlevel(int a);

    void on_pushButton_3_clicked();

private:
    Ui::option *ui;
    diff *diff1;
    music *music12;
    int di;
    int om;
};

#endif // OPTION_H
