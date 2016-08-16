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
		system("cls");

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

			system("cls");
		} 
		Time::calculateTime(6);
	}

void Game::showItemandStats()
{
	ConsoleWindow::SetDrawingPoint(0,0);
	system("cls");

}
