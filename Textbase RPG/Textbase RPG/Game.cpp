#include "Game.h"
#include "Potions.h"
#include <cstdlib>
#include "Character.h"
using namespace std;
int Game::bossesLeft = 10;

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


int Game::battleSystem(Player *player, Monster monster, int monsterID) {

	monster.characterVector[monsterID].characterID = monsterID;
	system("cls");
	int choice = 0;
	player->showItemandStats( 0, 0);


	while (monster.getHp(monsterID - 1) > 0 && player->getHp() > 0) {// do while loop to enable a turn based like battle system
		ConsoleWindow::equalSignMaker9000(80);
		cout << "You encountered a" << monster.characterVector[monsterID - 1].characterName << endl;
		cout << "What do you want to do?\n1.Attack\n2.NIGERO(Run)\n3.Potion\n4.Skills\n";
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
				// EDITED BY KEITH
				player->showPotions();
				cout << "\n\nPotion choice (Number) : ";
				cin >> selection;
				player->addPotion(-1, selection-1);

				if (player->getPotionQuantity(selection-1) < 0)
				{
					cout << "You're out of " << player->getPotionName(selection-1) << "s!\n\n";
					player->addPotion(1, selection - 1);
				}

				else{
					Sleep(1000);
					cout << "You used :" << player->getPotionName(selection-1)<< "!\n";
					cout << "Player HP + " << player->getPotionHeal(selection-1) << "!\n\n";
					player->setHp(player->getHp() + player->getPotionHeal(selection - 1));
				}

				Sleep(1000);
				ConsoleWindow::equalSignMaker9000(80);
				cout << "Command(Attack, Run or Potion):";
				cout << endl << endl;
				break;
			}

		case 4: { ////////////////////////////////////////////SKILLS SYSTEM (SUPER INEFFICIENT)/////////////////////////////////////////////////////////////////// ZER MADE THIS CATASTROPHE
			//int a = 0;
			//int c = 10;
			//int b = 10;
			//int skill;
			//Sleep(1000);

			////BOX DRAWING
			//ConsoleWindow::SetDrawingPoint(0, 9);
			//for (int i = 0; i <= 50; i++) { cout << "_"; } //Top line of the box
			//for (int i = 0; i <= 6; i++) { ConsoleWindow::SetDrawingPoint(0, c); cout << "|"; c++; } // Left horizontal line of the box
			//for (int i = 0; i <= 6; i++) { ConsoleWindow::SetDrawingPoint(50, b); cout << "|"; b++; } // Right horizontal line of the box
			//ConsoleWindow::SetDrawingPoint(0, 16);
			//for (int i = 0; i <= 50; i++) { cout << "¯"; } //Bottom line of the box
			////BOX DRAWING

			//ConsoleWindow::SetDrawingPoint(1, 10);
			//cout << "Skills : \t\t   DMG\t\tManaCost";
			//if (skills->skillVector[0].profession == "Jock")
			//{
			//	for (a = 0; a <= 4; a++)
			//	{
			//		ConsoleWindow::SetDrawingPoint(1, 11 + a);
			//		cout << a + 1 << skills->skillVector[a].skillName;
			//		ConsoleWindow::SetDrawingPoint(27, 11 + a);
			//		cout << skills->skillVector[a].skillDamage;
			//		ConsoleWindow::SetDrawingPoint(42, 11 + a);
			//		cout << skills->skillVector[a].skillManaCost << "\n";
			//	}
			//}
			//else if (skills->skillVector[1].profession == "ConMan")
			//{
			//	for (b = 5; b <= 9; b++)
			//	{
			//		ConsoleWindow::SetDrawingPoint(1, 11 + b - 5);
			//		cout << b - 4 << skills->skillVector[b].skillName << "\n\n";
			//		ConsoleWindow::SetDrawingPoint(27, 11 + b - 5);
			//		cout << skills->skillVector[b].skillDamage << "\n";
			//		ConsoleWindow::SetDrawingPoint(42, 11 + b - 5);
			//		cout << skills->skillVector[b].skillManaCost << "\n";
			//	}
			//}

			//cout << endl;

			//cout << "Select your skill to use! : ";
			//cin >> skill;
			//if (skills->skillVector[0].profession == "Jock")
			//{
			//	if (skill = skills->skillVector[skill - 1].skillID)
			//	{
			//		cout << "You CHANNEL " << skills->skillVector[skill - 1].skillManaCost << " mana !\n";
			//		Sleep(1000);
			//		cout << "You used " << skills->skillVector[skill - 1].skillName << "!";
			//		monster.characterVector[monsterID - 1].hp -= skills->skillVector[skill - 1].skillDamage;
			//		cout << "\nYou did " << skills->skillVector[skill - 1].skillDamage << " damage." << endl;
			//		cout << "The monster did " << monster.damage << " damage" << endl;
			//		Sleep(1000);

			//		if (monster.getHp(monsterID - 1) > 0)
			//		{
			//			player->setHp(player->getHp() - monster.damage); // Monster turn to attack
			//			cout << "The monster did " << monster.damage << " damage" << endl;
			//			Sleep(1000);

			//			if (player->getHp() <= 0)
			//			{
			//				cout << "You died. Game over.\n";
			//				Sleep(3000);
			//				exit(1);
			//			}

			//		}
			//		else {
			//			Sleep(1000);
			//			cout << monster.characterVector[monsterID - 1].characterName << " died." << endl;
			//			Player player;
			//			Sleep(1000);
			//			cout << "You gained " << monster.characterVector[monsterID - 1].money << " muneys.\n";
			//			player.addMoney(monster.characterVector[monsterID - 1].money);
			//			Sleep(1000);
			//			system("pause");
			//			system("cls");
			//			break;
			//		}
			//	}
			//}
			//else if (skills->skillVector[1].profession == "ConMan")
			//{
			//	cout << "You CHANNEL " << skills->skillVector[skill + 4].skillManaCost << " mana !\n";
			//	Sleep(1000);
			//	cout << "You used " << skills->skillVector[skill + 4].skillName << "!";
			//	monster.characterVector[monsterID - 1].hp -= skills->skillVector[skill + 4].skillDamage;
			//	cout << "\nYou did " << skills->skillVector[skill + 4].skillDamage << " damage." << endl;
			//	cout << "The monster did " << monster.damage << " damage" << endl;
			//	Sleep(1000);

			//	if (monster.getHp(monsterID - 1) > 0)
			//	{
			//		player->setHp(player->getHp() - monster.damage); // Monster turn to attack
			//		cout << "The monster did " << monster.damage << " damage" << endl;
			//		Sleep(1000);

			//		if (player->getHp() <= 0)
			//		{
			//			cout << "You died. Game over.\n";
			//			Sleep(3000);
			//			exit(1);
			//		}

			//	}
			//	else {
			//		Sleep(1000);
			//		cout << monster.characterVector[monsterID - 1].characterName << " died." << endl;
			//		Player player;
			//		Sleep(1000);
			//		cout << "You gained " << monster.characterVector[monsterID - 1].money << " muneys.\n";
			//		player.addMoney(monster.characterVector[monsterID - 1].money);
			//		Sleep(1000);
			//		system("pause");
			//		system("cls");
			//		break;
			//	}

			//}  ////////////////////////////////////////////SKILLS SYSTEM (SUPER INEFFICIENT)///////////////////////////////////////////////////////////////////

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

	player->showItemandStats( 0, 0); // changed as well to not accept weapon and armour objects
	Time::calculateTime(6);
}



