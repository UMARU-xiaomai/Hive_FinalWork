#include "cell.h"
#include "board.h"


Cell::Cell(int x,int y, QObject *parent)
    : QObject{parent}
{
    position.setX(x);
    position.setY(y);
    piecesHere.clear();
}

void Cell::setPiece(Piece *piece)
{

    this->piecesHere.push(piece);
    piece->setCell(this);
    setPieceTips();
}

Piece *Cell::getPiece(bool pop)
{
    if(this->piecesHere.isEmpty())
        return nullptr;
    else if(pop)
    {
        return piecesHere.pop();
        setPieceTips();
    }
    else
        return piecesHere.top();
}

int Cell::getPiecesNum()
{
    return piecesHere.size();
}

Position *Cell::getPosition()
{
    return &position;
}

Cell *Cell::getAdjacentCell(int i,bool dontCreNewCell)
{
    Cell* resCell = adjacentCells[i];
    if(!resCell)
    {
        Position curPosition = this->getPosition()->getAdjacentPosition(i);
        resCell = Board::instance->getPositionCell(curPosition,dontCreNewCell);

        this->setAdjacentCell(i,resCell);

    }
    return resCell;
}

void Cell::setAdjacentCell(int i, Cell *cell)
{
    adjacentCells[i] = cell;
}

void Cell::setPieceTips()
{
    QString resTip("——顶层——\n");
    for(auto it=piecesHere.rbegin();it!=piecesHere.rend();it++)
    {
        resTip.append((*it)->typeStr()+"\n");
    }
    resTip += "——底层——";
    piecesHere.top()->getPieceWidget()->setPieceToolTip(resTip);
}
