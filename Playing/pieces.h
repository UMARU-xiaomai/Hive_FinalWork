#ifndef PIECES_H
#define PIECES_H

#include "piece.h"

namespace Pieces {

class QueenBee : public Piece
{
public:
    QueenBee(int belongingPlayer,QObject* parent = nullptr);
    QVector<Cell*> getValidMoves( Board* board) const override;
    bool isQueenBee() const override;
    QString typeStr() const override;
    int startQuantity() const override;
    QString getImgPath() const override;
};

class Spider : public Piece
{
public:
    Spider(int belongingPlayer,QObject* parent = nullptr);
    QVector<Cell*> getValidMoves( Board* board) const override;
    bool isQueenBee() const override;
    QString typeStr() const override;
    int startQuantity() const override;
    QString getImgPath() const override;
};

class Beetle : public Piece
{
public:
    Beetle(int belongingPlayer,QObject* parent = nullptr);
    QVector<Cell*> getValidMoves( Board* board) const override;
    bool isQueenBee() const override;
    QString typeStr() const override;
    int startQuantity() const override;
    QString getImgPath() const override;
};

class Grasshopper : public Piece
{
public:
    Grasshopper(int belongingPlayer,QObject* parent = nullptr);
    QVector<Cell*> getValidMoves( Board* board) const override;
    bool isQueenBee() const override;
    QString typeStr() const override;
    int startQuantity() const override;
    QString getImgPath() const override;
};

class SoldierAnt : public Piece
{
public:
    SoldierAnt(int belongingPlayer,QObject* parent = nullptr);
    QVector<Cell*> getValidMoves( Board* board) const override;
    bool isQueenBee() const override;
    QString typeStr() const override;
    int startQuantity() const override;
    QString getImgPath() const override;
};
}
#endif // PIECES_H
