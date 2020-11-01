#ifndef BEFORETREE_H
#define BEFORETREE_H

#include<iostream>
#include"node.h"

using namespace std;

class beforetree{
    public:
        vector<vector<node>> olList;
        beforetree(vector<vector<node>> olList);
        vector<node> Tree_Father;
        vector<node> Tree_Baby;
        vector<vector<node>> TreeBaby;

        void Father_Baby();
        bool checkMatrixEqual(const int Matrix1[3][3], const int Matrix2[3][3]);

};



#endif


