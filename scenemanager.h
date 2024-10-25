#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <QObject>
#include <QWidget>

class SceneManager : public QWidget
{
    Q_OBJECT
public:
    static SceneManager* instance; // 单例模式
    explicit SceneManager(QWidget *parent = nullptr);
    //切换场景
    void switchToScene(const int num) ;
    QWidget *currentScene = nullptr;
private:
    //添加场景，让每个场景（QWiget）在创建时添加到场景管理器
    QWidget* addSceneToMainQWidget(QWidget *scene);
    // QMap<int, QWidget*> scenes;


signals:
};

#endif // SCENEMANAGER_H
