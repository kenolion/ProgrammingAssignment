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

void equalSignMaker9000(int eqCount) // COUT'S EQUAL SIGNS
{
	for (int a = 0; a < eqCount; a++)
	{
		cout << "=";
	}
}

int main() {
	srand(time(nullptr));
	Time day;
	Player player;
	string name;
	Activities doableActions; //doableActions consists of all the actions you can do in the day.
	int job;

	//Menu system start from here
	///////
	cout << "Please Enter your name: ";
	cin >> name;  //Gets player name
	player.setPlayerName(name);
	Sleep(1000); //The transition combo, Sleep and CLS.
	system("cls");
	equalSignMaker9000(80); // TYPES OUT HOW MANY EQUAL SIGNS ACCORDING TO HOW MUCH NUMBERS YOU INPUT IN THE PARAMETERS.'
	
	cout << "\nWelcome " << player.getCharacterName() << ". You are a male looking to make the world a better place whilst \nwanting to produce offspring with your unique skillsets.\n\nSelect a playstyle.\n" << endl;
	cout << "1.Con Man - Gets more discount from shopkeepers, able to execute more actions inthe day compared to others.\n" << endl;
	cout << "2.The Jock - Deals more damage to enemies, also has a higher chance of \nattracting a female mate." << endl << endl;
	cout << "(There are secret jobs to be picked in the game, explore the game to find out!)" << endl;
	equalSignMaker9000(80);
	cin >> job;
	player.setJob(job);
	Sleep(1000);
	system("cls");
	equalSignMaker9000(80);
	cout << "You are " << player.getCharacterName();

	switch (player.getJob()) {
	case 1: {
		cout << ",The Con Man. You gained 10 Intelligence and 5 Strength.\n\n" << endl;
		break;
	}
	case 2: {

		cout << ",The Jock. You gained 10 Strength and 5 Intelligence.\n\n" << endl << endl;
		break;
	}
	}
	cout << "***You have 12 hours before nightfall comes. Spend your time wisely.***" << endl;
	equalSignMaker9000(80);
	system("pause");
	Sleep(1000);
	do {
		system("cls");
		equalSignMaker9000(80);
		int action;
		int a;
		cout << "Choose your action :" << endl;
		cout << "1. Go to School (6 Hours)" << endl;
		cout << "2. Go to the Gym (6 Hours)" << endl;
		cout << "3. Go Shopping (6 Hours)" << endl;
		cout << "4. Fight Crime (6 Hours)" << endl;
		day.displayTime();
		equalSignMaker9000(80);
		cin >> action;

		switch (action) {
		Sleep(1000);
		case 1: {
			doableActions.school();
			break;
		}
		case 2: {
			doableActions.gym();
			break;
		}
		case 3: {
			doableActions.shopping();
			break;
		}
		
		case 4: {
			doableActions.fightCrime();
			break;
		}
		}
		equalSignMaker9000(80);
		day.calculateTime(6);
	} while (day.getHour() < 13);
	Sleep(1000);
	system("cls");
	Sleep(1500);
	equalSignMaker9000(80);
	cout << "Nightfall has come. Monsters arrive in 6 hours." << endl;
	cout << "Choose your action wisely!:" << endl;
	cout << "1. Go to the pub and hit on girls. (3 Hours) " << endl;
	cout << "2. Go home and prepare against the monsters. (1 Hour)"  << endl;
	cout << "3. Stay outside." << endl;
	day.displayTime();
	equalSignMaker9000(80);
	system("pause");
	//cin >> player.job;  // Getting input from player to choose their job

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



	//battleSystem();

	////////// TIMER COUNTDOWN SYSTEM(MAYBE USE TO KEEP THE SUSPENSE OF UPGRADING WEAPONS?


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

