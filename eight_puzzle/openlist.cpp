#include "openlist.h"
#include "ui_openlist.h"
#include "qelapsedtimer.h"
#include <QTime>

openlist::openlist(vector<vector<node>> olList, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::openlist)
{
    ui->setupUi(this);

    this->olList = olList;
    QApplication::setQuitOnLastWindowClosed(true);

}

openlist::~openlist()
{
    delete ui;
}

void openlist::loopDisplay()
{
    for(int i = 0; i < olList.size(); i++){
        if (isWindowClosed) return;
        displayPlayback(olList[i]);
        QTime dieTime = QTime::currentTime().addMSecs(delay);
            while( QTime::currentTime() < dieTime )
                QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
//        repaint();
    }
}


void openlist::displayPlayback(vector<node> transferList)
{
    //特殊情况检查
    if(transferList.size() == 0) return;
    else if (transferList.size() < 8){
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

    //初始打印出前8个矩阵
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
    for(int i = 1; i < transferList.size() / 8; i++){
        QString output;
        output = QString::number(transferList[8*i].matrix[0][0]) + " "
                + QString::number(transferList[8*i].matrix[0][1]) + " "
                + QString::number(transferList[8*i].matrix[0][2]) + " " + "|" + " "
                + QString::number(transferList[8*i+1].matrix[0][0]) + " "
                + QString::number(transferList[8*i+1].matrix[0][1]) + " "
                + QString::number(transferList[8*i+1].matrix[0][2]) + " " + "|" + " "
                + QString::number(transferList[8*i+2].matrix[0][0]) + " "
                + QString::number(transferList[8*i+2].matrix[0][1]) + " "
                + QString::number(transferList[8*i+2].matrix[0][2]) + " " + "|" + " "
                + QString::number(transferList[8*i+3].matrix[0][0]) + " "
                + QString::number(transferList[8*i+3].matrix[0][1]) + " "
                + QString::number(transferList[8*i+3].matrix[0][2]) + " " + "|" + " "
                + QString::number(transferList[8*i+4].matrix[0][0]) + " "
                + QString::number(transferList[8*i+4].matrix[0][1]) + " "
                + QString::number(transferList[8*i+4].matrix[0][2]) + " " + "|" + " "
                + QString::number(transferList[8*i+5].matrix[0][0]) + " "
                + QString::number(transferList[8*i+5].matrix[0][1]) + " "
                + QString::number(transferList[8*i+5].matrix[0][2]) + " " + "|" + " "
                + QString::number(transferList[8*i+6].matrix[0][0]) + " "
                + QString::number(transferList[8*i+6].matrix[0][1]) + " "
                + QString::number(transferList[8*i+6].matrix[0][2]) + " " + "|" + " "
                + QString::number(transferList[8*i+7].matrix[0][0]) + " "
                + QString::number(transferList[8*i+7].matrix[0][1]) + " "
                + QString::number(transferList[8*i+7].matrix[0][2]) + " " + "|" + "\n";

        output += QString::number(transferList[8*i].matrix[1][0]) + " "
                + QString::number(transferList[8*i].matrix[1][1]) + " "
                + QString::number(transferList[8*i].matrix[1][2]) + " " + "|" + " "
                + QString::number(transferList[8*i+1].matrix[1][0]) + " "
                + QString::number(transferList[8*i+1].matrix[1][1]) + " "
                + QString::number(transferList[8*i+1].matrix[1][2]) + " " + "|" + " "
                + QString::number(transferList[8*i+2].matrix[1][0]) + " "
                + QString::number(transferList[8*i+2].matrix[1][1]) + " "
                + QString::number(transferList[8*i+2].matrix[1][2]) + " " + "|" + " "
                + QString::number(transferList[8*i+3].matrix[1][0]) + " "
                + QString::number(transferList[8*i+3].matrix[1][1]) + " "
                + QString::number(transferList[8*i+3].matrix[1][2]) + " " + "|" + " "
                + QString::number(transferList[8*i+4].matrix[1][0]) + " "
                + QString::number(transferList[8*i+4].matrix[1][1]) + " "
                + QString::number(transferList[8*i+4].matrix[1][2]) + " " + "|" + " "
                + QString::number(transferList[8*i+5].matrix[1][0]) + " "
                + QString::number(transferList[8*i+5].matrix[1][1]) + " "
                + QString::number(transferList[8*i+5].matrix[1][2]) + " " + "|" + " "
                + QString::number(transferList[8*i+6].matrix[1][0]) + " "
                + QString::number(transferList[8*i+6].matrix[1][1]) + " "
                + QString::number(transferList[8*i+6].matrix[1][2]) + " " + "|" + " "
                + QString::number(transferList[8*i+7].matrix[1][0]) + " "
                + QString::number(transferList[8*i+7].matrix[1][1]) + " "
                + QString::number(transferList[8*i+7].matrix[1][2]) + " " + "|" + "\n";

        output += QString::number(transferList[8*i].matrix[2][0]) + " "
                + QString::number(transferList[8*i].matrix[2][1]) + " "
                + QString::number(transferList[8*i].matrix[2][2]) + " " + "|" + " "
                + QString::number(transferList[8*i+1].matrix[2][0]) + " "
                + QString::number(transferList[8*i+1].matrix[2][1]) + " "
                + QString::number(transferList[8*i+1].matrix[2][2]) + " " + "|" + " "
                + QString::number(transferList[8*i+2].matrix[2][0]) + " "
                + QString::number(transferList[8*i+2].matrix[2][1]) + " "
                + QString::number(transferList[8*i+2].matrix[2][2]) + " " + "|" + " "
                + QString::number(transferList[8*i+3].matrix[2][0]) + " "
                + QString::number(transferList[8*i+3].matrix[2][1]) + " "
                + QString::number(transferList[8*i+3].matrix[2][2]) + " " + "|" + " "
                + QString::number(transferList[8*i+4].matrix[2][0]) + " "
                + QString::number(transferList[8*i+4].matrix[2][1]) + " "
                + QString::number(transferList[8*i+4].matrix[2][2]) + " " + "|" + " "
                + QString::number(transferList[8*i+5].matrix[2][0]) + " "
                + QString::number(transferList[8*i+5].matrix[2][1]) + " "
                + QString::number(transferList[8*i+5].matrix[2][2]) + " " + "|" + " "
                + QString::number(transferList[8*i+6].matrix[2][0]) + " "
                + QString::number(transferList[8*i+6].matrix[2][1]) + " "
                + QString::number(transferList[8*i+6].matrix[2][2]) + " " + "|" + " "
                + QString::number(transferList[8*i+7].matrix[2][0]) + " "
                + QString::number(transferList[8*i+7].matrix[2][1]) + " "
                + QString::number(transferList[8*i+7].matrix[2][2]) + " " + "|" + "\n"
                + QString("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ") + "\n";
        ui->textBrowser->append(output);
    }

    if (transferList.size() % 8 == 1){
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
    else if (transferList.size() % 8 == 2){
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
    else if (transferList.size() % 8 == 3)
    {
        int i = transferList.size() - 3;
        QString output;
        output = QString::number(transferList[i].matrix[0][0]) + " "
                + QString::number(transferList[i].matrix[0][1]) + " "
                + QString::number(transferList[i].matrix[0][2]) + " " + "|" + " "
                + QString::number(transferList[i+1].matrix[0][0]) + " "
                + QString::number(transferList[i+1].matrix[0][1]) + " "
                + QString::number(transferList[i+1].matrix[0][2]) + " " + "|" + " "
                + QString::number(transferList[i+2].matrix[0][0]) + " "
                + QString::number(transferList[i+2].matrix[0][1]) + " "
                + QString::number(transferList[i+2].matrix[0][2]) + " " + "\n";

        output += QString::number(transferList[i].matrix[1][0]) + " "
                + QString::number(transferList[i].matrix[1][1]) + " "
                + QString::number(transferList[i].matrix[1][2]) + " " + "|" + " "
                + QString::number(transferList[i+1].matrix[1][0]) + " "
                + QString::number(transferList[i+1].matrix[1][1]) + " "
                + QString::number(transferList[i+1].matrix[1][2]) + " " + "|" + " "
                + QString::number(transferList[i+2].matrix[1][0]) + " "
                + QString::number(transferList[i+2].matrix[1][1]) + " "
                + QString::number(transferList[i+2].matrix[1][2]) + " " + "\n";


        output += QString::number(transferList[i].matrix[2][0]) + " "
                + QString::number(transferList[i].matrix[2][1]) + " "
                + QString::number(transferList[i].matrix[2][2]) + " " + "|" + " "
                + QString::number(transferList[i+1].matrix[2][0]) + " "
                + QString::number(transferList[i+1].matrix[2][1]) + " "
                + QString::number(transferList[i+1].matrix[2][2]) + " " + "|" + " "
                + QString::number(transferList[i+2].matrix[2][0]) + " "
                + QString::number(transferList[i+2].matrix[2][1]) + " "
                + QString::number(transferList[i+2].matrix[2][2]) + " " + "\n";

        ui->textBrowser->append(output);
    }
    else if (transferList.size() % 8 == 4)
    {
        int i = transferList.size() - 4;
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
                + QString::number(transferList[i+3].matrix[0][2]) + " " + "\n";


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
                + QString::number(transferList[i+3].matrix[1][2]) + " " + "\n";


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
                + QString::number(transferList[i+3].matrix[2][2]) + " " + "\n";

        ui->textBrowser->append(output);
    }
    else if (transferList.size() % 8 == 5)
    {
        int i = transferList.size() - 5;
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
                + QString::number(transferList[i+4].matrix[0][2]) + " " + "\n";


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
                + QString::number(transferList[i+4].matrix[1][2]) + " " + "\n";

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
                + QString::number(transferList[i+4].matrix[2][2]) + " " + "\n";

        ui->textBrowser->append(output);
    }
    else if (transferList.size() % 8 == 6)
    {
        int i = transferList.size() - 6;
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
                + QString::number(transferList[i+5].matrix[0][2]) + " " + "\n";

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
                + QString::number(transferList[i+5].matrix[1][2]) + " " + "\n";


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
                + QString::number(transferList[i+5].matrix[2][2]) + " " + "\n";
        ui->textBrowser->append(output);
    }
    else if (transferList.size() % 8 == 7)
    {
        int i = transferList.size() - 7;
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
                + QString::number(transferList[i+6].matrix[0][2]) + " " + "\n";


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
                + QString::number(transferList[i+6].matrix[1][2]) + " " + "\n";


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
                + QString::number(transferList[i+6].matrix[2][2]) + " " + "\n";

        ui->textBrowser->append(output);
    }

}



void openlist::on_start_clicked()
{
    ui->start->setStyleSheet("background:cyan");
    loopDisplay();
    ui->start->setStyleSheet("background:white");
}

void openlist::on_close_clicked()
{
    isWindowClosed = true;
    this->close();
}
