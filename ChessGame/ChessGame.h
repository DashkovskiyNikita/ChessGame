#pragma once
#include"PieceValidator.h"
#include"ConsoleCanvas.h"
#include"ChessNotationParser.h"

struct KingInfo {
	Position pos;
	Color color;
};

class ChessGame {
public:
	ChessBoard* board;
	PieceValidator* validator;
	ConsoleCanvas* canvas;
	ChessNotationParser* parser;
	Color currentColor;
	bool isGameOver;
public:
	ChessGame(ChessBoard* board, PieceValidator* validator, ConsoleCanvas* canvas, ChessNotationParser* parser);
	~ChessGame();
	void start();
private:
	void showPieces();
	void gameLoop();
	void playerMove();
	void gameOver();
	bool availableMoves();
	Move getUserInput();
	bool mate();
	void changePlayer();
	Color pickUserColor();
};
