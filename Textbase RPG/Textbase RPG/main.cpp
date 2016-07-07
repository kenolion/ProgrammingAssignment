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
#include "Player.h"
#include "Monster.h"
int battleSystem();
int tempPointer;
using namespace std;


int choice = 99; ////Temporary variable to store choices of player.

int main() {
	Time day;
	Player player;
	string name;

	//Menu system start from here
	///////
	cout << "Please Enter your name: ";
	cin >> name;  //Gets player name
	player.setPlayerName(name);

	cout << "Master " << player.getCharacterName() << ". What job do you want to choose next?" << endl;
	cout << "1.Swordsman" << endl << "2.Archer" << endl << "3.Deprived" << endl;
	//cin >> player.job;  // Getting input from player to choose their job
	cout << "Character Info" << endl; //Displays character Info
	cout << "Name : " << player.getCharacterName() << endl;
	cout << "Class : ";
	/*
	switch (player.job)
	{
	case 1:
		cout << "Nerd"; //Higher int
		break;
	case 2:
		cout << "Athletic"; //Higher str
		break;
	case 3:
		cout << "Otaku";			// Higher stats ?
		break;
	}
	*/

	cout << "RING RING\n";
	cout << "RING RING\n You open your eyes slowly as if they were glued together.\n RING RING\n. Huh?";
	
	

	//battleSystem();
	
	////////// TIMER COUNTDOWN SYSTEM(MAYBE USE TO KEEP THE SUSPENSE OF UPGRADING WEAPONS?
	day.cdTimer(5);
	battleSystem();
	
	// DAY NIGHT SYSTEM
	/*
	while (choice != 3) {
		system("cls");
		day.displayTime(); //Function to display time
		cout << endl << "2.Add 1 hour(Temp function to test day/night)";
		cin >> choice;
		day.CalculateTime(1); // Function to calculate time
		system("pause");
	}
	*/

}

int battleSystem(){
	Player player; // Players information
	Monster monster;
	/////////////////// TEMPORARY DECLARATION AREA WILL BE REMOVED LATER FOR TESTING PURPOSES
	monster.setHp(100); // Lets assume its 10 for now. going to remove this line of code later
	monster.setMaxAtk(5);
	monster.setMinAtk(0);
	player.setMaxAtk(10);
	player.setMinAtk(1);
	player.setHp(100);
	int tempHp=0;

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
		switch(choice) {
		case 1:{
			player.damage = player.attack();
			monster.damage = monster.attack();
			monster.setHp(monster.getHp() - player.damage); //MINUSING THE MONSTERS HP
			player.setHp(player.getHp() - monster.damage); // Monster turn to attack
			cout << "You did " << player.damage << " damage." << endl;
			cout << "The monster did " << monster.damage << " damage" << endl;
			cout << "You now have " << player.getHp() << " hp left" << endl;
			cout << "The monster now has " << monster.getHp() << "hp" << endl;
			system("pause");
			system("cls");
			break;
		}
		case 2: {


		}
		}
	} while (player.getHp() >0 || monster.getHp()>0);
	return 0;
}
