#ifndef PIECE_H
#define PIECE_H
#include <string>

enum pieceType {KING,QUEEN,PAWN,ROOK,BISHOP,KNIGHT,NONE};
enum pieceColor {BLACK,WHITE,NOCOLOR};
typedef enum pieceType pieceType;
typedef enum pieceColor pieceColor;

class Piece
{
public:
    Piece(int position, pieceColor Color, pieceType pieceType);

    int getPosition();
    pieceColor getPieceColor();
    pieceType getPieceType();

    void setPostion(int position);
    void setPieceType(pieceType pieceType);
    void setPieceColor( pieceColor pieceColor);

    bool isCheck(Piece king);

private:
    int m_position;
    pieceType m_pieceType;
    pieceColor m_color;


};

#endif // PIECE_H
