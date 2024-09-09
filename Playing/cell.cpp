#include "cell.h"
#include "board.h"


Cell::Cell(int x,int y, QObject *parent)
    : QObject{parent}
{
    position.setX(x);
    position.setY(y);
}

void Cell::setPiece(Piece *piece)
{

    this->piecesHere.push(piece);
    piece->setPosition(&position);
}

Piece *Cell::getPiece() const
{
    if(this->piecesHere.empty())
        return nullptr;
    else
        return piecesHere.top();//仅获取
}

Position *Cell::getPosition()
{
    return &position;
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

void Cell::setAdjacentCell(int i, Cell *cell)
{
    adjacentCells[i] = cell;
}
