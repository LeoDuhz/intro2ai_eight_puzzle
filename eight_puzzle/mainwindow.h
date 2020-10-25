#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qlabel.h"
#include "qlineedit.h"

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


private slots:
    void on_aboutUs_clicked();

    void on_algorithm_clicked();

    void on_initial_set_clicked();

    void on_initial_set_final_clicked();


    void on_continuous_clicked();

private:
    Ui::MainWindow *ui;
    QLineEdit* judgeZero(std::vector<int> list, string s);

};
#endif // MAINWINDOW_H
