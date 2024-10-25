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
#include <QCoreApplication>
#include <QLibrary>
#include <QSoundEffect>

#include "pieceinterface.h"

typedef PieceInterface* (*CreatePluginFunc)();
typedef void (*DestroyPluginFunc)(PieceInterface*);
Game::Game(bool aiMode,QObject* parent)
    :QObject(parent),effect(this)
{
    this->aiMode = aiMode;

    //单例模式
    // if(Game::instance != nullptr)
    //     delete Game::instance;
    Game::instance = this;

    //初始化棋盘
    board = new Board(this);
    isGameOver = false;

    round =1;
    // future = QtConcurrent::run([this]() { this->start(); });
    qDebug()<<effect.status();
    effect.setSource(QUrl("qrc:/playing/Resources/piece_placed.wav"));
    qDebug()<<effect.status();
    effect.setLoopCount(1);
    effect.setVolume(0.25f);
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
    players[0] = new Player(text,false,0,this);
    Playing::instance->setPlayerName(text,0);

    if(aiMode)
    {
        players[1] = new AIPlayer(1);
        Playing::instance->setPlayerName("AI",1);

        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(MainWindow::instance, "确认", "你想要先手吗？",
                                      QMessageBox::Yes | QMessageBox::No);

        if (reply == QMessageBox::Yes) {
            currentPlayer = 0;
        }else{
            currentPlayer = 1;
            //AI先下
            setChoosedPiece(static_cast<AIPlayer*>(players[1])->selectPiece());
            static_cast<AIPlayer*>(players[1])->movePiece();
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
        players[1] = new Player(text,false,1,this);
        Playing::instance->setPlayerName(text,1);
        currentPlayer = 0;
    }

    //加载插件

    MainWindow::instance->setStatusBarMessage(QString("请先手 %1 放置棋子。请注意，您需要在接下来的4回合内放置蜂后。").arg(players[currentPlayer]->name));
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
    Playing::instance->addWidgetToBoardWidget(choosedCell->getPosition(),choosedPiece->getPieceWidget(),choosedCell->getPiecesNum()-1);
    Playing::instance->hidePleasePlacePiece_label();

    //检测放的是不是蜂后
    if(choosedPiece->isQueenBee())
    {
        queenBees[currentPlayer] = choosedPiece;
    }

    if(checkGameOver())
    {
        MainWindow::instance->setStatusBarMessage("");
        return;
    }
    setChoosedPiece(nullptr);
    choosedCell = nullptr;
    currentPlayer = currentPlayer?0:1;
    qDebug() << "now:"<<currentPlayer;
    round++;

    //显示状态栏信息
    if(getRound(true)==2)
    {
        MainWindow::instance->setStatusBarMessage(QString("请后手 %1 放置棋子。请注意，您需要在接下来的4回合内放置蜂后。").arg(players[currentPlayer]->name));
    }else
    {
        QString msg = QString("请 %1 ").arg(players[currentPlayer]->name);
        if(!queenBees[currentPlayer])
        {
            int remainRound = 5-getRound(false);
            if(remainRound>1)
                msg += QString("放置棋子。请注意，您需要在接下来的%1回合内放置蜂后。").arg(remainRound);
            else
                msg += QString("放置棋子。请注意，您必须在本回合内放置蜂后。");
        }else
        {
            msg +=QString("移动或放置棋子。");
        }
        MainWindow::instance->setStatusBarMessage(msg);
    }
    // future = QtConcurrent::run([this]() { this->playTurn(); });

    //AI模式
    if(aiMode&&currentPlayer==1)
    {
        setChoosedPiece(static_cast<AIPlayer*>(players[1])->selectPiece());
        static_cast<AIPlayer*>(players[1])->movePiece();
    }
}
bool Game::checkGameOver()
{
    for(int i = 0;i<2;i++)
    {
        if(Piece* curQB = queenBees[i])
        {
            bool wasSurrounded = true;
            for(int j=0;j<6;j++)
                if(curQB->getCell()->getAdjacentCell(j)->getPiece() == nullptr)
                    wasSurrounded = false;
            if(wasSurrounded)
            {
                QMessageBox::information(MainWindow::instance,"游戏结束",QString("%1获胜！").arg(players[i?0:1]->name));
                SceneManager::instance->switchToScene(0);
                return true;
            }
        }else if(getRound(false)>=4)
        {
            QMessageBox::information(MainWindow::instance,"游戏结束",QString("%1获胜！").arg(players[i?0:1]->name));
            SceneManager::instance->switchToScene(0);
            return true;
        }
    }
    return false;
}

int Game::getRound(bool isTurn)
{
    if(isTurn)
        return round;
    else
        return (round+1)/2;
}

QVector<Cell *> Game::getAvaliablePositions(Piece* tar)
{
    if(!tar)
        tar = choosedPiece;
    QVector<Cell*> positions;
    if(tar->isPlaced()&&queenBees[currentPlayer])
        positions = tar->getValidMoves(board);
    else if(!tar->isPlaced())
        positions = board->getValidPlaces(tar);
    //qDebug() <<piece->isPlaced()<< positionPtr->count();
    return positions;
}

void Game::setChoosedPiece(Piece *piece)
{
    if(choosedPiece)
        choosedPiece->getPieceWidget()->cancelChecked();
    choosedPiece = piece;

    //若非该回合玩家棋子，不允许移动

    if(piece&&piece->belongingPlayer==currentPlayer)
    {
        QVector<Cell*> positions = getAvaliablePositions();
            for(Cell* i :positions)
            {
                QWidget* curAvaCellWidget = new AvailableCellWidget(i);
                displayedAvailableCellWidget.append(curAvaCellWidget);
                Playing::instance->addWidgetToBoardWidget(i->getPosition(),curAvaCellWidget,i->getPiecesNum());
            }


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
    if(MainWindow::instance->settings.enableSoundEffect)
        effect.play();
    playTurn();


}

void Game::loadAndUsePlugin(const QString& pluginPath) {
    QLibrary pluginLib(pluginPath);

    if (pluginLib.load()) {
        // 获取创建和销毁插件的函数指针
        CreatePluginFunc createPlugin = (CreatePluginFunc)pluginLib.resolve("createPlugin");
        DestroyPluginFunc destroyPlugin = (DestroyPluginFunc)pluginLib.resolve("destroyPlugin");

        if (createPlugin && destroyPlugin) {
            PieceInterface* plugin = createPlugin();  // 创建插件实例


            players[0]->addPlugPiece(plugin);
            players[1]->addPlugPiece(plugin);


            destroyPlugin(plugin);  // 销毁插件实例
        } else {
            qDebug() << "Failed to resolve plugin functions";
        }
    } else {
        qDebug() << "Failed to load plugin:" << pluginLib.errorString();
    }
}

Game::~Game()
{
    qDebug()<<"Game was terminated.";

}
