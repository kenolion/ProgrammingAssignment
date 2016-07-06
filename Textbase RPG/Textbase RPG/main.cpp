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

int main() {
	Time day;
	Character player;
	string name;

	//Menu system start from here
	///////
	cout << "Please Enter your name: ";

	cin >> name;  //Gets player name
	player.setPlayerName(name);

	cout << "Master " << player.getPlayerName() << ". What job do you want to choose next?" << endl;
	cout << "1.Swordsman" << endl << "2.Archer" << endl << "3.Deprived" << endl;
	cin >> player.job;  // Getting input from player to choose their job
	cout << "Character Info" << endl; //Displays character Info
	cout << "Name : " << player.getPlayerName() << endl;
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
	cout << "You encountered a !\n";
	do {										// do while loop to enable a turn based like battle system
		cout << "What do you want to do?\n1.Attack\n2.NIGERO(run)";
		while (!(cin >> choice)) {
			cout << "Incorrect input. Please try again.\n";
			cin.clear();
			cin.ignore(100, '\n');
		}
		if (choice == 1) {
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
