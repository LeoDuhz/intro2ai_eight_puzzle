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

    vector<node> openlist;
    vector<node> closelist;
    int initMatrix[3][3];
    int finalMatrix[3][3];

    void readInInitial(Ui::MainWindow *ui);
    void readInFinal(Ui::MainWindow *ui);
    bool checkMatrixValid(int matrix[3][3]);

    void addCloseList();

};

#endif // EIGHT_PUZZLE_H
