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
    // //在这里创建所有的场景
    // addScene(0,new StartScene());
    // addScene(1,new Playing(false));
    // addScene(2,new Playing(true));
    //设置初始场景
    switchToScene(0);
}

SceneManager* SceneManager::instance = nullptr;

QWidget* SceneManager::addSceneToMainQWidget(QWidget *scene) {


    QWidget* centralWidget = MainWindow::instance->centralWidget();
    scene->setParent(centralWidget);
    centralWidget->layout()->addWidget(scene);
    return scene;
}

void SceneManager::switchToScene(const int num) {
    if (currentScene) {
        delete currentScene;
    }
    switch (num) {
    case 0:
        currentScene = addSceneToMainQWidget(new StartScene());
        break;
    case 1:
        currentScene = addSceneToMainQWidget(new Playing(false));
        break;
    case 2:
        currentScene = addSceneToMainQWidget(new Playing(true));
        break;
    default:
        qDebug() << "Illegal scene number.\n";
        break;
    }

    qDebug() << "Change to scene " << num;
    currentScene->show();
}

