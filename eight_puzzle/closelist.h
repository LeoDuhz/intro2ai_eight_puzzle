#ifndef CLOSELIST_H
#define CLOSELIST_H

#include <QDialog>
#include "node.h"

namespace Ui {
class closelist;
}

class closelist : public QDialog
{
    Q_OBJECT

public:
    explicit closelist(vector<vector<node>> clList, QWidget *parent = nullptr);
    ~closelist();

    void displayPlayback(vector<node> transferList);
    void loopDisplay();

    vector<vector<node>> clList;

private slots:
    void on_start_clicked();

    void on_close_clicked();

private:
    Ui::closelist *ui;

    bool isWindowClosed = false;
};

#endif // CLOSELIST_H
