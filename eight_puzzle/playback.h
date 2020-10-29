#ifndef PLAYBACK_H
#define PLAYBACK_H

#include <QDialog>
#include "node.h"


namespace Ui {
class Playback;
}

class Playback : public QDialog
{
    Q_OBJECT

public:
    explicit Playback(vector<node> transferList, QWidget *parent = nullptr);
    ~Playback();

    void displayPlayback(vector<node> transferList);

private:
    Ui::Playback *ui;
};

#endif // PLAYBACK_H
