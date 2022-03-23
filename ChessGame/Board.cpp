#include"Board.h"
//#include"Pieces.cpp"


Board::Board() {

	this->mainColor = Color::WHITE;
	
	for (int i = 0; i < 8; i++) {
		
		for (int j = 0; j < 8; j++) field[i][j] = nullptr;
		
	}
}

Board::~Board() {
	
	for (int i = 0; i < 8; i++) {
		
		for (int j = 0; j < 8; j++) delete field[i][j];
		
	}

}

 //возвращает фигуру в указанной позиции
BasePiece* Board::pieceAt(Position pos) {
	
	return field[pos.y][pos.x];

}

//удаление фигуры в указанно позиции
void Board::removePieceAt(Position pos) {
	
	field[pos.y][pos.x] = 0;

}

//установка фигуры в указанную позицию
void Board::setPieceAt(BasePiece* piece) {
	
	auto pos = piece->getPosition();

	field[pos.y][pos.x] = piece;
}

//  0 1 2 3 4 5 6 7 
//0 R N B K Q B N R
//1 P P P P P P P P
//2 . . . . . . . .
//3 . . . . . . . .
//4 . . . . . . . .
//5 . . . . . . . .
//6 p p p p p p p p
//7 r n b k q b n r

//установка фигур на доске на начало партии
void Board::reset() {

	Color secondColor = Color::BLACK;

	if (mainColor != Color::WHITE) secondColor = Color::WHITE;

	//Pawns
	for (int i = 0; i < 8; i++) {

		field[1][i] = new Pawn({ i,1 }, secondColor);

		field[6][i] = new Pawn({ i,6 }, mainColor);
	}

	//Rooks
	field[0][0] = new Rook({ 0,0 }, secondColor);
	field[0][7] = new Rook({ 7,0 }, secondColor);
	field[7][0] = new Rook({ 0,7 }, mainColor);
	field[7][7] = new Rook({ 7,7 }, mainColor);

	//Knights
	field[0][1] = new Knight({ 1,0 }, secondColor);
	field[0][6] = new Knight({ 6,0 }, secondColor);
	field[7][1] = new Knight({ 1,7 }, mainColor);
	field[7][6] = new Knight({ 6,7 }, mainColor);

	//Bishops
	field[0][2] = new Bishop({ 2,0 }, secondColor);
	field[0][5] = new Bishop({ 5,0 }, secondColor);
	field[7][2] = new Bishop({ 2,7 }, mainColor);
	field[7][5] = new Bishop({ 5,7 }, mainColor);

	//Kings
	field[0][3] = new King({ 3,0 }, secondColor);
	field[7][3] = new King({ 3,7 }, mainColor);

	//Queens
	field[0][4] = new Queen({ 4,0 }, secondColor);
	field[7][4] = new Queen({ 4,7 }, mainColor);

}

Color Board::getMainColor() {
	
	return mainColor;

}

void Board::setMainColor(Color mainColor) {
	
	this->mainColor = mainColor;

}