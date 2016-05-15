#ifndef MAINWINDOW2_H
#define MAINWINDOW2_H

#include <QMainWindow>
#include <ctime>
#include <QTimer>
#include "hit.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QVector>
#include <QString>
#include "score.h"
#include <QMediaPlayer>

namespace Ui {
class MainWindow2;
}

class MainWindow2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow2(QWidget *parent = 0);


    ~MainWindow2();
public slots:
void add_hits();
void countscore(int c,int d);
void setlevel(QString lv);
void timecount();
void resultshow();

private slots:
void hitdelete();
void gamestart();
void mainshow();
signals:
    void onMainClosed();
    void timeend();

private:
    void keyPressEvent(QKeyEvent *event);
    Ui::MainWindow2 *ui;
    QTimer *tt,*cc;
    int totaltime;
    QGraphicsScene* scene;
    QGraphicsView* view;
    hit* n_note;
    QVector<hit*> note;
    int scores;
    QString dif;
    QVector<hit*>::iterator ath;
   QVector<hit*>::iterator cur;
    score *sc;
     QMediaPlayer* music1=new QMediaPlayer();
};

#endif // MAINWINDOW2_H
