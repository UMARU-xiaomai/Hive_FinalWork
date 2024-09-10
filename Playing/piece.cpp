#include "piece.h"
#include <QMetaEnum>

Piece::Piece(int belongingPlayer,QObject *parent)
    : QObject{parent}
{
    this->belongingPlayer = belongingPlayer;
    // this->isQB = isQueenBee;
    // this->typeStr =typeStr;
    // Piece::startQuantity = startQuantity;



}
void Piece::initWidget()
{
    widget = new PieceWidget(this);
}
bool Piece::isPlaced()
{
    return currentCell!=nullptr;
}

PieceWidget *Piece::getPieceWidget()
{
    return widget;
}

Cell *Piece::getCell()
{
    return currentCell;
}

// bool Piece::isQB = false;


void Piece::setCell(Cell *cell)
{
    currentCell = cell;
}
