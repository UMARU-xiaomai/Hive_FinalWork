#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    struct Settings
    {
        bool addMosquito = false;
        bool addLadybug = true;
        bool addPillbug = false;

        bool enableSoundEffect = true;
        bool backGroundMusic = true;
    };

    Q_OBJECT

public:
    static MainWindow* instance;
    MainWindow(QWidget *parent = nullptr);
    void setStatusBarMessage(QString msg);
    Settings settings;
    ~MainWindow();

private slots:

    void on_actionExit_triggered();
    void on_actionAbout_triggered();
    void on_actionMosquito_toggled(bool val);
    void on_actionLadybug_toggled(bool val);
    void on_actionPillbug_toggled(bool val);
    void on_actionPlacePiece_SE_toggled(bool val);
    void on_actionBackgroundMusic_toggled(bool val);

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
