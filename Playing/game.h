#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QWidget>
#include <QVector>
#include "board.h"
#include "player.h"

class Game : public QWidget {
    Q_OBJECT

public:
    Game(QWidget *parent = nullptr);
    void start();
    void playTurn();
    void checkGameOver();

private:
    QVector<Player*> players;
    Board* board;
    Player* currentPlayer;
    bool isGameOver;

    void switchPlayer();
};

#endif // GAME_H
