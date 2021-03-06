#include "board.h"
#include <iostream>
#include "piece.h"
#include <QApplication>



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

    //Whites always start
    m_turn = WHITE;

    //Nobody has castled
    m_whiteCastled = false;
    m_blackCastled = false;

    //No pawns to promote
    m_waitingForPromotion = false;
    m_promotionColor =NOCOLOR;

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
    if (piece.getColor() == target.getColor()){
        return false;
    }
    switch(piece.getPieceType()){


        //Moving a king
        case(KING):
            if((target.getPosition() - 1 == piece.getPosition() ) || (target.getPosition() + 1 == piece.getPosition()) || (target.getPosition() + 8 == piece.getPosition()) || (target.getPosition() - 8 == piece.getPosition()) || (target.getPosition() - 9 == piece.getPosition()) || (target.getPosition() + 9 == piece.getPosition()) || (target.getPosition() - 7 == piece.getPosition()) || (target.getPosition() + 7 == piece.getPosition()) ){

                //Avoid king from crossing the entire baord with just one move
                if(!(((piece.getPosition()%8 == 0) && (target.getPosition()%8 == 1)) || ((piece.getPosition()%8 == 1) && (target.getPosition()%8 == 0)))){
                    return true;
                }     
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

                //Avoid knight from crossing the entire baord with just one move
                if(!(((piece.getPosition()%8 == 0) && (target.getPosition()%8 == 1)) || ((piece.getPosition()%8 == 1) && (target.getPosition()%8 == 0)) || ((piece.getPosition()%8 == 0) && (target.getPosition()%8 == 2)) || ((piece.getPosition()%8 == 1) && (target.getPosition()%8 == 7)) || ((piece.getPosition()%8 == 2) && (target.getPosition()%8 == 0)) || ((piece.getPosition()%8 == 7) && (target.getPosition()%8 == 1)))){
                    return true;
                }
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
            if(piece.getColor() ==WHITE){
                if((piece.getPosition() == target.getPosition() +8) && (target.getPieceType() == NONE)){
                    return true;
                }

                //Attacking with a white pawn
                if(( piece.getPosition() == target.getPosition() +7 ) || (piece.getPosition() == target.getPosition() +9)){

                    //Avoid pawn from crossing the entire baord with just one move
                    if(!(((piece.getPosition()%8 == 0) && (target.getPosition()%8 == 1)) || ((piece.getPosition()%8 == 1) && (target.getPosition()%8 == 0)) )){

                        if(target.getPieceType() != NONE){
                             return  true;
                        }
                        if(possibleEnPassant(piece,target) && (target.getPieceType() == NONE)){
                            return true;
                        }
                    }
                }

                //Pawns can skip 1 square if it's first time they move and there is no piece
                //between them and the targeted square
                if((piece.getPosition() >= 49) && (piece.getPosition() <= 56) && (!columnPieceBetween(piece, target))){
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

                    //Avoid pawn from crossing the entire baord with just one move
                    if(!(((piece.getPosition()%8 == 0) && (target.getPosition()%8 == 1)) || ((piece.getPosition()%8 == 1) && (target.getPosition()%8 == 0)) )){

                        if(target.getPieceType() != NONE){
                             return  true;
                        }
                        if(possibleEnPassant(piece,target) && (target.getPieceType() == NONE)){
                            return true;
                        }
                    }
                }

                //Pawns can skip 1 square if it's first time they move and there is no piece
                //between them and the targeted square
                if((piece.getPosition() >= 9) && (piece.getPosition() <= 16) && (!columnPieceBetween(piece, target))){
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
    if(piece.getColor() == BLACK){
        movePieceAnyway(piece, target);
        Piece blackKing = findBlackKing();

        //Verify if the king is now check

         if(isCheck(blackKing)){
              numberOfPieceChecking +=1;

        }
    }

    //Moving a white piece
    if(piece.getColor() == WHITE){
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
        if(this->getPiece(i).getColor() != king.getColor()){
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

    //Castling
    if((piece.getPieceType() == KING) && (m_turn == piece.getColor())){

        //Castling white king
        if(m_turn == WHITE){
            std::vector <Piece> whiteRooks = findWhiteRooks();
            int whiteRooksNumber = whiteRooks.size();

            //Small castling
            if((target.getPosition() == 63)){
                for(int i=0; i< whiteRooksNumber; i++){

                   //Choose the rook
                    if(whiteRooks.at(i).getPosition() == 64){
                        if(castling(whiteRooks.at(i))){
                            m_moveNumber +=1;
                            return true;
                        }
                    }
                }
            }
            //Big castling
            if((target.getPosition() == 59)){
                for(int i=0; i< whiteRooksNumber; i++){

                    //Choose the rook
                    if(whiteRooks.at(i).getPosition() == 57){
                        if(castling(whiteRooks.at(i))){
                            m_moveNumber +=1;
                            return true;
                        }
                    }
                }
            }

        }
        if(m_turn == BLACK){
            std::vector <Piece> blackRooks = findBlackRooks();
            int blackRooksNumber = blackRooks.size();

            //Small castling
            if((target.getPosition() == 7)){
                for(int i=0; i< blackRooksNumber; i++){

                   //Choose the rook
                    if(blackRooks.at(i).getPosition() == 8){
                        if(castling(blackRooks.at(i))){
                            m_moveNumber +=1;
                            return true;
                        }
                    }
                }
            }

            //Big castling
            if((target.getPosition() == 3)){
                for(int i=0; i< blackRooksNumber; i++){

                   //Choose the rook
                    if(blackRooks.at(i).getPosition() == 1){
                        if(castling(blackRooks.at(i))){
                            m_moveNumber +=1;
                            return true;
                        }
                    }
                }
            }
        }
    }

    //Normal move
    if(legalMove(piece, target) && !willBeCheck(piece, target) && (target.getPieceType() != KING) && (m_turn == piece.getColor())){
        Piece copiePiece = piece;
        Piece copieTarget =target;

        enPassant(copiePiece,copieTarget);

        //Used for en passant
        int moveNumber = piece.getMoveNumber();
        moveNumber++;
        piece.setMoveNumber(moveNumber);
        piece.setLastMoveNumber(m_moveNumber);

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

        //Indicate that the piece has move at least one time.
        //Used for castling
        this->m_board.at(targetPosition).setHasMoved(true);


        //If a pawn arrive at the end of the board
        //the pawn is promoted to a queen/rook/knight/bishop
        if((piece.getPieceType() == PAWN)){
            switch(piece.getColor()){
                case(BLACK):
                    if((piece.getPosition() >=57) && (piece.getPosition() <=64)){

                        m_waitingForPromotion = true;
                        m_promotionColor = BLACK;
                        m_promotedPawn = piece;
                    }
                    break;
                case(WHITE):
                    if((piece.getPosition() >= 1) && (piece.getPosition() <= 8 )){

                        m_waitingForPromotion = true;
                        m_promotionColor = WHITE;
                        m_promotedPawn = piece;
                     }
                    break;
            case(NOCOLOR):
                    break;

            }
        }


        //Change turn
        switch(m_turn){
         case(WHITE):
            m_turn =BLACK;
            break;
         case(BLACK):
            m_turn =WHITE;
            break;
        case(NOCOLOR):
            break;

        }

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
        if((this->getPiece(i).getPieceType() == KING) && (this->getPiece(i).getColor() == BLACK)){
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
        if((this->getPiece(i).getPieceType() == KING) && (this->getPiece(i).getColor() == WHITE)){
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






//Return true if it's your turn and your king is checkmate
//Will be used every turn
bool Board::isCheckMate(){


    //Black's turn
    if(m_turn ==BLACK){
        Piece blackKing = findBlackKing();

        //You have to be check to be checkmate
        if(isCheck(blackKing)){
            int numberOfCheck =0;
            int numberOfPossibleCheck =0;

            //Finding all black pieces
            for(int i=1;i<=64;i++){
                if(getPiece(i).getColor() == BLACK){

                    //Looking all legal moves for every black pieces
                    for(int j=1;j<=64;j++){
                        if((legalMove(getPiece(i),getPiece(j))) && (getPiece(j).getPieceType() != KING)){
                            numberOfPossibleCheck +=1;

                            //Testing for every legal moves of every black pieces
                            // if you will be check
                            if(willBeCheck(getPiece(i),getPiece(j))){

                                numberOfCheck +=1;
                            }
                        }
                    }
                }
            }
            if(numberOfCheck == numberOfPossibleCheck){
                return true;
            }
        }
    }

    //White's turn
    if(m_turn ==WHITE){
        Piece whiteKing = findWhiteKing();

        //You have to be check to be checkmate
        if(isCheck(whiteKing)){
            int numberOfCheck =0;
            int numberOfPossibleCheck =0;

            //Finding all white pieces
            for(int i=1;i<=64;i++){
                if(getPiece(i).getColor() == WHITE){

                    //Looking all legal moves for every white pieces
                    for(int j=1;j<=64;j++){
                        if((legalMove(getPiece(i),getPiece(j))) && (getPiece(j).getPieceType() != KING)){
                            numberOfPossibleCheck +=1;

                            //Testing for every legal moves of every white pieces
                            // if you will be check
                            if(willBeCheck(getPiece(i),getPiece(j))){

                                numberOfCheck +=1;
                            }
                        }
                    }
                }
            }
            if(numberOfCheck == numberOfPossibleCheck){
                return true;
            }
        }
    }

    return false;
}

bool Board::movePieceCastling(Piece rook, Piece king, Piece rookTarget, Piece kingTarget){

    //Moving the rook
    Piece empty(rook.getPosition(),NOCOLOR,NONE);

    int rookTargetPosition,rookPosition;
    rookTargetPosition = rookTarget.getPosition()-1;
    rookPosition = rook.getPosition()-1;

    //Change the attribute "position" of the rook by the position of the targeted square
    rook.setPosition(rookTarget.getPosition());

    //Replace the targeted square by the rook
    this->m_board.at(rookTargetPosition) = rook;

    //Replace the square where the rook was by an empty square
    this->m_board.at(rookPosition) = empty;



    //Moving the king

    empty.setPosition(king.getPosition());

    int kingTargetPosition,kingPosition;
    kingTargetPosition = kingTarget.getPosition()-1;
    kingPosition = king.getPosition()-1;

    //Change the attribute "position" of the king by the position of the targeted square
    king.setPosition(kingTarget.getPosition());

    //Replace the targeted square by the king
    this->m_board.at(kingTargetPosition) = king;

    //Replace the square where the king was by an empty square
    this->m_board.at(kingPosition) = empty;




    //Change turn
    switch(m_turn){
     case(WHITE):
        m_turn =BLACK;
        break;
     case(BLACK):
        m_turn =WHITE;
        break;
    case(NOCOLOR):
        break;

    }


    return true;
}



//Castle if it's possible
bool Board::castling(Piece rook){
    Piece whiteKing = findWhiteKing();
    Piece blackKing = findBlackKing();
    //Ability for whites to castle
    if((rook.getColor() == WHITE) && (m_whiteCastled == false) && (!isCheck(whiteKing)) && (whiteKing.getHasMoved() == false) && (rook.getHasMoved() == false)){

        //Castling with the right rook (squares between the rook and the king have to be empty)
        if((rook.getPosition() == 64) && (this->getPiece(63).getPieceType() == NONE) && (this->getPiece(62).getPieceType() == NONE) && (!willBeCheck(whiteKing, this->getPiece(63)))){
            movePieceCastling(rook, whiteKing,this->getPiece(62),this->getPiece(63) );
            //Whites have castled
            m_whiteCastled =true;
            return true;

        }

        //Castling with the left rook (squares between the rook and the king have to be empty)
        if((rook.getPosition() == 57) && (this->getPiece(59).getPieceType() == NONE) && (this->getPiece(60).getPieceType() == NONE) && (!willBeCheck(whiteKing, this->getPiece(59)))){
            movePieceCastling(rook, whiteKing,this->getPiece(60),this->getPiece(59) );
            //Whites have castled
            m_whiteCastled =true;
            return true;

        }
    }

    //Ability for blacks to castle
    if((rook.getColor() == BLACK) && (m_blackCastled == false) && (!isCheck(blackKing)) && (blackKing.getHasMoved() == false) && (rook.getHasMoved() == false)){

        //Castling with the right rook (squares between the rook and the king have to be empty)
        if((rook.getPosition() == 8) && (this->getPiece(7).getPieceType() == NONE) && (this->getPiece(6).getPieceType() == NONE) && (!willBeCheck(blackKing, this->getPiece(7)))){
            movePieceCastling(rook, blackKing,this->getPiece(6),this->getPiece(7) );
            //Blacks have castled
            m_blackCastled =true;
            return true;

        }

        //Castling with the left rook (squares between the rook and the king have to be empty)
        if((rook.getPosition() == 1) && (this->getPiece(3).getPieceType() == NONE) && (this->getPiece(4).getPieceType() == NONE) && (!willBeCheck(blackKing, this->getPiece(3)))){
            movePieceCastling(rook, blackKing,this->getPiece(4),this->getPiece(3) );
            //Blacks have castled
             m_blackCastled =true;
            return true;

        }
    }
    return false;
}








//Return true if it's your turn and you can't move a piece without being check
//Will be used every turn
bool Board::isDraw(){

    //If there are 30 pieces dead, it's a king vs king
    //which is impossible to finish
    int notAlivePiece = this->getNotAlivePiece().size();
    if(notAlivePiece == 30){
        return true;
    }

    //only 2 kings + 1  piece left
    if(notAlivePiece == 29){
        for(int i=1; i<=64;i++){
            //it's a (king + bishop) vs king  or (king + knight) vs king.
            //Impossible to win
            if((this->getPiece(i).getPieceType() == BISHOP) || (this->getPiece(i).getPieceType() == KNIGHT)){
                return true;
            }
        }
    }

    //only 2 kings and 2 pieces left
    if(notAlivePiece == 28){
        int numberOfWhiteBishopAlive = 0;
        int numberOfBlackBishopAlive = 0;
        for(int i=1; i<=64;i++){

            //it's a (king + bishop) vs (king + bishop).
            //Impossible to win
            if((this->getPiece(i).getPieceType() == BISHOP) && (this->getPiece(i).getColor() == WHITE)){
                numberOfWhiteBishopAlive +=1;

            }
            if((this->getPiece(i).getPieceType() == BISHOP) && (this->getPiece(i).getColor() == BLACK)){
                numberOfBlackBishopAlive +=1;
            }
        }
        if((numberOfWhiteBishopAlive == 1) && (numberOfBlackBishopAlive == 1)){
            return true;
        }
    }


    //Black's turn
    if(m_turn ==BLACK){
        Piece blackKing = findBlackKing();

        //To be draw, you're not in check
        if(!isCheck(blackKing)){
            int numberOfCheck =0;
            int numberOfPossibleCheck =0;

            //Finding all black pieces
            for(int i=1;i<=64;i++){
                if(getPiece(i).getColor() == BLACK){

                    //Looking all legal moves for every black pieces
                    for(int j=1;j<=64;j++){
                        if((legalMove(getPiece(i),getPiece(j))) && (getPiece(j).getPieceType() != KING)){
                            numberOfPossibleCheck +=1;

                            //Testing for every legal moves of every black pieces
                            // if you will be check
                            if(willBeCheck(getPiece(i),getPiece(j))){

                                numberOfCheck +=1;

                            }
                        }
                    }
                }
            }
            if(numberOfCheck == numberOfPossibleCheck){
                return true;
            }
        }
    }

    //White's turn
    if(m_turn ==WHITE){
        Piece whiteKing = findWhiteKing();

        //To be draw, you're not in check
        if(!isCheck(whiteKing)){
            int numberOfCheck =0;
            int numberOfPossibleCheck =0;

            //Finding all white pieces
            for(int i=1;i<=64;i++){
                if(getPiece(i).getColor() == WHITE){

                    //Looking all legal moves for every white pieces
                    for(int j=1;j<=64;j++){
                        if((legalMove(getPiece(i),getPiece(j))) && (getPiece(j).getPieceType() != KING)){
                            numberOfPossibleCheck +=1;

                            //Testing for every legal moves of every white pieces
                            // if you will be check
                            if(willBeCheck(getPiece(i),getPiece(j))){

                                numberOfCheck +=1;

                            }
                        }
                    }
                }
            }
            if(numberOfCheck == numberOfPossibleCheck){
                return true;
            }
        }
    }

    return false;
}





//Promote a pawn into the piece in parameter
void Board::promotion(Piece pawn ,Piece piece){

    int pawnPosition;
    pawnPosition=pawn.getPosition()-1;

    //Change the attribute "position" of the piece by the position of the pawn
    piece.setPosition(pawn.getPosition());

    //Replace the pawn square by the piece
    this->m_board.at(pawnPosition) = piece;

}





//Return all the squares where the piece can move
std::vector<Piece> Board::getPossibleMoves(Piece piece){

    //Saving parameters of the actual board
    std::vector <Piece> board = this->getBoard();
    std::vector <Piece> deadPiece = this->getNotAlivePiece();
    std::vector <Piece> PossiblesMoves;

    //For castling
    bool hasMoved = piece.getHasMoved();
    bool whiteCastled = m_whiteCastled;
    bool blackCastled = m_blackCastled;

    //For promotion
    bool waitingForPromotion = m_waitingForPromotion;

    //Used for en passant
    int moveNumber = piece.getMoveNumber();
    int lastMoveNumber = m_moveNumber;
    Piece empty;

    Color turn;
    turn =m_turn;


    for(int i=0;i<=63;i++){   
        //Do the move
        if(movePiece(piece,board.at(i))){
            PossiblesMoves.push_back(board.at(i));

            //cancelling the move by replacing the board by
            //the previous board
            m_board = board;
            m_turn = turn;
            m_notAlive=deadPiece;
            piece.setHasMoved(hasMoved);
            m_moveNumber --;
            m_whiteCastled = whiteCastled;
            m_blackCastled = blackCastled;
            piece.setMoveNumber(moveNumber);
            piece.setLastMoveNumber(lastMoveNumber);
            m_waitingForPromotion = waitingForPromotion;
            m_promotedPawn = empty;

        }
    }
    return PossiblesMoves;
}





bool Board::getTurn(){
    return m_turn;
}




//Return white rooks
std::vector <Piece> Board::findWhiteRooks(){
    std::vector <Piece> whiteRooks;
    for(int i=1; i<=64;i++){
        if((getPiece(i).getPieceType() == ROOK) && (getPiece(i).getColor() == WHITE)){
            whiteRooks.push_back(getPiece(i));
        }
    }
    return whiteRooks;
}




//Return black rooks
std::vector <Piece> Board::findBlackRooks(){
    std::vector <Piece> blackRooks;
    for(int i=1; i<=64;i++){
        if((getPiece(i).getPieceType() == ROOK) && (getPiece(i).getColor() == BLACK)){
            blackRooks.push_back(getPiece(i));
        }
    }
    return blackRooks;
}



//En passant
bool Board::enPassant(Piece piece, Piece target){

    if(piece.getColor() == WHITE){

        //En passant for black pawns
        if ((possibleEnPassant(piece,target)) && (legalMove(piece,target)) ){
            Piece nextLinePiece = getPiece(target.getPosition()+8);

                AddNotAlivePiece(nextLinePiece);
                deletePiece(nextLinePiece);
                return true;
        }
     }

    if(piece.getColor() == BLACK){

        //En passant for white pawns
        if (possibleEnPassant(piece,target) && (legalMove(piece,target)) ){
            Piece nextLinePiece = getPiece(target.getPosition()-8);
            AddNotAlivePiece(nextLinePiece);
            deletePiece(nextLinePiece);
            return true;
        }
    }

    return false;
}





//Delete the piece from the board
void Board::deletePiece(Piece piece){
    int position = piece.getPosition();
    Piece empty(position,NOCOLOR,NONE);
    m_notAlive.push_back(piece);
    m_board.at(position-1) = empty;
}




//Return true if en passant is possible
bool Board::possibleEnPassant(Piece piece, Piece target){

   if(piece.getColor() == WHITE){

        //En passant for black pawns
        if (( (target.getPosition())>16 ) && ((target.getPosition())<25 )){
            Piece nextLinePiece = getPiece(target.getPosition()+8);

            //En passant is possible if it's on a pawn which moved only one time and it was on the last turn
            if(( nextLinePiece.getColor() == BLACK) && ( nextLinePiece.getPieceType() == PAWN) && (nextLinePiece.getLastMoveNumber() == (m_moveNumber-1)) && (nextLinePiece.getMoveNumber() == 1)){
                return true;
            }
        }
    }
    if(piece.getColor() == BLACK){

        //En passant for white pawns
        if (( (target.getPosition())>40 ) && ((target.getPosition())<49 ) ){
            Piece nextLinePiece = getPiece(target.getPosition()-8);

            //En passant is possible if it's on a pawn which moved only one time and it was on the last turn
            if(( nextLinePiece.getColor() == WHITE) && ( nextLinePiece.getPieceType() == PAWN) && (nextLinePiece.getLastMoveNumber() == (m_moveNumber-1)) && (nextLinePiece.getMoveNumber() == 1)){
                return true;
            }
        }
    }
    return false;
}




void Board::setPromotion(Piece piece){
    m_promotion = piece;
}



bool Board::getWaitingForPromotion(){
    return m_waitingForPromotion;
}

void Board::setWaitingForPromotion(bool waitingForPromotion){
    m_waitingForPromotion = waitingForPromotion;
}



Color Board::getPromotionColor(){
    return m_promotionColor;
}


Piece Board::getPromotion(){
    return m_promotion;
}


Piece Board::getPromotedPawn(){
    return m_promotedPawn;
}
