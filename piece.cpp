#include "piece.h"
#include <board.h>
#include <string>

Piece::Piece(int Position, color color,pieceType pieceType)
{
    m_color = color;
    m_position = Position;
    m_pieceType = pieceType;
    m_hasMoved = false;
    m_moveNumber = 0;
    m_lastMoveNumber =-2;
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

int Piece::getMoveNumber(){
    return m_moveNumber;
}

int Piece::getLastMoveNumber(){
    return m_lastMoveNumber;
}



void Piece::setLastMoveNumber(int lastMoveNumber){
    m_lastMoveNumber = lastMoveNumber;
}


void Piece::setMoveNumber(int moveNumber){
    m_moveNumber = moveNumber;
}




