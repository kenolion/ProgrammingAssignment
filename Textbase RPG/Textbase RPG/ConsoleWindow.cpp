#include "ConsoleWindow.h"
#include <windows.h>
#include <iostream>

using namespace std;
ConsoleWindow::ConsoleWindow() // "ConsoleWindow::ConsoleWindow () To make things your member
{
}

ConsoleWindow::~ConsoleWindow()
{
}

//_____________________________  BELOW THIS LINE IS IMPORTANT  ____________________

void ConsoleWindow::ShowConsoleCursor(bool torf)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = torf; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo); //Disable console cursor
}

void ConsoleWindow::SetDrawingPoint(int x, int y)
{
	COORD cord; // Allows you to print words at a specific coordinate.
	cord.X = x;
	cord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cord);
}

void ConsoleWindow::SetFontColour(int kolor)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, kolor); //SetConsoleTextAttribute allows you to change font color, at will.
}
void ConsoleWindow::equalSignMaker9000(int eqCount) // COUT'S EQUAL SIGNS
{
	for (int a = 0; a < eqCount; a++)
	{
		cout << "=";
	}
}