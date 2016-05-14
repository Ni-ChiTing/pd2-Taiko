#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <mainwindow2.h>
#include <QMainWindow>
#include "rank.h"
#include "option.h"
#include <QMouseEvent>
#include "inrtroduction.h"
#include <QMediaPlayer>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void mouseMoveEvent(QMouseEvent *e);
    ~MainWindow();



private slots:
    void on_start_clicked();

    void on_rank_clicked();

    void rankClose();

    void on_option_clicked();
    void getlevel(int a);
    void on_introduction_clicked();
    void misicon();
    void misicoff();
    void on_Exit_clicked();

signals:
    void senddata(int);


private:
    Ui::MainWindow *ui;
    MainWindow2 *mainwindow2;
    rank *rank1;
    option *option1;
    Inrtroduction *intr;
    QMovie *movie;
    QMediaPlayer* music=new QMediaPlayer();

};

#endif // MAINWINDOW_H
