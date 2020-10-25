#ifndef NODE_H
#define NODE_H


class node
{
public:
//    friend class Heuristic_function;
    node();
    int martix[3][3];
    int f;
    int g;
    int h;
    node *parent;
    static int type;
    static int target_matrix[3][3];

    int cal_h1();
    int cal_h2();
    void update_f();
};


#endif // NODE_H
