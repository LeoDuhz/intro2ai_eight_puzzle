#include "analysis.h"
#include "ui_analysis.h"

analysis::analysis(vector<int> nodeCntList, vector<double> timeList, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::analysis)
{
    ui->setupUi(this);
}

analysis::~analysis()
{
    delete ui;
}
