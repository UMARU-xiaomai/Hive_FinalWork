#include "startscene.h"
#include "ui_startscene.h"
#include "..\scenemanager.h"
#include <QDebug>
#include <QSoundEffect>

StartScene::StartScene(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StartScene)
    , theme_music(this)
    , outpt(this)
{
    ui->setupUi(this);

    theme_music.setSource(QUrl("qrc:/music/Resources/legend_of_hive.mp3"));
    theme_music.setAudioOutput(&outpt);
    theme_music.setLoops(QMediaPlayer::Infinite);
    outpt.setVolume(50);
    theme_music.play();
    qDebug()<<theme_music.error();
}

StartScene::~StartScene()
{
    theme_music.stop();
    delete ui;
}



void StartScene::on_singlePlayBtn_clicked()
{
    SceneManager::instance->switchToScene(2);
}


void StartScene::on_multiplePlayBtn_clicked()
{
    SceneManager::instance->switchToScene(1);

}


void StartScene::on_exitGameBtn_clicked()
{
    exit(0);
}


void StartScene::on_horizontalSlider_valueChanged(int value)
{
    outpt.setVolume(value);
}

