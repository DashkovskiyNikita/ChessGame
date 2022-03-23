#pragma once
#include<string>

using namespace std;

struct Move {
	int fromX, fromY;
	int toX, toY;
};

class ChessNotationParser {
public:
	Move parse(string input);
};