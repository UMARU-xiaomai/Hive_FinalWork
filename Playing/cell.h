#ifndef CELL_H
#define CELL_H

#include <QObject>
#include "piece.h"
#include "position.h"
#include <QStack>

class Cell : public QObject {
    Q_OBJECT

public:
    Cell(int x,int y, QObject *parent = nullptr);
    /*
     * @brief 添加棋子到此单元格，tip：piece.push(piece);
     */
    void setPiece(Piece* piece);
    /*
     * @brief 获取当前位置上的棋子，返回nullptr则表示没有棋子；由于使用栈存储棋子，若要移动棋推荐使用pop()取出
     */
    Piece* getPiece() const;
    Position* getPosition();
    Cell* getAdjacentCell(int i,bool dontCreNewCell = false);
    void setAdjacentCell(int i,Cell* cell);

private:
    Position position;///<当前位置
    QStack<Piece*> piecesHere; ///<由于甲虫的存在，使用栈存储棋子
    QMap<int,Cell*> adjacentCells;///<邻接的Cell
};

#endif // CELL_H
