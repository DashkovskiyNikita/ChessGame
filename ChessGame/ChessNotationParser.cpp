#include"ChessNotationParser.h"
#include<sstream>
#include<vector>

//парсим шахматную нотацию в индексы массива
Move ChessNotationParser::parse(string input) {

	vector<string> moves;

	istringstream streamData(input);

	string s_buffer;
	string error_message = "Unexpected coordinate : ";

	while (streamData>>s_buffer) {
		
		if (s_buffer.length() == 2) moves.push_back(s_buffer);
		else throw::runtime_error(error_message + s_buffer);

	}

	for (int i = 0; i < 2; i++) {

		char s1 = moves[i][0];
		char s2 = moves[i][1];

		if ('a' > s1 || 'h' < s1) {
			throw::runtime_error(error_message + s1);
		}
		if ('1' > s2 || '8' < s2) {
			throw::runtime_error(error_message + s2);
		}

	}

	Move move;

	move.fromY = abs(moves[0][1] - '1' - 7);
	move.toY = abs(moves[1][1] - '1' - 7);

	move.fromX = moves[0][0] - 'a';
	move.toX = moves[1][0] - 'a';
	
	return move;

}