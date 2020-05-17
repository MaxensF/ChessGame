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

     // Set size of the window
    setWidht(width);
    setHeight(height);
    setFixedSize(getWidth(), getHeight());



    //Put the Board at the center of the window
    m_piecesLabel = new PiecesLabel(board,this);
    QVBoxLayout *vLayout = new QVBoxLayout;
    QHBoxLayout *hLayout = new QHBoxLayout;
    vLayout->addWidget(m_piecesLabel,0,Qt::AlignHCenter);
    hLayout->addWidget(m_piecesLabel,0,Qt::AlignHCenter);



    this->setLayout(vLayout);








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

