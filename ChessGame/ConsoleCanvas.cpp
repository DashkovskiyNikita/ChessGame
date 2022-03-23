#include"ConsoleCanvas.h"
#include<iostream>
#include<Windows.h>

using namespace std;

void ConsoleCanvas::drawAt(int x, int y, string s) {
	
	setCursorTo(x, y);
	
	cout << s;
}

void ConsoleCanvas::setCursorTo(int x, int y) {

	COORD coord = { x,y };

	auto handle = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleCursorPosition(handle, coord);

}

int ConsoleCanvas::getCurrentX() {

	CONSOLE_SCREEN_BUFFER_INFO bufferInfo;

	auto handle = GetStdHandle(STD_OUTPUT_HANDLE);

	if (GetConsoleScreenBufferInfo(handle, &bufferInfo)) {
		return bufferInfo.dwCursorPosition.X;
	}
	else {
		return -1;
	}

}

int ConsoleCanvas::getCurrentY() {

	CONSOLE_SCREEN_BUFFER_INFO bufferInfo;

	auto handle = GetStdHandle(STD_OUTPUT_HANDLE);

	if (GetConsoleScreenBufferInfo(handle, &bufferInfo)) {
		return bufferInfo.dwCursorPosition.Y;
	}
	else {
		return -1;
	}

}