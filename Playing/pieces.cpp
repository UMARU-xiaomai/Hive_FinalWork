#include "pieces.h"
namespace Pieces {

// QueenBee
QueenBee::QueenBee(int belongingPlayer, QObject *parent)
    : Piece{belongingPlayer, PieceType::QueenBee, "QueenBee", parent}  // 枚举转字符串
{}

QVector<Position*>* QueenBee::getValidMoves(const Board *board) const
{

}

// Spider
Spider::Spider(int belongingPlayer, QObject *parent)
    : Piece{belongingPlayer, PieceType::Spider, "Spider", parent}  // 枚举转字符串
{}

QVector<Position*>* Spider::getValidMoves(const Board *board) const
{

}

// Beetle
Beetle::Beetle(int belongingPlayer, QObject *parent)
    : Piece{belongingPlayer, PieceType::Beetle, "Beetle", parent}  // 枚举转字符串
{}

QVector<Position*>* Beetle::getValidMoves(const Board *board) const
{

}

// Grasshopper
Grasshopper::Grasshopper(int belongingPlayer, QObject *parent)
    : Piece{belongingPlayer, PieceType::Grasshopper, "Grasshopper", parent}  // 枚举转字符串
{}

QVector<Position*>* Grasshopper::getValidMoves(const Board *board) const
{

}

// SoldierAnt
SoldierAnt::SoldierAnt(int belongingPlayer, QObject *parent)
    : Piece{belongingPlayer, PieceType::SoldierAnt, "SoldierAnt", parent}  // 枚举转字符串
{}

QVector<Position*>* SoldierAnt::getValidMoves(const Board *board) const
{

}
}
