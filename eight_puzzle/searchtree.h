#ifndef SEARCHTREE_H
#define SEARCHTREE_H

#include <QWidget>
#include <QMainWindow>
#include <QPainter>//绘制图案头文件
#include <QPen>
#include "node.h"
#include <QDialog>
#include <vector>

namespace Ui {
class searchTree;
}

class searchTree : public QMainWindow
{
    Q_OBJECT

public:
    static int printCnt;

    vector<vector<node>> deep;
    int depth = 0;
    int wedth = 0;

    ~searchTree();
    vector<node> treefather;
    vector<vector<node>> treebaby;
    explicit searchTree(vector<node> treefather, vector<vector<node>>treebaby, QMainWindow *parent = nullptr);
    bool checkMatrixEqual(const int Matrix1[3][3], const int Matrix2[3][3]);

    void paintEvent(QPaintEvent *event);
    void draw_tree(vector<vector<node>> TreeBaby, vector<node> Tree_Father,int n ,QPainter& painter, QPen& pen);
    void draw_brunch(vector<node> Babynode, long long int center_x,long long int center_y,  long long int child_x,long long int child_y,QPainter& painter, QPen &pen);
    void deepFather(vector<node> Tree_Father,vector<vector<node>> TreeBaby);
    void draw_one_matrix(int matrix[3][3],long long int center_x,long long int center_y, QPainter &painter, QPen &pen);
    void deeppush(vector<vector<node>> TreeBaby);

protected:
//    void paintEvent(QPaintEvent *event);

private slots:
    void on_step_clicked();

    void on_close_clicked();

private:
    Ui::searchTree *ui;
    vector<node> path;
};

#endif // SEARCHTREE_H
