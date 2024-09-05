#include "pieces.h"
namespace Pieces {

//QueenBee
QueenBee::QueenBee(int belongingPlayer, QObject *parent)
    : Piece{belongingPlayer,PieceType::QueenBee,parent}
{}

QVector<Position> QueenBee::getValidMoves(const Board *board) const
{

}

//Spider
Spider::Spider(int belongingPlayer, QObject *parent)
    : Piece{belongingPlayer,PieceType::Spider,parent}
{}

QVector<Position> Spider::getValidMoves(const Board *board) const
{

}

//Beetle
Beetle::Beetle(int belongingPlayer, QObject *parent)
    : Piece{belongingPlayer,PieceType::Beetle,parent}
{}

QVector<Position> Beetle::getValidMoves(const Board *board) const
{

}

//Grasshopper
Grasshopper::Grasshopper(int belongingPlayer, QObject *parent)
    : Piece{belongingPlayer,PieceType::Grasshopper,parent}
{}

QVector<Position> Grasshopper::getValidMoves(const Board *board) const
{

}

//SoldierAnt
SoldierAnt::SoldierAnt(int belongingPlayer, QObject *parent)
    : Piece{belongingPlayer,PieceType::SoldierAnt,parent}
{}

QVector<Position> SoldierAnt::getValidMoves(const Board *board) const
{

}
}
