#include "player.h"
#include "cell.h"
#include "pieces.h"
#include "../Scenes/playing.h"


Player::Player(const QString &name, bool isAI,int numOfPlayer,QObject* parent)
    :QObject(parent)
{
    //初始化拥有的昆虫并加到玩家栏
    pieces.append(new Pieces::QueenBee(numOfPlayer));
    for(int i = 0;i<2;i++)
        pieces.append(new Pieces::Spider(numOfPlayer));
    for(int i = 0;i<2;i++)
        pieces.append(new Pieces::Beetle(numOfPlayer));
    for(int i = 0;i<3;i++)
        pieces.append(new Pieces::Grasshopper(numOfPlayer));
    for(int i = 0;i<3;i++)
        pieces.append(new Pieces::SoldierAnt(numOfPlayer));
    for(Piece* i :pieces)
    {
        Playing::instance->addPieceWidgetToPlayerColumn(numOfPlayer,i->getPieceWidget());
    }
}

Piece *Player::selectPiece(Board *board)
{

}

void Player::placePiece(Piece *piece, Board *board, const Position *position)
{
    board->getPositionCell(position)->setPiece(piece);
}

void Player::movePiece(Piece *piece, Board *board, const Position *newPosition)
{
    board->getPositionCell(newPosition)->setPiece(piece);
}
