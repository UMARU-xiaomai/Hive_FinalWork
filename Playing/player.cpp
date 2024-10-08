#include "player.h"
#include "cell.h"
#include "pieces.h"
#include "../Scenes/playing.h"


Player::Player(const QString &name, bool isAI,int numOfPlayer,QObject* parent)
    :QObject(parent)
{
    //TODO：初始化拥有的昆虫并加到玩家栏

    //下面是UI相关，别动
    for(Piece* i :pieces)
    {
        i->initWidget();
        Playing::instance->addPieceWidgetToPlayerColumn(numOfPlayer,i->getPieceWidget());
    }
}

//
Piece *Player::selectPiece(Board *board)
{
    return nullptr;
}

void Player::placePiece(Piece *piece, Board *board, const Position *position)
{
    board->getPositionCell(position)->setPiece(piece);
}

void Player::movePiece(Piece *piece, Board *board, const Position *newPosition)
{
    board->getPositionCell(newPosition)->setPiece(piece);
}
//这三个函数仅会被Ai所调用
void Player::addPlugPiece(Piece *piece)
{
    pieces.append(piece);
    Playing::instance->addPieceWidgetToPlayerColumn(numberOfPlayer,piece->getPieceWidget());

}

