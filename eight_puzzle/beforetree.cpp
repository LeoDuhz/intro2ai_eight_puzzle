#include"beforetree.h"
#include "qmessagebox.h"
#include "qstring.h"

beforetree::beforetree(vector<vector<node>> olList){
    this->olList = olList;
}
void beforetree::Father_Baby(){
    //static int num = 0;
    int num = 100;

    while(1){
        if(num > olList.size()){
            num--;
        }
        if(num <= olList.size()){
            break;
        }
    }
    qDebug("the number of olList0 %d",olList[0].size());
    qDebug("the number of olList1 %d",olList[1].size());
    for(int h = 0; h < num; h++){
        for(int i = 0; i < olList[h].size(); i++){
            for(int j = 0; j < olList[h + 1].size(); j++){
                if(checkMatrixEqual(olList[h][i].matrix, olList[h+1][j].matrix)){
                    break;
                }
                if((j == olList[h + 1].size() - 1) && !(checkMatrixEqual(olList[h][i].matrix, olList[h+1][j].matrix))){
                    Tree_Father.push_back(olList[h][i]);
                }
            }
        }


        for(int i = 0; i < olList[h + 1].size(); i++){
            for(int j = 0; j < olList[h].size(); j++){
                if(checkMatrixEqual(olList[h + 1][i].matrix, olList[h][j].matrix)){
                    break;
                }
                if((j == olList[h].size() - 1) && !(checkMatrixEqual(olList[h + 1][i].matrix, olList[h][j].matrix))){
                    Tree_Baby.push_back(olList[h + 1][i]);
                }
            }

        }
        qDebug("the number of Tree_Father %d",Tree_Father.size());
        qDebug("the number of Tree_Baby %d",Tree_Baby.size());
        TreeBaby.push_back(Tree_Baby);
        vector<node>::iterator it;
        for(it = Tree_Baby.begin(); it != Tree_Baby.end(); ){
            it = Tree_Baby.erase(it);
        }
    }
    vector<int> num2;
    for(int i = 0; i < TreeBaby.size();i++){
        num2.clear();
        for(int j = 0; j < TreeBaby[i].size();j++){
            for(int h = i + 1;(h + i + 1)< Tree_Father.size();h++){
                if(checkMatrixEqual(Tree_Father[h].matrix, TreeBaby[i][j].matrix)){
                    num2.push_back(h);
                    break;
                }
                if((h + j + 2) == Tree_Father.size() && !(checkMatrixEqual(Tree_Father[h].matrix, TreeBaby[i][j].matrix))){
                    num2.push_back(100);
                }
            }
        }
        qDebug("the number of num2 %d",num2.size());
        qDebug("the number of num22222 %d",TreeBaby[i].size());
        int number = num2.size();
        for(int k = 0; (k+1) < number;k++){
            int min_index = k;
            for(int p = k; p < number; p++)
            {
                if(num2[p] < num2[min_index]){
                    min_index = p;
                }
            }
            node temp;
            temp = TreeBaby[i][min_index];
            TreeBaby[i][min_index] = TreeBaby[i][k];
            TreeBaby[i][k] = temp;
        }

    }

}

bool beforetree::checkMatrixEqual(const int Matrix1[3][3], const int Matrix2[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if (Matrix1[i][j] != Matrix2[i][j]) return false;
        }
    }
    return true;
}

