#pragma once
#include"ChessBoard.h"


class PieceValidator {
private:
	ChessBoard* chessBoard;
public:
	PieceValidator(ChessBoard* chessBoard);
	~PieceValidator();
	bool check(BasePiece* piece, Position to);
private:
	bool checkPawn(BasePiece* piece, Position to);
	bool checkKnight(BasePiece* piece, Position to);
	bool checkRook(BasePiece* piece, Position to);
	bool checkBishop(BasePiece* piece, Position to);
	bool checkQueen(BasePiece* piece, Position to);
	bool checkKing(BasePiece* piece, Position to);
};