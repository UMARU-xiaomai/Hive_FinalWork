#include "position.h"

Position::Position(int x, int y,QObject* parent)
    :QObject(parent)
{
    this->x = x;
    this->y = y;

}

Position Position::getAdjacentPosition(int i) const
{
    int offsetOdd[] = {-1,0,1,0,-1,-1};
    int offsetPlural[] = {0,1,1,1,0,-1};
    int offsetY[] = {-1,-1,0,1,1,0};

    if(abs(y)%2 == 1)
        return Position(x+offsetOdd[i],y+offsetY[i]);
    else
        return Position(x+offsetPlural[i],y+offsetY[i]);
}

int Position::getX() const
{
    return x;
}

int Position::getY() const
{
    return y;
}

void Position::setX(int x)
{
    this->x = x;
}

void Position::setY(int y)
{
    this->y = y;
}

Position::Position(const Position &ori):x(ori.getX()),y(ori.getY()){}
