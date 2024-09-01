#ifndef PLAYING_H
#define PLAYING_H

#include <QWidget>

namespace Ui {
class Playing;
}

class Playing : public QWidget
{
    Q_OBJECT

public:
    explicit Playing(QWidget *parent = nullptr);
    ~Playing();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Playing *ui;
};

#endif // PLAYING_H
