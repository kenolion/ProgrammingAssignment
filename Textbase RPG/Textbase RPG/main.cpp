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
#include "Skills.h"
int tempHp;
int action;
using namespace std;

int choice = 0; ////Temporary variable to store choices of player.

int main() {
	int sleep = 0;				// to control the duration of Sleep() for debugging purposes
	srand(time(nullptr));
	Time day(6,1);
	Player player(" ", 100, 0, 0, 0, 0, 1, 2);			// name , int hp,int job, int money, int intel, int str,int minAtk,int maxAtk
	Monster monster;
	string name;
	Activities doableActions; //doableActions consists of all the actions you can do in the day.
	Shop shop;
	Weapons weapon;
	Armours armour;
	Potions potion;
	Skills skills;

	Items *weapons = &weapon;
	Items *armours = &armour;
	Items *potions = &potion;
	
	monster.readMonsterDatabase();
	weapons->readItemDatabase();
	armours->readItemDatabase();
	potions->readItemDatabase();
	skills.readSkillsDatabase();


	int job;
	////////////////////////////// TESTING ZONE


	/////////////////////
	//Menu system start from here
	///////
	Sleep(sleep);
	cout << "???? : Agent 1447.\n";
	Sleep(sleep);
	cout << "*Project Agent 1447 Initiated.*\n";
	Sleep(sleep);
	cout << "???? : Wake up. Slumber time is over.\n";
	Sleep(sleep);
	cout << "???? : Agent 1447. The world is at stake.\n";
	Sleep(sleep);
	cout << "???? : Decide a public alias for yourself, Agent 1447.\n";
	Sleep(sleep);
	cout << "???? : I am no babysitter, and certainly not your mother, so do it.\n\n\n";
	Sleep(sleep);
	cout << "Please Enter your name: ";
	getline(cin,name);  //Gets player name
	player.setPlayerName(name);
	Sleep(sleep);
	system("cls");
	cout << "???? : So, '" << player.getCharacterName() << "'. Huh? Can't say I like your decision for that name.\n";
	Sleep(sleep);
	cout << "???? : " << player.getCharacterName() << ", Listen, I don't have much time.\n";
	Sleep(sleep);
	cout << "???? : The world is not in a healthy state right now, choose quickly.\n\n\n";
	Sleep(sleep);
	cout << "*PROFESSION SELECTION, ONLINE.*\n";
	Sleep(sleep);
	ConsoleWindow::equalSignMaker9000(80);
	cout << "1.Con Man - Notable skills include\n-'YOU ACTIVATED MY TRAP CARD' (70 DAMAGE, 30 MANACOST)\n-'NECK BREAKER' (300 DAMAGE, 50 MANACOST)\n" << endl;
	cout << "2.The Jock - Notable skills include \n-'MUSCLE BODY SLAM' (200 DAMAGE, 70 MANACOST).\n-'MUSCLE UPPERCUT' (30 DAMAGE, 10 MANACOST)\n" << endl << endl;

	ConsoleWindow::equalSignMaker9000(80);
	while (!(cin >> job) || job <1 || job >2) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Enter 1 or 2 to choose your job\n";
	}
	player.setJob(job);
	Sleep(1000);
	system("cls");

	ConsoleWindow::equalSignMaker9000(80);

	//GIVEPOTION NOT WORKING
	potion.givePotion(0, 5); // Gives five normal potions
	potion.givePotion(1, 1); // Gives one strong potion

	player.addMoney(5);
	switch (player.getJob()) {
	case 1: {
		player.addStr(5);
		player.addIntel(10);
		ConsoleWindow::getCursorXY();
		player.showItemandStats(weapon, armour, ConsoleWindow::x, ConsoleWindow::y);
		cout << "You are " << player.getCharacterName();
		cout << ",The Con Man. You gained 10 Intelligence and 5 Strength.\n\n" << endl;
		break;
	}
	case 2: {

		player.addStr(10);
		player.addIntel(5);
		ConsoleWindow::getCursorXY();
		player.showItemandStats(weapon, armour, ConsoleWindow::x, ConsoleWindow::y);
		cout << "You are " << player.getCharacterName();
		cout << ",The Jock. You gained 10 Strength and 5 Intelligence.\n\n" << endl << endl;
		break;

	}
	}
	
	Sleep(sleep);
	cout << "???? : You have 12 hours before the monsters arrive.\n";
	Sleep(sleep);
	cout << "???? : Spend your time wisely, Agent 1447.\n\n";
	Sleep(sleep);
	system("pause");
	Sleep(1000);
	while (1) {
		do {
			system("cls");
			player.showItemandStats(weapon, armour,0,0);
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
			system("cls");
			player.showItemandStats(weapon, armour,0,0);
			ConsoleWindow::equalSignMaker9000(80);
			switch (action) {
				Sleep(1000);
			case 1: {
				doableActions.school();
				player.addIntel(2);
				day.calculateTime(6);
				break;
			}
			case 2: {
				doableActions.gym();
				player.addStr(2);
				day.calculateTime(6);
				break;
			}
			case 3: {
				doableActions.work();
				player.addMoney(5);
				day.calculateTime(6);
				break;
			}

			case 4: {

				doableActions.fightCrime(&potion,&player,weapon,armour,monster);	// NEEDS TO ADD MONEY GAIN AFTER KILLING SOMEONE
				day.calculateTime(6);
				break;
			}
			case 5: {
				while(action != 4){
					ConsoleWindow::SetDrawingPoint(0, 0);
					ConsoleWindow::equalSignMaker9000(80);
					ConsoleWindow::SetDrawingPoint(0, 5);
					ConsoleWindow::equalSignMaker9000(80);
					ConsoleWindow::SetDrawingPoint(0, 1);
				cout << "1.Buy weapons\n";
				cout << "2.Buy armours\n";
				cout << "3.Buy potions\n";
				cout << "4.Exit Shop\n";
				ConsoleWindow::SetDrawingPoint(0, 6);
				cin >> action;
					switch (action) {
					case 1:
						shop.displayWeapon(weapon);
						system("pause");
						system("cls");
						player.showItemandStats(weapon, armour,0,0);
						break;
					case 2:
						shop.displayArmour(armour);
						system("pause");
						system("cls");
						player.showItemandStats(weapon, armour,0,0);
						break;
					case 3:
						shop.displayPotions(potion);
						system("pause");
						system("cls");
						player.showItemandStats(weapon, armour, 0, 0);
						break;
					case 4:
					{
						action = 4;
					}
				}
				}
				ConsoleWindow::equalSignMaker9000(80);
		
				break;
			}
			}

		} while (Time::getHour() < 13);

		Sleep(1000);
		system("cls");
		player.showItemandStats(weapon, armour,0,0);
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
			doableActions.home(&potion ,&player, weapon, armour, monster);
			break;
		}
		case 3: {
			doableActions.randEvents(&potion,&player,weapon,armour,monster);
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

