#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include "pieceslabel.h"
#include <QWidget>


class GameWindow : public QWidget
{
 Q_OBJECT
 public:
  explicit GameWindow(Board *board = nullptr, QWidget *parent = 0);
    int getHeight();
    int getWidth();
    void setHeight(int height);
    void setWidht(int width);
    PiecesLabel* getPieceLabel();

private:
    int m_height;
    int m_width;
    PiecesLabel* m_piecesLabel;

 signals:
 public slots:



};

#endif // GAMEWINDOW_H
