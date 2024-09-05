#include "piece.h"

Piece::Piece(int belongingPlayer,PieceType type, QObject *parent)
    : QObject{parent}
{
    widget = new PieceWidget();
}

PieceWidget *Piece::getPieceWidget()
{
    return widget;
}

Position *Piece::getPosition()
{
    return &currentPosition;
}
