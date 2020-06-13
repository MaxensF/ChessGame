#include "gamewindow.h"
#include "pieceslabel.h"
#include "pieceslabel.h"
#include <QWidget>
#include <QLabel>
#include <QApplication>
#include <QStyle>
#include <iostream>
#include <QCheckBox>
#include <QDesktopWidget>
#include <QLayout>
#include <QMouseEvent>

GameWindow::GameWindow(Board *board, QWidget *parent) :
 QWidget(parent)
 {


    //Getting srceen informations
     const int width = ((QApplication::desktop()->width())/6)*5;
     const int height = ((QApplication::desktop()->height())/6)*5;

     // Set the size attributes for things in the window
    setWidht(width);
    setHeight(height);



    //Put the Board at the center of the window
    m_piecesLabel = new PiecesLabel(board,this);
    QGridLayout *Layout = new QGridLayout;
    Layout->addWidget(m_piecesLabel,0,Qt::AlignCenter);



    this->setLayout(Layout);

    //Center the window
    int x = (QApplication::desktop()->width()/2) -(width/4);
    int y = (QApplication::desktop()->height()/2) - (height/2);
    this->move(x,y);

    //Set the window icon
    this->setWindowIcon(QIcon("://Pieces/BlackKnight.png"));


}






int GameWindow::getWidth(){
    return m_width;
}




int GameWindow::getHeight(){
    return m_height;
}




void GameWindow::setWidht(int width){
    m_width = width;
}





void GameWindow::setHeight(int height){
    m_height = height;
}



PiecesLabel *GameWindow::getPieceLabel(){
    return m_piecesLabel;
}














