#include "aboutus.h"
#include "ui_aboutus.h"

aboutus::aboutus(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::aboutus)
{
    ui->setupUi(this);
}

aboutus::~aboutus()
{
    delete ui;
}

void aboutus::on_pushButton_clicked()
{
    this->close();
}
