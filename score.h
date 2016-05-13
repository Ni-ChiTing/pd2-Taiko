#ifndef SCORE_H
#define SCORE_H

#include <QDialog>
#include <QString>
namespace Ui {
class score;
}

class score : public QDialog
{
    Q_OBJECT

public:
    explicit score(QWidget *parent = 0);
    void setscore(QString a);
       QString aa,bb;
    ~score();

private slots:
    void on_pushButton_3_clicked();
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

signals:
    void closes();
    void newgame();
    void ok();
private:
    Ui::score *ui;
};

#endif // SCORE_H
