#include "Game.h"
#include "Potions.h"
#include <cstdlib>
#include "Character.h"
using namespace std;
int Game::midnightBosses = 5;
int Game::morningBosses = 5;

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

	int choice = 0;
	while (monster.getHp(monsterID - 1) > 0 && player->getHp() > 0) {// do while loop to enable a turn based like battle system
		monster.damage = monster.attack(monsterID - 1);			//generated monsters damage each loop because monster will attack each round
	
		do {												// THIS do while loop is to loop until player wants to exit from potion or skill menu condition at LINE 136
			system("cls");
			ConsoleWindow::equalSignMaker9000(80);
			cout << "You encountered a" << monster.characterVector[monsterID - 1].characterName << endl;					//1. DISPLAY ENCOUNTER MESSAGE																							
			cout << "What do you want to do?\n1.Attack\n2.NIGERO(Run)(30% Chance)\n3.Potion\n4.Skills\n";
			ConsoleWindow::equalSignMaker9000(80);



			while (!(cin >> choice)) {																						//2. GET USER INPUT
				cout << "Incorrect input. Please try again.\n";
				cin.clear();
				cin.ignore(100, '\n');
			}
			switch (choice) {
			case 1: {																									// ATTACK

				player->damage = player->attack();
				monster.characterVector[monsterID - 1].hp -= player->damage; //MINUSING THE MONSTERS HP

				cout << "You did " << player->damage << " damage." << endl;
				Sleep(1000);
				break;
			}
			case 2: {
				Sleep(1000);
				cout << "You attempt to run away.\n";
				int randNum;
				randNum = rand() % 100; // 100 
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
					break;

				}
			}
			case 3: {
				cout << "\nPick your potion to consume :\n\n";
				ConsoleWindow::getCursorXY();
				// EDITED BY KEITH
				player->showPotions();
				ConsoleWindow::SetDrawingPoint(0, ConsoleWindow::y + 1);
				cout << "-5. Cancel";
				cout << "\n\nPotion choice (Number) : ";
				do {
					while (!(cin >> choice)) {
						cout << "Incorrect input. Please try again.\n";
						cin.clear();
						cin.ignore(100, '\n');
					}

					if (choice == -5) {
						system("cls");
						break;
					}
					else if (player->getPotionQuantity(choice) == 0)
					{
						cout << "You're out of " << player->getPotionName(choice) << "s!\n\n";
						cout << "Use another potion :";
					}
					else if (player->getPotionQuantity(choice) > 0) {
						Sleep(1000);
						player->addPotion(-1, choice);
						cout << "You used :" << player->getPotionName(choice) << "!\n";
						cout << "Player HP + " << player->getPotionHeal(choice) << "!\n\n";
						player->setHp(player->getHp() + player->getPotionHeal(choice));
					}

				} while (player->getPotionQuantity(choice) == 0);
				break;

			}


			case 4: { ////////////////////////////////////////////SKILLS SYSTEM (SUPER INEFFICIENT)/////////////////////////////////////////////////////////////////// ZER MADE THIS CATASTROPHE(FIXED)
				player->showSkills();
				cout << endl << endl;
				cout << "-5. Cancel\n";
				cout << "Select your skill to use! : ";
				while (!(cin >> choice)) {
					cout << "Incorrect input. Please try again.\n";
					cin.clear();
					cin.ignore(100, '\n');
				}
				if (choice != -5) {
					cout << "You CHANNEL " << player->getSkillCost(choice) << " mana !\n";
					Sleep(1000);
					cout << "You used " << player->getSkillName(choice) << "!";
					monster.characterVector[monsterID - 1].hp -= player->getSkillDmg(choice);
					cout << "\nYou did " << player->getSkillDmg(choice) << " damage." << endl;

					Sleep(1000);
					break;
				}
				system("cls");
			}

			}
		} while (choice == -5);								// sentinel value(?)

		if (monster.getHp(monsterID - 1) > 0) {
			cout << "The enemy has "<< monster.characterVector[monsterID-1].hp<<" Hp left\n" ;
			player->setHp(player->getHp() - monster.damage); // Monster turn to attack
			cout << "The enemy did " << monster.damage << " damage" << endl;
			cout << "You have " << player->getHp() << " HP left\n";
			system("pause");
			
		}

	}										/// EXITING WHILE LOOP
	if (player->getHp() <= 0) {
		cout << "You died. Game over.\n";
		Sleep(3000);
		exit(1);

	}
	else {

		Sleep(1000);
		cout << monster.characterVector[monsterID - 1].characterName << " died." << endl;
		Sleep(1000);
		cout << "You gained " << monster.characterVector[monsterID - 1].money << " muneys.\n";
		player->addMoney(monster.characterVector[monsterID - 1].money);
		Sleep(1000);

		if (monster.characterVector[monsterID - 1].characterID == monster.characterVector[1].characterID || monster.characterVector[monsterID - 1].characterID == monster.characterVector[2].characterID || monster.characterVector[monsterID - 1].characterID == monster.characterVector[3].characterID || monster.characterVector[monsterID - 1].characterID == monster.characterVector[4].characterID || monster.characterVector[monsterID - 1].characterID == monster.characterVector[5].characterID)
		{
			cout << "Congratulations! Midnight Mini Boss "<< monster.characterVector[monsterID - 1].characterName << " Annihilated!!! \n";
			cout << "Fulfillment Bar Increased!!\n";
			Game::midnightBosses--;
		}
		else if(monster.characterVector[monsterID - 1].characterID == monster.characterVector[15].characterID || monster.characterVector[monsterID - 1].characterID == monster.characterVector[16].characterID || monster.characterVector[monsterID - 1].characterID == monster.characterVector[17].characterID || monster.characterVector[monsterID - 1].characterID == monster.characterVector[18].characterID || monster.characterVector[monsterID - 1].characterID == monster.characterVector[19].characterID)
		{
			cout << "Congratulations! Crime Mini Boss" << monster.characterVector[monsterID - 1].characterName << "Annihilated!!! \n";
			cout << "Fulfillment Bar Increased!!\n";
			Game::morningBosses++;
		}

		Sleep(1000);
		ConsoleWindow::equalSignMaker9000(80);
		Time::calculateTime(6);
		system("cls");
		return 0;
	}
}
