#include "startscene.h"
#include "ui_startscene.h"
#include "..\scenemanager.h"
#include <QDebug>

StartScene::StartScene(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StartScene)
{
    ui->setupUi(this);
}

StartScene::~StartScene()
{
    delete ui;
}



void StartScene::on_singlePlayBtn_clicked()
{
    SceneManager::instance->switchToScene(1);
}


void StartScene::on_multiplePlayBtn_clicked()
{
    SceneManager::instance->switchToScene(1);
}


void StartScene::on_exitGameBtn_clicked()
{
    exit(0);
}

