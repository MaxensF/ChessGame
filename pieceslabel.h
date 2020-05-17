#ifndef PIECESLABEL_H
#define PIECESLABEL_H


#include <QApplication>
#include <QLabel>
#include <QWidget>
#include <vector>
#include "board.h"
#include "piece.h"

class PiecesLabel : public QLabel
{
    Q_OBJECT
public:
    explicit PiecesLabel(Board *board = nullptr,QWidget *parent = nullptr);
    void mousePressEvent(QMouseEvent *event) override;
    int  clickToPosition(QPoint point);
    QRect positionToRectangle(int position);
    void drawGamePixmap(std::vector <Piece> board);
    bool getSelected();
private:
    int m_labelHeight;
    int m_labelWidth;
    int m_squareSize;
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
    bool m_selected;
    Piece m_firstSelectedPiece;
    Piece m_secondSelectedPiece;
    Board *m_boardPieces;

signals:

};

#endif // PIECESLABEL_H
