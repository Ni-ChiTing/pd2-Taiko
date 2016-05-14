#ifndef MUSIC_H
#define MUSIC_H

#include <QDialog>

namespace Ui {
class music;
}

class music : public QDialog
{
    Q_OBJECT

public:
    explicit music(QWidget *parent = 0);
    ~music();
signals:
    void onmusic(int);
    void offmusic(int);
    void itclose();
private slots:
    void on_pushButton_clicked();

private:
    Ui::music *ui;
};

#endif // MUSIC_H
