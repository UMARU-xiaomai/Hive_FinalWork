#ifndef AIPLAYER_H
#define AIPLAYER_H

#include "player.h"

class AIPlayer : public Player {
    Q_OBJECT

public:
    AIPlayer(const QString &name);
    /*
     * @brief 随机选择一个棋子
     */
    Piece* selectPiece(Board* board) override;
    /*
     * @brief 随机放置到一个位置
     */
    void placePiece(Piece* piece ,Board* board, const Position &position) override;
    /*
     * @brief 随机放置到一个位置
     */
    void movePiece(Piece* piece, Board* board, const Position &newPosition) override;
};

#endif // AIPLAYER_H
