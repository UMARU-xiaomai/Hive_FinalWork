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

QVector<Cell*>* QueenBee::getValidMoves( Board *board) const
{
    QVector<Cell*>* res = new QVector<Cell*>();
    if(!currentCell)
    {
        qDebug() <<"piece not be placed";
        delete res;
        return nullptr;
    }

    for(int i = 0;i<6;i++)
    {
        Cell* cur = currentCell->getAdjacentCell(i,true);
        if(!cur)
            qDebug()<<"error!!!!!!!!!!";
        if(cur->getPiece())
            continue;
        Piece* last = currentCell->getAdjacentCell(i==0?5:i-1)->getPiece();
        Piece* next = currentCell->getAdjacentCell(i==5?0:i+1)->getPiece();

        if((!last&&next)||(last&&!next))
            res->push_back(cur);
    }
    return res;
}

// Spider
Spider::Spider(int belongingPlayer, QObject *parent)
    : Piece{belongingPlayer, parent}  // 枚举转字符串
{}
bool Spider::isQueenBee() const {return false;}
QString Spider::typeStr() const {return "Spider";}
int Spider::startQuantity() const {return 2;}
QString Spider::getImgPath() const {return "";}

QVector<Cell*>* Spider::getValidMoves( Board *board) const
{
return nullptr;
}

// Beetle
Beetle::Beetle(int belongingPlayer, QObject *parent)
    : Piece{belongingPlayer, parent}  // 枚举转字符串
{}
bool Beetle::isQueenBee() const {return false;}
QString Beetle::typeStr() const {return "Beetle";}
int Beetle::startQuantity() const {return 2;}
QString Beetle::getImgPath() const {return "";}

QVector<Cell*>* Beetle::getValidMoves( Board *board) const
{
return nullptr;
}

// Grasshopper
Grasshopper::Grasshopper(int belongingPlayer, QObject *parent)
    : Piece{belongingPlayer, parent}  // 枚举转字符串
{}
bool Grasshopper::isQueenBee() const {return false;}
QString Grasshopper::typeStr() const {return "Grasshopper";}
int Grasshopper::startQuantity() const {return 3;}
QString Grasshopper::getImgPath() const {return "";}

QVector<Cell*>* Grasshopper::getValidMoves( Board *board) const
{
return nullptr;
}

// SoldierAnt
SoldierAnt::SoldierAnt(int belongingPlayer, QObject *parent)
    : Piece{belongingPlayer, parent}  // 枚举转字符串
{}
bool SoldierAnt::isQueenBee() const {return false;}
QString SoldierAnt::typeStr() const {return "SoldierAnt";}
int SoldierAnt::startQuantity() const {return 3;}
QString SoldierAnt::getImgPath() const {return "";}

QVector<Cell*>* SoldierAnt::getValidMoves( Board *board) const
{
return nullptr;
}
}
