#ifndef PLAYING_H
#define PLAYING_H

#include <QWidget>
#include "..\Playing\game.h"

namespace Ui {
class Playing;
}

class Playing : public QWidget
{
    Q_OBJECT

public:
    explicit Playing(bool aiMode,QWidget *parent = nullptr);
    static Playing* instance;
    ~Playing();

private slots:
    void on_tieBtn_clicked();

private:
    Ui::Playing *ui;
    Game* mainGame;
};

#endif // PLAYING_H
