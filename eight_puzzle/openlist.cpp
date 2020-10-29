#include "openlist.h"
#include "ui_openlist.h"

openlist::openlist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::openlist)
{
    ui->setupUi(this);
}

openlist::~openlist()
{
    delete ui;
}
