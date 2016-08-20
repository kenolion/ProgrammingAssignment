#include "ConsoleWindow.h"
#include <math.h>
using namespace std;
int ConsoleWindow::x = 0;
int ConsoleWindow::y = 0;
	

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


void ConsoleWindow::getCursorXY() {
	
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
		x = csbi.dwCursorPosition.X;
		y = csbi.dwCursorPosition.Y;
	}
}

void ConsoleWindow::CIRCLEMAKER9000()
{
	int circle_radius = 10; // or whatever you want

	for (int i = 0; i <= 2 * circle_radius; i++)
	{
		for (int j = 0; j <= 2 * circle_radius; j++)
		{
			float distance_to_centre = sqrt((i - circle_radius)*(i - circle_radius) + (j - circle_radius)*(j - circle_radius));
			if (distance_to_centre > circle_radius - 0.5 && distance_to_centre < circle_radius + 0.5)
			{
				cout << "*";
			}
			else
			{
				cout << " ";
			}
		}
		cout << endl;
	}
}