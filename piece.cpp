#include "piece.h"
#include <string>

Piece::Piece(int Position, pieceColor color,pieceType pieceType)
{
    m_color = color;
    m_position = Position;
    m_pieceType = pieceType;
}



void Piece::setPostion(int position){
    this->m_position = position;
}



int Piece::getPosition(){
    return this->m_position;
}



pieceType Piece::getPieceType(){
    return this->m_pieceType;
}


void Piece::setPieceType(pieceType pieceType){
    this->m_pieceType = pieceType;
}


pieceColor Piece::getPieceColor(){
    return this->m_color;
}


void Piece::setPieceColor(pieceColor color){
    this->m_color = color;
}




bool Piece ::isCheck(Piece king){
return false
}


bool Piece::legalMove(Piece piece, Piece target){

    //Can't move on a piece of the same color
    if (piece.getPieceColor() == target.getPieceColor()){
        return false;
    }

    //Can't move on a king
    if (target.getPieceType() == KING){
        return false;
    }

    //Moving a king
    if(piece.getPieceType() == KING){

    }

    //Moving a queen
    else if(piece.getPieceType() == QUEEN){

    }

    //Moving a knight
    else if(piece.getPieceType() == KNIGHT){

    }

    //Moving a bishop
    else if(piece.getPieceType() == BISHOP){

    }

    //Moving a Rook
    else if(piece.getPieceType() == ROOK){

    }

    //Moving a pawn
    else if(piece.getPieceType() == PAWN){

    }

    return true;

}
