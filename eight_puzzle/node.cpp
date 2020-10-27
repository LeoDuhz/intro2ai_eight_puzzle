#include "node.h"

int node::type = 1; //默认选择h1启发式函数

node::node(int myMatrix[3][3]):f(0),g(0),h(0),parent(nullptr)
{
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            matrix[i][j] = myMatrix[i][j];
        }
    }
}

//h1:不在位置的数码个数
int node::cal_h1(int targetMatrix[3][3])
{
    int score = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if (matrix[i][j] != targetMatrix[i][j]) score++;
        }
    }
    return score;
}

int node::cal_h2(int targetMatrix[3][3])
{

}

void update_f()
{

}
