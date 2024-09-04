#include "beetle.h"

Beetle::Beetle(int belongingPlayer,QWidget* parent)
    :Piece(belongingPlayer,PieceType::Beetle,parent)
{

}

QVector<Position> Beetle::getValidMoves(const Board *board) const
{

}
