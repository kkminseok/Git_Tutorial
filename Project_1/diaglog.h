#ifndef DIAGLOG_H
#define DIAGLOG_H

#include <QDialog>

namespace Ui {
class Diaglog;
}

class Diaglog : public QDialog
{
    Q_OBJECT

public:
    explicit Diaglog(QWidget *parent = 0);
    ~Diaglog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Diaglog *ui;
};

#endif // DIAGLOG_H
