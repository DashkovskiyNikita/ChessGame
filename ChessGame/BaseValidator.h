#pragma once
#include"BasePiece.h"

class BaseValidator {
private:
	Board* board;
public:
	BaseValidator(Board* board);
	~BaseValidator();
	bool isClearHorizontal(Position from,Position to);
	bool isClearVertical(Position from, Position to);
	bool isClearDiagonal(Position from, Position to);
	bool isEnemyOrEmptyCell(Position pos,Color color);
	bool isEmptyCell(Position pos);
};