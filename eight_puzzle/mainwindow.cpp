#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "aboutus.h"
#include "heuristic_function.h"
#include "qelapsedtimer.h"
#include <QTime>

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

QLineEdit* MainWindow::judgeNum(std::vector<int> list, string s, int num)
{
    int numPosition = 0;
    for(int i = 0; i < list.size(); i++){
        if (list[i] == num) numPosition = i + 1;
    }

    if(s == "initial"){
        switch(numPosition){
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
        switch(numPosition){
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
    else if (s == "transfer"){
        switch(numPosition){
        case 1:
            return ui->tran1;
        case 2:
            return ui->tran2;
        case 3:
            return ui->tran3;
        case 4:
            return ui->tran4;
        case 5:
            return ui->tran5;
        case 6:
            return ui->tran6;
        case 7:
            return ui->tran7;
        case 8:
            return ui->tran8;
        case 9:
            return ui->tran9;
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
    Eight_puzzle::actionCount = 0;
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

    judgeNum(initial, "initial", 0)->setText("");
    judgeNum(initial, "initial", 0)->setStyleSheet("background:white");
    judgeNum(initial, "initial", 1)->setStyleSheet("background:orange");
    judgeNum(initial, "initial", 2)->setStyleSheet("background:blue");
    judgeNum(initial, "initial", 3)->setStyleSheet("background:purple");
    judgeNum(initial, "initial", 4)->setStyleSheet("background:cyan");
    judgeNum(initial, "initial", 5)->setStyleSheet("background:pink");
    judgeNum(initial, "initial", 6)->setStyleSheet("background:red");
    judgeNum(initial, "initial", 7)->setStyleSheet("background:yellow");
    judgeNum(initial, "initial", 8)->setStyleSheet("background:green");
}

void MainWindow::on_initial_set_final_clicked()
{
    Eight_puzzle::actionCount = 0;
    std::vector<int> final;
//    for(int i = 0; i < 9; i++) final.push_back(i);
//    std::random_shuffle(final.begin(), final.end());
    for(int i = 0; i < 9; i++) final.push_back(i+1);
    final[8] = 0;
//    ui->final1->setText(QString::number(final[0]));
//    ui->final2->setText(QString::number(final[1]));
//    ui->final3->setText(QString::number(final[2]));
//    ui->final4->setText(QString::number(final[3]));
//    ui->final5->setText(QString::number(final[4]));
//    ui->final6->setText(QString::number(final[5]));
//    ui->final7->setText(QString::number(final[6]));
//    ui->final8->setText(QString::number(final[7]));
//    ui->final9->setText(QString::number(final[8]));

    ui->final1->setText(QString::number(1));
    ui->final2->setText(QString::number(2));
    ui->final3->setText(QString::number(3));
    ui->final4->setText(QString::number(4));
    ui->final5->setText(QString::number(5));
    ui->final6->setText(QString::number(6));
    ui->final7->setText(QString::number(7));
    ui->final8->setText(QString::number(8));
    ui->final9->setText(QString::number(0));

    judgeNum(final, "final", 0)->setText("");
    judgeNum(final, "final", 0)->setStyleSheet("background:white");
    judgeNum(final, "final", 1)->setStyleSheet("background:orange");
    judgeNum(final, "final", 2)->setStyleSheet("background:blue");
    judgeNum(final, "final", 3)->setStyleSheet("background:purple");
    judgeNum(final, "final", 4)->setStyleSheet("background:cyan");
    judgeNum(final, "final", 5)->setStyleSheet("background:pink");
    judgeNum(final, "final", 6)->setStyleSheet("background:red");
    judgeNum(final, "final", 7)->setStyleSheet("background:yellow");
    judgeNum(final, "final", 8)->setStyleSheet("background:green");
}

void MainWindow::displayTransOnce(int matrix[3][3])
{
    ui->tran1->setText(QString::number(matrix[0][0]));
    ui->tran2->setText(QString::number(matrix[0][1]));
    ui->tran3->setText(QString::number(matrix[0][2]));
    ui->tran4->setText(QString::number(matrix[1][0]));
    ui->tran5->setText(QString::number(matrix[1][1]));
    ui->tran6->setText(QString::number(matrix[1][2]));
    ui->tran7->setText(QString::number(matrix[2][0]));
    ui->tran8->setText(QString::number(matrix[2][1]));
    ui->tran9->setText(QString::number(matrix[2][2]));

    vector<int> transfer;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            transfer.push_back(matrix[i][j]);
        }
    }

    judgeNum(transfer, "transfer", 0)->setText("");
    judgeNum(transfer, "transfer", 0)->setStyleSheet("background:white");
    judgeNum(transfer, "transfer", 1)->setStyleSheet("background:orange");
    judgeNum(transfer, "transfer", 2)->setStyleSheet("background:blue");
    judgeNum(transfer, "transfer", 3)->setStyleSheet("background:purple");
    judgeNum(transfer, "transfer", 4)->setStyleSheet("background:cyan");
    judgeNum(transfer, "transfer", 5)->setStyleSheet("background:pink");
    judgeNum(transfer, "transfer", 6)->setStyleSheet("background:red");
    judgeNum(transfer, "transfer", 7)->setStyleSheet("background:yellow");
    judgeNum(transfer, "transfer", 8)->setStyleSheet("background:green");

}

void MainWindow::on_continuous_clicked()
{
    Eight_puzzle eightpuzzle;
    eightpuzzle.readInInitial(ui);
    eightpuzzle.readInFinal(ui);
    eightpuzzle.continueSolve();
    transferList = eightpuzzle.transferNodes;


    for(int i = 0; i < transferList.size(); i++){
        displayTransOnce(transferList[i].matrix);
        QTime dieTime = QTime::currentTime().addMSecs(500);
            while( QTime::currentTime() < dieTime )
                QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
}



void MainWindow::on_singlestep_clicked()
{
//    Eight_puzzle::actionCount = 0;
    static int count = 0;


    if (count == 0){
        Eight_puzzle eightpuzzle;
        eightpuzzle.readInInitial(ui);
        eightpuzzle.readInFinal(ui);
        eightpuzzle.continueSolve();
        transferList = eightpuzzle.transferNodes;
    }

    displayTransOnce(transferList[++count].matrix);
    QTime dieTime = QTime::currentTime().addMSecs(100);
    while( QTime::currentTime() < dieTime ) QCoreApplication::processEvents(QEventLoop::AllEvents, 100);

    if (count == transferList.size() - 1) count = 0;

}

void MainWindow::on_h1_clicked()
{
    node::type = 1;
    ui->algorithm->setText(QString("Algorithm 1"));
    ui->algorithm->setStyleSheet("background:orange");
}

void MainWindow::on_h2_clicked()
{
    node::type = 2;
    ui->algorithm->setText(QString("Algorithm 2"));
    ui->algorithm->setStyleSheet("background:pink");
}

void MainWindow::on_h3_clicked()
{
    node::type = 3;
    ui->algorithm->setText(QString("Algorithm 3"));
    ui->algorithm->setStyleSheet("background:cyan");
}

void MainWindow::on_playback_clicked()
{
    Playback* playback = new Playback(transferList);
    playback->show();
}
