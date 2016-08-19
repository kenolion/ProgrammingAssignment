/*
Everyday Quest with Waifus and Monsters simulator 2016 #Swag
C++ Programming Assignment
Text Based RPG Game
By : Keith, Ben and Zer
Date : 10/6/2016
*/
#define NOMINMAX
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
#include "Game.h"
#include "Weapons.h"
#include "Armours.h"
int tempHp;
int action;
using namespace std;

int choice = 0; ////Temporary variable to store choices of player.

int main() {
	srand(time(nullptr));
	Time day(6,1);
	Player player;
	Monster monster;
	string name;
	Activities doableActions; //doableActions consists of all the actions you can do in the day.
	Shop shop;
	Weapons weapon;
	Armours armour;
	Items *weapons = &weapon;
	Items *armours = &armour;
	weapons->readItemDatabase();
	armours->readItemDatabase();
	int job;

	//Menu system start from here
	///////
	Sleep(2500);
	cout << "???? : Agent 13324.\n";
	Sleep(2500);
	cout << "*Project Agent 13324 Initiated.*\n";
	Sleep(2500);
	cout << "???? : Wake up. Slumber time is over.\n";
	Sleep(2500);
	cout << "???? : Agent 13324. The world is at stake.\n";
	Sleep(2500);
	cout << "???? : Decide a public alias for yourself, Agent 13324.\n";
	Sleep(2500);
	cout << "???? : I am no babysitter, and certainly not your mother, so do it.\n\n";
	Sleep(2500);
	cout << "Please Enter your name: ";
	getline(cin,name);  //Gets player name
	player.setPlayerName(name);
	Sleep(2500);
	system("cls");
	cout << "???? : So, '" << player.getCharacterName() << "'. Huh? Can't say I like your decision for that name.\n";
	Sleep(2500);
	cout << "???? : " << player.getCharacterName() << ", Listen, I don't have much time.\n";
	Sleep(2500);
	cout << "???? : The world is not in a healthy state right now\n\n\n";
	Sleep(2500);
	cout << "*PROFESSION SELECTION, ONLINE.*\n";
	Sleep(2500);
	ConsoleWindow::equalSignMaker9000(80);
	cout << "1.Con Man - Gets more discount from shopkeepers, able to execute more actions inthe day compared to others.\n" << endl;
	cout << "2.The Jock - Deals more damage to enemies, also has a higher chance of \nattracting a female mate." << endl << endl;
	cout << "(There are secret jobs to be picked in the game, explore the game to find out!)" << endl;
	ConsoleWindow::equalSignMaker9000(80);
	while (!(cin >> job) || job <1 || job >1) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Enter 1 or 2 to choose your job\n";
	}
	player.setJob(job);
	Sleep(1000);
	Game::showItemandStats();
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
	
	Sleep(2500);
	cout << " ???? : You have 12 hours before the monsters arrive.\n";
	Sleep(2500);
	cout << " ???? : Spend your time wisely, Agent 13324.\n";
	Sleep(2500);
	system("pause");
	Sleep(1000);
	while (1) {
		do {
			Game::showItemandStats();
			ConsoleWindow::equalSignMaker9000(80);
			int action;
			int a;
			cout << "Choose your action :" << endl;
			cout << "1. Go to School (6 Hours)" << endl;
			cout << "2. Go to the Gym (6 Hours)" << endl;
			cout << "3. Go to work at McDonalds (6 Hours)" << endl;
			cout << "4. Fight Crime (6 Hours)" << endl;
			cout << "5. Visit the Shop( 0 Hours)" << endl;
			day.displayTime();
			ConsoleWindow::equalSignMaker9000(80);
			cin >> action;
			Game::showItemandStats();
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
				doableActions.work();
				day.calculateTime(6);
				break;
			}

			case 4: {
				doableActions.fightCrime();
				day.calculateTime(6);
				break;
			}
			case 5: {
				while(action != 3){
				cout << "1.Buy weapons\n";
				cout << "2.Buy armours\n";
				cout << "3.Exit Shop\n";
				cin >> action;
					switch (action) {
					case 1:
						shop.displayWeapon(weapon);
						system("pause");
						Game::showItemandStats();
						break;
					case 2:
						shop.displayArmour(armour);
						system("pause");
						Game::showItemandStats();
						break;
				}
				}
				ConsoleWindow::equalSignMaker9000(80);
				system("pause");
				break;
			}
			}

		} while (Time::getHour() < 13);

		Sleep(1000);
		Game::showItemandStats();
		Sleep(1500);
		ConsoleWindow::equalSignMaker9000(80);
		cout << "Nightfall has come. Monsters arrive in 6 hours." << endl;
		cout << "Choose your action wisely!:" << endl;
		cout << "1. Go to the pub and hit on girls. (3 Hours) " << endl;
		cout << "2. Go home and prepare against the monsters. (1 Hour)" << endl;
		cout << "3. Stay outside and hunt for rare monsters." << endl;
		day.displayTime();
		ConsoleWindow::equalSignMaker9000(80);
		cin >> action;
		switch (action) {
			Sleep(1000);
		case 1: {
			//Ben's Harem System
		}
		case 2: {
			day.calculateTime(1);
			doableActions.home();
			break;
		}
		case 3: {
			doableActions.randEvents();
		}

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

