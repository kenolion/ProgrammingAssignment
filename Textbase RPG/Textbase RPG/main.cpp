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
	int sleep = 2500;				// to control the duration of Sleep() for debugging purposes
	srand(time(nullptr));
	Time day(6,1);
	Monster monster;
	string name;
	Activities doableActions; //doableActions consists of all the actions you can do in the day.
	Shop shop;
	Weapons weapon;
	Armours armour;
	Potions potion;
	Skills skill;
	Items *weapons = &weapon;
	Items *armours = &armour;
	Items *potions = &potion;

	
	monster.readMonsterDatabase();
	weapons->readItemDatabase();
	armours->readItemDatabase();
	potions->readItemDatabase();
	
	Player player(" ", 100, 0, 100, 0, 0, 1, 2,weapon,armour,potion);			// name , int hp,int job, int money, int intel, int str,int minAtk,int maxAtk

	int job;
	////////////////////////////// TESTING ZONE
	player.addPotion(2, 0);
	unsigned int test = -5;
	cout << test;
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
	getline(cin,name);			//Gets player name
	player.setPlayerName(name);	//Sets player name
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
	player.addMoney(5);
	cout << "You are " << player.getCharacterName();
	switch (player.getJob()) {
	case 1: {
		player.addStr(5);
		player.addIntel(10);
		cout << ",The Con Man. You gained 10 Intelligence and 5 Strength.\n\n" << endl;
		break;
	}
	case 2: {
		player.addStr(10);
		player.addIntel(5);
		cout << ",The Jock. You gained 10 Strength and 5 Intelligence.\n\n" << endl << endl;
		break;

	}
			
	}
	
	ConsoleWindow::getCursorXY();
	player.showItemandStats(ConsoleWindow::x, ConsoleWindow::y);
	Sleep(sleep);
	cout << "???? : You have 12 hours before the neutral monsters arrive.\n";
	Sleep(sleep);
	cout << "???? : You will be free once your fulfillment bar is full.\n";
	Sleep(sleep);
	cout << "???? : Kill 5 Midnight Bosses and 5 Crime Bosses to fill your fulfillment Bar.\n";
	Sleep(sleep);
	cout << "???? : I don't recommend hunting for those bosses at the start\n";
	Sleep(sleep);
	cout << "???? : You'll get destroyed.\n";
	Sleep(sleep);
	cout << "???? : My advice, go for the neutral monsters at night at your home.Agent.\n";
	Sleep(sleep);
	cout << "???? : Your modified home allows you to boost your survival for the fight.\n";
	Sleep(sleep);
	cout << "???? : However, the survival boosts last for only one night.\n";
	Sleep(sleep);
	cout << "???? : Strengthen yourself at the gym, go to school for more intelligence.\n";
	Sleep(sleep);
	cout << "???? : Those are permanent upgrades.\n";
	Sleep(sleep);
	cout << "???? : Good luck, " << player.getCharacterName() << "\n";
	system("pause");
	Sleep(1000);
	while (Game::midnightBosses!= 0 && Game::morningBosses!=0) {
		do {
			system("cls");
			player.showItemandStats(0, 0);
			ConsoleWindow::equalSignMaker9000(80);
			int action;
			int a;
			cout << "Choose your action :" << endl;
			cout << "1. Go to School (6 Hours)" << endl;
			cout << "2. Go to the Gym (6 Hours)" << endl;
			cout << "3. Go to work at McDonalds (6 Hours)" << endl;
			cout << "4. Hunt Crime Bosses ( " << Game::morningBosses <<" Crime Bosses Left) (6 Hours)" << endl;
			cout << "5. Visit the Shop( 0 Hours)" << endl;
			day.displayTime();
			ConsoleWindow::equalSignMaker9000(80);
			cin >> action;
			system("cls");
			player.showItemandStats(0, 0);
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

				doableActions.fightCrime(&player, monster);	// NEEDS TO ADD MONEY GAIN AFTER KILLING SOMEONE
				day.calculateTime(6);
				break;
			}
			case 5: {
				while (action != 4) {
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
						shop.displayWeapon(weapon, &player);
						system("cls");
						player.showItemandStats(0, 0);
						break;
					case 2:
						shop.displayArmour(armour, &player);
						system("cls");
						player.showItemandStats(0, 0);
						break;
					case 3:
						shop.displayPotions(potion, &player);
						system("cls");
						player.showItemandStats(0, 0);
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
		player.showItemandStats(0, 0);
		Sleep(1500);
		ConsoleWindow::equalSignMaker9000(80);
		cout << "Nightfall has come. Monsters arrive in 6 hours." << endl;
		cout << "Choose your action wisely!:" << endl;
		cout << "1. Go to the pub and hit on girls. (3 Hours) " << endl;
		cout << "2. Go home and farm neutral monsters. (1 Hour Journey)" << endl;
		cout << "3. Stay outside and hunt for rare boss monsters. ( "<< Game::midnightBosses <<" Midnight Bosses Left )" << endl;
		day.displayTime();
		ConsoleWindow::equalSignMaker9000(80);
		cin >> action;
		switch (action) {
			Sleep(1000);
		case 1: {
			//Ben's Harem System
		}
		case 2: {
			system("cls");
			day.calculateTime(1);
			doableActions.home(&player, monster);
			break;
		}
		case 3: {
			doableActions.randEvents(&player, monster);
		}

		}
	}

	ConsoleWindow::equalSignMaker9000(80);
	cout << "You won the game, Congratulations!\n";
	cout << "You have beaten this game in" << day.getDay() << "days!";
	cout << "Try to beat this game in lesser days!\n";
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

