#include "pieces_add.h"
#include "cell.h"
#include "board.h"
namespace PiecesAdd {

// Mosquito
Mosquito::Mosquito(int belongingPlayer, QObject *parent)
    : Piece{belongingPlayer, parent}  // 枚举转字符串
{}
bool Mosquito::isQueenBee() const {return false;}
QString Mosquito::typeStr() const {return "Mosquito";}
int Mosquito::startQuantity() const {return 1;}
QString Mosquito::getImgPath() const {return ":/playing/piece/Resources/mosquito.png";}

QVector<Cell*> Mosquito::getValidMoves( Board *board) const
{

}

// Ladybug
Ladybug::Ladybug(int belongingPlayer, QObject *parent)
    : Piece{belongingPlayer, parent}  // 枚举转字符串
{}
bool Ladybug::isQueenBee() const {return false;}
QString Ladybug::typeStr() const {return "Ladybug";}
int Ladybug::startQuantity() const {return 1;}
QString Ladybug::getImgPath() const {return ":/playing/piece/Resources/ladybug.png";}

void Ladybug::DFS(int step,Cell* tarCell, QVector<Cell *> &res) const
{
    if(step==1||step==2)
    {
        if(tarCell->getPiece()==nullptr||tarCell->getPiece()==this)
            return;
        for(int i =0;i<6;i++)
            DFS(step+1,tarCell->getAdjacentCell(i),res);
    }else
    {
        if(tarCell->getPiece()!=nullptr)
            return;
        if(std::find(res.begin(),res.end(),tarCell)==res.end())
        res.append(tarCell);
    }
}

QVector<Cell*> Ladybug::getValidMoves( Board *board) const
{
    QVector<Cell*> res;
    if(!currentCell||currentCell->getPiece()!=this||!canBeMoved())
    {
        qDebug() <<"Cannot move piece";
        return res;
    }
    // QVector<QPair<int,Cell*>> curCells;//通过pair来存储下一个点不要遍历的位置
    // curCells.push_back(QPair<int,Cell*>(-1,currentCell));
    // QVector<QPair<int,Cell*>> nextCells;
    // int curStep = 0;
    // while(curStep <3)
    // {
    //     nextCells.clear();
    //     for(auto curCell:curCells)
    //     {//bug：允许往回走了，会导致错误
    //         for(int i = 0;i<6;i++)
    //         {
    //             if(curCell.first==i)
    //                 continue;
    //             Cell* cur = curCell.second->getAdjacentCell(i,true);
    //             // if(!cur)
    //             //     qDebug()<<"error!!!!!!!!!!";
    //             if(!cur||cur->getPiece())// 遍历的点附近可能为空
    //                 continue;
    //             Piece* last = curCell.second->getAdjacentCell(i==0?5:i-1)->getPiece();
    //             Piece* next = curCell.second->getAdjacentCell(i==5?0:i+1)->getPiece();
    //             if(last == this)
    //                 last = nullptr;
    //             if(next == this)
    //                 next = nullptr;

    //             if((!last&&next)||(last&&!next))
    //                 nextCells.push_back(QPair<int,Cell*>(i>2?i-3:i+3,cur));
    //         }
    //     }
    //     curCells = nextCells;
    //     curStep++;
    // }
    // for(auto i:nextCells)
    // {
    //     res.push_back(i.second);
    // }
    for(int i =0;i<6;i++)
        DFS(1,currentCell->getAdjacentCell(i),res);
    return res;
}

// Pillbug
Pillbug::Pillbug(int belongingPlayer, QObject *parent)
    : Piece{belongingPlayer, parent}  // 枚举转字符串
{}
bool Pillbug::isQueenBee() const {return false;}
QString Pillbug::typeStr() const {return "Pillbug";}
int Pillbug::startQuantity() const {return 1;}
QString Pillbug::getImgPath() const {return ":/playing/piece/Resources/pillbug.png";}

QVector<Cell*> Pillbug::getValidMoves( Board *board) const
{

}
}
