#include "piece.h"

Piece::Piece(int belongingPlayer,PieceType type, QObject *parent)
    : QObject{parent}
{
    widget = new PieceWidget(this);
    this->belongingPlayer = belongingPlayer;
    this->type = type;

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

void Piece::setPosition(Position *position)
{
    currentPosition = position;
}
