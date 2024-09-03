#include "playing.h"
#include "ui_playing.h"
#include "..\scenemanager.h"
#include <QMessageBox>

Playing::Playing(bool aiMode,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Playing)
{
    ui->setupUi(this);

    //为持有棋子设置滚动条的布局
    QVBoxLayout* p1sLayout = new QVBoxLayout(ui->p1sPieces->widget());
    QVBoxLayout* p2sLayout = new QVBoxLayout(ui->p2sPieces->widget());

    //test
    // for(int i = 0;i<100;i++)
    // {
    //     p1sLayout->addWidget(new QPushButton(QString("%1").arg(i)));
    //     p2sLayout->addWidget(new QPushButton(QString("%1").arg(i)));
    // }


    this->mainGame = new Game(aiMode);
}
Playing* Playing::instance = nullptr;
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

