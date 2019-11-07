#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include<QDebug>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    Ui::Dialog *ui;
    int data;
    double dataou;
    bool databoo;
    QString datastr;
    const double pi=3.14159265359;

    int oper1;
    int oper2;
};

#endif // DIALOG_H

