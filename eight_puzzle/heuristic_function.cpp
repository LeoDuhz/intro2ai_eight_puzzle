#include "heuristic_function.h"
#include "ui_heuristic_function.h"
#include "node.h"
#include "qlogging.h"
#include "mainwindow.h"

Heuristic_function::Heuristic_function(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Heuristic_function)
{
    ui->setupUi(this);
}

Heuristic_function::~Heuristic_function()
{
    delete ui;
}



void Heuristic_function::on_close_clicked()
{

    this->close();
}

