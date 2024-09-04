#ifndef BOARD_H
#define BOARD_H

#include <QObject>
#include <QWidget>
#include <QVector>
//#include "cell.h"
#include "piece.h"
#include "position.h"
class Cell;
class Board :public QObject{
    Q_OBJECT

public:
    Board(QObject* parent = nullptr);
    /*
     * @brief 从给定的位置获取Cell
     */
    Cell* getPositionCell(const Position *position) const;
    /*
     * @brief 获取可以放新棋子的位置，可移动位置写在每个Piece子类中
     */
    QVector<Position> getValidPlaces(const Piece* piece) const;
    /*
     * @brief 放置选定的棋子
     */
    void placePiece(Piece* piece, const Position *position);
    /*
     * @brief 将选择的棋子移动到给定的位置
     */
    void movePiece(Piece* piece, const Position *newPosition);

private:
    QVector<QVector<Cell*>> cells;
};

#endif // BOARD_H
