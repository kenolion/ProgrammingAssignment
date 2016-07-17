#include "UserInterface.h"
#include <Windows.h>
#include <string>

using namespace std;
UserInterface::UserInterface()
{
}


UserInterface::~UserInterface()
{
}

void UserInterface::setDrawingPoint(int x, int y)
{
	COORD coord; //Does not need to be define because if we right click COORD and go to definition it is already defined in another library
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
