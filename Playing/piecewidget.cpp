#include "piecewidget.h"
#include "ui_piecewidget.h"
#include "game.h"

PieceWidget::PieceWidget(Piece* srcPiece,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PieceWidget)
{
    ui->setupUi(this);
    connectedPiece=srcPiece;
    ui->label->setText(srcPiece->typeStr);
    // qDebug() <<;
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

void PieceWidget::cancelChecked()
{
    ui->pieceToggle->setChecked(false);
}

void PieceWidget::on_pieceToggle_toggled(bool checked)
{
    if(checked)
    {
        qDebug()<<"choosed!!";
        Game::instance->setChoosedPiece(connectedPiece);
    }else
    {
        Game::instance->setChoosedPiece(nullptr);
    }
}

