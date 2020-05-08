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

    bool isInTheSameDiagonal(Piece piece, Piece target);
    bool isInTheSameColumn(Piece piece , Piece target);
    bool isInTheSameLine(Piece piece, Piece target);
    bool legalMove(Piece piece, Piece target);
    bool linePieceBetween(Piece piece, Piece target);
    bool columnPieceBetween(Piece piece, Piece target);
    bool diagonalPieceBetween(Piece piece, Piece target);
    void movePiece(Piece);

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
};

#endif // BOARD_H
