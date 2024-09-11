#ifndef PIECE_H
#define PIECE_H

#include <QObject>
//#include <QWidget>
#include "position.h"
#include "piecewidget.h"
//#include "cell.h"
//#include "board.h"

class Board;
class Cell;
//enum PieceType { QueenBee, Spider ,Beetle, Grasshopper,SoldierAnt};
class Piece : public QObject {
    Q_OBJECT

public:


    Piece(int belongingPlayer,QObject *parent = nullptr);
    bool isPlaced();///<是否已经被放到棋盘上
    virtual QVector<Cell*>* getValidMoves(Board* board) const = 0;// 获取可移动位置虚函数，无需实现
    PieceWidget* getPieceWidget();
    Cell* getCell() const;

    void setCell(Cell* cell);
    int belongingPlayer;
    virtual bool isQueenBee() const = 0;
    virtual QString typeStr() const = 0;
    virtual int startQuantity() const = 0;
    virtual QString getImgPath() const = 0;
    void initWidget();
protected:
    Cell* currentCell = nullptr;///<现在的位置
    PieceWidget* widget;
    bool canBeMoved() const;

};

#endif // PIECE_H
