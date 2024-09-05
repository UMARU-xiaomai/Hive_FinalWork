#include "playing.h"
#include "ui_playing.h"
#include "..\scenemanager.h"
#include <QMessageBox>

Playing::Playing(bool aiMode,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Playing)
{
    ui->setupUi(this);

    //单例模式
    if(!Playing::instance)
        delete Playing::instance;
    Playing::instance = this;

    //为持有棋子设置滚动条的布局
    QVBoxLayout* p1sLayout = new QVBoxLayout(ui->p1sPieces->widget());
    QVBoxLayout* p2sLayout = new QVBoxLayout(ui->p2sPieces->widget());

    //test
    // for(int i = 0;i<100;i++)
    // {
    //     p1sLayout->addWidget(new QPushButton(QString("%1").arg(i)));
    //     p2sLayout->addWidget(new QPushButton(QString("%1").arg(i)));
    // }


    this->mainGame = new Game(aiMode,this);
}

Playing* Playing::instance = nullptr;

void Playing::showEvent(QShowEvent* event) {
    QWidget::showEvent(event);

    mainGame->start();
}

void Playing::addPieceWidgetToPlayerColumn(int playerNum, QWidget *pieceWidget)
{
    qDebug()<<"add pw";

    if(playerNum==0)
    {
        pieceWidget->setParent(ui->p1sContent);
        ui->p1sContent->layout()->addWidget(pieceWidget);
        //test
        //QPushButton* button = new QPushButton("点击我", this);
        //ui->p1sContent->layout()->addWidget(button);

        ui->p1sContent->setLayout(ui->p1sContent->layout());
        //debug
        //qDebug()<<ui->p1sContent->geometry().x()<<ui->p1sContent->geometry().y()<<button->geometry().x()<<button->geometry().y();
    }else
    {
        pieceWidget->setParent(ui->p2sContent);
        ui->p2sContent->layout()->addWidget(pieceWidget);
        ui->p2sContent->setLayout(ui->p2sContent->layout());
    }
}
Playing::~Playing()
{
    delete ui;
}



void Playing::on_tieBtn_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "确认", "你想要和局吗？",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        QMessageBox::information(this,"游戏结束","游戏平局！");
        SceneManager::instance->switchToScene(0);
    }
}



