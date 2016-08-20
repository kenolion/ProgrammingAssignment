#ifndef CONSOLEWINDOW
#define CONSOLEWINDOW
#include <windows.h>
#include <iostream>
#include <conio.h>
class ConsoleWindow
{

public:
	static void ShowConsoleCursor(bool torf);
	static void SetDrawingPoint(int x, int y);
	static void SetFontColour(int kolor);
	static void equalSignMaker9000(int eqCount); // COUT'S EQUAL SIGNS
	static void CIRCLEMAKER9000();

	static void getCursorXY();
	static int x;
	static int y;
	
	ConsoleWindow(); // ignore 4now
	~ConsoleWindow();

};

#endif