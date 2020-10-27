#include "eight_puzzle.h"
#include "qmessagebox.h"
#include "qstring.h"

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

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
//            qDebug("matrix, %d", initMatrix[i][j]);
        }
    }
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

bool Eight_puzzle::checkMatrixEqual(int Matrix1[3][3], int Matrix2[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if (Matrix1[i][j] != Matrix2[i][j]) return false;
        }
    }
    return true;
}

bool Eight_puzzle::checkIndexValid(int i, int j)
{
    if(i < 0 || i >= 3 || j < 0 || j >= 3) return false;
    return true;
}

vector<int> Eight_puzzle::findZeroPos(int matrix[3][3])
{
    vector<int> zeroPos;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if (matrix[i][j] == 0){
                zeroPos.push_back(i);
                zeroPos.push_back(j);
                return zeroPos;
            }
        }
    }
}

void Eight_puzzle::initOpenList()
{
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            node::target_matrix[i][j] = finalMatrix[i][j];
        }
    }
    node init(initMatrix);
    init.g = 0;
    init.update_f();
    openlist.push_back(init);
}

node Eight_puzzle::findMinInOpenList()
{
    int min_f = 9999;
    node min_node;
    for(int i = 0; i < openlist.size(); i++){
        if (openlist[i].f < min_f){
            min_f = openlist[i].f;
            min_node = openlist[i];
        }
    }

    return min_node;
}

void Eight_puzzle::addToOpenList(int matrix[3][3])
{

    node testnode(matrix);
    testnode.g = 0;
    for(int i = 0; i < openlist.size(); i++){
        if (checkMatrixEqual(openlist[i].matrix, matrix)){

        }
    }
}

void Eight_puzzle::addToCloseList(node transferNode)
{
    closelist.push_back(transferNode);
}

void Eight_puzzle::expandNode(node transferNode)
{
    int matrix[3][3];
    int newMatrix[3][3];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            matrix[i][j] = transferNode.matrix[i][j];
            newMatrix[i][j] = transferNode.matrix[i][j];
        }
    }

    vector<int> zeroPos = findZeroPos(matrix);
    int x = zeroPos[0];
    int y = zeroPos[1];

    if (x == 0 && y == 0){
        newMatrix[0][0] = matrix[0][1];
        newMatrix[0][1] = matrix[0][0];
    }else if (x == )

}

void Eight_puzzle::continueSolve()
{
    initOpenList();
    while (true)
    {
        node transferNode = findMinInOpenList();
        transferNodes.push_back(transferNode);

        if (checkMatrixEqual(transferNode.matrix, finalMatrix)){
            addToCloseList(transferNode);
            break;
        }

        addToCloseList(transferNode);

        expandNode(transferNode);

        if(openlist.size() == 0){
            QMessageBox::information(NULL, "Waring", "此状态下无解", QMessageBox::Yes, QMessageBox::Yes);
            break;
        }

    }
}
