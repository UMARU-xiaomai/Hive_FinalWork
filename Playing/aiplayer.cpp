#include "aiplayer.h"

AIPlayer::AIPlayer(int numOfPlayer,QObject* parent)
    :Player("AI",true,numOfPlayer,parent)
{

}

Piece *AIPlayer::selectPiece(Board *board)
{

}

void AIPlayer::placePiece(Piece *piece, Board *board, const Position &position)
{

}

void AIPlayer::movePiece(Piece *piece, Board *board, const Position &newPosition)
{

}
