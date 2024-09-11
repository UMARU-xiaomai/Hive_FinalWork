#include "hexagonlayout.h"
HexagonLayout::HexagonLayout(CenteredScrollArea* csa,QWidget *parent) : QLayout(parent) {
    this->csa = csa;
}
HexagonLayout::~HexagonLayout() {
    while (!cells.isEmpty()) {
        delete takeAt(0);
    }
}

// 添加 QLayoutItem
void HexagonLayout::addItem(QLayoutItem *item) {
    cells.append({item, -1, -1});
}

// 添加 QWidget 到指定行列
void HexagonLayout::addWidgetAt(QWidget *widget, int col, int row,int layer) {
    addWidget(widget);
    int offset = 200;
    cells.last().row = offset+row;
    cells.last().col = offset+col;
    cells.last().layer = layer;
    csa->Sresize();
}

// 返回布局中的项目数量
int HexagonLayout::count() const {
    return cells.size();
}

// 返回指定索引的 QLayoutItem
QLayoutItem* HexagonLayout::itemAt(int index) const {
    if (index >= 0 && index < cells.size()) {
        return cells[index].item;
    }
    return nullptr;
}

// 移除指定索引的 QLayoutItem
QLayoutItem* HexagonLayout::takeAt(int index) {
    if (index >= 0 && index < cells.size()) {
        HexCell cell = cells.takeAt(index);
        return cell.item;
    }
    return nullptr;
}

QSize HexagonLayout::sizeHint() const {
    return calculateBoundingSize();
}

QSize HexagonLayout::minimumSize() const {
    return calculateBoundingSize();
}

QSize HexagonLayout::calculateBoundingSize() const {
    if (cells.isEmpty()) return QSize(0, 0);

    int minX = INT_MAX, minY = INT_MAX;
    int maxX = INT_MIN, maxY = INT_MIN;

    for (const HexCell &cell : cells) {
        QPoint pos = getCellPosition(cell.row, cell.col,cell.layer);
        minX = qMin(minX, pos.x());
        minY = qMin(minY, pos.y());
        maxX = qMax(maxX, pos.x() + cellWidth);
        maxY = qMax(maxY, pos.y() + cellHeight);
    }

    return QSize(maxX - minX, maxY - minY);
}
// 设置布局的几何形状
void HexagonLayout::setGeometry(const QRect &rect) {
    QLayout::setGeometry(rect);

    for (const HexCell &cell : cells) {
        int minX = INT_MAX, minY = INT_MAX;

        for (const HexCell &cell : cells) {
            QPoint pos = getCellPosition(cell.row, cell.col,cell.layer);
            minX = qMin(minX, pos.x());
            minY = qMin(minY, pos.y());
        }
        QPoint pos = getCellPosition(cell.row, cell.col,cell.layer) - QPoint(minX,minY);
        cell.item->setGeometry(QRect(pos, QSize(cellWidth, cellHeight)));
    }
}

// 计算每个六边形单元格的位置
QPoint HexagonLayout::getCellPosition(int row, int col,int layer) const {

    int xOffset = (row % 2 == 0) ? cellWidth / 2 : 0;
    int yLayerOffset = -layer*(cellHeight/10);
    int x = col * cellWidth + xOffset;
    int y = row * (cellHeight * 3 / 4) + yLayerOffset;  // 每一行向下移动 3/4 个高度
    return QPoint(x, y);
}
