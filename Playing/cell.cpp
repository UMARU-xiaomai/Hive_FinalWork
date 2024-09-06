#include "cell.h"

Cell::Cell(int x,int y, QObject *parent)
    : QObject{parent}
{

}

void Cell::setPiece(Piece *piece)
{
    this->piece.append(piece);
}

Piece *Cell::getPiece() const
{
    return piece.top();//仅获取
}

Position *Cell::getPosition()
{
    return &position;
}
