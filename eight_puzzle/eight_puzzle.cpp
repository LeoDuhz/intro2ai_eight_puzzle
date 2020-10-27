#include "eight_puzzle.h"
#include "qmessagebox.h"

Eight_puzzle::Eight_puzzle()
{
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            initMatrix[i][j] = 0;
        }
    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            finalMatrix[i][j] = 0;
        }
    }

    openlist.clear();
    closelist.clear();
}

void Eight_puzzle::readInInitial(Ui::MainWindow *ui)
{
    initMatrix[0][0] = ui->ini1->text().toInt();
    initMatrix[0][1] = ui->ini2->text().toInt();
    initMatrix[0][2] = ui->ini3->text().toInt();
    initMatrix[1][0] = ui->ini4->text().toInt();
    initMatrix[1][1] = ui->ini5->text().toInt();
    initMatrix[1][2] = ui->ini6->text().toInt();
    initMatrix[2][0] = ui->ini7->text().toInt();
    initMatrix[2][1] = ui->ini8->text().toInt();
    initMatrix[2][2] = ui->ini9->text().toInt();

    qDebug("get initial matrix!");
    checkMatrixValid(initMatrix);

}



void Eight_puzzle::readInFinal(Ui::MainWindow *ui)
{
    finalMatrix[0][0] = ui->final1->text().toInt();
    finalMatrix[0][1] = ui->final2->text().toInt();
    finalMatrix[0][2] = ui->final3->text().toInt();
    finalMatrix[1][0] = ui->final4->text().toInt();
    finalMatrix[1][1] = ui->final5->text().toInt();
    finalMatrix[1][2] = ui->final6->text().toInt();
    finalMatrix[2][0] = ui->final7->text().toInt();
    finalMatrix[2][1] = ui->final8->text().toInt();
    finalMatrix[2][2] = ui->final9->text().toInt();

    qDebug("get final matrix!");
    checkMatrixValid(finalMatrix);

}


bool Eight_puzzle::checkMatrixValid(int Matrix[3][3])
{
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if (Matrix[i][j] > 9 || Matrix[i][j] < 0){
                QMessageBox::information(NULL, "Waring", "输入不在0-9范围内,请重新输入", QMessageBox::Yes, QMessageBox::Yes);
                return false;
            }

            for(int k = 0; k < 3; k++){
                for(int m = 0; m < 3; m++){
                    if (k == i && m == j) continue;
                    if (Matrix[i][j] == Matrix[k][m]){
                        QMessageBox::information(NULL, "Waring", "有重复输入,请重新输入", QMessageBox::Yes, QMessageBox::Yes);
                        return false;
                    }
                }
            }
        }
    }

    return true;
}
