#include "board.h"
#include "..\Scenes\playing.h"
#include "cell.h"

Board::Board(Game * mainGame,QObject* parent)
    :QObject(parent)

{
    this->mainGame = mainGame;
}

Cell *Board::getPositionCell(const Position *position) const
{

}

QVector<Position*>* Board::getValidPlaces(const Piece *piece)
{
    QVector<Position*>* res = new QVector<Position*>();
    if(Game::instance->getRound(true)==1)
    {
        Cell* curCell = new Cell(0,0,this);
        cells[0][0] = curCell;
        res->append(curCell->getPosition());
        return res;
    }else if(Game::instance->getRound(true)==2)
    {
        for(int i =0;i<6;i++)
        {
            res->append((new Position(0,0))->getAdjacentPosition(i));
        }
        return res;
    }else
    {
        for (const QMap<int, Cell*> &innerMap : cells) {
            for (Cell* const &cell : innerMap) {
                if(!cell->getPiece())
                {
                    bool ava = true;
                    for(int i =0;i<6;i++)
                    {
                        if(Piece* cur = getPositionCell(cell->getPosition()->getAdjacentPosition(i))->getPiece())
                            if(cur->belongingPlayer != piece->belongingPlayer)
                                ava = false;
                    }
                    if(ava)
                        res->append(cell->getPosition());
                }
            }
        }
        return res;
    }
}

void Board::placePiece(Piece *piece, const Position *position)
{

}

void Board::movePiece(Piece *piece, const Position *newPosition)
{

}
