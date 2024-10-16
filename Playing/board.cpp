#include "board.h"
#include "..\Scenes\playing.h"
#include "testwidget.h"
#include "cell.h"
#include <QDebug>

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
Cell *Board::getPositionCell(const Position position,bool dontCreNewCell)
{

    int x = position.getX();
    int y = position.getY();
    if(!cells[x][y]&&!dontCreNewCell)
    {
        qDebug()<<"tes"<<x<<y;
        cells[x][y] = new Cell(x,y);
        // qDebug() <<x;
    }
    return cells[x][y];
}

QVector<Cell*> Board::getValidPlaces(const Piece *piece)
{
    QVector<Cell*> res;
    if(Game::instance->getRound(true)==1)
    {


        Cell* curCell = new Cell(0,0);
        cells[0][0] = curCell;
        res.append(curCell);
        return res;
    }else if(Game::instance->getRound(true)==2)
    {
        for(int i =0;i<6;i++)
        {
            res.append(cells[0][0]->getAdjacentCell(i));
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
                        res.append(cell);
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

Board::PieceIterator Board::begin()
{
    auto res = PieceIterator(cells.begin(),(*(cells.begin())).begin(),this);
    if(!(*res))
        res++;
    return res;
}


Board::PieceIterator::PieceIterator(QMap<int,QMap<int,Cell*>>::Iterator x, QMap<int,Cell*>::Iterator y,Board* tar):x_it(x),y_it(y),tar(tar){}

bool Board::PieceIterator::operator!=(const PieceIterator &b)
{
    return !(this->x_it==b.x_it&&this->y_it==b.y_it);
}

Board::PieceIterator Board::PieceIterator::operator++(int)
{
    Cell* res_c;
    Piece* res_p;

    do{
        if(y_it==(*x_it).end())
        {
            ++x_it;
            if(x_it==tar->cells.end())
            {
                isEnd = true;
                return *this;
            }
            y_it=(*x_it).begin();
            res_c = *y_it;
        }

        res_c = *y_it;

        if(res_c)
            res_p = res_c->getPiece();
        else
            res_p=nullptr;

        ++y_it;
    }while(!res_p);
    return *this;
}

Piece *Board::PieceIterator::operator*()
{
    return (*y_it)?(*y_it)->getPiece():nullptr;
}

bool Board::PieceIterator::getIsEnd() {return isEnd;}
