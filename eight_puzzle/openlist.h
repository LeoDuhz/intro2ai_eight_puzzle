#ifndef OPENLIST_H
#define OPENLIST_H

#include <iostream>
#include <QDialog>
#include "node.h"

using namespace std;

namespace Ui {
class openlist;
}

class openlist : public QDialog
{
    Q_OBJECT

public:
    explicit openlist(vector<vector<node>> olList, QWidget *parent = nullptr);
    ~openlist();

    void displayPlayback(vector<node> transferList);
    void loopDisplay();

    vector<vector<node>> olList;

private slots:
    void on_start_clicked();

    void on_close_clicked();

private:
    Ui::openlist *ui;

    bool isWindowClosed = false;
};

#endif // OPENLIST_H
