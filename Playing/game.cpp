#include "game.h"
#include <QMessageBox>
#include <QInputDialog>
#include "aiplayer.h"
#include "..\mainwindow.h"
#include <QtConcurrent/QtConcurrent>
#include "cell.h"
#include <QThread>
#include "..\scenemanager.h"
#include "availablecellwidget.h"
#include "..\Scenes\playing.h"
#include <QDebug>
Game::Game(bool aiMode,QObject* parent)
    :QObject(parent)
{
    this->aiMode = aiMode;

    //单例模式
    if(Game::instance)
        delete Game::instance;
    Game::instance = this;

    //初始化棋盘
    board = new Board(this);
    isGameOver = false;

    round =1;
    // future = QtConcurrent::run([this]() { this->start(); });

}

Game* Game::instance = nullptr;

void Game::start()
{
    //初始化玩家
    bool ok;
    QString text;
    do
    {
        text = QInputDialog::getText(MainWindow::instance, "输入对话框",
                                     "请输入玩家1的名称：", QLineEdit::Normal,
                                     "玩家1", &ok);
    }
    while(!ok || text.isEmpty());
    players.push_back(new Player(text,false,0,this));
    //TODO：更改显示名称

    if(aiMode)
    {
        players.push_back(new AIPlayer(1));
            //TODO：更改显示名称

        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(MainWindow::instance, "确认", "你想要先手吗？",
                                      QMessageBox::Yes | QMessageBox::No);

        if (reply == QMessageBox::Yes) {
            currentPlayer = 0;
        }else{
            currentPlayer = 1;
        }
    }else
    {
        do
        {
            text = QInputDialog::getText(MainWindow::instance, "输入对话框",
                                         "请输入玩家2的名称：", QLineEdit::Normal,
                                         "玩家2", &ok);
        }
        while(!ok || text.isEmpty());
        players.push_back(new Player(text,false,1));
            //TODO：更改显示名称
        currentPlayer = 0;
    }
}

void Game::playTurn()//在选择完地址后调用
{
    // //相当于Update
    // while((!choosedPiece || !choosedPosition)&&!future.isCanceled())
    // {
    //     // QThread::sleep(1);
    //     // qDebug()<<"Hello";
    // }

    // if(future.isCanceled())
    //     return;//防止切换场景时发生错误

    //回合结束的操作
    board->movePiece(choosedPiece,choosedCell);
    Playing::instance->addWidgetToBoardWidget(choosedCell->getPosition(),choosedPiece->getPieceWidget());

    checkGameOver();
    setChoosedPiece(nullptr);
    choosedCell = nullptr;
    currentPlayer = currentPlayer?0:1;
    round++;
    // future = QtConcurrent::run([this]() { this->playTurn(); });
}
void Game::checkGameOver()
{
    for(Piece* i:queenBees)
    {
        bool wasSurrounded = true;
        for(int j=0;j<6;j++)
            if(board->getPositionCell(i->getPosition()->getAdjacentPosition(j))->getPiece() == nullptr)
                wasSurrounded = false;
        if(wasSurrounded)
        {
            QMessageBox::information(MainWindow::instance,"游戏结束",QString("%1获胜！").arg(players[i->belongingPlayer]->name));
            SceneManager::instance->switchToScene(0);
        }
    }
}

int Game::getRound(bool isTurn)
{
    if(isTurn)
        return round;
    else
        return round/2+1;
}

void Game::setChoosedPiece(Piece *piece)
{
    if(choosedPiece)
        choosedPiece->getPieceWidget()->cancelChecked();
    choosedPiece = piece;
    if(piece)
    {
        QVector<Position*>* positionPtr = piece->isPlaced()?piece->getValidMoves(board):board->getValidPlaces(piece);
        //qDebug() <<piece->isPlaced()<< positionPtr->count();
        for(Position* i :*positionPtr)
        {
            QWidget* curAvaCellWidget = new AvailableCellWidget(board->getPositionCell(i));
            displayedAvailableCellWidget.append(curAvaCellWidget);
            Playing::instance->addWidgetToBoardWidget(i,curAvaCellWidget);
        }
        delete positionPtr;
    }else
    {
        for(QWidget* i:displayedAvailableCellWidget)
        {
            delete i;
        }
        displayedAvailableCellWidget.clear();
        Playing::instance->Iresize();
    }
}

void Game::setChoosedCell(Cell *cell)
{
    choosedCell = cell;
    playTurn();
}

Game::~Game()
{
    qDebug()<<"Game was terminated.";

}
