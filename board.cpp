#include "board.h"
#include "piece.h"



Board::Board()
{
    //Setting black pieces on the board
    Piece bRook (1,BLACK,ROOK);
    Piece bKnight (2,BLACK,KNIGHT);
    Piece bBishop (3,BLACK,BISHOP);
    Piece bQueen (4,BLACK,QUEEN);
    Piece bKing (5,BLACK,KING);
    m_board.push_back(bRook);
    m_board.push_back(bKnight);
    m_board.push_back(bBishop);
    m_board.push_back(bQueen);
    m_board.push_back(bKing);
    bBishop.setPostion(6);
    bKnight.setPostion(7);
    bRook.setPostion(8);
    m_board.push_back(bBishop);
    m_board.push_back(bKnight);
    m_board.push_back(bRook);


    //Setting black pawns on the board
    for(int i=0; i<=7;i++){
        Piece bPawn (9+i,BLACK,PAWN);
       m_board.push_back(bPawn);
    }


    //Setting empty squares on the board
    for(int i=0; i<=31;i++){
        Piece empty(17+i,NOCOLOR,NONE);
        m_board.push_back(empty);
    }


    //Setting white pawns on the board
    for(int i=0; i<=7;i++){
        Piece wPawn (49+i,WHITE,PAWN);
        m_board.push_back(wPawn);
    }


    //Setting white pieces on the board
    Piece wRook (57,WHITE,ROOK);
    Piece wKnight (58,WHITE,KNIGHT);
    Piece wBishop (59,WHITE,BISHOP);
    Piece wQueen (60,WHITE,QUEEN);
    Piece wKing (61,WHITE,KING);
    m_board.push_back(wRook);
    m_board.push_back(wKnight);
    m_board.push_back(wBishop);
    m_board.push_back(wQueen);
    m_board.push_back(wKing);
    wBishop.setPostion(62);
    wKnight.setPostion(63);
    wRook.setPostion(64);
    m_board.push_back(wBishop);
    m_board.push_back(wKnight);
    m_board.push_back(wRook);

}

Piece Board::getPiece(int position){
    return this->m_board.at(position-1);
}


std::vector <Piece> Board::getBoard(){
    return this->m_board;
}


//Return true if the piece and the target are in the same line
bool Board::isInTheSameLine(Piece piece, Piece target){
        for(int i=0; i <= 56; i+= 8){
            if(piece.getPosition() >=1+i && (piece.getPosition() <=8+i ) && (target.getPosition() >=1+i) && (target.getPosition() <=8+i)){
                return true;
        }
    }
    return false;
}


//Return true if the piece and the target are in the same column
bool Board::isInTheSameColumn(Piece piece, Piece target){
    if(piece.getPosition() % 8 == target.getPosition() % 8){
        return true;
    }
    else{
        return false;
    }

}

//Return true if the piece and the target are in the same diagonal
bool Board::isInTheSameDiagonal(Piece piece, Piece target){
    if(piece.getPosition() % 9 == target.getPosition() % 9){
        return true;
    }
    if(piece.getPosition() % 7 == target.getPosition() % 7){
        return true;
    }

    return false;

}




//Return true if there are pieces between the piece and the target (for lines)
//USE ONLY IF THE PIECE AND THE TARGET ARE ON THE SAME LINE
bool Board::linePieceBetween(Piece piece, Piece target){
    int leftPiece, rightPiece,numberOfPieceBetween;
    numberOfPieceBetween=0;

    //Determines if the piece is on the left of the target or no
    if(piece.getPosition() < target.getPosition()){
        leftPiece = piece.getPosition();
        rightPiece = target.getPosition();
    }
    else{
        leftPiece = target.getPosition();
        rightPiece = piece.getPosition();
    }

    //Check if there are pieces between the piece and the target
    for(int i=leftPiece+1; i<rightPiece; i++){
        if(this->getPiece(i).getPieceType() != NONE){
            numberOfPieceBetween +=1;
        }
    }
    if(numberOfPieceBetween != 0){
        return true;
    }
    else{
        return false;
    }
}

//Return true if there are pieces between the piece and the target (for columns)
//USE ONLY IF THE PIECE AND THE TARGET ARE ON THE SAME COLUMN
bool Board::columnPieceBetween(Piece piece, Piece target){
    int upPiece, downPiece,numberOfPieceBetween;
    numberOfPieceBetween=0;

    //Determines if the piece is above the target or no
    if(piece.getPosition() < target.getPosition()){
        upPiece = piece.getPosition();
        downPiece = target.getPosition();
    }
    else{
        upPiece = target.getPosition();
        downPiece = piece.getPosition();
    }

    //Check if there are pieces between the piece and the target
    for(int i=upPiece+8; i<downPiece; i+=8){
        if(this->getPiece(i).getPieceType() != NONE){
            numberOfPieceBetween +=1;
        }
    }
    if(numberOfPieceBetween != 0){
        return true;
    }
    else{
        return false;
    }
}


//Return true if there are pieces between the piece and the target (for diagonals)
//USE ONLY IF THE PIECE AND THE TARGET ARE ON THE SAME diagonal
bool Board::diagonalPieceBetween(Piece piece, Piece target){
int numberOfPieceBetween =0;

    //First diagonal
    if(piece.getPosition() % 9 == target.getPosition() % 9){
        int upLeftPiece,downRightPiece;

        //Determines if the piece is on the left up diection of the target or no
        if(piece.getPosition() < target.getPosition()){
            upLeftPiece= piece.getPosition();
            downRightPiece=target.getPosition();

            //Check if there are pieces between the piece and the target
             for(int i=upLeftPiece+9; i<downRightPiece; i+=9){
                 if(this->getPiece(i).getPieceType() != NONE){
                     numberOfPieceBetween +=1;
                 }
             }
             if(numberOfPieceBetween !=0){
                 return true;
             }
        }
    }

    //Second diagonal
    else if(piece.getPosition() % 7 == target.getPosition() % 7){
        int upRightPiece,downLeftPiece;

        //Determines if the piece is on the right up diection of the target or no
        if(piece.getPosition() < target.getPosition()){
            upRightPiece= piece.getPosition();
            downLeftPiece=target.getPosition();

            //Check if there are pieces between the piece and the target
             for(int i=upRightPiece+7; i<downLeftPiece; i+=7){
                 if(this->getPiece(i).getPieceType() != NONE){
                     numberOfPieceBetween +=1;
                 }
             }
             if(numberOfPieceBetween !=0){
                 return true;
             }
        }
    }

    return false;
}



//Return true if the move is legal
bool Board::legalMove(Piece piece, Piece target){

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
        if((target.getPosition() - 1 == piece.getPosition() ) || target.getPosition() + 1 == piece.getPosition() || target.getPosition() + 8 == piece.getPosition() ||target.getPosition() - 8 == piece.getPosition() ){
            return true;
        }

    }

    //Moving a queen
    else if(piece.getPieceType() == QUEEN){
        if((isInTheSameDiagonal(piece, target)) && !(diagonalPieceBetween(piece, target))){
            return true;
    }
        else if((isInTheSameLine(piece, target)) && !(linePieceBetween(piece, target))){
                return true;
    }
        else if((isInTheSameColumn(piece, target)) && !(columnPieceBetween(piece, target))){
                return true;
    }

    }

    //Moving a knight
    else if(piece.getPieceType() == KNIGHT){
        if((target.getPosition() - 17 == piece.getPosition() ) || (target.getPosition() - 15 == piece.getPosition() )|| (target.getPosition() - 10 == piece.getPosition() ) || (target.getPosition() - 6 == piece.getPosition() ) || (target.getPosition() + 17 == piece.getPosition() ) || (target.getPosition() + 15 == piece.getPosition() )|| (target.getPosition() + 10 == piece.getPosition() ) || (target.getPosition() + 6 == piece.getPosition() ) ){
            return true;
        }

    }

    //Moving a bishop
    else if(piece.getPieceType() == BISHOP){
        if(isInTheSameDiagonal(piece, target) && !diagonalPieceBetween(piece, target)){
            return true;
        }

    }

    //Moving a rook
    else if(piece.getPieceType() == ROOK){

        //Moving vertically
        if(isInTheSameColumn(piece,target) && !columnPieceBetween(piece,target)){
            return true;

        }
        //Moving horizontally
        if(isInTheSameLine(piece,target) && !linePieceBetween(piece,target)){
            return true;
        }
    }


    //Moving a pawn
    else if(piece.getPieceType() == PAWN){

        //Moving a white pawn
        if(piece.getPieceColor() ==WHITE){
            if((piece.getPosition() == target.getPosition() +8) && (target.getPieceType() == NONE)){
                return true;
            }

            //Attacking with a white pawn
            if(( piece.getPosition() == target.getPosition() +7 ) || (piece.getPosition() == target.getPosition() +9)){
                if(target.getPieceType() != NONE){
                    return  true;
                }
            }

            //Pawns can skip 1 square if it's first time they move
            if((piece.getPosition() == 57) || (piece.getPosition() == 58) || (piece.getPosition() == 59) | (piece.getPosition() == 60) || (piece.getPosition() == 61) || (piece.getPosition() == 62) || (piece.getPosition() == 63) || (piece.getPosition() == 64)){
                if((piece.getPosition() == target.getPosition() + 16) && target.getPieceType() == NONE){
                     return true;
                }
            }
        }

        //Moving a black pawn
        else{
            if((piece.getPosition() == target.getPosition() -8) && (target.getPieceType() == NONE)){
                return true;
            }

            //Attacking with a black pawn
            if(( piece.getPosition() == target.getPosition() -7 ) || (piece.getPosition() == target.getPosition() -9)){
                if(target.getPieceType() != NONE ){
                    return true;
                }
            }

            //Pawns can skip 1 square if it's first time they move
            if((piece.getPosition() == 9) || (piece.getPosition() == 10) || (piece.getPosition() == 11) | (piece.getPosition() == 12) || (piece.getPosition() == 13) || (piece.getPosition() == 14) || (piece.getPosition() == 15) || (piece.getPosition() == 16)){
                if((piece.getPosition() == target.getPosition() - 16) && target.getPieceType() == NONE){
                     return true;
                }
            }

        }

    }

    return false;

}
