#include "player.h"
#include "cell.h"
#include "pieces.h"
#include "../Scenes/playing.h"
#include "../mainwindow.h"
#include "pieces_add.h"


Player::Player(const QString &name, bool isAI,int numOfPlayer,QObject* parent)
    :QObject(parent)
{
    //初始化拥有的昆虫并加到玩家栏
    pieces.append(new Pieces::QueenBee(numOfPlayer));
    for(int i = 0;i<2;i++)
        pieces.append(new Pieces::Spider(numOfPlayer));
    for(int i = 0;i<2;i++)
        pieces.append(new Pieces::Beetle(numOfPlayer));
    for(int i = 0;i<3;i++)
        pieces.append(new Pieces::Grasshopper(numOfPlayer));
    for(int i = 0;i<3;i++)
        pieces.append(new Pieces::SoldierAnt(numOfPlayer));

    if(MainWindow::instance->settings.addMosquito)
        pieces.append(new PiecesAdd::Mosquito(numOfPlayer));
    if(MainWindow::instance->settings.addLadybug)
        pieces.append(new PiecesAdd::Ladybug(numOfPlayer));
    if(MainWindow::instance->settings.addPillbug)
        pieces.append(new PiecesAdd::Pillbug(numOfPlayer));

    for(PieceInterface* cur :pieces)
    {
        Piece* i = static_cast<Piece*>(cur);
        i->initWidget();
        Playing::instance->addPieceWidgetToPlayerColumn(numOfPlayer,i->getPieceWidget());
    }
    this->name = name;
    this->numberOfPlayer = numOfPlayer;
}

// Piece *Player::selectPiece(Board *board)
// {
//     return nullptr;
// }

// void Player::placePiece(Piece *piece, Board *board, const Position *position)
// {
//     board->getPositionCell(position)->setPiece(piece);
// }

// void Player::movePiece(Piece *piece, Board *board, const Position *newPosition)
// {
//     board->getPositionCell(newPosition)->setPiece(piece);
// }
//这三个函数仅会被Ai所调用
void Player::addPlugPiece(PieceInterface *piece)
{
    pieces.append(piece);
    Playing::instance->addPieceWidgetToPlayerColumn(numberOfPlayer,static_cast<Piece*>(piece)->getPieceWidget());

}

