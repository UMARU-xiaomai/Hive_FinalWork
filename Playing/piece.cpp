#include "piece.h"
#include <QMetaEnum>
#include "cell.h"

Piece::Piece(int belongingPlayer,QObject *parent)
    : QObject{parent},belonginfPlayer(belongingPlayer)
{
    //TODO
}
void Piece::initWidget()
{
    widget = new PieceWidget(this);
    widget->setPieceBelonging(belongingPlayer);
}
///
/// \brief Piece::isPlaced 获取是否已经被放置
/// \return
///
bool Piece::isPlaced()
{
    return currentCell !=nullptr;
}

PieceWidget *Piece::getPieceWidget()
{
    return widget;
}
///
/// \brief Piece::getCell 获取Cell
/// \return
///
Cell *Piece::getCell() const
{
   return currentCell;
}

// bool Piece::isQB = false;

///
/// \brief Piece::setCell设置新的放置在的Cell
/// \param cell
///
void Piece::setCell(Cell *cell)
{
    currentCell = cell;
}

bool Piece::canBeMoved() const
{
    QVector<Cell*> segs;
    if(getCell()->getPiecesNum()>=2)
        return true;
    for(int i=0;i<6;i++)
    {
        Cell* cur = getCell()->getAdjacentCell(i);
        Cell* next = getCell()->getAdjacentCell(i>=5?0:i+1);

        if(cur->getPiece()&&!next->getPiece())
            segs.push_back(cur);
    }
    if(segs.size()<=1)
    {
        return true;
    }else
    {
        //回路检测算法

        return false;
    }

}
