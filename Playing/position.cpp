#include "position.h"

Position::Position(int x, int y,QObject* parent)
    :QObject(parent)
{

}

Position *Position::getAdjacentPosition(int i) const
{

}

int Position::getX() const
{
    return x;
}

int Position::getY() const
{
    return y;
}
