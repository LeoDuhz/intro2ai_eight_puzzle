#include "heuristic_function.h"
#include "ui_heuristic_function.h"

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
    //设置某个flag使得选择h1
}
