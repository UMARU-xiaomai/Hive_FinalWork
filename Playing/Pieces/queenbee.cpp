#include "queenbee.h"

QueenBee::QueenBee(int belongingPlayer,QWidget* parent)
    :Piece(belongingPlayer,PieceType::QueenBee,parent)
{}

QVector<Position> QueenBee::getValidMoves(const Board *board) const
{

}
