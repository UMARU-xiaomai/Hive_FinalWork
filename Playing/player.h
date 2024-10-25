#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QWidget>
#include <QVector>
#include "piece.h"
#include "pieceinterface.h"
// #include "board.h"

class Player:public QObject{
    Q_OBJECT
public:
    Player(const QString &name, bool isAI,int numOfPlayer,QObject* parent = nullptr);
    // /*
    //  * @brief 选择要操作的棋子
    //  */
    // virtual Piece* selectPiece(Board* board);
    // /*
    //  * @brief 放置选择的新棋子
    //  */
    // virtual void placePiece(Piece* piece ,Board* board, const Position *position);
    // /*
    //  * @brief 移动选择的棋子
    //  */
    // virtual void movePiece(Piece* piece, Board* board, const Position *newPosition);
    QString name;///<Player1/Player2/AI
    void addPlugPiece(PieceInterface* piece);
protected:

    int numberOfPlayer;///<0:玩家1；1：玩家2
    bool isAI;///<是否为AI
    QVector<PieceInterface*> pieces;///<持有的，还没有下到棋盘上的棋子
    bool queenBeePlaced;

};

#endif // PLAYER_H
