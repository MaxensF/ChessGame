#include "board.h"
#include <iostream>
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
    bBishop.setPosition(6);
    bKnight.setPosition(7);
    bRook.setPosition(8);
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
    wBishop.setPosition(62);
    wKnight.setPosition(63);
    wRook.setPosition(64);
    m_board.push_back(wBishop);
    m_board.push_back(wKnight);
    m_board.push_back(wRook);

    m_moveNumber=0;

}




int Board::getMoveNumber(){
    return m_moveNumber;
}








Piece Board::getPiece(int position){
    position -=1;
    return this->m_board.at(position);
}









std::vector <Piece> Board::getBoard(){
    return this->m_board;
}










//Return true if the piece and the target are in the same line
bool Board::isInTheSameLine(Piece piece, Piece target){
        for(int i=0; i <= 56; i+= 8){
            if(((piece.getPosition() >=1+i) && (piece.getPosition() <=8+i)) && ((target.getPosition() >=1+i) && (target.getPosition() <=8+i))){
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
    int abovePiece, belowPiece;

    if(piece.getPosition() < target.getPosition()){
        abovePiece = piece.getPosition();
        belowPiece = target.getPosition();
    }
    else{
        abovePiece = target.getPosition();
        belowPiece = piece.getPosition();
    }


    //diagonals from up left corner to down right corner
    if(abovePiece % 9 == belowPiece % 9){

        int i;
        i=abovePiece;
        while((i != 8) && (i != 16) && (i != 24) && ( i != 32) && ( i != 40) && ( i != 48) && ( i != 56) && ( i < 57 )){
            i=i+9;
            if(belowPiece == i){

                return true;
            }
        }


    }

    //diagonals from up right corner to down left corner
    if(abovePiece % 7 == belowPiece % 7){
        int i;
        i=abovePiece;
        while((i != 1) && (i != 9) && (i != 17) && ( i != 25) && ( i != 33) && ( i != 41) && ( i != 49) && ( i < 57  )){
            i=i+7;
            if(belowPiece == i){

                return true;
            }
        }
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


    //diagonal from the top left corner to the right bottom corner
    if(piece.getPosition() % 9 == target.getPosition() % 9){
        int upLeftPiece,downRightPiece;

        //Determines if the piece is on the left up diection of the target or no
        if(piece.getPosition() < target.getPosition()){
            upLeftPiece= piece.getPosition();
            downRightPiece=target.getPosition();
        }
        else{
            upLeftPiece= target.getPosition();
            downRightPiece= piece.getPosition();
        }

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

    //diagonal from the top right corner to the left bottom corner
    else if(piece.getPosition() % 7 == target.getPosition() % 7){
        int upRightPiece,downLeftPiece;

        //Determines if the piece is on the right up diection of the target or no
        if(piece.getPosition() < target.getPosition()){
            upRightPiece= piece.getPosition();
            downLeftPiece=target.getPosition();
        }
        else{
            upRightPiece= target.getPosition();
            downLeftPiece= piece.getPosition();

         }

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
    return false;
}












//Return true if the move is legal
bool Board::legalMove(Piece piece, Piece target){

    //Can't move on a piece of the same color
    if (piece.getPieceColor() == target.getPieceColor()){
        return false;
    }
    switch(piece.getPieceType()){


        //Moving a king
        case(KING):
            if((target.getPosition() - 1 == piece.getPosition() ) || (target.getPosition() + 1 == piece.getPosition()) || (target.getPosition() + 8 == piece.getPosition()) || (target.getPosition() - 8 == piece.getPosition()) || (target.getPosition() - 9 == piece.getPosition()) || (target.getPosition() + 9 == piece.getPosition()) || (target.getPosition() - 7 == piece.getPosition()) || (target.getPosition() + 7 == piece.getPosition()) ){
                return true;
            }
            return false;


        //Moving a queen
        case(QUEEN):
            if((isInTheSameDiagonal(piece, target)) && !(diagonalPieceBetween(piece, target))){
                return true;
             }
             else if((isInTheSameLine(piece, target)) && !(linePieceBetween(piece, target))){
                return true;
              }
             else if((isInTheSameColumn(piece, target)) && !(columnPieceBetween(piece, target))){
                return true;
              }
            return false;


        //Moving a knight
        case(KNIGHT):
            if((target.getPosition() - 17 == piece.getPosition() ) || (target.getPosition() - 15 == piece.getPosition() )|| (target.getPosition() - 10 == piece.getPosition() ) || (target.getPosition() - 6 == piece.getPosition() ) || (target.getPosition() + 17 == piece.getPosition() ) || (target.getPosition() + 15 == piece.getPosition() )|| (target.getPosition() + 10 == piece.getPosition() ) || (target.getPosition() + 6 == piece.getPosition() ) ){
                return true;
             }
             return false;


        //Moving a bishop
        case(BISHOP):
           if(isInTheSameDiagonal(piece, target) && (!diagonalPieceBetween(piece, target))){

               return true;
           }
             return false;


        //Moving a rook
        case(ROOK):
            //Moving vertically
            if(isInTheSameColumn(piece,target) && !columnPieceBetween(piece,target)){
                return true;

            }
            //Moving horizontally
            if(isInTheSameLine(piece,target) && !linePieceBetween(piece,target)){
                return true;
            }

             return false;
        //Moving a pawn
        case(PAWN):
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
                if((piece.getPosition() >= 57) && (piece.getPosition() <= 64)){
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
                if((piece.getPosition() >= 9) && (piece.getPosition() <= 16)){
                    if((piece.getPosition() == target.getPosition() - 16) && target.getPieceType() == NONE){
                         return true;
                    }
                }

            }
            return false;


        //Can't move an empty square
        case(NONE):
            return false;
    }

    return false;

}





// Return true if the player will check himself
bool Board::willBeCheck(Piece piece, Piece target){



    //copying the board as a save because it will do the move on the board and
    //then verify if the king is check.
    std::vector <Piece> board = this->getBoard();
    int numberOfPieceChecking = 0;

    //Moving a black piece
    if(piece.getPieceColor() == BLACK){
        movePieceAnyway(piece, target);
        Piece blackKing = findBlackKing();

        //Verify if the king is now check

         if(isCheck(blackKing)){
              numberOfPieceChecking +=1;

        }

    }

    //Moving a white piece
    if(piece.getPieceColor() == WHITE){
        movePieceAnyway(piece,target);
        Piece whiteKing = findWhiteKing();

        //Verify if the king is now check
        if(isCheck(whiteKing)){
             numberOfPieceChecking +=1;

       }
    }
    //Cancelling the move
    m_board = board;
    if(numberOfPieceChecking !=0){
        return true;
    }
    else{
       return false;
    }
}






//Return true if the king is check
bool Board::isCheck(Piece king){
    for(int i=1 ; i<=64; i++){
        if(this->getPiece(i).getPieceColor() != king.getPieceColor()){
            if(legalMove(this->getPiece(i), king)){

            return true;
             }

        }

    }
    return false;
}







void Board::AddNotAlivePiece(Piece piece){
    this->m_notAlive.push_back(piece);
}








std::vector<Piece> Board::getNotAlivePiece(){
    return this->m_notAlive;
}







//Move the piece on the targeted square
//Return true if the move has been done successfully
bool Board::movePiece(Piece piece, Piece target){
    if(legalMove(piece, target) && !willBeCheck(piece, target) && (target.getPieceType() != KING)){

        //Add the piece which was on the target square in the vector of dead pieces
        if(target.getPieceType() != NONE){
            AddNotAlivePiece(target);
        }

        Piece empty(piece.getPosition(),NOCOLOR,NONE);
        int targetPosition,piecePosition;
        targetPosition=target.getPosition()-1;
        piecePosition= piece.getPosition()-1;

        //Change the attribute "position" of the piece by the position of the target square
        piece.setPosition(target.getPosition());

        //Replace the target square by the piece
        this->m_board.at(targetPosition) = piece;

        //Replace the square where the piece was by an empty square
        this->m_board.at(piecePosition) = empty;

        m_moveNumber +=1;

        return true;

    }
    return false;
}







//Move a piece even if the player check himself
void Board::movePieceAnyway(Piece piece, Piece target){
    if(legalMove(piece, target)){

        Piece empty(piece.getPosition(),NOCOLOR,NONE);

        int targetPosition,piecePosition;
        targetPosition=target.getPosition()-1;
        piecePosition= piece.getPosition()-1;

        //Change the attribute "position" of the piece by the position of the target square
        piece.setPosition(target.getPosition());

        //Replace the target square by the piece
        this->m_board.at(targetPosition) = piece;

        //Replace the square where the piece was by an empty square
        this->m_board.at(piecePosition) = empty;

    }

}








//Return the black king piece
Piece Board::findBlackKing(){
    Piece empty(1,NOCOLOR,NONE);

    for(int i=1;i<=64;i++){
        if((this->getPiece(i).getPieceType() == KING) && (this->getPiece(i).getPieceColor() == BLACK)){
            return this->getPiece(i);
        }
    }

    //Never return empty, just for avoid a warning
    return empty;
}





//Return the white king piece
Piece Board::findWhiteKing(){
    Piece empty(1,NOCOLOR,NONE);

    for(int i=1;i<=64;i++){
        if((this->getPiece(i).getPieceType() == KING) && (this->getPiece(i).getPieceColor() == WHITE)){
            return this->getPiece(i);
        }
    }

    //Never return empty, just for avoid a warning
    return empty;
}


//Display the board on the console
void Board::showBoard(){
    int line = 0;
    for(int i=1; i<=64; i++){
        switch(this->getPiece(i).getPieceType()){
            case(PAWN):
            std::cout<<" P  ";
            break;
        case(ROOK):
            std::cout<<" R  ";
            break;
        case(KING):
            std::cout<<" K  ";
            break;
        case(QUEEN):
            std::cout<<" Q  ";
            break;
        case(KNIGHT):
            std::cout<<" KT ";
            break;
        case(NONE):
            std::cout<<" ** ";
            break;
        case(BISHOP):
            std::cout<<" B  ";
            break;
        }

        line+=1;

        if(line %8 == 0){
            std::cout<<std::endl;


        }

    }
}
