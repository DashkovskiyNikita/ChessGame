#include <iostream>
#include"ChessGame.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "RU");
	
	ChessBoard* board = new ChessBoard();
	PieceValidator* validator = new PieceValidator(board);
	ConsoleCanvas* canvas = new ConsoleCanvas();
	ChessNotationParser* parser = new ChessNotationParser();
	ChessGame* game = new ChessGame(board,validator,canvas,parser);

	game->start();

}
