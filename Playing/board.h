#ifndef BOARD_H
#define BOARD_H

#include <QObject>
#include <QWidget>
#include <QVector>
//#include "cell.h"
#include "piece.h"
#include "position.h"
//#include "game.h"
class Game;
class Cell;
class Board :public QObject{
    Q_OBJECT

public:
    Board(Game * mainGame,QObject* parent = nullptr);
    static Board* instance;
    /*
     * @brief 从给定的位置获取Cell
     */
    Cell* getPositionCell(const Position position,bool dontCreNewCell = false);
    /*
     * @brief 获取可以放新棋子的位置，可移动位置写在每个Piece子类中,需要手动释放返回的指针
     */
    QVector<Cell*> getValidPlaces(const Piece* piece);
    /*
     * @brief 将选择的棋子移动到给定的位置
     */
    void movePiece(Piece* piece, Cell *cell);

    class PieceIterator
    {
        QMap<int,QMap<int,Cell*>>::Iterator x_it;
        QMap<int,Cell*>::Iterator y_it;
        Board* tar;
        bool isEnd = false;
    public:
        PieceIterator(QMap<int,QMap<int,Cell*>>::Iterator x,QMap<int,Cell*>::Iterator y,Board* tar);
        bool operator!=(const PieceIterator& b);
        PieceIterator operator++(int);
        Piece* operator*();
        bool getIsEnd();
    };
    PieceIterator begin();
private:
    Game* mainGame;
    QMap<int,QMap<int,Cell*>> cells;
};

#endif // BOARD_H
