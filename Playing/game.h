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
    void checkGameOver();
    int getRound(bool isTurn);//false指一来一回，true指进行的操作数

    void setChoosedPiece(Piece* piece);//传入一个空指针来清空
    void setChoosedCell(Cell* cell);

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
    Cell* choosedCell = nullptr;

    QFuture<void> future;
    void switchPlayer();
    void playTurn();

};

#endif // GAME_H
