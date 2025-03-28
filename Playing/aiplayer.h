#ifndef AIPLAYER_H
#define AIPLAYER_H

#include "player.h"

class AIPlayer : public Player {
    Q_OBJECT

public:
    AIPlayer(int numOfPlayer,QObject* parent = nullptr);
    /*
     * @brief 随机选择一个棋子
     */
    Piece* selectPiece() ;
    /*
     * @brief 随机放置到一个位置
     */
    void movePiece() ;
};

#endif // AIPLAYER_H
