#include"BasePiece.h"
#include<iostream>

using namespace std;

BasePiece::BasePiece(PieceType type, Position pos, Color color,char name) {
	this->type = type;
	this->pos = pos;
	this->color = color;
	this->isMoved = false;
	if (color == Color::WHITE) {
		this->name = toupper(name);
	}
	else {
		this->name = name;
	}
}

BasePiece::~BasePiece() {

}

void BasePiece::draw() {
	
	cout << name;

}

Position BasePiece::getPosition() {
	return this->pos;
}

void BasePiece::setPosition(Position pos) {
	this->pos = pos;
}

Color BasePiece::getColor() {
	return this->color;
}

void BasePiece::setColor(Color color) {
	this->color = color;
}

bool BasePiece::getIsMoved() {
	return this->isMoved;
}

void BasePiece::setIsMoved(bool value) {
	this->isMoved = value;
}

PieceType BasePiece::getPieceType() {
	return this->type;
}

void BasePiece::setPieceType(PieceType type) {
	this->type = type;
}
