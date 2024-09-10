#ifndef PLUGPIECE_H
#define PLUGPIECE_H

#include "piece.h"

class PlugPiece : public Piece
{
public:
    explicit PlugPiece(int belongingPlayer,QObject *parent = nullptr);
    virtual void initialize() = 0;  // 插件初始化
    virtual void shutdown() = 0;    // 插件关闭时调用
};

#endif // PLUGPIECE_H
