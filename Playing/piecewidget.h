#ifndef PIECEWIDGET_H
#define PIECEWIDGET_H

#include <QWidget>
#include <QResizeEvent>


namespace Ui {
class PieceWidget;
}

class PieceWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PieceWidget(QWidget *parent = nullptr);
    ~PieceWidget();
protected:
    void resizeEvent(QResizeEvent* event) override;
private slots:
    void on_pieceToggle_toggled(bool checked);

private:
    Ui::PieceWidget *ui;
};

#endif // PIECEWIDGET_H
