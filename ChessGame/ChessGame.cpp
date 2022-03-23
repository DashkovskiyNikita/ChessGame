#include"ChessGame.h"
#include<iostream>

std::string white = "Ѕелые";
std::string black = "„ерные";

int position = 18;

ChessGame::ChessGame(ChessBoard* board, PieceValidator* validator, ConsoleCanvas* canvas, ChessNotationParser* parser) {
	this->board = board;
	this->validator = validator;
	this->canvas = canvas;
	this->parser = parser;
	this->currentColor = Color::WHITE;
	this->isGameOver = false;
}

ChessGame::~ChessGame() {

	if (board) delete board;
	if (validator) delete validator;
	if (canvas) delete canvas;
	if (parser) delete parser;
}

//выбор пользователем цвета фигур
Color ChessGame::pickUserColor() {

	char color;

	cout << "¬ыберите цвет фигур : ";

	(cin >> color).get();
	position++;

	switch (color) {
	case 'b':
		return Color::BLACK;
		break;
	case 'w':
		return Color::WHITE;
		break;
	default: return pickUserColor();
	}

}

//начало игры
void ChessGame::start() {

	board->drawBoard();

	Color mainColor = pickUserColor();
	Color secondColor = Color::BLACK;

	if (mainColor == Color::BLACK) secondColor = Color::WHITE;

	board->setMainColor(mainColor);
	board->reset();
	
	showPieces();

	canvas->setCursorTo(0, position);
	
	gameLoop();
}

//основной цикл игры
void ChessGame::gameLoop() {

	while (!isGameOver) {

		playerMove();

		showPieces();

		canvas->setCursorTo(0, position);

		changePlayer();

		gameOver();

	}

}

//смена игрока
void ChessGame::changePlayer() {

	currentColor = currentColor == Color::WHITE ? Color::BLACK : Color::WHITE;

}

//отрисовка фигур
void ChessGame::showPieces() {

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {

			auto piece = board->pieceAt({ j,i });

			if (piece) {
				canvas->setCursorTo(5 + j * 4,2 + i * 2);
				piece->draw();
			}
		}
	}

}

//получение координат хода с консоли и проверка их на правильность
Move ChessGame::getUserInput() {

	bool isCorrect = false;

	Move move;

	while (!isCorrect) {
		
		std::string buffer;
		std::getline(std::cin, buffer);
		position++;

		try {
			
			move = parser->parse(buffer);
			
			isCorrect = true;

		}catch (const runtime_error& error) { }

	}

	return move;
}

//ход игрока
void ChessGame::playerMove() {

	Move move;
	BasePiece* piece = nullptr;

	bool isCorrect = false;

	if (currentColor == Color::WHITE) cout << "’од белых : ";
	else cout << "’од черных : ";

	while (!isCorrect) {

		move = getUserInput();

		piece = board->pieceAt({ move.fromX,move.fromY });

		if (piece == nullptr) continue;
	
		if (piece->getColor() != currentColor) continue;

		bool legalMove = validator->check(piece, { move.toX,move.toY });

		if (!legalMove) continue;
		
		auto tmp = board->pieceAt({ move.toX,move.toY });

		board->removePieceAt({ move.fromX,move.fromY });
		piece->setPosition({ move.toX,move.toY });
		board->setPieceAt(piece);

		if (mate()) {
			if(tmp) board->setPieceAt(tmp);
			piece->setPosition({move.fromX,move.fromY});
			board->setPieceAt(piece);
			continue;
		}

		if (tmp) delete tmp;

		canvas->drawAt(5 + move.fromX * 4, 2 + move.fromY * 2," ");

		isCorrect = true;
	}

}

//проверка на шах и мат или пат
void ChessGame::gameOver() {

	if (!availableMoves()) {
		
		if (mate()) {
			
			isGameOver = true;

			std::string message = currentColor == Color::WHITE ? black : white;

			cout << message << " побеждают!";
		
		}else {

			isGameOver = true;

			cout << "ѕат!";
		}

	}
}

//проверка корол€ находитс€ ли он под матом
bool ChessGame::mate() {

	Position kingPos;
	bool isFound = false;

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {

			auto piece = board->pieceAt({ j,i });

			if (piece == nullptr) continue;

			if (piece->getColor() != currentColor) continue;

			if (piece->getPieceType() == PieceType::KING) {
				kingPos = piece->getPosition();
				isFound = true;
				break;
			}
		}

		if (isFound) break;
	}

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {

			auto piece = board->pieceAt({ j,i });

			if (piece == nullptr) continue;

			if (piece->getColor() != currentColor) {

				bool result = validator->check(piece, kingPos);

				if (result) return true;
			}
		}
	}

	return false;

}

//проверка того остались ли доступные ходы у игрока
bool ChessGame::availableMoves() {

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {

			auto piece = board->pieceAt({ j,i });

			if (piece == nullptr) continue;

			if (piece->getColor() != currentColor) continue;

			for (int a = 0; a < 8; a++) {
				for (int b = 0; b < 8; b++) {
					
					bool result = validator->check(piece, { b,a });

					if (result) {

						auto tmp = board->pieceAt({ b,a });
						
						board->removePieceAt({ j,i });
						piece->setPosition({ b,a });
						board->setPieceAt(piece);
						
						bool isMate = mate();

						board->removePieceAt({ b,a });
						piece->setPosition({ j,i });
						board->setPieceAt(piece);
						if(tmp) board->setPieceAt(tmp);

						if (!isMate) return true;
					}
				}
			}
		}
	}

	return false;
}