#include "diaglog.h"
#include "ui_diaglog.h"

Diaglog::Diaglog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Diaglog)
{
    ui->setupUi(this);
}

Diaglog::~Diaglog()
{
    delete ui;
}

void Diaglog::on_pushButton_clicked()
{
    ui->pushButton->setText("Hello World");
}

void Diaglog::on_pushButton_3_clicked()
{
    ui->pushButton_3->setText("");
}

void Diaglog::on_pushButton_2_clicked()
{
    this->close();
}
