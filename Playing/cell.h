#ifndef CELL_H
#define CELL_H

#include <QObject>
#include "piece.h"
#include "position.h"
#include <QStack>

class Cell : public QWidget {
    Q_OBJECT

public:
    Cell(const Position &position, QWidget *parent = nullptr);
    /*
     * @brief 添加棋子到此单元格，tip：piece.push(piece);
     */
    void setPiece(Piece* piece);
    /*
     * @brief 获取当前位置上的棋子，返回nullptr则表示没有棋子；由于使用栈存储棋子，若要移动棋推荐使用pop()取出
     */
    Piece* getPiece() const;

private:
    Position position;///<当前位置
    QStack<Piece*> piece; ///<由于甲虫的存在，使用栈存储棋子
};

#endif // CELL_H
