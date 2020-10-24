#ifndef HEURISTIC_FUNCTION_H
#define HEURISTIC_FUNCTION_H

#include <QDialog>

namespace Ui {
class Heuristic_function;
}

class Heuristic_function : public QDialog
{
    Q_OBJECT

public:
    explicit Heuristic_function(QWidget *parent = nullptr);
    ~Heuristic_function();

private slots:
    void on_h1_button_clicked();

private:
    Ui::Heuristic_function *ui;
};

#endif // HEURISTIC_FUNCTION_H
