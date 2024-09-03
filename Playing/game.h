#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QWidget>
#include <QVector>
#include "board.h"
#include "player.h"

class Game :public QObject{
        Q_OBJECT
public:
    Game(bool aiMode);
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
