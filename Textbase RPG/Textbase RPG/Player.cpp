#include "Player.h"
#include "Game.h"

Player::Player()
{
}

Player::Player(string name,int hp,int job, int money, int intel, int str,int minAtk,int maxAtk, Weapons weapon, Armours armour,Potions potion)
{
	character.hp = hp;
	this->job = job;
	character.money = money;
	this->intel = intel;
	this->str = str;
	character.characterName = name;
	character.minAtk = minAtk;
	character.maxAtk = maxAtk;
	this->weapon = weapon;
	this->armour = armour;
	this->potion = potion;
	this->weapon.item.itemId = 0;				//Sets the players weapon ID at the start to 0 which is his pencil
	this->armour.item.itemId = 0;
	this->skill = skill;
	character.profession = job;
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

int Player::calculateMana()
{
	return character.Mana = (intel * 1.5) + 100;

}

int Player::calculateHp()
{
	return  character.hp = (str * 1.5) + 100;
}

int Player::calculateMinAtk()
{
	return character.minAtk = character.minAtk + weapon.weaponVector[weapon.item.itemId].minAtk;
}

int Player::calculateMaxAtk()
{
	return character.maxAtk = character.maxAtk + weapon.weaponVector[weapon.item.itemId].maxAtk;
}

int Player::getJob()
{

	return character.profession;
}

void Player::setJob(int job)
{
	skill.readSkillsDatabase(job);
	character.profession = job;
}

int Player::attack()
{
	
	double strMultiplier;
	strMultiplier = str * 0.5;
	return (rand() % character.maxAtk + weapon.weaponVector[weapon.item.itemId].maxAtk + character.minAtk + weapon.weaponVector[weapon.item.itemId].minAtk) + strMultiplier;
}

void Player::showItemandStats(int cursorX,int cursorY)
{
	int c = 21;
	int d = 21;
	ConsoleWindow::SetDrawingPoint(1, 20);
	for (int i = 0; i <= 60; i++) { cout << "_"; } //Top line of the box
	for (int i = 0; i <= 17; i++) { ConsoleWindow::SetDrawingPoint(1, c); cout << "|"; c++; } // Left horizontal line of the box
	for (int i = 0; i <= 17; i++) { ConsoleWindow::SetDrawingPoint(61, d); cout << "|"; d++; }; //Right horizontal line of the box
	ConsoleWindow::SetDrawingPoint(1, 38);
	for (int i = 0; i <= 60; i++) { cout << "¯"; } //Bottom line of the box

	ConsoleWindow::SetDrawingPoint(2, 22); // Line 1 in the box
	cout << "STATS";
	ConsoleWindow::SetDrawingPoint(2, 23);
	cout << "Hp : " << calculateHp();
	ConsoleWindow::SetDrawingPoint(32, 23);
	cout << "Total Damage : " << character.minAtk + weapon.weaponVector[weapon.item.itemId].minAtk << '-' << character.maxAtk + weapon.weaponVector[weapon.item.itemId].maxAtk;
	ConsoleWindow::SetDrawingPoint(2, 24); // Line 2 in the box
	cout << "Mana : " << calculateMana();
	ConsoleWindow::SetDrawingPoint(2, 25); // and etc.
	cout << "Strength : " << str;  // Updated Strength Value whenever he levels up, when he chooses one of the two jobs at the start of the game;
	ConsoleWindow::SetDrawingPoint(2, 26);
	cout << "Intelligence : " << intel; // Updated Intelligence Value whenever he levels up, when he chooses one of the two jobs at the start of the game;
	ConsoleWindow::SetDrawingPoint(2, 28);
	cout << "WEAPON EQUIPPED";
	ConsoleWindow::SetDrawingPoint(2, 29);
	cout << weapon.weaponVector[weapon.item.itemId].name; // Updated Weapons
	ConsoleWindow::SetDrawingPoint(32, 29);
	cout << "Minimum Weapon Attack : " << weapon.weaponVector[weapon.item.itemId].minAtk;
	ConsoleWindow::SetDrawingPoint(32, 30);
	cout << "Maximum Weapon Attack : " << weapon.weaponVector[weapon.item.itemId].maxAtk;
	ConsoleWindow::SetDrawingPoint(2, 32);
	cout << "ARMOR EQUIPPED"; // Updated Armor
	ConsoleWindow::SetDrawingPoint(2, 33);
	cout << armour.armourVector[armour.item.itemId].name;
	ConsoleWindow::SetDrawingPoint(2, 35);
	cout << "MONEY";
	ConsoleWindow::SetDrawingPoint(2, 36);
	cout << character.money;
	ConsoleWindow::SetDrawingPoint(32, 36);
	cout << "Fulfillment Bar :"; for (int i = 10; i > Game::bossesLeft; i--) { cout << "|"; }
	ConsoleWindow::SetDrawingPoint(cursorX,cursorY);

}

/////////////// WEAPON DEFINITION
int Player::getWeaponID()
{
	return weapon.item.itemId;
}

int Player::getArmourID()
{
	return armourID;
}

void Player::setWeaponID(int weaponID)
{
	this->weapon.item.itemId = weaponID;
}

void Player::setArmourID(int armourID)
{
	this->armour.item.itemId = armourID;
}


/////////////////// POTIONS DEFINITION
void Player::addPotion(int quantity, int potionID)
{
	potion.potionVector[potionID].potionQuantity += quantity;
}

void Player::showPotions()
{
	int c = 10;
	ConsoleWindow::SetDrawingPoint(ConsoleWindow::x,ConsoleWindow::y );
	for (int i = 0; i <= 25; i++) { cout << "_"; } //Top line of the box
	ConsoleWindow::getCursorXY();
	c = ConsoleWindow::y+1;
	for (int i = 0; i <= 3; i++) { ConsoleWindow::SetDrawingPoint(0, c); cout << "|"; c++; } // Left horizontal line of the box
	ConsoleWindow::getCursorXY();
	c = ConsoleWindow::y;
	for (int i = 0; i <= 3; i++) { ConsoleWindow::SetDrawingPoint(25, c); cout << "|"; c--; } // Right horizontal line of the box
	ConsoleWindow::SetDrawingPoint(0, ConsoleWindow::y+1);
	for (int i = 0; i <= 25; i++) { cout << "¯"; } //Bottom line of the box

	ConsoleWindow::SetDrawingPoint(1, ConsoleWindow::y-3);
	cout << potion.potionVector[0].itemId << potion.potionVector[0].name << " x " << potion.potionVector[0].potionQuantity << endl;
	ConsoleWindow::SetDrawingPoint(1, ConsoleWindow::y -2);
	cout << potion.potionVector[1].itemId << potion.potionVector[1].name << " x " << potion.potionVector[1].potionQuantity << endl;
	ConsoleWindow::SetDrawingPoint(1, ConsoleWindow::y + -1);
	cout << potion.potionVector[2].itemId << potion.potionVector[2].name << " x " << potion.potionVector[2].potionQuantity << endl;

	
}

int Player::getPotionQuantity(int potionID)
{
	return potion.potionVector[potionID-1].potionQuantity;
}

string Player::getPotionName(int potionID)
{
	return potion.potionVector[potionID-1].name;
}

int Player::getPotionHeal(int potionID)
{
	return potion.potionVector[potionID-1].potionHeal;
}

////////////////////////////////

void Player::showSkills()
{
	int y = 10;
	ConsoleWindow::SetDrawingPoint(0, 9);
	for (int i = 0; i <= 50; i++) { cout << "_"; } //Top line of the box
	for (int i = 0; i <= 6; i++) { ConsoleWindow::SetDrawingPoint(0, y); cout << "|"; y++; } // Left horizontal line of the box
	y = 10;
	for (int i = 0; i <= 6; i++) {  ConsoleWindow::SetDrawingPoint(50, y); cout << "|"; y++; } // Right horizontal line of the box
	ConsoleWindow::SetDrawingPoint(0, 16);
	for (int i = 0; i <= 50; i++) { cout << "¯"; } //Bottom line of the box

	ConsoleWindow::SetDrawingPoint(1, 10);
	cout << "Skills : \t\t   DMG\t\tManaCost";

		for (int a = 0; a < skill.skillVector.size(); a++)
		{
			ConsoleWindow::SetDrawingPoint(1, 11 + a);
			cout << a + 1 << skill.skillVector[a].skillName;
			ConsoleWindow::SetDrawingPoint(27, 11 + a);
			cout << skill.skillVector[a].skillDamage;
			ConsoleWindow::SetDrawingPoint(42, 11 + a);
			cout << skill.skillVector[a].skillManaCost << "\n";
		}
}

int Player::getSkillDmg(int skillID)
{
	return skill.skillVector[skillID-1].skillDamage;
}

int Player::getSkillCost(int skillID)
{
	return skill.skillVector[skillID-1].skillManaCost;
}

string Player::getSkillName(int skillID)
{
	return skill.skillVector[skillID-1].skillName;
}

int Player::getSkillVectorSize()
{
	return skill.skillVector.size();
}

int Player::getPotionVectorSize()
{
	return potion.potionVector.size();
}









