#include "cell.h"
#include "board.h"


Cell::Cell(int x,int y, QObject *parent)
    : QObject{parent},position(x,y)
{
    //TODO
}
///
/// \brief Cell::setPiece 存储新的piece到该位置
/// \param piece
///
void Cell::setPiece(Piece *piece)
{
    if (piece) {
        piecesHere.push(piece); // 添加到栈顶
        piece->setPosition(&position); // 更新Piece的当前位置
    }
}
///
/// \brief Cell::getPiece 获取第一个棋子
/// \param pop 是否要删除取出的棋子
/// \return
///
Piece *Cell::getPiece(bool pop)
{
    /  if (piecesHere.isEmpty()) {
        return nullptr;
    }

    // 如果 pop 为 true，则弹出栈顶棋子
    Piece* topPiece = piecesHere.top();
    if (pop) {
        piecesHere.pop();  // 弹出栈顶棋子
    }
    return topPiece;
}
///
/// \brief Cell::getPiecesNum 获取棋子数目
/// \return
///
int Cell::getPiecesNum()
{
    return piecesHere.size();
}

///
/// \brief Cell::getPosition 获取该Cell的Position指针
/// \return
///
Position *Cell::getPosition()
{
    return &position;
}

Cell *Cell::getAdjacentCell(int i,bool dontCreNewCell)
{
    Cell* resCell = adjacentCells[i];
    if(!resCell)
    {
        Position* curPosition = this->getPosition()->getAdjacentPosition(i);
        resCell = Board::instance->getPositionCell(curPosition,dontCreNewCell);

        this->setAdjacentCell(i,resCell);

        delete curPosition;
    }
    return resCell;
}
///
/// \brief Cell::setAdjacentCell 设置临近Cell数组
/// \param i
/// \param cell
///
void Cell::setAdjacentCell(int i, Cell *cell)
{
    adjacentCells[i] = cell;
}

bool Cell::checkPieceBelongingHere(int tarBelong)
{
    for(auto i : piecesHere)
    {
        if(i->belongingPlayer != tarBelong)
            return false;
    }
}
