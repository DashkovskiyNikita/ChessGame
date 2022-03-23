#pragma once
#include"Pieces.h"

class Board {
private:
	BasePiece* field[8][8];
protected:
	Color mainColor;
public:
	Board();
	~Board();

	BasePiece* pieceAt(Position pos);
	void removePieceAt(Position pos);
	void setPieceAt(BasePiece* pos);
	void reset();

	Color getMainColor();
	void setMainColor(Color mainColor);
};