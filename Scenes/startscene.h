#ifndef STARTSCENE_H
#define STARTSCENE_H

#include <QWidget>

namespace Ui {
class StartScene;
}

class StartScene : public QWidget
{
    Q_OBJECT

public:
    explicit StartScene(QWidget *parent = nullptr);
    ~StartScene();

private slots:
    void on_pushButton_clicked(bool checked);

private:
    Ui::StartScene *ui;
};

#endif // STARTSCENE_H
