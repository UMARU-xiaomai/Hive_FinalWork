#include "piecewidget.h"
#include "ui_piecewidget.h"
#include "game.h"
#include <QStackedLayout>
#include "cell.h"
#include "..\Scenes\playing.h"
#include "testwidget.h"

PieceWidget::PieceWidget(Piece* srcPiece,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PieceWidget)
{
    ui->setupUi(this);
    connectedPiece=srcPiece;

    QStackedLayout* qsl = new QStackedLayout;
    qsl->setStackingMode(QStackedLayout::StackAll);
    qsl->setAlignment(Qt::AlignHCenter);
    qsl->addWidget(ui->testlabel);
    qsl->addWidget( ui->label);
    qsl->addWidget( ui->pieceToggle);
    this->setLayout(qsl);
    //ui->label->setText(srcPiece->typeStr());
    ui->label->setPixmap(QPixmap(srcPiece->getImgPath()).scaled(512,512));
    ui->label->setAttribute(Qt::WA_TransparentForMouseEvents,true);
    ui->testlabel->setAttribute(Qt::WA_TransparentForMouseEvents,true);
    // qDebug() <<;
}

void PieceWidget::resizeEvent(QResizeEvent* event)
{
    QWidget::resizeEvent(event);

    // 获取当前宽度
    int width = this->width();

    // 根据宽度设置高度，保持 1:1 比例
    this->setFixedHeight(width);

    ui->pieceToggle->setFixedSize(width,width);
    ui->pieceToggle->setIconSize(QSize(width,width));
    ui->label->setFixedSize(width,width);

    //Test
    // if(Cell* cell = connectedPiece->getCell())
    // {
    //     ui->testlabel->setText(QString("(%1,%2)").arg(cell->getPosition()->getX()).arg(cell->getPosition()->getY()));
    // }

    // // 计算水平和垂直方向上的居中位置
    // int xOffset = qMax(0, width/5);
    // int yOffset = qMax(0, width/5);

    // // 设置内容部件的位置
    // ui->label->move(xOffset,
    //                     yOffset);
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
        // if(Cell* cur = connectedPiece->getCell())
        // {
        //     for(int i =0 ;i<6;i++)
        //         Playing::instance->addWidgetToBoardWidget(cur->getAdjacentCell(i)->getPosition(),new TestWidget());
        // }
        qDebug()<<"choosed!!";
        Game::instance->setChoosedPiece(connectedPiece);
    }else
    {
        Game::instance->setChoosedPiece(nullptr);
    }

}

