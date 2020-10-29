#ifndef OPENLIST_H
#define OPENLIST_H

#include <QDialog>

namespace Ui {
class openlist;
}

class openlist : public QDialog
{
    Q_OBJECT

public:
    explicit openlist(QWidget *parent = nullptr);
    ~openlist();

private:
    Ui::openlist *ui;
};

#endif // OPENLIST_H
