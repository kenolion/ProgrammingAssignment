#include "Game.h"
#include <iostream>
#include "Player.h"
#include "Monster.h"
#include "ConsoleWindow.h"
#include "Time.h"
#include <windows.h>// to use the function sleep
using namespace std;


Game::Game()
{
}


Game::~Game()
{
}


void Game::battleSystem() {
	Player player;
	Monster monster;
		/////////////////// TEMPORARY DECLARATION AREA WILL BE REMOVED LATER FOR TESTING PURPOSES
		// Lets assume its 100 for now. going to remove this line of code later
		player.setHp(100);
		monster.setHp(100);
		///////////////////////
		//////// Simeple BATTLE SYSTEM   /////////
		int choice = 0;
		Game::showItemandStats();

		ConsoleWindow::equalSignMaker9000(80);
		while (monster.getHp()>0 && player.getHp() >0) {										// do while loop to enable a turn based like battle system
			cout << "You encountered a !\n";
			cout << "What do you want to do?\n1.Attack\n2.NIGERO(Run)\n";
			cout << "=================================================================\n";
			switch (choice) {
			case 0: {
				cout << "\n\n\n\n\n";
				break;
			}
			case 1: {
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
				if (monster.getHp() > 0 && player.getHp() > 0) {
					cout << "You now have " << player.getHp() << " hp left" << endl;
					cout << "The monster now has " << monster.getHp() << "hp\n" << endl;
				}
				break;
			}
			case 2: {


			}
			}
			cout << "=================================================================\n";
			cout << "Command:";
			cout << endl << endl;
			ConsoleWindow::equalSignMaker9000(80);
			while (!(cin >> choice)) {
				cout << "Incorrect input. Please try again.\n";
				cin.clear();
				cin.ignore(100, '\n');
			}

			Game::showItemandStats();
		} 
		Time::calculateTime(6);
	}

void Game::showItemandStats()
{
	system("cls");
	int c = 21;
	int d = 21;
	ConsoleWindow::SetDrawingPoint(1,20);
	for (int i = 0; i <= 30; i++) { cout << "_"; } //Top line of the box
	ConsoleWindow::SetDrawingPoint(1, 21);
	for (int i = 0; i <= 14; i++) { ConsoleWindow::SetDrawingPoint(1, c); cout << "|"; c++; } // Left horizontal line of the box
	ConsoleWindow::SetDrawingPoint(31, 21);
	for (int i = 0; i <= 14; i++) { ConsoleWindow::SetDrawingPoint(31, d); cout << "|"; d++; }; //Right horizontal line of the box
	ConsoleWindow::SetDrawingPoint(1, 35);
	for (int i = 0; i <= 30; i++) { cout << "¯"; } //Bottom line of the box
	ConsoleWindow::SetDrawingPoint(2, 22); // Line 1 in the box
	cout << "STATS";
	ConsoleWindow::SetDrawingPoint(2, 23); // Line 2 in the box
	cout << "Strength : 5";
	ConsoleWindow::SetDrawingPoint(2, 24); // and etc.
	cout << "Intelligence : 10";
	ConsoleWindow::SetDrawingPoint(2, 27);
	cout << "WEAPON EQUIPPED";
	ConsoleWindow::SetDrawingPoint(2, 28);
	cout << "Steel Shortsword";
	ConsoleWindow::SetDrawingPoint(2, 30);
	cout << "ARMOR EQUIPPED";
	ConsoleWindow::SetDrawingPoint(2, 31);
	cout << "Pajamas";
	ConsoleWindow::SetDrawingPoint(0, 0);
}
