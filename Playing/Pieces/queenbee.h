#ifndef QUEENBEE_H
#define QUEENBEE_H

#include "../piece.h"

class QueenBee : public Piece
{
public:
    QueenBee();
    QVector<Position> getValidMoves(const Board* board) const override;
};

#endif // QUEENBEE_H
