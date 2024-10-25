#ifndef STARTSCENE_H
#define STARTSCENE_H

#include <QWidget>
#include <QtMultimedia>
#include <QAudioOutput>

namespace Ui {
class StartScene;
}

class StartScene : public QWidget
{
    Q_OBJECT

public:
    static StartScene* instance;
    explicit StartScene(QWidget *parent = nullptr);
    void SetBackgroundMusic(bool val);
    ~StartScene();

private slots:
    void on_singlePlayBtn_clicked();

    void on_multiplePlayBtn_clicked();

    void on_exitGameBtn_clicked();

    void on_horizontalSlider_valueChanged(int value);

private:
    Ui::StartScene *ui;
    QMediaPlayer theme_music;
    QAudioOutput outpt;
};

#endif // STARTSCENE_H
