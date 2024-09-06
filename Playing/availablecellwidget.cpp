#include "availablecellwidget.h"
#include "ui_availablecellwidget.h"

AvailableCellWidget::AvailableCellWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AvailableCellWidget)
{
    ui->setupUi(this);
}

AvailableCellWidget::~AvailableCellWidget()
{
    delete ui;
}
