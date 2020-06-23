#ifndef BOARD_H
#define BOARD_H
#include "piece.h"
#include <string>
#include <vector>


class Board
{
public:
    Board();
    Piece getPiece(int position);
    Piece getPromotion();
    Piece getPromotedPawn();
    std::vector <Piece> getBoard();
    bool getTurn();

    bool isInTheSameDiagonal(Piece piece, Piece target);
    bool isInTheSameColumn(Piece piece , Piece target);
    bool isInTheSameLine(Piece piece, Piece target);
    bool legalMove(Piece piece, Piece target);
    bool linePieceBetween(Piece piece, Piece target);
    bool columnPieceBetween(Piece piece, Piece target);
    bool diagonalPieceBetween(Piece piece, Piece target);
    bool isCheck(Piece king);
    bool willBeCheck(Piece piece, Piece target);
    bool isCheckMate();
    bool movePiece(Piece piece, Piece target);
    bool movePieceCastling(Piece rook, Piece king, Piece rookTarget, Piece kingTarget);
    bool isDraw();

    void promotion(Piece pawn,Piece piece);
    void showBoard();
    void AddNotAlivePiece(Piece piece);
    void movePieceAnyway(Piece piece, Piece target);
    void deletePiece(Piece piece);
    void setPromotion(Piece piece);
    bool castling(Piece rook);
    bool enPassant(Piece piece, Piece target);
    bool possibleEnPassant(Piece piece, Piece target);
    bool getWaitingForPromotion();
    Color getPromotionColor();
    void setWaitingForPromotion(bool waitingForPromotion);


    std::vector<Piece> getNotAlivePiece();
    Piece findBlackKing();
    Piece findWhiteKing();
    std::vector <Piece> findWhiteRooks();
    std::vector <Piece> findBlackRooks();
    std::vector<Piece> getPossibleMoves(Piece piece);

    int getMoveNumber();


private:

    std::vector <Piece> m_board ;
    std::vector <Piece> m_notAlive;
    int m_moveNumber;
    color m_turn;
    bool m_blackCastled;
    bool m_whiteCastled;
    Piece m_promotion;
    Piece m_promotedPawn;
    bool m_waitingForPromotion;
    Color m_promotionColor;
};

#endif // BOARD_H
