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

	int menuSystem(int rowMenu,int columnMenu, char menu[25][30], string description);
	// ALL List of items in a menu will be here
	char mainMenuItems[3][30] = { "Start Game", "Options", "Exit" };
	char optionsMenuItems[4][30] = { "Zer","Keith","Ben","Test" };
	char battleMenuItems[2][30] = { "Attack","Run" };
	char alphabetSelection[5][30];

};

