#ifndef AVAILABLECELLWIDGET_H
#define AVAILABLECELLWIDGET_H

#include <QWidget>

namespace Ui {
class AvailableCellWidget;
}

class AvailableCellWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AvailableCellWidget(QWidget *parent = nullptr);
    ~AvailableCellWidget();

private:
    Ui::AvailableCellWidget *ui;
};

#endif // AVAILABLECELLWIDGET_H
