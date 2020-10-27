#ifndef NODE_H
#define NODE_H


class node
{
public:
//    friend class Heuristic_function;
    node();
    node(int myMatrix[3][3]);
    node(const node& mynode);
    node& operator= (const node& mynode);
    int matrix[3][3];
    int f;
    int g;
    int h;
    node *parent;
    static int type;
    static int target_matrix[3][3];

    int cal_h1();
    int cal_h2();
    void update_h();
    void update_f();
};


#endif // NODE_H
