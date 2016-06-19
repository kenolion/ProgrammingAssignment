#pragma once
#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

class Menu
{
public:
	Menu();
	~Menu();

	int menuSystem(int itemsMenu, string menu[25], string description);
	// ALL List of items in a menu will be here
	string mainMenuItems[3] = { "Start Game", "Options", "Exit" };
	string optionsMenuItems[4] = { "Zer","Keith","Ben","Test" };
	string battleMenuItems[2] = { "Attack","Run" };
};

