#include "game.h"
#include <QMessageBox>
#include <QInputDialog>
#include "aiplayer.h"
#include "..\mainwindow.h"
#include <QtConcurrent/QtConcurrent>
#include "cell.h"
#include <QThread>
#include "..\scenemanager.h"
Game::Game(bool aiMode,QObject* parent)
    :QObject(parent)
{
    this->aiMode = aiMode;

    //初始化棋盘
    board = new Board(this);
    isGameOver = false;

    // future = QtConcurrent::run([this]() { this->start(); });

}

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
    if(choosedPiece->isPlaced)
    {
        board->movePiece(choosedPiece,choosedPosition);
    }else{
        board->placePiece(choosedPiece,choosedPosition);
    }
    checkGameOver();
    choosedPiece = nullptr;
    choosedPosition = nullptr;
    currentPlayer = currentPlayer?0:1;
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

int Game::getRound()
{
    return round;
}

Game::~Game()
{
    qDebug()<<"Game was terminated.";

}
