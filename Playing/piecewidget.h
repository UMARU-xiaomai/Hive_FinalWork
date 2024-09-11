#ifndef PIECEWIDGET_H
#define PIECEWIDGET_H

#include <QWidget>
#include <QResizeEvent>
//#include "piece.h"
class Piece;
namespace Ui {
class PieceWidget;
}

class PieceWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PieceWidget(Piece* srcPiece,QWidget *parent = nullptr);
    ~PieceWidget();
    void cancelChecked();
    void setPieceBelonging(int belongingNum);
protected:
    void resizeEvent(QResizeEvent* event) override;
private slots:
    void on_pieceToggle_toggled(bool checked);

private:
    Ui::PieceWidget *ui;
    Piece* connectedPiece;
};

#endif // PIECEWIDGET_H
