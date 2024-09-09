#include "piece.h"
#include <QMetaEnum>

Piece::Piece(int belongingPlayer,PieceType type,const QString &typeStr, QObject *parent)
    : QObject{parent}
{
    this->belongingPlayer = belongingPlayer;
    this->type = type;
    this->typeStr =typeStr;

    widget = new PieceWidget(this);

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
PieceType Piece::getType()
{
    return type;
}



void Piece::setPosition(Position *position)
{
    currentPosition = position;
}
