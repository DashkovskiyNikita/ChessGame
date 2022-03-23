#include"BaseValidator.h"
#include"Board.h"


BaseValidator::BaseValidator(Board* board) {
	this->board = board;
}

BaseValidator::~BaseValidator() {
	delete this->board;
}

bool BaseValidator::isEmptyCell(Position pos) {

	auto piece = board->pieceAt(pos);

	return piece == NULL;
}

bool BaseValidator::isEnemyOrEmptyCell(Position pos,Color color) {

	bool isValid = false;
	
	auto piece = board->pieceAt(pos);

	if (piece == NULL) {
		isValid = true;
	}

	else if (piece->getColor() != color) {
		isValid = true;
	}

	return isValid;

}

bool BaseValidator::isClearHorizontal(Position from, Position to) {

	bool valid = true;

	Position* start = &from;
	Position* end = &to;

	if (to.x < from.x) {
		start = &to;
		end = &from;
	}

	for (int x = start->x + 1; x < end->x; x++) {

		Position pos = { x,start->y };
		
		auto piece = board->pieceAt(pos);

		if (piece != NULL) {
			valid = false;
			break;
		}
	}

	return valid;

}

bool BaseValidator::isClearVertical(Position from, Position to) {

	bool valid = true;

	Position* start = &from;
	Position* end = &to;

	if (to.y < from.y) {
		start = &to;
		end = &from;
	}

	for (int y = start->y + 1; y < end->y; y++) {

		Position pos = { start->x,y };

		auto piece = board->pieceAt(pos);

		if (piece != NULL) {
			valid = false;
			break;
		}
	}

	return valid;

}

bool BaseValidator::isClearDiagonal(Position from, Position to) {

	bool valid = true;

	int translateX = to.x - from.x;
	int translateY = to.y - from.y;

	int xDir = 1;
	int yDir = 1;

	if (translateX < 0) xDir = -1;

	if (translateY < 0) yDir = -1;

	int y = 1;

	for (int x = 1; x < abs(translateX); x++, y++) {

		Position pos = { from.x + x * xDir, from.y + y * yDir };

		auto piece = board->pieceAt(pos);

		if (piece != NULL) {
			valid = false;
			break;
		}
	}

	return valid;
}