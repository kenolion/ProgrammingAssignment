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
#include "ConsoleWindow.h"
#include "Shop.h"

int tempHp;
int action;
using namespace std;

int choice = 0; ////Temporary variable to store choices of player.

int main() {
	srand(time(nullptr));
	Time day;
	day.setTime(6);
	Player player;
	string name;
	Activities doableActions; //doableActions consists of all the actions you can do in the day.
	Shop shop;
	Items item[10];
	int job;

	//Menu system start from here
	///////

	cout << "Please Enter your name: ";
	cin >> name;  //Gets player name
	player.setPlayerName(name);
	Sleep(1000); //The transition combo, Sleep and CLS.
	system("cls");
	ConsoleWindow::equalSignMaker9000(80); // TYPES OUT HOW MANY EQUAL SIGNS ACCORDING TO HOW MUCH NUMBERS YOU INPUT IN THE PARAMETERS.'
	cout << "\nWelcome " << player.getCharacterName() << ". You are a male looking to make the world a better place whilst \nwanting to produce offspring with your unique skillsets.\n\nSelect a playstyle.\n" << endl;
	cout << "1.Con Man - Gets more discount from shopkeepers, able to execute more actions inthe day compared to others.\n" << endl;
	cout << "2.The Jock - Deals more damage to enemies, also has a higher chance of \nattracting a female mate." << endl << endl;
	cout << "(There are secret jobs to be picked in the game, explore the game to find out!)" << endl;
	ConsoleWindow::equalSignMaker9000(80);
	cin >> job;
	player.setJob(job);
	Sleep(1000);
	system("cls");
	ConsoleWindow::equalSignMaker9000(80);

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
	ConsoleWindow::equalSignMaker9000(80);
	system("pause");
	Sleep(1000);
	while (1) {
	do {
		system("cls");
		ConsoleWindow::equalSignMaker9000(80);
		int action;
		int a;
		cout << "Choose your action :" << endl;
		cout << "1. Go to School (6 Hours)" << endl;
		cout << "2. Go to the Gym (6 Hours)" << endl;
		cout << "3. Go Shopping (6 Hours)" << endl;
		cout << "4. Fight Crime (6 Hours)" << endl;
		cout << "5. Visit the Shop( 0 Hours)" << endl;
		day.displayTime();
		ConsoleWindow::equalSignMaker9000(80);
		cin >> action;
		system("cls");
		ConsoleWindow::equalSignMaker9000(80);
		switch (action) {
			Sleep(1000);
		case 1: {
			doableActions.school();
			day.calculateTime(6);
			break;
		}
		case 2: {
			doableActions.gym();
			day.calculateTime(6);
			break;
		}
		case 3: {
			doableActions.shopping();
			day.calculateTime(6);
			break;
		}

		case 4: {
			doableActions.fightCrime();
			day.calculateTime(6);
			break;
		}
		case 5: {
			shop.readItemDatabase();
			shop.displayItems();
			ConsoleWindow::equalSignMaker9000(80);
			system("pause");
			break;
		}
		}
		ConsoleWindow::equalSignMaker9000(80);

	} while (day.getHour() < 13);
	Sleep(1000);
	system("cls");
	Sleep(1500);
	ConsoleWindow::equalSignMaker9000(80);
	cout << "Nightfall has come. Monsters arrive in 6 hours." << endl;
	cout << "Choose your action wisely!:" << endl;
	cout << "1. Go to the pub and hit on girls. (3 Hours) " << endl;
	cout << "2. Go home and prepare against the monsters. (1 Hour)" << endl;
	cout << "3. Stay outside." << endl;
	day.displayTime();
	ConsoleWindow::equalSignMaker9000(80);
	cin >> action;
	switch (action) {
		Sleep(1000);
	case 2: { 
		day.calculateTime(1);
		doableActions.home();
		break;
	}
	}

		ConsoleWindow::equalSignMaker9000(80);
		system("pause");
	}

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
