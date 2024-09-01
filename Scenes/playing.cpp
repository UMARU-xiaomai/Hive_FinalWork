#include "playing.h"
#include "ui_playing.h"
#include "..\scenemanager.h"

Playing::Playing(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Playing)
{
    ui->setupUi(this);

}

Playing::~Playing()
{
    delete ui;
}

void Playing::on_pushButton_clicked()
{
    SceneManager::instance->switchToScene(0);
}

