#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "aboutus.h"
#include "heuristic_function.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QLineEdit* MainWindow::judgeZero(std::vector<int> list, string s)
{
    int zeroPosition = 0;
    for(int i = 0; i < list.size(); i++){
        if (list[i] == 0) zeroPosition = i + 1;
    }

    if(s == "initial"){
        switch(zeroPosition){
        case 1:
            return ui->ini1;
        case 2:
            return ui->ini2;
        case 3:
            return ui->ini3;
        case 4:
            return ui->ini4;
        case 5:
            return ui->ini5;
        case 6:
            return ui->ini6;
        case 7:
            return ui->ini7;
        case 8:
            return ui->ini8;
        case 9:
            return ui->ini9;
        }
    }
    else if (s == "final"){
        switch(zeroPosition){
        case 1:
            return ui->final1;
        case 2:
            return ui->final2;
        case 3:
            return ui->final3;
        case 4:
            return ui->final4;
        case 5:
            return ui->final5;
        case 6:
            return ui->final6;
        case 7:
            return ui->final7;
        case 8:
            return ui->final8;
        case 9:
            return ui->final9;
        }
    }
}

void MainWindow::on_aboutUs_clicked()
{
    aboutus* about = new aboutus();
    about->show();
}

void MainWindow::on_algorithm_clicked()
{
    Heuristic_function* hfunction = new Heuristic_function();
    hfunction->show();
}

void MainWindow::on_initial_set_clicked()
{
    std::vector<int> initial;
    for(int i = 0; i < 9; i++) initial.push_back(i);
    std::random_shuffle(initial.begin(), initial.end());

    ui->ini1->setText(QString::number(initial[0]));
    ui->ini2->setText(QString::number(initial[1]));
    ui->ini3->setText(QString::number(initial[2]));
    ui->ini4->setText(QString::number(initial[3]));
    ui->ini5->setText(QString::number(initial[4]));
    ui->ini6->setText(QString::number(initial[5]));
    ui->ini7->setText(QString::number(initial[6]));
    ui->ini8->setText(QString::number(initial[7]));
    ui->ini9->setText(QString::number(initial[8]));

    judgeZero(initial, "initial")->setText("");
}

void MainWindow::on_initial_set_final_clicked()
{
    std::vector<int> final;
    for(int i = 0; i < 9; i++) final.push_back(i);
    std::random_shuffle(final.begin(), final.end());

    ui->final1->setText(QString::number(final[0]));
    ui->final2->setText(QString::number(final[1]));
    ui->final3->setText(QString::number(final[2]));
    ui->final4->setText(QString::number(final[3]));
    ui->final5->setText(QString::number(final[4]));
    ui->final6->setText(QString::number(final[5]));
    ui->final7->setText(QString::number(final[6]));
    ui->final8->setText(QString::number(final[7]));
    ui->final9->setText(QString::number(final[8]));

    judgeZero(final, "final")->setText("");
}

void MainWindow::on_continuous_clicked()
{
    Eight_puzzle eightpuzzle;
    eightpuzzle.readInInitial(ui);
    eightpuzzle.readInFinal(ui);
}
