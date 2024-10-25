#ifndef PIECES_ADD_H
#define PIECES_ADD_H

#include "piece.h"
#include "pieceinterface.h"

namespace PiecesAdd {
class Mosquito : public Piece
{
public:
    Mosquito(int belongingPlayer,QObject* parent = nullptr);
    QVector<Cell*> getValidMoves( Board* board) const override;
    bool isQueenBee() const override;
    QString typeStr() const override;
    int startQuantity() const override;
    QString getImgPath() const override;
};

class Ladybug : public Piece
{
public:
    Ladybug(int belongingPlayer,QObject* parent = nullptr);
    QVector<Cell*> getValidMoves( Board* board) const override;
    bool isQueenBee() const override;
    QString typeStr() const override;
    int startQuantity() const override;
    QString getImgPath() const override;

    void DFS(int step,Cell* tarCell,QVector<Cell*> &res) const;
};

class Pillbug : public Piece
{
public:
    Pillbug(int belongingPlayer,QObject* parent = nullptr);
    QVector<Cell*> getValidMoves( Board* board) const override;
    bool isQueenBee() const override;
    QString typeStr() const override;
    int startQuantity() const override;
    QString getImgPath() const override;


};
}
#endif // PIECES_ADD_H
