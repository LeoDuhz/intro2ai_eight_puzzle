#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <vector>

using namespace std;

class node
{
public:
    node();
    node(int myMatrix[3][3]);
    node(const node& mynode);
    node& operator= (const node& mynode);
    int matrix[3][3];
    int f;
    int g;
    int h;
    int parentIndex;
    static int type;
    static int target_matrix[3][3];

    vector<int> findIndex(int num);
    int cal_h1();
    int cal_h2();
    int cal_h3();
    void update_h();
    void update_f();
};


#endif // NODE_H
