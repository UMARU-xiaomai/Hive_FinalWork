#include "cell.h"

Cell::Cell(const Position &position, QObject *parent)
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
