#include "closelist.h"
#include "ui_closelist.h"
#include "qelapsedtimer.h"
#include <QTime>

closelist::closelist(vector<vector<node>> clList, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::closelist)
{
    ui->setupUi(this);

    this->clList = clList;
    QApplication::setQuitOnLastWindowClosed(true);

}

closelist::~closelist()
{
    delete ui;
}

void closelist::loopDisplay()
{
    for(int i = 0; i < clList.size(); i++){
        if (isWindowClosed) return;
        displayPlayback(clList[i]);
        qDebug("here");
        QTime dieTime = QTime::currentTime().addMSecs(10);
            while( QTime::currentTime() < dieTime )
                QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
//        repaint();
    }
}


void closelist::displayPlayback(vector<node> transferList)
{
    //特殊情况检查
    if(transferList.size() == 0) return;
    else if (transferList.size() < 7){
        QString specialOutput;

        specialOutput = QString::number(transferList[0].matrix[0][0]) + " "
                    + QString::number(transferList[0].matrix[0][1]) + " "
                    + QString::number(transferList[0].matrix[0][2]) + " " + "\n";


        specialOutput += QString::number(transferList[0].matrix[1][0]) + " "
                    + QString::number(transferList[0].matrix[1][1]) + " "
                    + QString::number(transferList[0].matrix[1][2]) + " " + "\n";


        specialOutput += QString::number(transferList[0].matrix[2][0]) + " "
                    + QString::number(transferList[0].matrix[2][1]) + " "
                    + QString::number(transferList[0].matrix[2][2]) + " " + "\n"
                    + QString("- - - - - - - - - - - - - - - ") + "\n";

        ui->textBrowser->setText(specialOutput);

        for(int i = 1; i < transferList.size(); i++){
            QString specialOutput;
            specialOutput = QString::number(transferList[i].matrix[0][0]) + " "
                        + QString::number(transferList[i].matrix[0][1]) + " "
                        + QString::number(transferList[i].matrix[0][2]) + " " + "\n";


            specialOutput += QString::number(transferList[i].matrix[1][0]) + " "
                        + QString::number(transferList[i].matrix[1][1]) + " "
                        + QString::number(transferList[i].matrix[1][2]) + " " + "\n";


            specialOutput += QString::number(transferList[i].matrix[2][0]) + " "
                        + QString::number(transferList[i].matrix[2][1]) + " "
                        + QString::number(transferList[i].matrix[2][2]) + " " + "\n"
                        + QString("- - - - - - - - - - - - - - - ") + "\n";

            ui->textBrowser->append(specialOutput);
        }
        return;
    }

    //初始打印出前三个矩阵
    QString firstOutput;
    firstOutput = QString::number(transferList[0].matrix[0][0]) + " "
                + QString::number(transferList[0].matrix[0][1]) + " "
                + QString::number(transferList[0].matrix[0][2]) + " " + "|" + " "
                + QString::number(transferList[1].matrix[0][0]) + " "
                + QString::number(transferList[1].matrix[0][1]) + " "
                + QString::number(transferList[1].matrix[0][2]) + " " + "|" + " "
                + QString::number(transferList[2].matrix[0][0]) + " "
                + QString::number(transferList[2].matrix[0][1]) + " "
                + QString::number(transferList[2].matrix[0][2]) + " " + "|" + " "
                + QString::number(transferList[3].matrix[0][0]) + " "
                + QString::number(transferList[3].matrix[0][1]) + " "
                + QString::number(transferList[3].matrix[0][2]) + " " + "|" + " "
                + QString::number(transferList[4].matrix[0][0]) + " "
                + QString::number(transferList[4].matrix[0][1]) + " "
                + QString::number(transferList[4].matrix[0][2]) + " " + "|" + " "
                + QString::number(transferList[5].matrix[0][0]) + " "
                + QString::number(transferList[5].matrix[0][1]) + " "
                + QString::number(transferList[5].matrix[0][2]) + " " + "|" + " "
                + QString::number(transferList[6].matrix[0][0]) + " "
                + QString::number(transferList[6].matrix[0][1]) + " "
                + QString::number(transferList[6].matrix[0][2]) + " " + "|" + " "
                + QString::number(transferList[7].matrix[0][0]) + " "
                + QString::number(transferList[7].matrix[0][1]) + " "
                + QString::number(transferList[7].matrix[0][2]) + " " + "|" + "\n";

    firstOutput += QString::number(transferList[0].matrix[1][0]) + " "
                + QString::number(transferList[0].matrix[1][1]) + " "
                + QString::number(transferList[0].matrix[1][2]) + " " + "|" + " "
                + QString::number(transferList[1].matrix[1][0]) + " "
                + QString::number(transferList[1].matrix[1][1]) + " "
                + QString::number(transferList[1].matrix[1][2]) + " " + "|" + " "
                + QString::number(transferList[2].matrix[1][0]) + " "
                + QString::number(transferList[2].matrix[1][1]) + " "
                + QString::number(transferList[2].matrix[1][2]) + " " + "|" + " "
                + QString::number(transferList[3].matrix[1][0]) + " "
                + QString::number(transferList[3].matrix[1][1]) + " "
                + QString::number(transferList[3].matrix[1][2]) + " " + "|" + " "
                + QString::number(transferList[4].matrix[1][0]) + " "
                + QString::number(transferList[4].matrix[1][1]) + " "
                + QString::number(transferList[4].matrix[1][2]) + " " + "|" + " "
                + QString::number(transferList[5].matrix[1][0]) + " "
                + QString::number(transferList[5].matrix[1][1]) + " "
                + QString::number(transferList[5].matrix[1][2]) + " " + "|" + " "
                + QString::number(transferList[6].matrix[1][0]) + " "
                + QString::number(transferList[6].matrix[1][1]) + " "
                + QString::number(transferList[6].matrix[1][2]) + " " + "|" + " "
                + QString::number(transferList[7].matrix[1][0]) + " "
                + QString::number(transferList[7].matrix[1][1]) + " "
                + QString::number(transferList[7].matrix[1][2]) + " " + "|" + "\n";


    firstOutput += QString::number(transferList[0].matrix[2][0]) + " "
                + QString::number(transferList[0].matrix[2][1]) + " "
                + QString::number(transferList[0].matrix[2][2]) + " " + "|" + " "
                + QString::number(transferList[1].matrix[2][0]) + " "
                + QString::number(transferList[1].matrix[2][1]) + " "
                + QString::number(transferList[1].matrix[2][2]) + " " + "|" + " "
                + QString::number(transferList[2].matrix[2][0]) + " "
                + QString::number(transferList[2].matrix[2][1]) + " "
                + QString::number(transferList[2].matrix[2][2]) + " " + "|" + " "
                + QString::number(transferList[3].matrix[2][0]) + " "
                + QString::number(transferList[3].matrix[2][1]) + " "
                + QString::number(transferList[3].matrix[2][2]) + " " + "|" + " "
                + QString::number(transferList[4].matrix[2][0]) + " "
                + QString::number(transferList[4].matrix[2][1]) + " "
                + QString::number(transferList[4].matrix[2][2]) + " " + "|" + " "
                + QString::number(transferList[5].matrix[2][0]) + " "
                + QString::number(transferList[5].matrix[2][1]) + " "
                + QString::number(transferList[5].matrix[2][2]) + " " + "|" + " "
                + QString::number(transferList[6].matrix[2][0]) + " "
                + QString::number(transferList[6].matrix[2][1]) + " "
                + QString::number(transferList[6].matrix[2][2]) + " " + "|" + " "
                + QString::number(transferList[7].matrix[2][0]) + " "
                + QString::number(transferList[7].matrix[2][1]) + " "
                + QString::number(transferList[7].matrix[2][2]) + " " + "|" + "\n"
                + QString("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ") + "\n";

    ui->textBrowser->setText(firstOutput);

    //不断继续打印
    for(int i = 1; i < transferList.size() / 3; i++){
        QString output;
        output = QString::number(transferList[i].matrix[0][0]) + " "
                + QString::number(transferList[i].matrix[0][1]) + " "
                + QString::number(transferList[i].matrix[0][2]) + " " + "|" + " "
                + QString::number(transferList[i+1].matrix[0][0]) + " "
                + QString::number(transferList[i+1].matrix[0][1]) + " "
                + QString::number(transferList[i+1].matrix[0][2]) + " " + "|" + " "
                + QString::number(transferList[i+2].matrix[0][0]) + " "
                + QString::number(transferList[i+2].matrix[0][1]) + " "
                + QString::number(transferList[i+2].matrix[0][2]) + " " + "|" + " "
                + QString::number(transferList[i+3].matrix[0][0]) + " "
                + QString::number(transferList[i+3].matrix[0][1]) + " "
                + QString::number(transferList[i+3].matrix[0][2]) + " " + "|" + " "
                + QString::number(transferList[i+4].matrix[0][0]) + " "
                + QString::number(transferList[i+4].matrix[0][1]) + " "
                + QString::number(transferList[i+4].matrix[0][2]) + " " + "|" + " "
                + QString::number(transferList[i+5].matrix[0][0]) + " "
                + QString::number(transferList[i+5].matrix[0][1]) + " "
                + QString::number(transferList[i+5].matrix[0][2]) + " " + "|" + " "
                + QString::number(transferList[i+6].matrix[0][0]) + " "
                + QString::number(transferList[i+6].matrix[0][1]) + " "
                + QString::number(transferList[i+6].matrix[0][2]) + " " + "|" + " "
                + QString::number(transferList[i+7].matrix[0][0]) + " "
                + QString::number(transferList[i+7].matrix[0][1]) + " "
                + QString::number(transferList[i+7].matrix[0][2]) + " " + "|" + "\n";

        output += QString::number(transferList[i].matrix[1][0]) + " "
                + QString::number(transferList[i].matrix[1][1]) + " "
                + QString::number(transferList[i].matrix[1][2]) + " " + "|" + " "
                + QString::number(transferList[i+1].matrix[1][0]) + " "
                + QString::number(transferList[i+1].matrix[1][1]) + " "
                + QString::number(transferList[i+1].matrix[1][2]) + " " + "|" + " "
                + QString::number(transferList[i+2].matrix[1][0]) + " "
                + QString::number(transferList[i+2].matrix[1][1]) + " "
                + QString::number(transferList[i+2].matrix[1][2]) + " " + "|" + " "
                + QString::number(transferList[i+3].matrix[1][0]) + " "
                + QString::number(transferList[i+3].matrix[1][1]) + " "
                + QString::number(transferList[i+3].matrix[1][2]) + " " + "|" + " "
                + QString::number(transferList[i+4].matrix[1][0]) + " "
                + QString::number(transferList[i+4].matrix[1][1]) + " "
                + QString::number(transferList[i+4].matrix[1][2]) + " " + "|" + " "
                + QString::number(transferList[i+5].matrix[1][0]) + " "
                + QString::number(transferList[i+5].matrix[1][1]) + " "
                + QString::number(transferList[i+5].matrix[1][2]) + " " + "|" + " "
                + QString::number(transferList[i+6].matrix[1][0]) + " "
                + QString::number(transferList[i+6].matrix[1][1]) + " "
                + QString::number(transferList[i+6].matrix[1][2]) + " " + "|" + " "
                + QString::number(transferList[i+7].matrix[1][0]) + " "
                + QString::number(transferList[i+7].matrix[1][1]) + " "
                + QString::number(transferList[i+7].matrix[1][2]) + " " + "|" + "\n";

        output += QString::number(transferList[i].matrix[2][0]) + " "
                + QString::number(transferList[i].matrix[2][1]) + " "
                + QString::number(transferList[i].matrix[2][2]) + " " + "|" + " "
                + QString::number(transferList[i+1].matrix[2][0]) + " "
                + QString::number(transferList[i+1].matrix[2][1]) + " "
                + QString::number(transferList[i+1].matrix[2][2]) + " " + "|" + " "
                + QString::number(transferList[i+2].matrix[2][0]) + " "
                + QString::number(transferList[i+2].matrix[2][1]) + " "
                + QString::number(transferList[i+2].matrix[2][2]) + " " + "|" + " "
                + QString::number(transferList[i+3].matrix[2][0]) + " "
                + QString::number(transferList[i+3].matrix[2][1]) + " "
                + QString::number(transferList[i+3].matrix[2][2]) + " " + "|" + " "
                + QString::number(transferList[i+4].matrix[2][0]) + " "
                + QString::number(transferList[i+4].matrix[2][1]) + " "
                + QString::number(transferList[i+4].matrix[2][2]) + " " + "|" + " "
                + QString::number(transferList[i+5].matrix[2][0]) + " "
                + QString::number(transferList[i+5].matrix[2][1]) + " "
                + QString::number(transferList[i+5].matrix[2][2]) + " " + "|" + " "
                + QString::number(transferList[i+6].matrix[2][0]) + " "
                + QString::number(transferList[i+6].matrix[2][1]) + " "
                + QString::number(transferList[i+6].matrix[2][2]) + " " + "|" + " "
                + QString::number(transferList[i+7].matrix[2][0]) + " "
                + QString::number(transferList[i+7].matrix[2][1]) + " "
                + QString::number(transferList[i+7].matrix[2][2]) + " " + "|" + "\n"
                + QString("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ") + "\n";
        ui->textBrowser->append(output);
    }

    if (transferList.size() % 3 == 1){
        QString output;
        int i = transferList.size() - 1;
        output = QString::number(transferList[i].matrix[0][0]) + " "
                + QString::number(transferList[i].matrix[0][1]) + " "
                + QString::number(transferList[i].matrix[0][2]) + " " + "\n";


        output += QString::number(transferList[i].matrix[1][0]) + " "
                + QString::number(transferList[i].matrix[1][1]) + " "
                + QString::number(transferList[i].matrix[1][2]) + " " + "\n";


        output += QString::number(transferList[i].matrix[2][0]) + " "
                + QString::number(transferList[i].matrix[2][1]) + " "
                + QString::number(transferList[i].matrix[2][2]) + " " + "\n";

        ui->textBrowser->append(output);

    }
    else if (transferList.size() % 3 == 2){
        QString output;
        int i = transferList.size() - 2;
        output = QString::number(transferList[i].matrix[0][0]) + " "
                + QString::number(transferList[i].matrix[0][1]) + " "
                + QString::number(transferList[i].matrix[0][2]) + " " + "|" + " "
                + QString::number(transferList[i+1].matrix[0][0]) + " "
                + QString::number(transferList[i+1].matrix[0][1]) + " "
                + QString::number(transferList[i+1].matrix[0][2]) + " " + "\n";


        output += QString::number(transferList[i].matrix[1][0]) + " "
                + QString::number(transferList[i].matrix[1][1]) + " "
                + QString::number(transferList[i].matrix[1][2]) + " " + "|" + " "
                + QString::number(transferList[i+1].matrix[1][0]) + " "
                + QString::number(transferList[i+1].matrix[1][1]) + " "
                + QString::number(transferList[i+1].matrix[1][2]) + " " + "\n";


        output += QString::number(transferList[i].matrix[2][0]) + " "
                + QString::number(transferList[i].matrix[2][1]) + " "
                + QString::number(transferList[i].matrix[2][2]) + " " + "|" + " "
                + QString::number(transferList[i+1].matrix[2][0]) + " "
                + QString::number(transferList[i+1].matrix[2][1]) + " "
                + QString::number(transferList[i+1].matrix[2][2]) + " " + "\n";

        ui->textBrowser->append(output);
    }


}


void closelist::on_start_clicked()
{
    ui->start->setStyleSheet("background:cyan");
    loopDisplay();
    ui->start->setStyleSheet("background:white");
}

void closelist::on_close_clicked()
{
    isWindowClosed = true;
    this->close();
}

