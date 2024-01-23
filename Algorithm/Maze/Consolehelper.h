#pragma once

#include <windows.h>
enum class ConsoleColor {

	BLACK = 0,
	RED=FOREGROUND_RED,
	GREEN=FOREGROUND_GREEN,
	BLUE=FOREGROUND_BLUE,
	YELLOW=RED | GREEN,
	WHITE=RED | GREEN | BLUE,

};


class Consolehelper
{
public:
	static void SetCursorPosition(INT32 x, INT32 Y);
	static void SetCursorColor(ConsoleColor color);
	static void ShowConsoleCursor(bool flag);

private: 



};

