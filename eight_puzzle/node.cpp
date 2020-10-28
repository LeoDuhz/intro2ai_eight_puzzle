#include "node.h"

int node::type = 1; //默认选择h1启发式函数

int node::target_matrix[3][3] = {0};

node::node():f(0),g(0),h(0),parentIndex(-1)/*parent(nullptr)*/
{
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            matrix[i][j] = 0;
        }
    }
}

node::node(int myMatrix[3][3]):f(0),g(0),h(0),parentIndex(-1)/*parent(nullptr)*/
{
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            matrix[i][j] = myMatrix[i][j];
        }
    }
}

node::node(const node& mynode):f(mynode.f),g(mynode.g),h(mynode.h),parentIndex(mynode.parentIndex)/*parent(mynode.parent)*/
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
//    this->parent = mynode.parent;
    this->parentIndex = mynode.parentIndex;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            matrix[i][j] = mynode.matrix[i][j];
        }
    }
}

vector<int> node::findIndex(int num)
{
    vector<int> index;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if (target_matrix[i][j] == num){
                index.push_back(i);
                index.push_back(j);
                return index;
            }
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
    int score = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            vector<int> index = findIndex(matrix[i][j]);
            int target_i = index[0];
            int target_j = index[1];
            score += abs(i - target_i) + abs(j - target_j);
        }
    }
    return score;
}

int node::cal_h3()
{
    int score = 0;
    vector<int> list;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            list.push_back(matrix[i][j]);
        }
    }
    for(int i = 0; i < list.size(); i++){
        for(int j = 0; j < i; j++){
            if (list[i] != 0 && list[i] < list[j]) score++;
        }
    }

    return score;
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
    case 3:
    {
        this->h = cal_h3();
        break;
    }
    }
}

void node::update_f()
{
    update_h();
    this->f = this->g + this->h;
}
