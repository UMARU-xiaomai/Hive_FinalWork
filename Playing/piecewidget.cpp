#include "piecewidget.h"
#include "ui_piecewidget.h"

PieceWidget::PieceWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PieceWidget)
{
    ui->setupUi(this);
}

void PieceWidget::resizeEvent(QResizeEvent* event)
{
    QWidget::resizeEvent(event);

    // 获取当前宽度
    int width = this->width();

    // 根据宽度设置高度，保持 1:1 比例
    this->setFixedHeight(width);

    ui->pieceToggle->setIconSize(QSize(width,width));
}

PieceWidget::~PieceWidget()
{
    delete ui;
}

void PieceWidget::on_pieceToggle_toggled(bool checked)
{
    if(checked)
    {
        //当棋子被选中时，需要展示甲虫重叠情况下全部的棋子
    }
}

