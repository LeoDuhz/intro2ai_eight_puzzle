#ifndef EIGHT_PUZZLE_H
#define EIGHT_PUZZLE_H

#include <iostream>
#include <vector>
#include "node.h"

using namespace std;

class Eight_puzzle
{
public:
    Eight_puzzle();

    vector<node> openlist;
    vector<node> closelist;
    int targetMartix[3][3];
};

#endif // EIGHT_PUZZLE_H
