#include "piece.h"
#include <board.h>
#include <string>

Piece::Piece(int Position, color color,pieceType pieceType)
{
    m_color = color;
    m_position = Position;
    m_pieceType = pieceType;
    m_hasMoved = false;
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


color Piece::getColor(){
    return this->m_color;
}


void Piece::setColor(color color){
    this->m_color = color;
}


void Piece::setHasMoved(bool hasMoved){
    m_hasMoved = hasMoved;
}



bool Piece::getHasMoved(){
    return m_hasMoved;
}










