#include "piece.h"

Piece::Piece(int belongingPlayer,PieceType type, QObject *parent)
    : QObject{parent}
{
    widget = new PieceWidget(this);
    currentPosition = nullptr;
}

bool Piece::isPlaced()
{
    return currentPosition!=nullptr;
}

PieceWidget *Piece::getPieceWidget()
{
    return widget;
}

Position *Piece::getPosition()
{
    return currentPosition;
}
