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

void StartScene::on_pushButton_clicked(bool checked)
{
    SceneManager::instance->switchToScene(1);
    qDebug() << typeid(this->parent()).name();
}

