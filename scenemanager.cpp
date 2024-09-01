#include "scenemanager.h"
#include "mainwindow.h"
#include <QWidget>
#include <QDebug>
#include <QLayout>
#include "Scenes/startscene.h"
#include "Scenes/playing.h"


SceneManager::SceneManager(QWidget *parent)
    : QWidget{parent}
{
    SceneManager::instance = this;
    //在这里创建所有的场景
    addScene(0,new StartScene());
    addScene(1,new Playing());
    //设置初始场景
    switchToScene(0);
}

SceneManager* SceneManager::instance = nullptr;

void SceneManager::addScene(const int num, QWidget *scene) {
    this->scenes[num] = scene;

    QWidget* centralWidget = MainWindow::instance->centralWidget();
    scene->setParent(centralWidget);
    centralWidget->layout()->addWidget(scene);
    scene->hide();
}

void SceneManager::switchToScene(const int num) {
    if (currentScene) {
        currentScene->hide();
    }
    currentScene = scenes[num];
    qDebug() << "Change to scene " << num;
    currentScene->show();
}
