#pragma once
#include<string>

using namespace std;

class ConsoleCanvas {
public:
	void drawAt(int x, int y, string s);
	void setCursorTo(int x,int y);
	int getCurrentX();
	int getCurrentY();
};
