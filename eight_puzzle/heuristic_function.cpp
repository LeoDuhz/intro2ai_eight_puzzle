#include "heuristic_function.h"
#include "ui_heuristic_function.h"
#include "node.h"
#include "qlogging.h"

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

void Heuristic_function::on_h1_button_clicked()
{
    node::type = 1;
    qDebug("you select function1");
}

void Heuristic_function::on_h2_button_clicked()
{
    node::type = 2;
    qDebug("you select function2");
}

void Heuristic_function::on_close_clicked()
{

    this->close();
}

