#include "mainwindow.h"
#include "piece.h"
#include "board.h"
#include <QApplication>
#include <iostream>
#include <QDesktopWidget>
#include "gamewindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Board board;

    // TEST TEST TEST TEST TEST TEST  
    // TEST TEST TEST TEST TEST TEST


    //Test of the promotion
    board.movePiece(board.getPiece(56),board.getPiece(40)); //W
    board.movePiece(board.getPiece(9),board.getPiece(25)); //B
    board.movePiece(board.getPiece(40),board.getPiece(32)); //W
    board.movePiece(board.getPiece(25),board.getPiece(33)); //B
    board.movePiece(board.getPiece(32),board.getPiece(24)); //W
    board.movePiece(board.getPiece(33),board.getPiece(41));//B
    board.movePiece(board.getPiece(24),board.getPiece(15)); //W
    board.movePiece(board.getPiece(41),board.getPiece(50));//B
    board.movePiece(board.getPiece(15),board.getPiece(8)); //W
    board.movePiece(board.getPiece(50),board.getPiece(57));//B



    //Checkmate in 4 moves for whites
    /*
    board.movePiece(board.getPiece(53),board.getPiece(45)); //W
    board.movePiece(board.getPiece(9),board.getPiece(17)); //B
    board.movePiece(board.getPiece(60),board.getPiece(32)); //W
    board.movePiece(board.getPiece(10),board.getPiece(18)); //B
    board.movePiece(board.getPiece(62),board.getPiece(44)); //W
    board.movePiece(board.getPiece(1),board.getPiece(9)); //B
    board.movePiece(board.getPiece(32),board.getPiece(14)); //W
    */

    //Castling right rook
    /*
    board.movePiece(board.getPiece(63),board.getPiece(48)); //W moving knight
    board.movePiece(board.getPiece(2),board.getPiece(17)); //B  Moving knight
    board.movePiece(board.getPiece(58),board.getPiece(41)); //W Moving knight
    board.movePiece(board.getPiece(7),board.getPiece(24)); //B Moving knight

    board.movePiece(board.getPiece(55),board.getPiece(47)); //W Moving pawn
    board.movePiece(board.getPiece(15),board.getPiece(23)); //B Moving pawn

    board.movePiece(board.getPiece(62),board.getPiece(55)); //W Moving bishop
    board.movePiece(board.getPiece(6),board.getPiece(15)); //B Moving bishop

    board.castling(board.getPiece(64)); //W castling
    board.castling(board.getPiece(8)); //B castling

   */
    //castling left rook
    /*

    board.movePiece(board.getPiece(50),board.getPiece(42)); //W Moving pawn
    board.movePiece(board.getPiece(10),board.getPiece(18)); //B Moving pawn
    board.movePiece(board.getPiece(52),board.getPiece(44)); //W Moving pawn
    board.movePiece(board.getPiece(12),board.getPiece(20)); //B Moving pawn


    board.movePiece(board.getPiece(60),board.getPiece(52)); //W Moving queen
    board.movePiece(board.getPiece(4),board.getPiece(12)); //B Moving queen

    board.movePiece(board.getPiece(59),board.getPiece(50)); //W Moving bishop
    board.movePiece(board.getPiece(3),board.getPiece(10)); //B Moving bishop


    board.movePiece(board.getPiece(61),board.getPiece(60)); //W Moving king
    board.movePiece(board.getPiece(5),board.getPiece(4)); //B Moving king
    board.movePiece(board.getPiece(60),board.getPiece(61)); //W Moving king
    board.movePiece(board.getPiece(4),board.getPiece(5)); //B Moving king


    board.castling(board.getPiece(1)); //W castling
    board.castling(board.getPiece(57)); //B castling

*/

/*
    //Verifying checks/checkmates
    if(board.isCheckMate()){
        std::cout<<"Checkmate"<<std::endl;
    }
    if(board.isCheck(board.findBlackKing())){
        std::cout<<"Black king is check"<<std::endl;
    }
    if(board.isCheck(board.findWhiteKing())){
        std::cout<<"white king is check"<<std::endl;
    }
*/




    board.showBoard();


    GameWindow gameWindow;
    gameWindow.show();





// MainWindow w;
 // w.show();

    return a.exec();
    return 0;
}
