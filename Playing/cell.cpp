#include "cell.h"
#include "board.h"


Cell::Cell(int x,int y, QObject *parent)
    : QObject{parent}
{
    //TODO
}
///
/// \brief Cell::setPiece 存储新的piece到该位置
/// \param piece
///
void Cell::setPiece(Piece *piece)
{
    //TODO
    //提示：Cell用栈存储piece，反之piece只有一个cell
}
///
/// \brief Cell::getPiece 获取第一个棋子
/// \param pop 是否要删除取出的棋子
/// \return
///
Piece *Cell::getPiece(bool pop)
{
    //TODO
    //提示：Top/pop
}
///
/// \brief Cell::getPiecesNum 获取棋子数目
/// \return
///
int Cell::getPiecesNum()
{
    //TODO
}

///
/// \brief Cell::getPosition 获取该Cell的Position指针
/// \return
///
Position *Cell::getPosition()
{
    //TODO
}

Cell *Cell::getAdjacentCell(int i,bool dontCreNewCell)
{
    Cell* resCell = adjacentCells[i];
    if(!resCell)
    {
        Position* curPosition = this->getPosition()->getAdjacentPosition(i);
        resCell = Board::instance->getPositionCell(curPosition,dontCreNewCell);

        this->setAdjacentCell(i,resCell);

        delete curPosition;
    }
    return resCell;
}
///
/// \brief Cell::setAdjacentCell 设置临近Cell数组
/// \param i
/// \param cell
///
void Cell::setAdjacentCell(int i, Cell *cell)
{
    //TODO
}

bool Cell::checkPieceBelongingHere(int tarBelong)
{
    for(auto i : piecesHere)
    {
        if(i->belongingPlayer == tarBelong)
            return true;
    }
    return false;
}
