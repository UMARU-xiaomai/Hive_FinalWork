#include "board.h"

Board::Board(Game * mainGame,QObject* parent)
    :QObject(parent)

{
    this->mainGame = mainGame;
}

Cell *Board::getPositionCell(const Position *position) const
{

}

QVector<Position> Board::getValidPlaces(const Piece *piece) const
{

}

void Board::placePiece(Piece *piece, const Position *position)
{

}

void Board::movePiece(Piece *piece, const Position *newPosition)
{

}
