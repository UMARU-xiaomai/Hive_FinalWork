#include "board.h"
#include "cell.h"
#include "game.h"

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
////
/// \brief Board::getPositionCell
/// 对于指定的位置Position给出棋位Cell
/// \param position
/// 目标位置
/// \param dontCreNewCell
/// 为false时，若找不到目标位置，将不会在棋盘中创建新的Cell，返回nullptr
/// \return 返回找到的Cell的指针
///
Cell *Board::getPositionCell(const Position *position,bool dontCreNewCell)
{
//TODO
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
                            if(cur->checkPieceBelongingHere(piece->belongingPlayer))
                                ava = true;
                            if(cur->checkPieceBelongingHere(piece->belongingPlayer?0:1))// 检查对手棋子是否在这
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
///
/// \brief Board::movePiece 移动piece到目标cell
/// \param piece 要移动的piece
/// \param cell 目标cell
///
void Board::movePiece(Piece *piece, Cell *cell)
{
    //TODO
    //提示:cell.setPiece()
}
