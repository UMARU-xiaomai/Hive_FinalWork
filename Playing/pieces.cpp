#include "pieces.h"
#include "cell.h"
#include "board.h"
namespace Pieces {

// QueenBee
QueenBee::QueenBee(int belongingPlayer, QObject *parent)
    : Piece{belongingPlayer, parent}  // 枚举转字符串
{}
bool QueenBee::isQueenBee() const {return true;}
QString QueenBee::typeStr() const {return "QueenBee";}
int QueenBee::startQuantity() const {return 1;}
QString QueenBee::getImgPath() const {return ":/playing/piece/Resources/queen_bee.png";}

QVector<Cell*> QueenBee::getValidMoves( Board *board) const
{
    QVector<Cell*> res;
    if(!currentCell||currentCell->getPiece()!=this||!canBeMoved())
    {
        qDebug() <<"piece not be placed";
        return res;
    }

    for(int i = 0;i<6;i++)
    {
        Cell* cur = currentCell->getAdjacentCell(i,true);
        // if(!cur)
        //     qDebug()<<"error!!!!!!!!!!";
        if(!cur||cur->getPiece())
            continue;
        Piece* last = currentCell->getAdjacentCell(i==0?5:i-1)->getPiece();
        Piece* next = currentCell->getAdjacentCell(i==5?0:i+1)->getPiece();

        if((!last&&next)||(last&&!next))
            res.push_back(cur);
    }
    return res;
}

// Spider
Spider::Spider(int belongingPlayer, QObject *parent)
    : Piece{belongingPlayer, parent}// 枚举转字符串
{}
bool Spider::isQueenBee() const {return false;}
QString Spider::typeStr() const {return "Spider";}
int Spider::startQuantity() const {return 2;}
QString Spider::getImgPath() const {return ":/playing/piece/Resources/spider.png";}

QVector<Cell*> Spider::getValidMoves( Board *board) const
{

    QVector<Cell*> res;
    if(!currentCell||currentCell->getPiece()!=this||!canBeMoved())
    {
        qDebug() <<"Cannot move piece";
        return res;
    }
    QVector<QPair<int,Cell*>> curCells;//通过pair来存储下一个点不要遍历的位置
    curCells.push_back(QPair<int,Cell*>(-1,currentCell));
    QVector<QPair<int,Cell*>> nextCells;
    int curStep = 0;
    while(curStep <3)
    {
        nextCells.clear();
        for(auto curCell:curCells)
        {//bug：允许往回走了，会导致错误
            for(int i = 0;i<6;i++)
            {
                if(curCell.first==i)
                    continue;
                Cell* cur = curCell.second->getAdjacentCell(i,true);
                // if(!cur)
                //     qDebug()<<"error!!!!!!!!!!";
                if(!cur||cur->getPiece())// 遍历的点附近可能为空
                    continue;
                Piece* last = curCell.second->getAdjacentCell(i==0?5:i-1)->getPiece();
                Piece* next = curCell.second->getAdjacentCell(i==5?0:i+1)->getPiece();
                if(last == this)
                    last = nullptr;
                if(next == this)
                    next = nullptr;

                if((!last&&next)||(last&&!next))
                    nextCells.push_back(QPair<int,Cell*>(i>2?i-3:i+3,cur));
            }
        }
        curCells = nextCells;
        curStep++;
    }
    for(auto i:nextCells)
    {
        res.push_back(i.second);
    }
    return res;
}

// Beetle
Beetle::Beetle(int belongingPlayer, QObject *parent)
    : Piece{belongingPlayer, parent} // 枚举转字符串
{}
bool Beetle::isQueenBee() const {return false;}
QString Beetle::typeStr() const {return "Beetle";}
int Beetle::startQuantity() const {return 2;}
QString Beetle::getImgPath() const {return ":/playing/piece/Resources/beetles.png";}

QVector<Cell*> Beetle::getValidMoves( Board *board) const
{
    QVector<Cell*> res;
    if(!currentCell||currentCell->getPiece()!=this||!canBeMoved())
    {
        qDebug() <<"piece not be placed";
        return res;
    }

    for(int i = 0;i<6;i++)
    {
        Cell* cur = currentCell->getAdjacentCell(i,true);
        // if(!cur)
        //     qDebug()<<"error!!!!!!!!!!";
        if(!cur)
            continue;
        Piece* last = currentCell->getAdjacentCell(i==0?5:i-1)->getPiece();
        Piece* next = currentCell->getAdjacentCell(i==5?0:i+1)->getPiece();

        if(currentCell->getPiecesNum()>1||last||next||cur->getPiece())
            res.push_back(cur);
    }
    return res;
}

// Grasshopper
Grasshopper::Grasshopper(int belongingPlayer, QObject *parent)
    : Piece{belongingPlayer, parent} // 枚举转字符串
{}
bool Grasshopper::isQueenBee() const {return false;}
QString Grasshopper::typeStr() const {return "Grasshopper";}
int Grasshopper::startQuantity() const {return 3;}
QString Grasshopper::getImgPath() const {return ":/playing/piece/Resources/grasshopper.png";}

QVector<Cell*> Grasshopper::getValidMoves( Board *board) const
{
    QVector<Cell*> res;
    if(!currentCell||currentCell->getPiece()!=this||!canBeMoved())
    {
        qDebug() <<"piece not be placed";
        return res;
    }

    for(int i = 0;i<6;i++)
    {
        Cell* cur = currentCell->getAdjacentCell(i,true);
        if(!cur||!cur->getPiece())
            continue;
        while(cur->getPiece())
        {
            cur = cur->getAdjacentCell(i);
        }
        res.push_back(cur);
    }
    return res;
}

// SoldierAnt
SoldierAnt::SoldierAnt(int belongingPlayer, QObject *parent)
    : Piece{belongingPlayer, parent} // 枚举转字符串
{}
bool SoldierAnt::isQueenBee() const {return false;}
QString SoldierAnt::typeStr() const {return "SoldierAnt";}
int SoldierAnt::startQuantity() const {return 3;}
QString SoldierAnt::getImgPath() const {return ":/playing/piece/Resources/soldier_ant.png";}

QVector<Cell*> SoldierAnt::getValidMoves( Board *board) const
{
    QVector<Cell*> res;
    if(!currentCell||currentCell->getPiece()!=this||!canBeMoved())
    {
        qDebug() <<"piece not be placed";
        return res;
    }

    QVector<QPair<int,Cell*>> curCells;//通过pair来存储下一个点不要遍历的位置
    curCells.push_back(QPair<int,Cell*>(-1,currentCell));
    QVector<QPair<int,Cell*>> nextCells;
    while(curCells.size())
    {
        nextCells.clear();
        for(auto curCell:curCells)
        {//bug：允许往回走了，会导致错误
            for(int i = 0;i<6;i++)
            {
                if(curCell.first==i)
                    continue;
                Cell* cur = curCell.second->getAdjacentCell(i,true);
                // if(!cur)
                //     qDebug()<<"error!!!!!!!!!!";
                if(!cur||cur->getPiece())// 遍历的点附近可能为空
                    continue;
                Piece* last = curCell.second->getAdjacentCell(i==0?5:i-1)->getPiece();
                Piece* next = curCell.second->getAdjacentCell(i==5?0:i+1)->getPiece();
                if(last == this)
                    last = nullptr;
                if(next == this)
                    next = nullptr;

                if((!last&&next)||(last&&!next))
                {

                    nextCells.push_back(QPair<int,Cell*>(i>2?i-3:i+3,cur));

                    if(std::find(res.begin(),res.end(),cur)==res.end())
                    res.push_back(cur);
                }
            }
        }
        curCells = nextCells;
    }
    for(auto i:nextCells)
    {
        res.push_back(i.second);
    }
    return res;
}
}
