#ifndef POSITION_H
#define POSITION_H

#include <QObject>

class Position : public QObject{
    Q_OBJECT
public:
    Position(int x = 0, int y = 0,QObject* parent = nullptr);//构造函数
    /*
     *  @brief 获取临近位置，需要手动删除返回的指针
     */
    Position* getAdjacentPosition(int i) const;

    int getX() const;//要求返回位置的x坐标
    int getY() const;//要求返回位置的y坐标
    int setX(int x);
    int setY(int y);

private:
    int x;
    int y;
};

#endif // POSITION_H
