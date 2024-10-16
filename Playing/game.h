#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QWidget>
#include <QVector>
#include "board.h"
#include "player.h"
#include <QFuture>
#include <QSoundEffect>

class Game :public QObject{
        Q_OBJECT
public:
    Game(bool aiMode,QObject* parent = nullptr);
    static Game* instance;
    ~Game();
    void start();
    bool checkGameOver();
    int getRound(bool isTurn);//false指一来一回，true指进行的操作数
    QVector<Cell*> getAvaliablePositions(Piece* tar = nullptr);

    void setChoosedPiece(Piece* piece);//传入一个空指针来清空
    void setChoosedCell(Cell* cell);

private:
    bool aiMode;
    Player* players[2]{nullptr};
    Board* board;
    int currentPlayer;
    bool isGameOver;
    Piece* queenBees[2]{nullptr};
    int round;

    Piece* choosedPiece = nullptr;
    QVector<QWidget*> displayedAvailableCellWidget;
    Cell* choosedCell = nullptr;

    QFuture<void> future;
    void switchPlayer();
    void playTurn();
    void loadAndUsePlugin(const QString& pluginPath);

    QSoundEffect effect;

};

#endif // GAME_H
