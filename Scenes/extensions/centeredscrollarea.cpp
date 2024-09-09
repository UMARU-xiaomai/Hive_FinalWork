#include "centeredscrollarea.h"


CenteredScrollArea::CenteredScrollArea(QWidget *parent)
    : QAbstractScrollArea(parent), contentWidget(nullptr) {
    // 使滚动区域可以接受焦点用于键盘滚动等操作
    setFocusPolicy(Qt::StrongFocus);
}

void CenteredScrollArea::setWidget(QWidget *widget)
{
    contentWidget = widget;
    contentWidget->setParent(viewport());  // 将内容部件放到 viewport 中
    resizeWidget();
    updateScrollBars();
    updateContentPosition();

}

void CenteredScrollArea::resizeEvent(QResizeEvent *event)
{
    QAbstractScrollArea::resizeEvent(event);
    resizeWidget();
    updateScrollBars();
    updateContentPosition();

}

void CenteredScrollArea::setWidgetResizable(bool tar)
{
    widgetResizable = tar;
}

void CenteredScrollArea::updateScrollBars()
{
    if (!contentWidget)
        return;

    QSize contentSize = contentWidget->size();
    QSize viewportSize = viewport()->size();

    // 设置水平滚动条范围
    horizontalScrollBar()->setRange(0, qMax(0, contentSize.width() - viewportSize.width()));
    horizontalScrollBar()->setPageStep(viewportSize.width());

    // 设置垂直滚动条范围
    verticalScrollBar()->setRange(0, qMax(0, contentSize.height() - viewportSize.height()));
    verticalScrollBar()->setPageStep(viewportSize.height());
}

void CenteredScrollArea::updateContentPosition()
{
    if (!contentWidget)
        return;

    QSize contentSize = contentWidget->size();
    QSize viewportSize = viewport()->size();

    // 计算水平和垂直方向上的居中位置
    int xOffset = qMax(0, (viewportSize.width() - contentSize.width()) / 2);
    int yOffset = qMax(0, (viewportSize.height() - contentSize.height()) / 2);

    // 设置内容部件的位置
    contentWidget->move(xOffset - horizontalScrollBar()->value(),
                        yOffset - verticalScrollBar()->value());
}

void CenteredScrollArea::scrollContentsBy(int dx, int dy)
{
    QAbstractScrollArea::scrollContentsBy(dx, dy);
    resizeWidget();
    updateContentPosition();

}

void CenteredScrollArea::resizeWidget()
{
    if(contentWidget!=nullptr&&widgetResizable&&layout())
        contentWidget->resize(layout()->sizeHint());
}
