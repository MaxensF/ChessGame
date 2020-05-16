#include "pieceslabel.h"
#include "gamewindow.h"
#include <QWidget>
#include <iostream>
#include <QMouseEvent>
#include <QApplication>
#include <QDesktopWidget>
#include <QBoxLayout>
#include <QLabel>
#include <QPainter>

PiecesLabel::PiecesLabel(QWidget *parent) : QLabel(parent)
{

    //Getting the srceen height
     const int height = ((QApplication::desktop()->height())/6)*5;

    //The label will be a square of (heightWindow/10)*9
    m_labelWidth = (height/10)*9;
    m_labelHeight = (height/10)*9;
    this->setFixedSize(m_labelWidth,m_labelHeight);


    //Setting all the pixmaps for the white pieces
    m_whitePawn.load("://Pieces/WhitePawn.png");
    m_whiteRook.load("://Pieces/WhiteRook.png");
    m_whiteKnight.load("://Pieces/WhiteKnight.png");
    m_whiteBishop.load("://Pieces/WhiteBishop.png");
    m_whiteQueen.load("://Pieces/WhiteQueen.png");
    m_whiteKing.load("://Pieces/WhiteKing.png");


    //Setting all the white pieces sizes
    //Pieces are a little bit smaller than squares
    m_whitePawn = m_whitePawn.scaled(m_labelHeight/9,m_labelHeight/9,Qt::KeepAspectRatio, Qt::SmoothTransformation);
    m_whiteRook = m_whiteRook.scaled(m_labelHeight/9,m_labelHeight/9,Qt::KeepAspectRatio, Qt::SmoothTransformation);
    m_whiteKnight = m_whiteKnight.scaled(m_labelHeight/9,m_labelHeight/9,Qt::KeepAspectRatio, Qt::SmoothTransformation);
    m_whiteBishop = m_whiteBishop.scaled(m_labelHeight/9,m_labelHeight/9,Qt::KeepAspectRatio, Qt::SmoothTransformation);
    m_whiteQueen = m_whiteQueen.scaled(m_labelHeight/9,m_labelHeight/9,Qt::KeepAspectRatio, Qt::SmoothTransformation);
    m_whiteKing = m_whiteKing.scaled(m_labelHeight/9,m_labelHeight/9,Qt::KeepAspectRatio, Qt::SmoothTransformation);


    //Setting all the pixmaps for the black pieces
    m_blackPawn.load("://Pieces/BlackPawn.png");
    m_blackRook.load("://Pieces/BlackRook.png");
    m_blackKnight.load("://Pieces/BlackKnight.png");
    m_blackBishop.load("://Pieces/BlackBishop.png");
    m_blackQueen.load("://Pieces/BlackQueen.png");
    m_blackKing.load("://Pieces/BlackKing.png");


    //Setting all the black pieces sizes
    //Pieces are a little bit smaller than squares
    m_blackPawn = m_blackPawn.scaled(m_labelHeight/9,m_labelHeight/9,Qt::KeepAspectRatio, Qt::SmoothTransformation);
    m_blackRook = m_blackRook.scaled(m_labelHeight/9,m_labelHeight/9,Qt::KeepAspectRatio, Qt::SmoothTransformation);
    m_blackKnight = m_blackKnight.scaled(m_labelHeight/9,m_labelHeight/9,Qt::KeepAspectRatio, Qt::SmoothTransformation);
    m_blackBishop = m_blackBishop.scaled(m_labelHeight/9,m_labelHeight/9,Qt::KeepAspectRatio, Qt::SmoothTransformation);
    m_blackQueen = m_blackQueen.scaled(m_labelHeight/9,m_labelHeight/9,Qt::KeepAspectRatio, Qt::SmoothTransformation);
    m_blackKing = m_blackKing.scaled(m_labelHeight/9,m_labelHeight/9,Qt::KeepAspectRatio, Qt::SmoothTransformation);


    //Setting the board pixmap
    m_board.load("://Board/Board.png");
    m_board = m_board.scaled(m_labelHeight,m_labelHeight);


    //Setting the size of the pixmap which will be displayed
    m_game.load("://Board/Board.png");
    m_game = m_game.scaled(m_labelHeight,m_labelHeight);



    //Creating rectangle for the painter
    QRect boardSize(QPoint(0,0),QPoint(m_labelHeight,m_labelHeight));
    QRect pieceSize(QPoint(0,0),QPoint(m_labelHeight/8,m_labelHeight/8));


    //Setting the painter attributes
    //The painter will paint all the things that are
    //on the game Pixmap
    QPainter *painter = new QPainter (&m_game);
    painter->setRenderHint(QPainter::SmoothPixmapTransform);

    QRect square2(QPoint(10+m_labelHeight/8,10),QPoint(m_labelHeight/4,m_labelHeight/8));

    painter->drawPixmap(boardSize,m_board,boardSize);
    painter->fillRect(pieceSize,Qt::blue);
    painter->drawPixmap(square2,m_blackBishop,pieceSize);



    //Stop the painting
    painter->end();
    delete painter;

    //Use the painted pixmap as the Label Pixmap
    this->setPixmap(m_game);



}


//Set m_mousePoint cooridnates after each click on the board
void PiecesLabel::mousePressEvent(QMouseEvent *event){
    if (event->button() == Qt::LeftButton) {
        m_mousePoint = event->pos();
        std::cout<<" x = "<<m_mousePoint.x()<<std::endl;
        std::cout<<" y = "<<m_mousePoint.y()<<std::endl;
        clickToPosition(event->pos());
    }
}




//Return the position of the clicked square
int PiecesLabel::clickToPosition(QPoint point){
    int xPosition,yPosition,squareSize,position;
    squareSize = m_labelHeight/8;

    // 0 < xPosition < 8, 0 < yPosition < 8
    xPosition = point.x()/squareSize;
    yPosition = point.y()/squareSize;

    //0 < position < 63
    position = (xPosition + (8*yPosition));

    //1 < position < 64
    position +=1;
    std::cout<<"position = "<<position<<std::endl;
    return position;
}


