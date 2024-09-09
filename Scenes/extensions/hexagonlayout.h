#ifndef HEXAGONLAYOUT_H
#define HEXAGONLAYOUT_H

#include <QLayout>
#include <QWidget>
#include <QMap>
#include <QRect>
#include "centeredscrollarea.h"

class HexagonLayout : public QLayout {
public:
    HexagonLayout(CenteredScrollArea* csa,QWidget *parent = nullptr);
    ~HexagonLayout();

    // 必须实现的 QLayout 方法
    void addItem(QLayoutItem *item) override;
    QSize sizeHint() const override;
    QSize minimumSize() const override;
    QSize calculateBoundingSize() const;
    void setGeometry(const QRect &rect) override;
    QLayoutItem *itemAt(int index) const override;
    QLayoutItem *takeAt(int index) override;
    int count() const override;

    // 自定义方法：在指定位置添加QWidget
    void addWidgetAt(QWidget *widget, int row, int col);

private:
    struct HexCell {
        QLayoutItem *item;
        int row, col;
    };

    QList<HexCell> cells;
    int cellWidth = 100;  // 每个单元格的宽度
    int cellHeight = 100; // 每个单元格的高度

    QPoint getCellPosition(int row, int col) const;
    CenteredScrollArea* csa;
};


#endif // HEXAGONLAYOUT_H
