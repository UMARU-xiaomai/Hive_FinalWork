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
    static Game* instance;
    ~Game();
    void start();
    void playTurn();
    void checkGameOver();
    int getRound(bool isTurn);//false指一来一回，true指进行的操作数

    void setChoosedPiece(Piece* piece);
    void setChoosedPosition(Position* position);

private:
    bool aiMode;
    QVector<Player*> players;
    Board* board;
    int currentPlayer;
    bool isGameOver;
    QVector<Piece*> queenBees;
    int round;

    Piece* choosedPiece = nullptr;
    QVector<QWidget*> displayedAvailableCellWidget;
    Position* choosedPosition = nullptr;

    QFuture<void> future;
    void switchPlayer();

};

#endif // GAME_H
