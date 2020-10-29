#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qlabel.h"
#include "qlineedit.h"
#include "eight_puzzle.h"
#include "node.h"
#include "playback.h"

using namespace std;


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    vector<node> transferList;


private slots:
    void on_aboutUs_clicked();

    void on_algorithm_clicked();

    void on_initial_set_clicked();

    void on_initial_set_final_clicked();


    void on_continuous_clicked();


    void on_singlestep_clicked();

    void on_h1_clicked();

    void on_h2_clicked();

    void on_h3_clicked();

    void on_playback_clicked();

private:
    Ui::MainWindow *ui;
    QLineEdit* judgeNum(std::vector<int> list, string s, int i);
    void displayTransOnce(int matrix[3][3]);

};
#endif // MAINWINDOW_H
