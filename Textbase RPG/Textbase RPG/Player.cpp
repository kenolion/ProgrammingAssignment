#include "Player.h"
Player::Player()
{
}

Player::Player(string name,int hp,int job, int money, int intel, int str,int minAtk,int maxAtk)
{
	character.hp = hp;
	this->job = job;
	this->money = money;
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
	return this->money;
}

void Player::addMoney(int money)
{
	this->money += money;
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

	return rand() % character.maxAtk + character.minAtk;
}

void Player::showItemandStats(Weapons weapon,Armours armour)
{
	
	system("cls");
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
	ConsoleWindow::SetDrawingPoint(2, 23); // Line 2 in the box
	cout << "Strength : " <<str; // Updated Strength Value whenever he levels up, when he chooses one of the two jobs at the start of the game;
	ConsoleWindow::SetDrawingPoint(2, 24); // and etc.
	cout << "Intelligence : " << intel; // Updated Intelligence Value whenever he levels up, when he chooses one of the two jobs at the start of the game;
	ConsoleWindow::SetDrawingPoint(2, 27);
	cout << "WEAPON EQUIPPED";
	ConsoleWindow::SetDrawingPoint(2, 28);
	cout << weapon.weaponVector[weaponID].name; // Updated Weapons
	ConsoleWindow::SetDrawingPoint(2, 30);
	cout << "ARMOR EQUIPPED"; // Updated Armor
	ConsoleWindow::SetDrawingPoint(2, 31);
	cout << armour.armourVector[armourID].name;
	ConsoleWindow::SetDrawingPoint(2, 33);
	cout << "Money :" << money;
	ConsoleWindow::SetDrawingPoint(0, 0);
}