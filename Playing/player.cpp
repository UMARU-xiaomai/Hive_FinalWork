#include "player.h"

Player::Player(const QString &name, bool isAI,int numOfPlayer,QObject* parent)
    :QObject(parent)
{

}

Piece *Player::selectPiece(Board *board)
{

}

void Player::placePiece(Piece *piece, Board *board, const Position &position)
{

}

void Player::movePiece(Piece *piece, Board *board, const Position &newPosition)
{

}
