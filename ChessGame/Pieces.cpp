#include"Pieces.h"

Pawn::Pawn(Position pos, Color color) : BasePiece(PieceType::PAWN,pos,color,'p') { }
Pawn::~Pawn() { }

Knight::Knight(Position pos, Color color) : BasePiece(PieceType::KNIGHT, pos, color,'n') { }
Knight::~Knight(){ }

Rook::Rook(Position pos, Color color) : BasePiece(PieceType::ROOK, pos, color,'r') { }
Rook::~Rook() { }

Bishop::Bishop(Position pos, Color color) : BasePiece(PieceType::BISHOP, pos, color,'b') { }
Bishop::~Bishop() { }

Queen::Queen(Position pos, Color color) : BasePiece(PieceType::QUEEN,pos,color,'q') { }
Queen::~Queen() { }

King::King(Position pos, Color color) : BasePiece(PieceType::KING,pos,color,'k') { }
King::~King() { }