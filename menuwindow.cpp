#include "menuwindow.h"
#include <QDesktopWidget>
#include <QApplication>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include "board.h"
#include "gamewindow.h"
#include <QStackedLayout>
#include <qwidget.h>

MenuWindow::MenuWindow(QWidget *parent) : QWidget(parent)
{

    this->setWindowIcon(QIcon("://Pieces/BlackKnight.png"));
    this->minimumSize();

    QLabel *text = new QLabel;
    text->setText("ChessGame, the future of videogames");


    QPushButton *quit = new QPushButton ("Quit",this);
    QPushButton *newGame = new QPushButton ("New Game",this);

    QGridLayout *layout = new QGridLayout;

    layout->addWidget(text,0,0,1,0,Qt::AlignHCenter);
    layout->addWidget(quit,1,1);
    layout->addWidget(newGame,1,0);

    this->setLayout(layout);


    //Connect buttons to actions
    connect(newGame,SIGNAL(clicked()),this,SLOT(newGame()));
    connect(newGame,SIGNAL(clicked()),this,SLOT(close()));
    connect(quit,SIGNAL(clicked()),this,SLOT(close()));

    //Center the window
    int x = (QApplication::desktop()->width()/2) -(this->width()/4);
    int y = (QApplication::desktop()->height()/2) - (this->height()/4);
    this->move(x,y);

}

void MenuWindow::newGame(){
    Board *board = new Board;
    GameWindow *gameWindow = new GameWindow(board);
    gameWindow->show();
}
