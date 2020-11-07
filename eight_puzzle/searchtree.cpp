#include "searchtree.h"
#include "ui_searchtree.h"
#include <math.h>
#include "node.h"
#include <vector>
#include "qmessagebox.h"
#include "qstring.h"
#include <QBarSet>
#include <QTime>
#include <QDebug>
#include <QMainWindow>
#include "beforetree.h"

//加入保存整理好的树的节点的头文件
#define Left_Distance 60//左边的预留距离
#define Up_Distance 50//上边的预留距离
#define D_matrix 20//格子左右之间的单位距离
#define A_matrix 42//格子的大小
#define S_matrix 10//字体大小
#define D2_matrix 40//格子上下之间的单位距离


int searchTree::printCnt = 0;

searchTree::searchTree(vector<node> treefather, vector<vector<node>>treebaby, QMainWindow *parent ) :
    QMainWindow(parent),
    ui(new Ui::searchTree)
{
    this->treebaby = treebaby;
    this->treefather = treefather;
    ui->setupUi(this);


}

searchTree::~searchTree()
{
    delete ui;
}

void searchTree::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);

    QPainter painter(this);
    QPen pen;

    painter.setBrushOrigin(0,0);
    draw_tree(treebaby, treefather, printCnt, painter, pen);
    setUpdatesEnabled(true);
}






void searchTree::draw_one_matrix(node Node,long long int center_x,long long int center_y, QPainter &painter, QPen &pen)
{
    //设置颜色
    qDebug("in draw one matrix");
    painter.setPen(pen);
    //画矩形
    painter.drawRect(center_x-A_matrix/2,center_y-A_matrix/2,A_matrix,A_matrix);
    //填数字
    int x_deviation=-3;
    int y_deviation=-6;
    qDebug("draw text began!");

    QString str1 = "", str2 = "", str3 = "";
    str1 = QString::number(Node.f);
    str2 = QString::number(Node.g);
    str3 = QString::number(Node.h);
    QString str4 = "+";
    QString str5 = "=";
    str1.append(str5);
    str1.append(str2);
    str1.append(str4);
    str1.append(str3);

    qDebug("center_x-A_matrix/3+x_deviation %d",center_x-A_matrix/3+x_deviation);
    qDebug("center_y+y_deviation %d", center_y+y_deviation);
    qDebug("QString::number(matrix[0][0]) %d", Node.matrix[0][0]);
    painter.drawText(center_x-A_matrix/3+x_deviation,center_y+y_deviation,QString::number(Node.matrix[0][0]));
    qDebug("one draw text");
    painter.drawText(center_x+x_deviation,center_y+y_deviation,QString::number(Node.matrix[0][1]));
    painter.drawText(center_x+A_matrix/3+x_deviation,center_y+y_deviation,QString::number(Node.matrix[0][2]));
    painter.drawText(center_x-A_matrix/3+x_deviation,center_y+A_matrix/3+y_deviation,QString::number(Node.matrix[1][0]));
    painter.drawText(center_x+x_deviation,center_y+A_matrix/3+y_deviation,QString::number(Node.matrix[1][1]));
    painter.drawText(center_x+A_matrix/3+x_deviation,center_y+A_matrix/3+y_deviation,QString::number(Node.matrix[1][2]));
    painter.drawText(center_x-A_matrix/3+x_deviation,center_y+A_matrix*2/3+y_deviation,QString::number(Node.matrix[2][0]));
    painter.drawText(center_x+x_deviation,center_y+A_matrix*2/3+y_deviation,QString::number(Node.matrix[2][1]));
    painter.drawText(center_x+A_matrix/3+x_deviation,center_y+A_matrix*2/3+y_deviation,QString::number(Node.matrix[2][2]));
    qDebug("draw text end!");
    
    painter.drawText(center_x-A_matrix/2,center_y+A_matrix+y_deviation,str1);

}//用来画每一个小矩阵




void searchTree::draw_brunch(vector<node> Babynode, long long int center_x,long long int center_y,  long long int child_x,long long int child_y,QPainter& painter, QPen &pen){
    int i;

    qDebug("the number of baby %d",Babynode.size());
    for(i=0;i<(int)Babynode.size();i++){
        qDebug("the number of i %d",i);
         draw_one_matrix(Babynode[i],child_x+(D_matrix+A_matrix)*i,child_y,painter,pen);
         pen.setColor(Qt::black);
         painter.setPen(pen);
         painter.drawLine(center_x,center_y+A_matrix/2+15,child_x+(D_matrix+A_matrix)*i,child_y-A_matrix/2);
     }
}


void searchTree::draw_tree(vector<vector<node>> TreeBaby, vector<node> Tree_Father, int num, QPainter& painter, QPen& pen)
{

    int num_wedth = 0;
    int center_x=Left_Distance+A_matrix/2, center_y=Up_Distance+A_matrix/2,child_x,child_y;
    vector<node> Babynow;
    node Fathernow;

    draw_one_matrix(Tree_Father[0],center_x,center_y,painter,pen);

    vector<node>::iterator it;
    vector<node> deepmin;
    deepmin.push_back(Tree_Father[0]);
    deep.push_back(deepmin);

    for(int nu=0;nu<num;nu++){
        Babynow = TreeBaby[nu];
        Fathernow = Tree_Father[nu];

        deepFather(Tree_Father,TreeBaby);

        if((int)deep.size()-1==depth){//新建一层
           center_x=A_matrix*(wedth)+D_matrix*(wedth)+Left_Distance+A_matrix/2;
           center_y=A_matrix*(depth)+D2_matrix*(depth)+Up_Distance+A_matrix/2;
           child_x=Left_Distance+A_matrix/2;
           child_y=A_matrix*(depth+1)+D2_matrix*(depth+1)+Up_Distance+A_matrix/2;
           draw_brunch(Babynow,center_x,center_y, child_x, child_y,painter, pen);
        }
        else{//已有层
           num_wedth=deep[depth + 1].size();
           center_x=A_matrix*(wedth)+D_matrix*(wedth)+Left_Distance+A_matrix/2;
           center_y=A_matrix*(depth)+D2_matrix*(depth)+Up_Distance+A_matrix/2;
           child_x=A_matrix*(num_wedth)+D_matrix*(num_wedth)+Left_Distance+A_matrix/2;
           child_y=A_matrix*(depth+1)+D2_matrix*(depth+1)+Up_Distance+A_matrix/2;
           draw_brunch(Babynow,center_x,center_y, child_x, child_y, painter, pen);
        }
        deeppush(TreeBaby);


    }
}


void searchTree::deepFather(vector<node> Tree_Father, vector<vector<node>> TreeBaby){
    static int many = 0;
    int num;
    vector<node> deepmin;
    vector<node>::iterator it;
    int num1 = deep.size();
    if(num1 == 0){
        deepmin.push_back(Tree_Father[0]);
        deep.push_back(deepmin);

        for(it = deepmin.begin(); it != deepmin.end(); ){
            it = deepmin.erase(it);
        }
        for(int i = 0; i < TreeBaby[0].size();i++)
        deepmin.push_back(TreeBaby[0][i]);
        deep.push_back(deepmin);
        for(it = deepmin.begin(); it != deepmin.end(); ){
            it = deepmin.erase(it);
        }
        depth = 0;
        wedth = 0;
    }
    else{
        num = deep.size() - 1;
        for (int j = num; j >= 0; j--) {
            for (int i = 0; i < deep[j].size(); i++) {
                if (checkMatrixEqual(deep[j][i].matrix, Tree_Father[many].matrix)) {
                    depth = j;
                    wedth = i;
                    break;
                }
            }
        }
    }
    many++;
}


void searchTree::deeppush(vector<vector<node>> TreeBaby){

    vector<node>::iterator it;
    static int many = 0;
    vector<node> deepmin;
    if(this->depth == this->deep.size() - 1){
        for(int i = 0; i < TreeBaby[many].size();i++)
        deepmin.push_back(TreeBaby[many][i]);
        this->deep.push_back(deepmin);
        for(it = deepmin.begin(); it != deepmin.end(); ){
            it = deepmin.erase(it);
        }
    }
    else{
        for(int i = 0; i < TreeBaby[many].size();i++)
        deep[depth + 1].push_back(TreeBaby[many][i]);
    }
    many++;
}

bool searchTree::checkMatrixEqual(const int Matrix1[3][3], const int Matrix2[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if (Matrix1[i][j] != Matrix2[i][j]) return false;
        }
    }
    return true;
}




void searchTree::on_step_clicked()
{
    printCnt = ui->layer->text().toInt();

    repaint();
}

void searchTree::on_close_clicked()
{
    this->close();
}
