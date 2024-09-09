#include "availablecellwidget.h"
#include "ui_availablecellwidget.h"
#include "game.h"

AvailableCellWidget::AvailableCellWidget(Cell* cell,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AvailableCellWidget)
{
    ui->setupUi(this);
    connectedCell = cell;
}

AvailableCellWidget::~AvailableCellWidget()
{
    delete ui;
}

void AvailableCellWidget::on_cellToggle_clicked()
{
    if(!connectedCell)
    {
        qDebug()<<"ccptr is null!!";
        return;
    }
    Game::instance->setChoosedCell(connectedCell);
    qDebug()<<"test point";
}

