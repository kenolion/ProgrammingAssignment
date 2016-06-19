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
#include "Menu.h"
int battleSystem();
int tempPointer1,tempPointer2,tempCount; // used for storing temporary values
using namespace std;


class Character {
public:
	char name[15];
	int job; //1=Swordsman,2= Archer, 3= Deprived(not an actual class just decided to put it there in the mean time)
	int hp;
	int minAtk;
	int maxAtk;
	int damageDealt;
	int str;
	int energy;
	int intell;
	int weaboo;
};


int choice = 99; ////Temporary variable to store choices of player.

int main() {
	Time day;
	Character player;
	Menu menu;
	string name = "This is the keyboard input menu\n";
	int alphabet=97;
	
	for (int r = 0; r < 5;r++) {
		for (int c = 0; c < 6;c++) {
			menu.alphabetSelection[r][c] = alphabet++;
		}
		
	}
	// display name each time i hit Z 
	for (tempCount = 0; tempCount < 5;) {
	menu.menuSystem(5, 6, menu.alphabetSelection, name, &tempPointer1, &tempPointer2);
		if (GetAsyncKeyState(0x5A)) {

			player.name[tempCount] = menu.alphabetSelection[tempPointer1][tempPointer2];
			tempCount++;
			cout << player.name;
			
		}
	}
	


	system("pause");
	return 0;
	
	//Menu system start from here
	/*
	string welcome = "Welcome to a Text based RPG game!\n";
	choice = menu.menuSystem(3, menu.mainMenuItems, welcome); // This calls the menu system function (x,y) X represents the number of list in the menu and Y represents the Items to be displayed
	
	///////
	switch (choice) {
	case 0: {
		cout << "Starting game...\n";
		break;
	}
	case 1: {
		cout << "This is the options\n";
		break;
	}
	case 2:
		exit(0);
	}
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
	day.CdTimer(5);// the parameter is in seconds so this countsdown is 5 second
	
	// DAY NIGHT SYSTEM

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
	Menu menu;
	/////////////////// TEMPORARY DECLARATION AREA WILL BE REMOVED LATER FOR TESTING PURPOSES
	monster.hp = 100; // Lets assume its 10 for now. going to remove this line of code later
	player.maxAtk = 10;
	player.minAtk = 1;
	player.hp = 100;
	monster.maxAtk = 5;
	monster.minAtk = 0;

	///////////////////////
	//////// Simeple BATTLE SYSTEM   /////////
	system("cls");
	srand(time(NULL));
	string test = "You have encountered a(monsters name)!\nWhat would you do?\n";
	do {																	// do while loop to enable a turn based like battle system
		menu.menuSystem(2,0, menu.battleMenuItems,test,&tempPointer1,&tempPointer2); //First parameter is to display how many list you want to show in this case its 2 because theres only attack and run for now.
		choice = tempPointer1;
		if (choice == 0) {										//Second parameter is to pass in an array of string that list out the contents of the menu in this case we want to pass in the string in battlemenuitems and lastly that parameter is to display any text you want in your menu that is not selectable by player
			player.damageDealt = rand() % player.maxAtk + player.minAtk; // CALCULATING THE ATTACK RANGE
			monster.damageDealt = rand() % monster.maxAtk + monster.minAtk; // calculating monster attack
			monster.hp -= player.damageDealt; //MINUSING THE MONSTERS HP
			player.hp -= monster.damageDealt; // Monster turn to attack
			cout << "You did " << player.damageDealt << " damage." << endl;
			cout << "The monster did " << monster.damageDealt << " damage" << endl;
			cout << "You now have " << player.hp << " hp left" << endl;
			cout << "The monster now has " << monster.hp << "hp" << endl;
			Sleep(2000);
			system("cls");
		}
	} while (monster.hp > 0 || player.hp >0);
	return 0;
}
