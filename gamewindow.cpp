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

    //Layout which center the board + numbers and letters
    QGridLayout *finalLayout = new QGridLayout;

    //Put the Board at the center of the window
    m_piecesLabel = new PiecesLabel(board,this);
    QGridLayout *Layout = new QGridLayout;
    Layout->addWidget(m_piecesLabel,0,1);


    //Letters below the board
    int lettersBoardWidth = (height/10)*9;
    int lettersBoardHeight =((height/100)*9);
    QLabel *lettersBoard = new QLabel(this);
    lettersBoard->setFixedSize(lettersBoardWidth,lettersBoardHeight);
    QPixmap letters;
    letters.load("://Board/boardLetters.png");
    letters = letters.scaled(lettersBoardWidth,lettersBoardHeight,Qt::KeepAspectRatio, Qt::SmoothTransformation);
    lettersBoard->setPixmap(letters);
    Layout->addWidget(lettersBoard,1,1,Qt::AlignTop);


    //Numbers on the right of the board
    int numbersBoardWidth = (height/120)*9;
    int numbersBoardHeight = (height/10)*9;
    QLabel *NumbersBoard = new QLabel(this);
    NumbersBoard->setFixedSize(numbersBoardWidth,numbersBoardHeight);
    QPixmap numbers;
    numbers.load("://Board/boardNumbers.png");
    numbers = numbers.scaled(numbersBoardWidth,numbersBoardHeight,Qt::KeepAspectRatio, Qt::SmoothTransformation);
    NumbersBoard->setPixmap(numbers);
    Layout->addWidget(NumbersBoard,0,0,Qt::AlignRight);

    finalLayout->addLayout(Layout,0,0,Qt::AlignCenter);

    this->setLayout(finalLayout);

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
