#ifndef PIECESLABEL_H
#define PIECESLABEL_H

#include <QApplication>
#include <QLabel>
#include <QWidget>

class PiecesLabel : public QLabel
{
    Q_OBJECT
public:
    explicit PiecesLabel(QWidget *parent = nullptr);
public:
    void mousePressEvent(QMouseEvent *event) override;
    int  clickToPosition(QPoint point);
    void drawGamePixmap();
private:
    int m_labelHeight;
    int m_labelWidth;
    QPoint m_mousePoint;
    QPixmap m_whiteKnight;
    QPixmap m_blackKnight;
    QPixmap m_blackRook;
    QPixmap m_whiteRook;
    QPixmap m_blackPawn;
    QPixmap m_whitePawn;
    QPixmap m_blackQueen;
    QPixmap m_whiteQueen;
    QPixmap m_whiteKing;
    QPixmap m_blackKing;
    QPixmap m_whiteBishop;
    QPixmap m_blackBishop;
    QPixmap m_board;
    QPixmap m_game;

signals:

};

#endif // PIECESLABEL_H
