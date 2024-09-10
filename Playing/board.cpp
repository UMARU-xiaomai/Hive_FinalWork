#include "board.h"
#include "..\Scenes\playing.h"
#include "testwidget.h"
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
Cell *Board::getPositionCell(const Position *position,bool dontCreNewCell)
{

    int x = position->getX();
    int y = position->getY();
    if(!cells[x][y]&&!dontCreNewCell)
    {
        qDebug()<<"tes"<<x<<y;
        cells[x][y] = new Cell(x,y);
        // qDebug() <<x;
    }
    return cells[x][y];
}

QVector<Cell*>* Board::getValidPlaces(const Piece *piece)
{
    QVector<Cell*>* res = new QVector<Cell*>();
    if(Game::instance->getRound(true)==1)
    {


        Cell* curCell = new Cell(0,0);
        cells[0][0] = curCell;
        res->append(curCell);
        return res;
    }else if(Game::instance->getRound(true)==2)
    {
        for(int i =0;i<6;i++)
        {
            res->append(cells[0][0]->getAdjacentCell(i));
        }
        return res;
    }else
    {
        // QVector<TestWidget*> testPoints;
        for (const QMap<int, Cell*> &innerMap : cells) {
            for (Cell* const &cell : innerMap) {


                if(cell&&!cell->getPiece())//坑人，QMap只要读取过就会创建空对象，必须先检测对应位有没有Cell*
                {
                    //test
                    // TestWidget* tp = new TestWidget();
                    // testPoints.append(tp);

                    bool ava = false;
                    for(int i =0;i<6;i++)
                    {
                        Cell* cur = cell->getAdjacentCell(i,true);
                        if(cur&&cur->getPiece())
                        {
                            qDebug()<<"cmp:"<<cur->getPiece()->belongingPlayer <<piece->belongingPlayer<<cur->getPosition()->getX()<<cur->getPosition()->getY();
                            if(cur->getPiece()->belongingPlayer == piece->belongingPlayer)
                                ava = true;
                            if(cur->getPiece()->belongingPlayer != piece->belongingPlayer)
                            {
                                ava = false;
                                break;
                            }
                        }
                    }
                    qDebug()<<ava;
                    if(ava)
                        res->append(cell);
                }
            }
        }
        // for(auto i:testPoints)
        //     delete i;
        return res;
    }
}

void Board::movePiece(Piece *piece, Cell *cell)
{
    if(piece->getCell())
        piece->getCell()->getPiece(true);
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
        qDebug() <<"around cell position"<< curCell ->getPosition()->getX()<<curCell ->getPosition()->getY();

    }
}
