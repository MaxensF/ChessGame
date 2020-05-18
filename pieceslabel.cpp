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
#include "piece.h"
#include "board.h"


PiecesLabel::PiecesLabel(Board *board,QWidget *parent) : QLabel(parent)
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

    m_whitePawn = m_whitePawn.scaled(m_labelHeight/8,m_labelHeight/8,Qt::KeepAspectRatio, Qt::SmoothTransformation);
    m_whiteRook = m_whiteRook.scaled(m_labelHeight/8,m_labelHeight/8,Qt::KeepAspectRatio, Qt::SmoothTransformation);
    m_whiteKnight = m_whiteKnight.scaled(m_labelHeight/8,m_labelHeight/8,Qt::KeepAspectRatio, Qt::SmoothTransformation);
    m_whiteBishop = m_whiteBishop.scaled(m_labelHeight/8,m_labelHeight/8,Qt::KeepAspectRatio, Qt::SmoothTransformation);
    m_whiteQueen = m_whiteQueen.scaled(m_labelHeight/8,m_labelHeight/8,Qt::KeepAspectRatio, Qt::SmoothTransformation);
    m_whiteKing = m_whiteKing.scaled(m_labelHeight/8,m_labelHeight/8,Qt::KeepAspectRatio, Qt::SmoothTransformation);


    //Setting all the pixmaps for the black pieces
    m_blackPawn.load("://Pieces/BlackPawn.png");
    m_blackRook.load("://Pieces/BlackRook.png");
    m_blackKnight.load("://Pieces/BlackKnight.png");
    m_blackBishop.load("://Pieces/BlackBishop.png");
    m_blackQueen.load("://Pieces/BlackQueen.png");
    m_blackKing.load("://Pieces/BlackKing.png");


    //Setting all the black pieces sizes
    //Pieces are a little bit smaller than squares
    m_blackPawn = m_blackPawn.scaled(m_labelHeight/8,m_labelHeight/8,Qt::KeepAspectRatio, Qt::SmoothTransformation);
    m_blackRook = m_blackRook.scaled(m_labelHeight/8,m_labelHeight/8,Qt::KeepAspectRatio, Qt::SmoothTransformation);
    m_blackKnight = m_blackKnight.scaled(m_labelHeight/8,m_labelHeight/8,Qt::KeepAspectRatio, Qt::SmoothTransformation);
    m_blackBishop = m_blackBishop.scaled(m_labelHeight/8,m_labelHeight/8,Qt::KeepAspectRatio, Qt::SmoothTransformation);
    m_blackQueen = m_blackQueen.scaled(m_labelHeight/8,m_labelHeight/8,Qt::KeepAspectRatio, Qt::SmoothTransformation);
    m_blackKing = m_blackKing.scaled(m_labelHeight/8,m_labelHeight/8,Qt::KeepAspectRatio, Qt::SmoothTransformation);


    //Setting the board pixmap
    m_board.load("://Board/Board.png");
    m_board = m_board.scaled(m_labelHeight,m_labelHeight);


    //Setting the size of the pixmap which will be displayed
    m_game.load("://Board/Board.png");
    m_game = m_game.scaled(m_labelHeight,m_labelHeight);


    //Setting the square height/width
    m_squareSize = (m_labelHeight/8);


    //No pieces has been selected
    m_selected = false;


    //Giving the board to the class PiecesLabel
    m_boardPieces = board;

    //Draw the board
    drawGamePixmap(m_boardPieces->getBoard());

}




void endWindow(){

    QWidget endWindow;

    //Getting srceen informations
     const int width = 50;
     const int height = 50;

     // Set the size attributes for things in the window
    endWindow.setFixedSize(width,height);
    endWindow.show();


}




//Set m_mousePoint cooridnates after each click on the board
void PiecesLabel::mousePressEvent(QMouseEvent *event){
    int position = 0;
    if (event->button() == Qt::LeftButton) {
        m_mousePoint = event->pos();

        position = clickToPosition(event->pos());
    }
    //Second click on a piece (moving a piece)
    if(m_selected == true){
        m_secondSelectedPiece = m_boardPieces->getPiece(position);
        m_selected = false;

        //The move has been done
        if (m_boardPieces->movePiece(m_firstSelectedPiece,m_secondSelectedPiece)){

            //Stop the game if there is a draw/checkmate
            if(m_boardPieces->isCheckMate() || (m_boardPieces->isDraw())){
                endWindow();
                std::cout<<"checkmate"<<std::endl;

            }
        }

        drawGamePixmap(m_boardPieces->getBoard());

    }

    //First click on a piece (selecting a piece)
    if((m_boardPieces->getPiece(position).getPieceType() != NONE) && (m_selected == false)){
        m_firstSelectedPiece = m_boardPieces->getPiece(position);
        m_selected = true;
        drawGamePixmap(m_boardPieces->getBoard());
    }

    //The player didn't clicked on a piece on the first click
    else if((m_boardPieces->getPiece(position).getPieceType() == NONE) && (m_selected == false)){
        drawGamePixmap(m_boardPieces->getBoard());
    }


}





//Return the position of the clicked square
int PiecesLabel::clickToPosition(QPoint point){
    int xPosition,yPosition,position;
    m_squareSize = m_labelHeight/8;

    // 0 < xPosition < 8, 0 < yPosition < 8
    xPosition = point.x()/m_squareSize;
    yPosition = point.y()/m_squareSize;

    //0 < position < 63
    position = (xPosition + (8*yPosition));

    //1 < position < 64
    position +=1;

    return position;
}






QRect PiecesLabel::positionToRectangle(int position){
    int xPos,yPos,x2Pos,y2Pos;
    QPoint leftTopCorner,rightBottomCorner;

    xPos = ((position-1)%8)* m_squareSize;
    yPos = ((position-1)/8)*m_squareSize;


    //Setting the top left corner of the rectangle
    leftTopCorner.setX(xPos);
    leftTopCorner.setY(yPos);

    x2Pos = xPos + m_squareSize;
    y2Pos = yPos + m_squareSize;

    //Setting the bottom right corner of the rectangle
    rightBottomCorner.setX(xPos);
    rightBottomCorner.setY(yPos);

    QRect rectangle(QPoint(xPos,yPos),QPoint(x2Pos,y2Pos));


    return rectangle;
}





//Draw a Pixmap of the current game and display it
void PiecesLabel::drawGamePixmap(std::vector <Piece> board){

    //Creating rectangles for the painter
    QRect boardSize(QPoint(0,0),QPoint(m_labelHeight,m_labelHeight));
    QRect pieceSize(QPoint(0,0),QPoint(m_labelHeight/8,m_labelHeight/8));


    //Setting the painter attributes
    //The painter will paint all the things that are
    //on the game Pixmap
    QPainter *painter = new QPainter (&m_game);
    painter->setRenderHint(QPainter::SmoothPixmapTransform);

    //Draw the board
    painter->drawPixmap(boardSize,m_board,boardSize);

    QRect positionRect;
    pieceType pieceType;
    Color pieceColor;
    Piece king;
    if(m_boardPieces->getTurn() == BLACK){
        king = m_boardPieces->findBlackKing();
    }
    else if(m_boardPieces->getTurn() == WHITE){
        king = m_boardPieces->findWhiteKing();
    }


    //If a piece is selected show where it can move
    // with a blue square
    if(m_selected == true){
        std::vector <Piece> possibleMoves = m_boardPieces->getPossibleMoves(m_firstSelectedPiece);
        int sizePossibleMoves = possibleMoves.size();

        //Draw blue squares where selected piece can move
         for(int i=0; i<sizePossibleMoves;i++){
             positionRect = positionToRectangle(possibleMoves.at(i).getPosition());

             //Center of the Gradient
             int yMid = positionRect.top() + (positionRect.bottom() - positionRect.top() )/2;
             int xMid = positionRect.left() + (positionRect.right() - positionRect.left() )/2;

             //border of the square
             int x1= positionRect.left()+2;
             int y1 = positionRect.top()+2;
             int x2= positionRect.right()-2;
             int y2 = positionRect.bottom()-2;
             QPen pen1(QColor(0, 47, 88),4);
             painter->setPen(pen1);
           //  painter->setClipPath(Qt::)
             QRect border(QPoint(x1,y1),QPoint(x2,y2));
             painter->drawRect(border);

             //Drawing the gradient
             QRadialGradient radialGradient(xMid,yMid,150,xMid,yMid);
             radialGradient.setColorAt(0,QColor(0, 47, 186,100));
             radialGradient.setColorAt(1,QColor(0, 47, 186,220));
             QPen pen(Qt::NoPen);
             painter->setPen(pen);
             painter->fillRect(positionRect,radialGradient);

        }

         //Show what piece is selected in gray
         positionRect = positionToRectangle(m_firstSelectedPiece.getPosition());
         //Center of the Gradient
         int yMid = positionRect.top() + (positionRect.bottom() - positionRect.top() )/2;
         int xMid = positionRect.left() + (positionRect.right() - positionRect.left() )/2;

         //border of the square
         int x1= positionRect.left()+2;
         int y1 = positionRect.top()+2;
         int x2= positionRect.right()-2;
         int y2 = positionRect.bottom()-2;
         QPen pen1(QColor(79, 77, 84),4);
         painter->setPen(pen1);
         QRect border(QPoint(x1,y1),QPoint(x2,y2));
         painter->drawRect(border);

         //Drawing the gradient
         QRadialGradient radialGradient(xMid,yMid,150,xMid,yMid);
         radialGradient.setColorAt(0,QColor(79, 77, 84,100));
         radialGradient.setColorAt(1,QColor(79, 77, 84,220));
         QPen pen(Qt::NoPen);
         painter->setPen(pen);
         painter->fillRect(positionRect,radialGradient);

    }

    //Draw red square under the king if he's check
    if(m_boardPieces->isCheck(king)){
         positionRect = positionToRectangle(king.getPosition());

         //Center of the Gradient
         int yMid = positionRect.top() + (positionRect.bottom() - positionRect.top() )/2;
         int xMid = positionRect.left() + (positionRect.right() - positionRect.left() )/2;

         //border of the square
         int x1= positionRect.left()+2;
         int y1 = positionRect.top()+2;
         int x2= positionRect.right()-2;
         int y2 = positionRect.bottom()-2;
         QPen pen1(QColor(203, 65, 66),4);
         painter->setPen(pen1);
         QRect border(QPoint(x1,y1),QPoint(x2,y2));
         painter->drawRect(border);

         //Drawing the gradient
         QRadialGradient radialGradient(xMid,yMid,150,xMid,yMid);
         radialGradient.setColorAt(0,QColor(203, 65, 66,100));
         radialGradient.setColorAt(1,QColor(203, 65, 66,220));
         QPen pen(Qt::NoPen);
         painter->setPen(pen);
         painter->fillRect(positionRect,radialGradient);
    }


    for(int i=0;i<=63;i++){
        pieceType = board.at(i).getPieceType();
        pieceColor = board.at(i).getColor();
        positionRect = positionToRectangle(i+1);


        switch(pieceColor){
        case(WHITE):
            switch(pieceType){
            case(ROOK):
                painter->drawPixmap(positionRect,m_whiteRook,pieceSize);
                break;
            case(QUEEN):
                painter->drawPixmap(positionRect,m_whiteQueen,pieceSize);
                break;
            case(PAWN):
                painter->drawPixmap(positionRect,m_whitePawn,pieceSize);
                break;
            case(KNIGHT):
                painter->drawPixmap(positionRect,m_whiteKnight,pieceSize);
                break;
            case(KING):
                painter->drawPixmap(positionRect,m_whiteKing,pieceSize);
                break;
            case(BISHOP):
                painter->drawPixmap(positionRect,m_whiteBishop,pieceSize);
                break;
            case(NONE):
                break;

            }
        break;
        case(BLACK):
            switch(pieceType){
            case(ROOK):
                painter->drawPixmap(positionRect,m_blackRook,pieceSize);
                break;
            case(QUEEN):
                painter->drawPixmap(positionRect,m_blackQueen,pieceSize);
                break;
            case(PAWN):
                painter->drawPixmap(positionRect,m_blackPawn,pieceSize);
                break;
            case(KNIGHT):
                painter->drawPixmap(positionRect,m_blackKnight,pieceSize);
                break;
            case(KING):
                painter->drawPixmap(positionRect,m_blackKing,pieceSize);
                break;
            case(BISHOP):
                painter->drawPixmap(positionRect,m_blackBishop,pieceSize);
                break;
            case(NONE):
                break;

            }
        case(NOCOLOR):
            break;

        }


    }


    //Stop the painting
    painter->end();
    delete painter;

    //Use the painted pixmap as the Label Pixmap
    this->setPixmap(m_game);


}



bool PiecesLabel::getSelected(){
    return m_selected;
}



