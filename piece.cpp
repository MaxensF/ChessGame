#include "piece.h"
#include <board.h>
#include <string>

Piece::Piece(int Position, pieceColor color,pieceType pieceType)
{
    m_color = color;
    m_position = Position;
    m_pieceType = pieceType;
}



void Piece::setPosition(int position){
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










