/*
C++ Programming Assignment
Text Based RPG Game
By : Keith, Ben and Zer
Date : 10/6/2016
*/
#include <iostream>
#include <time.h> // to use the rand() function
#include <windows.h>// to use the function sleep
#include <string> //STRING DATA TYPE?!
#include "Time.h"
#include "Character.h"
int battleSystem();
int tempPointer;
using namespace std;


int choice = 99; ////Temporary variable to store choices of player.
class Menu {
public:
	// ALL List of items in a menu will be here
	string mainMenuItems[3] = { "Start Game", "Options", "Exit" };
	string optionsMenuItems[4] = { "Zer","Keith","Ben","Test" };
	string battleMenuItems[2] = { "Attack","Run" };

	// Code for accepting arrow keys and enters
	int menuSystem(int itemsMenu, string menu[25], string description) {

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
	//Code to decide what each item in a menu do
	int mainMenu(int pointer) {
		switch (pointer) {
		case 0: {
			cout << "Starting game...\n";
			break;
		}
		case 1: {
			cout << "This is the options\n";
			break;
		case 2:
			exit(0);
		}

		}

	}

}menu;

int main() {
	Time day;
	Character player;

	//Menu system start from here
	string welcome = "Welcome to a Text based RPG game!\n";
	tempPointer = menu.menuSystem(3, menu.mainMenuItems, welcome); // This calls the menu system function (x,y) X represents the number of list in the menu and Y represents the Items to be displayed
	menu.mainMenu(tempPointer); // This function accepts the pointer value from above and decides on what to do next
	///////
	cout << "Please Enter your name: ";

	cin >> player.name;  //Gets player name

	cout << "Master " << player.name << ". What job do you want to choose next?" << endl;
	cout << "1.Swordsman" << endl << "2.Archer" << endl << "3.Deprived" << endl;
	cin >> player.job;  // Getting input from player to choose their job
	cout << "Character Info" << endl; //Displays character Info
	cout << "Name : " << player.name << endl;
	cout << "Class : ";
	switch (player.job)
	{
	case 1:
		cout << "Swordsman";
		break;
	case 2:
		cout << "Archer";
		break;
	case 3:
		cout << "Deprived";
		break;
	}

	//battleSystem();
	
	////////// TIMER COUNTDOWN SYSTEM(MAYBE USE TO KEEP THE SUSPENSE OF UPGRADING WEAPONS?
	day.CdTimer(5);
	battleSystem();
	
	// DAY NIGHT SYSTEM
	/*
	while (choice != 3) {
		system("cls");
		day.DisplayTime(); //Function to display time
		cout << endl << "2.Add 1 hour(Temp function to test day/night)";
		cin >> choice;
		day.CalculateTime(1); // Function to calculate time
		system("pause");
	}
	*/

}

int battleSystem(){
	Character player; // Players information
	Character monster;
	/////////////////// TEMPORARY DECLARATION AREA WILL BE REMOVED LATER FOR TESTING PURPOSES
	monster.hp = 100; // Lets assume its 10 for now. going to remove this line of code later
	player.setMaxAtk(10);
	player.setMinAtk(1);
	player.hp = 100;
	monster.setMaxAtk(5);
	monster.setMinAtk(0);

	///////////////////////
	//////// Simeple BATTLE SYSTEM   /////////
	system("cls");
	srand(time(nullptr));
	string test = "You have encountered a(monsters name)!\nWhat would you do?\n";
	do {																	// do while loop to enable a turn based like battle system
		choice = menu.menuSystem(2, menu.battleMenuItems,test);
		if (choice == 0) {
			player.damage = player.damageDealt();
			monster.damage = monster.damageDealt();
			monster.hp -= player.damage; //MINUSING THE MONSTERS HP
			player.hp -= monster.damage; // Monster turn to attack
			cout << "You did " << player.damage << " damage." << endl;
			cout << "The monster did " << monster.damage << " damage" << endl;
			cout << "You now have " << player.hp << " hp left" << endl;
			cout << "The monster now has " << monster.hp << "hp" << endl;
			system("pause");
			
		}
	} while (monster.hp > 0 || player.hp >0);
	return 0;
}
