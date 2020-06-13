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
    bool castling(Piece rook);

    std::vector<Piece> getNotAlivePiece();
    Piece findBlackKing();
    Piece findWhiteKing();
    std::vector <Piece> findWhiteRooks();
    std::vector <Piece> findBlackRooks();
    std::vector<Piece> getPossibleMoves(Piece piece);

    int getMoveNumber();      

private:
    const std::string m_coordinates [64] ={"a8","b8","c8","d8","e8","f8","g8","h8",
                                          "a7","b7","c7","d7","e7","f7","g7","h7",
                                          "a6","b6","c6","d6","e6","f6","g6","h6",
                                          "a5","b5","c5","d5","e5","f5","g5","h5",
                                          "a4","b4","c4","d4","e4","f4","g4","h4",
                                          "a3","b3","c3","d3","e3","f3","g3","h3",
                                          "a2","b2","c2","d2","e2","f2","g2","h2",
                                          "a1","b1","c1","d1","e1","f1","g1","h1"};
    std::vector <Piece> m_board ;
    std::vector <Piece> m_notAlive;
    int m_moveNumber;
    color m_turn;
    bool m_blackCastled;
    bool m_whiteCastled;
};

#endif // BOARD_H
