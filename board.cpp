#include "board.h"
#include "piece.h"
#include "empty.h"
#include "queen.h"
#include "king.h"


Board::Board()
{
    //Setting black pieces on the board
    Piece bRook (0,BLACK,ROOK);
    Piece bKnight (1,BLACK,KNIGHT);
    Piece bBishop (2,BLACK,BISHOP);
    Piece bQueen (3,BLACK,QUEEN);
    Piece bKing (4,BLACK,KING);
    m_board.push_back(bRook);
    m_board.push_back(bKnight);
    m_board.push_back(bBishop);
    m_board.push_back(bQueen);
    m_board.push_back(bKing);
    bBishop.setPostion(5);
    bKnight.setPostion(6);
    bRook.setPostion(7);
    m_board.push_back(bBishop);
    m_board.push_back(bKnight);
    m_board.push_back(bRook);


    //Setting black pawns on the board
    for(int i=0; i<=7;i++){
        Piece bPawn (8+i,BLACK,PAWN);
       m_board.push_back(bPawn);
    }


    //Setting empty cases on the board
    for(int i=0; i<=31;i++){
        Piece empty(16+i,NOCOLOR,NONE);
        m_board.push_back(empty);
    }


    //Setting white pawns on the board
    for(int i=0; i<=7;i++){
        Piece wPawn (48+i,WHITE,PAWN);
        m_board.push_back(wPawn);
    }


     //Setting white pieces on the board
    Piece wRook (56,BLACK,ROOK);
    Piece wKnight (57,BLACK,KNIGHT);
    Piece wBishop (58,BLACK,BISHOP);
    Piece wQueen (59,BLACK,QUEEN);
    Piece wKing (60,BLACK,KING);
    m_board.push_back(wRook);
    m_board.push_back(wKnight);
    m_board.push_back(wBishop);
    m_board.push_back(wQueen);
    m_board.push_back(wKing);
    wBishop.setPostion(61);
    wKnight.setPostion(62);
    wRook.setPostion(63);
    m_board.push_back(wBishop);
    m_board.push_back(wKnight);
    m_board.push_back(wRook);


}

