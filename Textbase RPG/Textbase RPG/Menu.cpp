#include "Menu.h"
#include <iostream>
#include <windows.h>
#include <string>
using namespace std;



Menu::Menu()
{
}


Menu::~Menu()
{
}

// Code for accepting arrow keys and enters
int Menu::menuSystem(int itemsMenu, string menu[25], string description) {

		int pointer = 0;
		while (true)
		{
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // SETS TEXT COLOR TO WHITE
			cout << description;
			for (int i = 0; i < itemsMenu; ++i) {
				if (i == pointer) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11); //sets text color to cyan
					cout << menu[i] << endl;
				}
				else {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					cout << menu[i] << endl;
				}
			}
			while (true) {
				if (GetAsyncKeyState(VK_UP) != 0) { // Gets the up arrow key and each time its released it will give a random number that wont be 0
					pointer -= 1;
					if (pointer == -1) { // Basically brings the pointer to the bottom if the user cursor reaches the toppest
						pointer = itemsMenu - 1; //itemsmenu is placed there because different menu has different amount of items
					}
					break;
				}
				else if (GetAsyncKeyState(VK_DOWN) != 0) {
					pointer += 1;
					if (pointer == itemsMenu) { //Same thing but this time it is softcoded because the amount of items in menu may vary
						pointer = 0;			//It brings the cursor back to the top when it reaches its end at the bottom
					}
					break;
				}
				else if (GetAsyncKeyState(0x5A)) {

					return pointer;
				}

			}

			Sleep(150);
		}
	}
