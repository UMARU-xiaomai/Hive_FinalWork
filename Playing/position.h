#ifndef POSITION_H
#define POSITION_H

#include <QObject>

class Position {
public:
    Position(int x = 0, int y = 0);//构造函数
    bool isAdjacentTo(const Position &other) const;

    int getX() const;//要求返回位置的x坐标
    int getY() const;//要求返回位置的y坐标

private:
    int x;
    int y;
};

#endif // POSITION_H
