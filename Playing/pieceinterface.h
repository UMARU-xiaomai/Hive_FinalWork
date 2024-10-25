#ifndef PIECEINTERFACE_H
#define PIECEINTERFACE_H

#include <QString>
#include <QtPlugin>
class Cell;
class Board;

class PieceInterface
{
public:

    virtual QVector<Cell*> getValidMoves(Board* board) const = 0;// 获取可移动位置虚函数，无需实现
    virtual bool isQueenBee() const = 0;
    virtual QString typeStr() const = 0;
    virtual int startQuantity() const = 0;
    virtual QString getImgPath() const = 0;
};

Q_DECLARE_INTERFACE(PieceInterface,"com.Hive.PieceInterface");
#endif // PIECEINTERFACE_H

