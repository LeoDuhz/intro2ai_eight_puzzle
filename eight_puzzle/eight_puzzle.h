#ifndef EIGHT_PUZZLE_H
#define EIGHT_PUZZLE_H

#include <iostream>
#include <vector>
#include "node.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;

class Eight_puzzle
{
public:
    Eight_puzzle();

    static int actionCount;
    vector<node> openlist;
    vector<node> closelist;
    int initMatrix[3][3];
    int finalMatrix[3][3];
    vector<node> transferNodes;

    int getReverseOrder(vector<int> list);
    bool reverseOrderExamine();
    void readInInitial(Ui::MainWindow *ui);
    void readInFinal(Ui::MainWindow *ui);
    bool checkMatrixValid(int matrix[3][3]);
    bool checkMatrixEqual(const int Matrix1[3][3], const int Matrix2[3][3]);
    bool checkIndexValid(int i, int j);
    vector<int> findZeroPos(int matrix[3][3]);


    void initOpenList();
    void addToOpenList(const node& newnode);
    void addToCloseList(const node& transferNode);
    int findMinInOpenList();
    bool inCloseList(const int matrix[3][3]);
    void moveNode(int matrix[3][3], int x, int y, int g, int parentIndex, int direction);
    void expandNode(const node& transferNode, int indexInCloseList);

    void continueSolve();

    void backSearch(node& finalNode);

};

#endif // EIGHT_PUZZLE_H
