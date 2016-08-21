#include "Player.h"
#include "Game.h"

Player::Player()
{
}

Player::Player(string name,int hp,int job, int money, int intel, int str,int minAtk,int maxAtk)
{
	character.hp = hp;
	this->job = job;
	character.money = money;
	this->intel = intel;
	this->str = str;
	character.characterName = name;
	character.minAtk = minAtk;
	character.maxAtk = maxAtk;
	weaponID = 0;				//Sets the players weapon ID at the start to 0 which is his pencil
	armourID = 0;
}


Player::~Player()
{
}



void Player::setPlayerName(string name) {
	character.characterName = name;
}

int Player::getStr(){
	return this->str;
}
int Player::getIntel(){
	return this->intel;
}
int Player::getMoney(){
	return character.money;
}

void Player::addMoney(int money)
{
	character.money += money;
}


void Player::addIntel(int intel){
	this->intel += intel;
}
void Player::addStr(int str){
	this->str += str;
}

int Player::getJob()
{
	return job;
}

void Player::setJob(int job)
{
	this->job = job;
}

int Player::attack()
{
	double strMultiplier;
	strMultiplier = str * 0.5;
	return (rand() % character.maxAtk + weapon.weaponVector[weapon.item.itemId].maxAtk + character.minAtk + weapon.weaponVector[weapon.item.itemId].minAtk) + strMultiplier;
}

void Player::showItemandStats(Weapons weapon,Armours armour,int cursorX,int cursorY)
{
	int c = 21;
	int d = 21;
	ConsoleWindow::SetDrawingPoint(1, 20);
	for (int i = 0; i <= 30; i++) { cout << "_"; } //Top line of the box
	ConsoleWindow::SetDrawingPoint(1, 21);
	for (int i = 0; i <= 14; i++) { ConsoleWindow::SetDrawingPoint(1, c); cout << "|"; c++; } // Left horizontal line of the box
	ConsoleWindow::SetDrawingPoint(31, 21);
	for (int i = 0; i <= 14; i++) { ConsoleWindow::SetDrawingPoint(31, d); cout << "|"; d++; }; //Right horizontal line of the box
	ConsoleWindow::SetDrawingPoint(1, 35);
	for (int i = 0; i <= 30; i++) { cout << "¯"; } //Bottom line of the box
	ConsoleWindow::SetDrawingPoint(2, 22); // Line 1 in the box
	cout << "STATS";
	ConsoleWindow::SetDrawingPoint(2, 23);
	cout << "Hp : " << character.hp;
	ConsoleWindow::SetDrawingPoint(2, 24); // Line 2 in the box
	cout << "Strength : " <<str; // Updated Strength Value whenever he levels up, when he chooses one of the two jobs at the start of the game;
	ConsoleWindow::SetDrawingPoint(2, 25); // and etc.
	cout << "Intelligence : " << intel; // Updated Intelligence Value whenever he levels up, when he chooses one of the two jobs at the start of the game;
	ConsoleWindow::SetDrawingPoint(2, 28);
	cout << "WEAPON EQUIPPED";
	ConsoleWindow::SetDrawingPoint(2, 29);
	cout << weapon.weaponVector[weaponID].name; // Updated Weapons
	ConsoleWindow::SetDrawingPoint(2, 31);
	cout << "ARMOR EQUIPPED"; // Updated Armor
	ConsoleWindow::SetDrawingPoint(2, 32);
	cout << armour.armourVector[armourID].name;
	ConsoleWindow::SetDrawingPoint(2, 34);
	cout << "Money :" << character.money;
	ConsoleWindow::SetDrawingPoint(cursorX,cursorY);
}

int Player::getWeaponID()
{
	return weaponID;
}

int Player::getArmourID()
{
	return armourID;
}

void Player::setWeaponID(int weaponID)
{
	this->weaponID = weaponID;
}

void Player::setArmourID(int armourID)
{
	this->armourID = armourID;
}

