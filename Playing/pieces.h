#ifndef PIECES_H
#define PIECES_H

#include "piece.h"

namespace Pieces {

class QueenBee : public Piece
{
public:
    QueenBee(int belongingPlayer,QObject* parent = nullptr);
    QVector<Position*>* getValidMoves(const Board* board) const override;
};

class Spider : public Piece
{
public:
    Spider(int belongingPlayer,QObject* parent = nullptr);
    QVector<Position*>* getValidMoves(const Board* board) const override;
};

class Beetle : public Piece
{
public:
    Beetle(int belongingPlayer,QObject* parent = nullptr);
    QVector<Position*>* getValidMoves(const Board* board) const override;
};

class Grasshopper : public Piece
{
public:
    Grasshopper(int belongingPlayer,QObject* parent = nullptr);
    QVector<Position*>* getValidMoves(const Board* board) const override;
};

class SoldierAnt : public Piece
{
public:
    SoldierAnt(int belongingPlayer,QObject* parent = nullptr);
    QVector<Position*> *getValidMoves(const Board* board) const override;
};
}
#endif // PIECES_H
