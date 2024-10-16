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
    Q_OBJECT

public:
    static MainWindow* instance;
    MainWindow(QWidget *parent = nullptr);
    void setStatusBarMessage(QString msg);
    ~MainWindow();

private slots:

    void on_actionExit_triggered();
    void on_actionAbout_triggered();

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
