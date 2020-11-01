#ifndef ANALYSIS_H
#define ANALYSIS_H

#include <iostream>
#include <QDialog>
#include <vector>

using namespace std;

namespace Ui {
class analysis;
}

class analysis : public QDialog
{
    Q_OBJECT

public:
    explicit analysis(vector<int> nodeCntList, vector<double> timeList, QWidget *parent = nullptr);
    ~analysis();

private:
    Ui::analysis *ui;
};

#endif // ANALYSIS_H
