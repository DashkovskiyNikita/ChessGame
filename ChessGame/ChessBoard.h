#pragma once
#include"Board.h"

class ChessBoard : public Board {
public:
	~ChessBoard();
public:
	void drawBoard();
	bool isClearHorizontal(Position from, Position to);
	bool isClearVertical(Position from, Position to);
	bool isClearDiagonal(Position from, Position to);
	bool isEnemyCell(Position pos, Color color);
	bool isEmptyCell(Position pos);
	bool isEnemyOrEmptyCell(Position pos, Color color);
};
