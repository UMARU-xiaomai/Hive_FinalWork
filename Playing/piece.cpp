#include "piece.h"

Piece::Piece(int belongingPlayer,PieceType type, QWidget *parent)
    : QWidget{parent}
{}

Position *Piece::getPosition()
{
    return &currentPosition;
}
