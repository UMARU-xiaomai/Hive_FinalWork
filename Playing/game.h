#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QWidget>
#include <QVector>
#include "board.h"
#include "player.h"
#include <QFuture>

class Game :public QObject{
        Q_OBJECT
public:
    Game(bool aiMode,QObject* parent = nullptr);
    ~Game();
    void start();
    void playTurn();
    void checkGameOver();
    int getRound();

private:
    bool aiMode;
    QVector<Player*> players;
    Board* board;
    int currentPlayer;
    bool isGameOver;
    QVector<Piece*> queenBees;
    int round;

    Piece* choosedPiece = nullptr;
    Position* choosedPosition = nullptr;

    QFuture<void> future;
    void switchPlayer();

};

#endif // GAME_H
