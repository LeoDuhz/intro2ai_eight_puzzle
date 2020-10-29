#include "eight_puzzle.h"
#include "qmessagebox.h"
#include "qstring.h"
#include <QTime>

int Eight_puzzle::actionCount = 0;
int Eight_puzzle::addToOpenListCnt = 0;
double Eight_puzzle::solveTime = 0;

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
    actionCount = 0;
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
    actionCount = 0;
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

int Eight_puzzle::getReverseOrder(vector<int> list)
{
    int reverseOrder = 0;
    for(int i = 0; i < list.size(); i++){
        for(int j = 0; j < i; j++){
            if (list[i] != 0 && list[i] < list[j]) reverseOrder++;
        }
    }

    return reverseOrder;
}

bool Eight_puzzle::reverseOrderExamine()
{
    //initial matrix reverse order
    int iniReverseOrder = 0;
    vector<int> iniList;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            iniList.push_back(initMatrix[i][j]);
        }
    }

    iniReverseOrder = getReverseOrder(iniList);

    //final matrix reverse order
    int finalReverseOrder = 0;
    vector<int> finalList;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            finalList.push_back(finalMatrix[i][j]);
        }
    }

    finalReverseOrder = getReverseOrder(finalList);

    if (iniReverseOrder % 2 == finalReverseOrder % 2) return true;
    return false;

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

bool Eight_puzzle::checkMatrixEqual(const int Matrix1[3][3], const int Matrix2[3][3]){
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

int Eight_puzzle::findMinInOpenList()
{
    int min_f = 9999;
    int min_index = -1;
    node min_node;
    for(int i = 0; i < openlist.size(); i++){
        if (openlist[i].f < min_f){
            min_index = i;
            min_f = openlist[i].f;
            min_node = openlist[i];
        }
    }

    return min_index;
}

bool Eight_puzzle::inCloseList(const int matrix[3][3])
{
    for(int i = 0; i < closelist.size(); i++){
        if(checkMatrixEqual(matrix, closelist[i].matrix)) return true;
    }

    return false;
}

void Eight_puzzle::addToOpenList(const node& newnode)
{
    addToOpenListCnt++;
    if(inCloseList(newnode.matrix)) return;

    for(int i = 0; i < openlist.size(); i++){
        if (checkMatrixEqual(openlist[i].matrix, newnode.matrix)){
            if(newnode.f < openlist[i].f){
                openlist.erase(openlist.begin() + i);
                openlist.push_back(newnode);
                return;
            }
            return;
        }
    }

    openlist.push_back(newnode);
}

void Eight_puzzle::addToCloseList(const node& transferNode)
{
    closelist.push_back(transferNode);
}

void Eight_puzzle::moveNode(int matrix[3][3], int x, int y, int g, int parentIndex, int direction)
{
    static int moveNodeCnt = 0;
    moveNodeCnt++;
//    qDebug("moveNodeCnt: %d", moveNodeCnt);
    int newMatrix[3][3];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            newMatrix[i][j] = matrix[i][j];
        }
    }
    switch(direction)
    {
    case 1: //right move
    {
        newMatrix[x][y] = matrix[x][y+1];
        newMatrix[x][y+1] = matrix[x][y];
        break;
    }
    case 2: //left move
    {
        newMatrix[x][y] = matrix[x][y-1];
        newMatrix[x][y-1] = matrix[x][y];
        break;
    }
    case 3: //up move
    {
        newMatrix[x][y] = matrix[x-1][y];
        newMatrix[x-1][y] = matrix[x][y];
        break;
    }
    case 4: //down move
    {
        newMatrix[x][y] = matrix[x+1][y];
        newMatrix[x+1][y] = matrix[x][y];
        break;
    }
    }
    node newnode(newMatrix);
    newnode.g = g;
    newnode.update_f();
    newnode.parentIndex = parentIndex;
    addToOpenList(newnode);

    return;
}

void Eight_puzzle::expandNode(const node& transferNode, int indexInCloseList)
{
    int matrix[3][3];

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            matrix[i][j] = transferNode.matrix[i][j];
        }
    }

    vector<int> zeroPos = findZeroPos(matrix);
    int x = zeroPos[0];
    int y = zeroPos[1];
//    qDebug("zero x: %d",x);
//    qDebug("zero y: %d", y);
    if (x == 0 && y == 0)
    {
        moveNode(matrix, x, y, transferNode.g + 1, indexInCloseList, 1);
        moveNode(matrix, x, y, transferNode.g + 1, indexInCloseList, 4);

    }
    else if (x == 0 && y == 1)
    {
        moveNode(matrix, x, y, transferNode.g + 1, indexInCloseList, 1);
        moveNode(matrix, x, y, transferNode.g + 1, indexInCloseList, 2);
        moveNode(matrix, x, y, transferNode.g + 1, indexInCloseList, 4);
    }
    else if (x == 0 && y == 2)
    {
        moveNode(matrix, x, y, transferNode.g + 1, indexInCloseList, 2);
        moveNode(matrix, x, y, transferNode.g + 1, indexInCloseList, 4);
    }
    else if (x == 1 && y == 0)
    {
        moveNode(matrix, x, y, transferNode.g + 1, indexInCloseList, 1);
        moveNode(matrix, x, y, transferNode.g + 1, indexInCloseList, 3);
        moveNode(matrix, x, y, transferNode.g + 1, indexInCloseList, 4);
    }
    else if (x == 1 && y == 1)
    {
        moveNode(matrix, x, y, transferNode.g + 1, indexInCloseList, 1);
        moveNode(matrix, x, y, transferNode.g + 1, indexInCloseList, 2);
        moveNode(matrix, x, y, transferNode.g + 1, indexInCloseList, 3);
        moveNode(matrix, x, y, transferNode.g + 1, indexInCloseList, 4);
    }
    else if (x == 1 && y == 2)
    {
        moveNode(matrix, x, y, transferNode.g + 1, indexInCloseList, 2);
        moveNode(matrix, x, y, transferNode.g + 1, indexInCloseList, 3);
        moveNode(matrix, x, y, transferNode.g + 1, indexInCloseList, 4);
    }
    else if (x == 2 && y == 0)
    {
        moveNode(matrix, x, y, transferNode.g + 1, indexInCloseList, 1);
        moveNode(matrix, x, y, transferNode.g + 1, indexInCloseList, 3);
    }
    else if (x == 2 && y == 1)
    {
        moveNode(matrix, x, y, transferNode.g + 1, indexInCloseList, 1);
        moveNode(matrix, x, y, transferNode.g + 1, indexInCloseList, 2);
        moveNode(matrix, x, y, transferNode.g + 1, indexInCloseList, 3);
    }
    else if (x == 2 && y == 2)
    {
        moveNode(matrix, x, y, transferNode.g + 1, indexInCloseList, 2);
        moveNode(matrix, x, y, transferNode.g + 1, indexInCloseList, 3);
    }

}

void Eight_puzzle::continueSolve()
{
    actionCount = 0;
    addToOpenListCnt = 0;
    double startTime = (double)clock();
    QTime timer;
    timer.start();
    initOpenList();
    if (!reverseOrderExamine()){
        QMessageBox::information(NULL, "Waring", "此状态下无解", QMessageBox::Yes, QMessageBox::Yes);
        return;
    }
    while (openlist.size() != 0)
    {
        actionCount++;
        int min_index = findMinInOpenList();
        node transferNode(openlist[min_index]);

        if (checkMatrixEqual(transferNode.matrix, finalMatrix)){
            addToCloseList(transferNode);
            qDebug("find the result!!!");
            break;
        }

        if(!inCloseList(transferNode.matrix)) addToCloseList(transferNode);
        openlist.erase(openlist.begin() + min_index);

        expandNode(transferNode, closelist.size() - 1);


        qDebug("size of openlist: %d", openlist.size());
        qDebug("size of closelist: %d", closelist.size());

//        if(openlist.size() == 0){
//            QMessageBox::information(NULL, "Waring", "此状态下无解", QMessageBox::Yes, QMessageBox::Yes);
//            return;
//        }

    }
    double endTime = (double)clock();
    solveTime = (endTime - startTime) / 1000;  //ms为单位
    qDebug("solve time: %f", solveTime);
    qDebug("node cnt: %d", addToOpenListCnt);
    backSearch(closelist[closelist.size() - 1]);
}

void Eight_puzzle::backSearch(node& finalNode)
{
    node tmpNode(finalNode);
    while(tmpNode.parentIndex != -1)
    {
        transferNodes.push_back(tmpNode);
        tmpNode = closelist[tmpNode.parentIndex];
    }

    reverse(transferNodes.begin(), transferNodes.end());
}
