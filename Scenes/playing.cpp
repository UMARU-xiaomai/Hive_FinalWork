#include "playing.h"
#include "ui_playing.h"
#include "..\scenemanager.h"
#include <QMessageBox>
#include <QDebug>
#include "..\mainwindow.h"



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
    new QVBoxLayout(ui->p1sPieces->widget());
    new QVBoxLayout(ui->p2sPieces->widget());

    csa = new CenteredScrollArea(this);
    dynamic_cast<QGridLayout*>(this->layout())->addWidget(csa,1,1);
    // csa->setWidgetResizable(true);

    QSAWidget = new QWidget(csa);
    //QSAWidget->setSizePolicy(QSizePolicy(QSizePolicy::Policy::Maximum,QSizePolicy::Policy::Maximum));
    boardWidgetLayout = new HexagonLayout(csa,QSAWidget);
    //boardWidgetLayout->setAlignment(Qt::AlignHCenter);
    //test
    // for(int i = 0;i<100;i++)
    // {
    //     p1sLayout->addWidget(new QPushButton(QString("%1").arg(i)));
    //     p2sLayout->addWidget(new QPushButton(QString("%1").arg(i)));
    // }
    // for (int i = 15; i <20 ; ++i) {
    //     for (int j = 6;j<20;j++)
    //     {
    //         QPushButton *button = new QPushButton(QString::number(i + 1)+","+QString::number(j + 1));
    //         button->setSizePolicy(QSizePolicy(QSizePolicy::Policy::Fixed,QSizePolicy::Policy::Fixed));
    //         boardWidgetLayout->addWidgetAt(button,i,j);
    //     }
    // }
    boardWidgetLayout->addWidgetAt(pleasePlacePiece_label = new QLabel("请选择棋子并放置"),0,0);
    QSAWidget->setLayout(boardWidgetLayout);
    csa->setWidget(QSAWidget);
    QSAWidget->show();
    this->mainGame = new Game(aiMode,this);
}

Playing* Playing::instance = nullptr;

void Playing::showEvent(QShowEvent* event) {
    QWidget::showEvent(event);
    if(notStart)
    {
        mainGame->start();
        notStart = false;
    }
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

void Playing::addWidgetToBoardWidget(Position *position, QWidget *widget,int layer)
{
    qDebug() << "add widget to board";


    //添加至自定义的蜂窝布局
    //qDebug()<<position->getX()<<position->getY();
    widget->setSizePolicy(QSizePolicy(QSizePolicy::Policy::Fixed,QSizePolicy::Policy::Fixed));
    boardWidgetLayout->addWidgetAt(widget,position->getX(),position->getY(),layer);
    widget->raise();

}

void Playing::Iresize()
{
    csa->Sresize();
}

void Playing::setPlayerName(QString name, int num)
{
    if(num)
    {
        ui->p2l->setText(name);
    }else{
        ui->p1l->setText(name);
    }
}

void Playing::hidePleasePlacePiece_label()
{
    if(!pleasePlacePiece_label->isHidden())
        pleasePlacePiece_label->hide();
    return;
}
Playing::~Playing()
{
    MainWindow::instance->setStatusBarMessage("");
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



