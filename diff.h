#ifndef DIFF_H
#define DIFF_H

#include <QDialog>

namespace Ui {
class diff;
}

class diff : public QDialog
{
    Q_OBJECT

public:
    explicit diff(QWidget *parent = 0);
     QString level;
    ~diff();
signals:
    void ondiffClosed();
    void sendlevel(int);

private slots:
    void on_pushButton_clicked();

private:
    Ui::diff *ui;


};

#endif // DIFF_H
