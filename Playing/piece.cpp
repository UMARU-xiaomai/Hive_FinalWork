#include "piece.h"
#include <QMetaEnum>
#include "cell.h"

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
    widget->setPieceBelonging(belongingPlayer);
}
bool Piece::isPlaced()
{
    return currentCell!=nullptr;
}

PieceWidget *Piece::getPieceWidget()
{
    return widget;
}

Cell *Piece::getCell() const
{
    return currentCell;
}

// bool Piece::isQB = false;


void Piece::setCell(Cell *cell)
{
    currentCell = cell;
}

bool Piece::canBeMoved() const
{
    if(this->currentCell->getPiecesNum()>1)
        return true;
    QVector<Cell*> segs;
    for(int i=0;i<6;i++)
    {
        Cell* cur = getCell()->getAdjacentCell(i);
        Cell* next = getCell()->getAdjacentCell(i>=5?0:i+1);

        if(cur->getPiece()&&!next->getPiece())
            segs.push_back(cur);
    }
    if(segs.size()<=1)
    {
        return true;
    }else
    {
        QSet<Cell*> passedCells;
        for(auto curStartCell : segs)
        {
            passedCells.insert(curStartCell);
            return DFS(curStartCell,passedCells,segs);
        }

        return false;//TODO：还没写完！！处理回路情况
    }

}

bool Piece::DFS(Cell *curCell, QSet<Cell *> &passed,const QVector<Cell*> &segs) const
{
    passed.insert(curCell);
    for(int i=0;i<6;i++)
    {
        Cell* tmp = curCell->getAdjacentCell(i);
        if(tmp&&tmp->getPiece()&&tmp->getPiece()!=this)
        {
            if(!passed.contains(tmp)&&segs.contains(tmp))
                return true;
            if(!passed.contains(tmp))
                return DFS(tmp,passed,segs);
        }

    }
    return false;
}
