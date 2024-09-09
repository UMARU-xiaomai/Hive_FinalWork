#include "board.h"
#include "..\Scenes\playing.h"
#include "cell.h"

Board::Board(Game * mainGame,QObject* parent)
    :QObject(parent)

{
    this->mainGame = mainGame;
    //单例模式
    if(Board::instance)
        delete Board::instance;
    Board::instance = this;
}

Board* Board::instance = nullptr;
Cell *Board::getPositionCell(const Position *position)
{
    // qDebug()<<"tes"<<position->getX()<<position->getY();
    int x = position->getX();
    int y = position->getY();
    if(!cells[x][y])
    {
        cells[x][y] = new Cell(x,y);
    }
    return cells[x][y];
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
    }else if(Game::instance->getRound(true)>=2)
    {
        for(int i =0;i<6;i++)
        {
            res->append(cells[0][0]->getPosition()->getAdjacentPosition(i));
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

void Board::movePiece(Piece *piece, Cell *cell)
{
    cell->setPiece(piece);
    for(int i = 0;i<6;i++)
    {
        // Position* tarPosition = cell->getPosition()->getAdjacentPosition(i);
        // if(!getPositionCell(tarPosition))
        // {
        //     Cell* curCell = new Cell(tarPosition->getX(),tarPosition->getY(),this);
        //     cells[tarPosition->getX()][tarPosition->getY()] = curCell;
        // }
        Cell* curCell = cell->getAdjacentCell(i);

    }
}
