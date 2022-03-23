#pragma once

struct Position {
	int x;
	int y;
};

enum class Color {
	WHITE,BLACK
};

enum class PieceType {
	PAWN,KNIGHT,ROOK,BISHOP,QUEEN,KING
};

class BasePiece {
protected:
	PieceType type;
	char name;
	Position pos;
	Color color;
	bool isMoved;
public:
	BasePiece(PieceType type, Position pos, Color color,char name);
	~BasePiece();
	
	void draw();
	
	Position getPosition();
	void setPosition(Position pos);
	
	Color getColor();
	void setColor(Color color);
	
	bool getIsMoved();
	void setIsMoved(bool value);

	PieceType getPieceType();
	void setPieceType(PieceType type);

};
