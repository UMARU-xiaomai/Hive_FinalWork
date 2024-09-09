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

    this->piece.append(piece);
    piece->setPosition(&position);
}

Piece *Cell::getPiece() const
{
    return piece.top();//仅获取
}

Position *Cell::getPosition()
{
    return &position;
}

Cell *Cell::getAdjacentCell(int i)
{
    Cell* resCell = adjacentCells[i];
    if(!resCell)
    {
        Position* curPosition = this->getPosition()->getAdjacentPosition(i);
        resCell = Board::instance->getPositionCell(curPosition);

        this->setAdjacentCell(i,resCell);

        delete curPosition;
    }
    return resCell;
}

void Cell::setAdjacentCell(int i, Cell *cell)
{
    adjacentCells[i] = cell;
}
