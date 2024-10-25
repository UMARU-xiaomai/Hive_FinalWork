#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>
#include <QDesktopServices>
#include <QUrl>
#include "Scenes/startscene.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    MainWindow::instance = this;
    ui->setupUi(this);
    //设置标题
    this->setWindowTitle("Hive - by group 8");


}

void MainWindow::setStatusBarMessage(QString msg)
{
    ui->statusbar->showMessage(msg);
}
MainWindow* MainWindow::instance = nullptr;
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionExit_triggered()
{
    exit(0);
}
void MainWindow::on_actionAbout_triggered()
{
    QDesktopServices::openUrl(QUrl("https://github.com/UMARU-xiaomai/Hive_FinalWork"));
}

void MainWindow::on_actionMosquito_toggled(bool val)
{
    settings.addMosquito = val;
}

void MainWindow::on_actionLadybug_toggled(bool val)
{
    settings.addLadybug = val;
}

void MainWindow::on_actionPillbug_toggled(bool val)
{
    settings.addPillbug = val;
}

void MainWindow::on_actionPlacePiece_SE_toggled(bool val)
{
    settings.enableSoundEffect = val;
    qDebug()<<"Hello!!!!";
}

void MainWindow::on_actionBackgroundMusic_toggled(bool val)
{
    settings.backGroundMusic = val;
    if(StartScene::instance!=nullptr)
    StartScene::instance->SetBackgroundMusic(val);
}
