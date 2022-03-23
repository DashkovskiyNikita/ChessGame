#include"ChessBoard.h"
#include"iostream"

using namespace std;


ChessBoard::~ChessBoard() {
	
}   

//Board example
//     A   B   C   D   E   F   G   H
//   +---+---+---+---+---+---+---+---+
// 7 | r | n | b | k | q | b | n | r |
//   +---+---+---+---+---+---+---+---+
// 6 | p | p | p | p | p | p | p | p |
//   +---+---+---+---+---+---+---+---+

//отрисовка шахматной доски
void ChessBoard::drawBoard() {

	char start = 'A';

	cout << "  ";

	for (int i = 0; i < 8; i++) cout << "   " << start++;

	cout << "\n";

	for (int i = 8; i >= 0; i--) {

		cout << "   +";

		for (int j = 0; j < 8; j++) {
			cout << "---+";
		}

		cout << "\n";

		if (i == 0) break;

		cout << " " << i << " ";

		for (int k = 0; k < 9; k++) {
			cout << "|   ";
		}

		cout << "\n";
	}

}

//проверка является ли клетка пустой
bool ChessBoard::isEmptyCell(Position pos) {

	auto piece = pieceAt(pos);

	return piece == NULL;
}

//проверка является ли клетка вражеской
bool ChessBoard::isEnemyCell(Position pos,Color color) {

	bool isValid = false;

	auto piece = pieceAt(pos);

	if (piece != NULL) {

		if (piece->getColor() != color) {

			isValid = true;

		}
	}

	return isValid;

}

//проверка является клетка вражеской или пустой
bool ChessBoard::isEnemyOrEmptyCell(Position pos, Color color) {

	return isEnemyCell(pos, color) || isEmptyCell(pos);

}

//проверка пустые ли клетки в указанном промежутке по горизонтали
bool ChessBoard::isClearHorizontal(Position from, Position to) {

	bool valid = true;

	Position* start = &from;
	Position* end = &to;

	if (to.x < from.x) {
		start = &to;
		end = &from;
	}

	for (int x = start->x + 1; x < end->x; x++) {

		Position pos = { x,start->y };

		auto piece = pieceAt(pos);

		if (piece != NULL) {
			valid = false;
			break;
		}
	}

	return valid;

}

//проверка пустые ли клетки в указанном промежутке по вертикали
bool ChessBoard::isClearVertical(Position from, Position to) {

	bool valid = true;

	Position* start = &from;
	Position* end = &to;

	if (to.y < from.y) {
		start = &to;
		end = &from;
	}

	for (int y = start->y + 1; y < end->y; y++) {

		Position pos = { start->x,y };

		auto piece = pieceAt(pos);

		if (piece != NULL) {
			valid = false;
			break;
		}
	}

	return valid;

}

//проверка пустые ли клетки в указанном промежутке по диагонали
bool ChessBoard::isClearDiagonal(Position from, Position to) {

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

		auto piece = pieceAt(pos);

		if (piece != NULL) {
			valid = false;
			break;
		}
	}

	return valid;
}