#ifndef PIECE_H
#define PIECE_H

#include <QObject>
#include <QWidget>
#include "position.h"
#include "piecewidget.h"
//#include "board.h"

class Board;
enum class PieceType { QueenBee, Spider ,Beetle, Grasshopper,SoldierAnt};

class Piece : public QObject {
    Q_OBJECT

public:
    Piece(int belongingPlayer,PieceType type, QObject *parent = nullptr);
    bool isPlaced;///<是否已经被放到棋盘上
    virtual QVector<Position> getValidMoves(const Board* board) const = 0;// 获取可移动位置虚函数，无需实现
    PieceWidget* getPieceWidget();
    Position* getPosition();
    int belongingPlayer;
protected:
    PieceType type;///<棋子种类
    Position currentPosition;///<现在的位置
    PieceWidget* widget;
};

#endif // PIECE_H
