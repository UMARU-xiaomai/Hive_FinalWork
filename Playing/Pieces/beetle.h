#ifndef BEETLE_H
#define BEETLE_H
#include "../piece.h"
class Beetle : public Piece
{
public:
    Beetle(int belongingPlayer,QWidget* parent = nullptr);
    QVector<Position> getValidMoves(const Board* board) const override;
};

#endif // BEETLE_H
