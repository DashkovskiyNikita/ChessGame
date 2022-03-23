#include"PieceValidator.h"
#include<cmath>

PieceValidator::PieceValidator(ChessBoard* chessBoard) {

	this->chessBoard = chessBoard;

}

PieceValidator::~PieceValidator() {

	if (chessBoard) delete chessBoard;

}

bool PieceValidator::check(BasePiece* piece, Position toPos) {

	auto type = piece->getPieceType();

	bool result = false;

	switch (type) {

	case PieceType::PAWN:

		result = checkPawn(piece, toPos);
		
		break;

	case PieceType::KNIGHT:

		result = checkKnight(piece, toPos);

		break;

	case PieceType::ROOK:

		result = checkRook(piece, toPos);

		break;

	case PieceType::BISHOP:

		result = checkBishop(piece, toPos);

		break;

	case PieceType::QUEEN:

		result = checkQueen(piece, toPos);

		break;

	case PieceType::KING:

		result = checkKing(piece, toPos);

		break;
	}

	return result;

}

bool PieceValidator::checkPawn(BasePiece* piece, Position toPos) {

	Position pos = piece->getPosition();
	Color color = piece->getColor();
	bool isMoved = piece->getIsMoved();


	bool isValidMove = false;

	int allowableMove1 = 1;
	int allowableMove2 = 2;


	Color mainColor = chessBoard->getMainColor();

	if (color == mainColor) {
		allowableMove1 = -1;
		allowableMove2 = -2;
	}

	bool isEmptyCell = chessBoard->isEmptyCell(toPos);

	if (toPos.y == pos.y + allowableMove1 && toPos.x == pos.x) {

		if (isEmptyCell) isValidMove = true;

	}

	else if (toPos.y == pos.y + allowableMove2 && !isMoved && toPos.x == pos.x) {

		bool isClearVertical = chessBoard->isClearVertical(pos, toPos);

		if (isEmptyCell && isClearVertical) isValidMove = true;

	}

	else if (toPos.y == pos.y + allowableMove1 && abs(toPos.x - pos.x) == 1) {

		bool isEnemyCell = chessBoard->isEnemyCell(toPos,color);
		
		if (isEnemyCell) isValidMove = true;

	}

	return isValidMove;
}

bool PieceValidator::checkKnight(BasePiece* piece, Position toPos) {

	Position pos = piece->getPosition();
	Color color = piece->getColor();

	bool isValidMove = false;

	bool isEnemyOrEmpty = chessBoard->isEnemyOrEmptyCell(toPos, color);

	int translateX = abs(pos.x - toPos.x);
	int translateY = abs(pos.y - toPos.y);

	if (translateY == 2 && translateX == 1 && isEnemyOrEmpty) {
		isValidMove = true;
	}

	else if (translateX == 2 && translateY == 1 && isEnemyOrEmpty) {
		isValidMove = true;
	}

	return isValidMove;
}

bool PieceValidator::checkRook(BasePiece* piece, Position toPos) {

	Position pos = piece->getPosition();
	Color color = piece->getColor();

	bool isEnemyOrEmpty = chessBoard->isEnemyOrEmptyCell(toPos, color);

	bool isValidMove = false;

	int translateX = abs(pos.x - toPos.x);
	int translateY = abs(pos.y - toPos.y);

	if (translateX == 0 && translateY > 0 && isEnemyOrEmpty) {

		bool isClearVertical = chessBoard->isClearVertical(pos, toPos);

		if (isClearVertical) isValidMove = true;
		
	}

	else if (translateY == 0 && translateX > 0 && isEnemyOrEmpty) {

		bool isClearHorizontal = chessBoard->isClearHorizontal(pos, toPos);

		if (isClearHorizontal) isValidMove = true;
	
	}

	return isValidMove;

}

bool PieceValidator::checkBishop(BasePiece* piece, Position toPos) {

	Position pos = piece->getPosition();
	Color color = piece->getColor();

	bool isEnemyOrEmpty = chessBoard->isEnemyOrEmptyCell(toPos, color);
	bool isClearDiagonal = chessBoard->isClearDiagonal(pos,toPos);

	bool isValidMove = false;

	int translateX = abs(pos.x - toPos.x);
	int translateY = abs(pos.y - toPos.y);

	if (translateX == translateY && isEnemyOrEmpty && isClearDiagonal) {
		isValidMove = true;
	}

	return isValidMove;
}

bool PieceValidator::checkQueen(BasePiece* piece, Position toPos) {

	Position pos = piece->getPosition();
	Color color = piece->getColor();

	return checkRook(piece, toPos) || checkBishop(piece, toPos);
}

bool PieceValidator::checkKing(BasePiece* piece, Position toPos) {

	Position pos = piece->getPosition();
	Color color = piece->getColor();
	
	bool isEnemyOrEmpty = chessBoard->isEnemyOrEmptyCell(toPos,color);

	bool isValidMove = false;

	int locationX = abs(pos.x - toPos.x);
	int locationY = abs(pos.y - toPos.y);

	if (locationX == 1 && locationY == 1 && isEnemyOrEmpty) {
		isValidMove = true;
	}

	else if (locationX == 1 && locationY == 0 && isEnemyOrEmpty) {
		isValidMove = true;
	}

	else if (locationY == 1 && locationX == 0 && isEnemyOrEmpty) {
		isValidMove = true;
	}

	return isValidMove;

}

