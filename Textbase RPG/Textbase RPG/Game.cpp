#include "Game.h"
#include "Potions.h"
#include <cstdlib>
using namespace std;


Game::Game()
{
}


Game::~Game()
{
}

void Game::timeDISPLAY9000()
{
	ConsoleWindow::SetDrawingPoint(26, 20);
	ConsoleWindow::CIRCLEMAKER9000();
}


int Game::battleSystem(Potions *potion, Player *player, Weapons weapon, Armours armour, Monster monster, int monsterID) {

	monster.characterVector[monsterID].characterID = monsterID;
	system("cls");
	int choice = 0;
	player->showItemandStats(weapon, armour, 0, 0);


	while (monster.getHp(monsterID - 1) > 0 && player->getHp() > 0) {// do while loop to enable a turn based like battle system
		ConsoleWindow::equalSignMaker9000(80);
		cout << "You encountered a" << monster.characterVector[monsterID - 1].characterName << endl;
		cout << "What do you want to do?\n1.Attack\n2.NIGERO(Run)\n3.Potion\n";
		ConsoleWindow::equalSignMaker9000(80);
		monster.damage = monster.attack(monsterID - 1);

		switch (choice) {
		case 0: {
			cout << "\n\n\n\n\n";
			break;
		}
		case 1: {

			player->damage = player->attack();
			monster.characterVector[monsterID - 1].hp -= player->damage; //MINUSING THE MONSTERS HP

			cout << "You did " << player->damage << " damage." << endl;
			Sleep(1000);

			if (monster.getHp(monsterID - 1) > 0)
			{
				player->setHp(player->getHp() - monster.damage); // Monster turn to attack
				cout << "The monster did " << monster.damage << " damage" << endl;
				Sleep(1000);

				if (player->getHp() <= 0)
				{
					cout << "You died. Game over.\n";
					Sleep(3000);
					exit(1);
				}

			}
			else {
				Sleep(1000);
				cout << monster.characterVector[monsterID - 1].characterName << " died." << endl;
				Player player;
				Sleep(1000);
				cout << "You gained " << monster.characterVector[monsterID - 1].money << " muneys.\n";
				player.addMoney(monster.characterVector[monsterID - 1].money);
				Sleep(1000);
				system("cls");
				break;
			}



			if (monster.getHp() > 0) {

				cout << "You now have " << player->getHp() << " hp left" << endl;
				cout << "The monster now has " << monster.getHp(monsterID - 1) << "hp\n" << endl;

			}
			ConsoleWindow::equalSignMaker9000(80);
			cout << "Command:";
			cout << endl << endl;
			break;
		}
		case 2: {
			Sleep(1000);
			cout << "You attempt to run away.\n";
			int randNum;
			randNum = rand() % 100 + 0; // 0+100 
			if (randNum <= 30) //30% chance for the player to escapee
			{
				Sleep(1000);
				cout << "You successfully managed to get away!\n";
				Sleep(1000);
				system("cls");

				return 0;
			}
			else
			{
				Sleep(1000);

				cout << "The enemy managed to catch up to you!\n";

				player->setHp(player->getHp() - monster.damage); // Monster turn to attack
				cout << "The monster did " << monster.damage << " damage" << endl;
				Sleep(1000);
				if (player->getHp() <= 0)
				{
					cout << "You died. Game over.\n";
					Sleep(3000);
					exit(1);
				}
				
			}
			ConsoleWindow::equalSignMaker9000(80);
			cout << "Command:";
			cout << endl << endl;
			break;
		}

		case 3: {
			int selection = 0;
				int c = 10;
				int b = 10;
			

				cout << "\nPick your potion to consume :\n\n";
				//BOX DRAWING
				ConsoleWindow::SetDrawingPoint(0, 9);
				for (int i = 0; i <= 25; i++) { cout << "_"; } //Top line of the box
				for (int i = 0; i <= 3; i++) { ConsoleWindow::SetDrawingPoint(0, c); cout << "|"; c++; } // Left horizontal line of the box
				for (int i = 0; i <= 3; i++) { ConsoleWindow::SetDrawingPoint(25, b); cout << "|"; b++; } // Right horizontal line of the box
				ConsoleWindow::SetDrawingPoint(0, 13);
				for (int i = 0; i <= 25; i++) { cout << "¯"; } //Bottom line of the box
				//BOX DRAWING

				//INTERNAL DATA DRAWING.
				ConsoleWindow::SetDrawingPoint(1, 10);
				cout << potion->potionVector[0].itemId << potion->potionVector[0].name << " x " << potion->potionVector[0].potionQuantity << endl;
				ConsoleWindow::SetDrawingPoint(1, 11);
				cout << potion->potionVector[1].itemId << potion->potionVector[1].name << " x " << potion->potionVector[1].potionQuantity << endl;
				ConsoleWindow::SetDrawingPoint(1, 12);
				cout << potion->potionVector[2].itemId << potion->potionVector[2].name << " x " << potion->potionVector[2].potionQuantity << endl;
				cout << "\n\nPotion choice (Number) : ";
				cin >> selection;
				potion->potionVector[selection - 1].potionQuantity -= 1;
				potion->quantity -= 1;

				if (potion->potionVector[selection - 1].potionQuantity < 0)
				{
					cout << "You're out of " << potion->potionVector[selection - 1].name << "s!\n\n";
					potion->potionVector[selection - 1].potionQuantity += 1;
					potion->quantity += 1;
				}
				else{
					Sleep(1000);
					cout << "You used :" << potion->potionVector[selection - 1].name << "!\n";
					cout << "Player HP + " << potion->potionVector[selection - 1].potionHeal << "!\n\n";
					player->setHp(player->getHp() + 20);
				}

				Sleep(1000);
				ConsoleWindow::equalSignMaker9000(80);
				cout << "Command(Attack, Run or Potion):";
				cout << endl << endl;
				break;
			}
			
		
		}

		while (!(cin >> choice)) {
			cout << "Incorrect input. Please try again.\n";
			cin.clear();
			cin.ignore(100, '\n');
		}
		ConsoleWindow::equalSignMaker9000(80);
		system("cls");
	}

	player->showItemandStats(weapon, armour, 0, 0);
	Time::calculateTime(6);
}

		


	