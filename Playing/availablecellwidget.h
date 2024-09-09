#ifndef AVAILABLECELLWIDGET_H
#define AVAILABLECELLWIDGET_H

#include <QWidget>
#include "cell.h"

namespace Ui {
class AvailableCellWidget;
}

class AvailableCellWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AvailableCellWidget(Cell* cell,QWidget *parent = nullptr);
    ~AvailableCellWidget();

private slots:
    void on_cellToggle_clicked();

private:
    Cell* connectedCell = nullptr;
    Ui::AvailableCellWidget *ui;
};

#endif // AVAILABLECELLWIDGET_H
