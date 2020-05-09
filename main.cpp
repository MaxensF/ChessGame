#include "mainwindow.h"
#include "piece.h"
#include "board.h"
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    Board board;

    // TEST TEST TEST TEST TEST TEST
    board.movePiece(board.getPiece(9),board.getPiece(17));
    board.movePiece(board.getPiece(12),board.getPiece(20));
    board.movePiece(board.getPiece(53),board.getPiece(45));
    board.movePiece(board.getPiece(5),board.getPiece(12));
    board.movePiece(board.getPiece(62),board.getPiece(26));
    board.movePiece(board.getPiece(11),board.getPiece(19));
     board.movePiece(board.getPiece(19),board.getPiece(26));


    board.showBoard();

     // TEST TEST TEST TEST TEST TEST




    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
