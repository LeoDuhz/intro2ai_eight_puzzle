#include "node.h"

int node::type = 1; //默认选择h1启发式函数

int node::target_matrix[3][3] = {0};

node::node():f(0),g(0),h(0),parent(nullptr)
{
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            matrix[i][j] = 0;
        }
    }
}

node::node(int myMatrix[3][3]):f(0),g(0),h(0),parent(nullptr)
{
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            matrix[i][j] = myMatrix[i][j];
        }
    }
}

node::node(const node& mynode):f(mynode.f),g(mynode.g),h(mynode.h),parent(mynode.parent)
{
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            matrix[i][j] = mynode.matrix[i][j];
        }
    }
}

node& node::operator= (const node& mynode){
    this->f = mynode.f;
    this->g = mynode.g;
    this->h = mynode.h;
    this->parent = mynode.parent;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            matrix[i][j] = mynode.matrix[i][j];
        }
    }
}
//h1:不在位置的数码个数
int node::cal_h1()
{
    int score = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if (matrix[i][j] != target_matrix[i][j]) score++;
        }
    }
    return score;
}

int node::cal_h2()
{

}

void node::update_h()
{
    switch(type){
    case 1:
    {
        this->h = cal_h1();
        break;
    }
    case 2:
    {
        this->h = cal_h2();
        break;
    }


    }
}

void node::update_f()
{
    update_h();
    this->f = this->g + this->h;
}
