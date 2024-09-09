#include "position.h"

Position::Position(int x, int y,QObject* parent)
    :QObject(parent)
{
    this->x = x;
    this->y = y;

}

Position* Position::getAdjacentPosition(int i) const
{
    int offsetOdd[] = {-1,0,1,0,-1,-1};
    int offsetPlural[] = {0,1,1,1,0,-1};
    int offsetY[] = {-1,-1,0,1,1,0};

    if(y%2 == 1)
        return new Position(x+offsetOdd[i],y+offsetY[i]);
    else
        return new Position(x+offsetPlural[i],y+offsetY[i]);
}

int Position::getX() const
{
    return x;
}

int Position::getY() const
{
    return y;
}

int Position::setX(int x)
{
    this->x = x;
}

int Position::setY(int y)
{
    this->y = y;
}
