#ifndef PIECE_H
#define PIECE_H

#include <QObject>
//#include <QWidget>
// #include "position.h"
#include "piecewidget.h"
#include "pieceinterface.h"
//#include "cell.h"
//#include "board.h"

class Board;
class Cell;
//enum PieceType { QueenBee, Spider ,Beetle, Grasshopper,SoldierAnt};
class Piece : public QObject , public PieceInterface {
    Q_OBJECT

public:


    Piece(int belongingPlayer,QObject *parent = nullptr);
    bool isPlaced();///<是否已经被放到棋盘上
    PieceWidget* getPieceWidget();
    Cell* getCell() const;
    void setCell(Cell* cell);
    int belongingPlayer;
    void initWidget();
protected:
    Cell* currentCell = nullptr;///<现在的位置
    PieceWidget* widget;
    bool canBeMoved() const;
    bool DFS(Cell* curCell,QSet<Cell*> &passed,const QVector<Cell*> &segs) const;

};

#endif // PIECE_H
