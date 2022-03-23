#pragma once
#include"BasePiece.h"

class Pawn : public BasePiece {
public:
	Pawn(Position pos, Color color);
	~Pawn();
};

class Knight : public BasePiece {
public:
	Knight(Position pos, Color color);
	~Knight();
};

class Rook : public BasePiece {
public:
	Rook(Position pos, Color color);
	~Rook();
};

class Bishop : public BasePiece {
public:
	Bishop(Position pos, Color color);
	~Bishop();
};

class Queen : public BasePiece {
public:
	Queen(Position pos, Color color);
	~Queen();
};

class King : public BasePiece {
public:
	King(Position pos, Color color);
	~King();
};