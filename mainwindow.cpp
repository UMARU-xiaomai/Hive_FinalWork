#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>

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

