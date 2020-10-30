#include "playback.h"
#include "ui_playback.h"

Playback::Playback(vector<node> transferList, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Playback)
{
    ui->setupUi(this);
    ui->textBrowser->document()->setDefaultTextOption(QTextOption(Qt::AlignHCenter));

    displayPlayback(transferList);
}

Playback::~Playback()
{
    delete ui;
}

void Playback::displayPlayback(vector<node> transferList)
{
    //特殊情况检查
    if(transferList.size() == 0) return;
    else if (transferList.size() < 3){
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
                + QString::number(transferList[2].matrix[0][2]) + " " + "\n";

    firstOutput += QString::number(transferList[0].matrix[1][0]) + " "
                + QString::number(transferList[0].matrix[1][1]) + " "
                + QString::number(transferList[0].matrix[1][2]) + " " + "|" + " "
                + QString::number(transferList[1].matrix[1][0]) + " "
                + QString::number(transferList[1].matrix[1][1]) + " "
                + QString::number(transferList[1].matrix[1][2]) + " " + "|" + " "
                + QString::number(transferList[2].matrix[1][0]) + " "
                + QString::number(transferList[2].matrix[1][1]) + " "
                + QString::number(transferList[2].matrix[1][2]) + " " + "\n";

    firstOutput += QString::number(transferList[0].matrix[2][0]) + " "
                + QString::number(transferList[0].matrix[2][1]) + " "
                + QString::number(transferList[0].matrix[2][2]) + " " + "|" + " "
                + QString::number(transferList[1].matrix[2][0]) + " "
                + QString::number(transferList[1].matrix[2][1]) + " "
                + QString::number(transferList[1].matrix[2][2]) + " " + "|" + " "
                + QString::number(transferList[2].matrix[2][0]) + " "
                + QString::number(transferList[2].matrix[2][1]) + " "
                + QString::number(transferList[2].matrix[2][2]) + " " + "\n"
                + QString("- - - - - - - - - - - - - - - ") + "\n";

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
                + QString::number(transferList[i+2].matrix[2][2]) + " " + "\n"
                + QString("- - - - - - - - - - - - - - - ") + "\n";
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
