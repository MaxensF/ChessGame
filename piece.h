#ifndef PIECE_H
#define PIECE_H
#include <string>

enum pieceType {KING,QUEEN,PAWN,ROOK,BISHOP,KNIGHT,NONE};
enum color {BLACK,WHITE,NOCOLOR};
typedef enum pieceType pieceType;
typedef enum color Color;

class Piece
{
public:
    Piece(int position =0, color Color = NOCOLOR, pieceType pieceType =NONE);

    int getPosition();
    color getColor();
    pieceType getPieceType();
    bool getHasMoved();
    int getMoveNumber();
    int getLastMoveNumber();

    void setPosition(int position);
    void setPieceType(pieceType pieceType);
    void setColor( color Color);
    void setHasMoved(bool hasMoved);
    void setMoveNumber(int moveNumber);
    void setLastMoveNumber(int lastMoveNumber);




private:
    int m_position;
    int m_moveNumber;
    int m_lastMoveNumber;
    pieceType m_pieceType;
    color m_color;
    bool m_hasMoved;


};

#endif // PIECE_H
