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
#include "Activities.h"

int battleSystem();
int tempHp;
using namespace std;




int choice = 0; ////Temporary variable to store choices of player.

int main() {
	Time day;
	Player player;
	string name;

	//Menu system start from here
	///////
	battleSystem();
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
	monster.setHp(100); // Lets assume its 100 for now. going to remove this line of code later
	player.setHp(100);
	///////////////////////
	//////// Simeple BATTLE SYSTEM   /////////
	
	system("cls");
	srand(time(nullptr));
	
	do {										// do while loop to enable a turn based like battle system
		cout << "You encountered a !\n";
		cout << "What do you want to do?\n1.Attack\n2.NIGERO(run)\n";
		cout << "=================================================================\n";
		switch(choice) {
		case 0: {
			cout << "\n\n\n\n\n";
			break;
		}
		case 1:{
			monster.setMaxAtk(5);
			monster.setMinAtk(0);
			player.setMaxAtk(10);
			player.setMinAtk(1);
			player.damage = player.attack();
			monster.damage = monster.attack();
			monster.setHp(monster.getHp() - player.damage); //MINUSING THE MONSTERS HP
			player.setHp(player.getHp() - monster.damage); // Monster turn to attack
			cout << "You did " << player.damage << " damage." << endl;
			cout << "The monster did " << monster.damage << " damage" << endl;
			cout << "You now have " << player.getHp() << " hp left" << endl;
			cout << "The monster now has " << monster.getHp() << "hp\n" << endl;
			break;
		}
		case 2: {


		}
		}
		cout << "=================================================================\n";
		cout << "Command:";
		while (!(cin >> choice)) {
			cout << "Incorrect input. Please try again.\n";
			cin.clear();
			cin.ignore(100, '\n');
		}
		system("cls");
	} while (player.getHp() >0 || monster.getHp()>0);
	return 0;
}

