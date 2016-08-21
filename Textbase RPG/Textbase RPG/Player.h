#ifndef PLAYER_H
#define PLAYER_H
#include "ConsoleWindow.h"
#include "Character.h"
#include "Armours.h"
#include "Weapons.h"
#include "Potions.h"
#include "Skills.h"

class Player :public Character
{
private:
	Armours armour;
	Weapons weapon;
	Potions potion;
	int armourID;
	int job;
	int intel;
	int str;
public:
	Player();
	Player(string name, int hp, int job, int money, int intel, int str, int minAtk, int maxAtk, Weapons weapon,Armours armour, Potions potion);
	~Player();
	
	void setPlayerName(string name);
	int getStr();
	int getIntel();
	int getMoney();
	void addMoney(int money);
	void addIntel(int intel);
	void addStr(int str);

	//MANA,HP,MIN AND MAX ATK CALCULATIONS
	int calculateMana();
	int calculateHp();
	int calculateMinAtk();
	int calculateMaxAtk();

	int getJob();
	void setJob(int job);
	int attack();
	void showItemandStats(int cursorX, int cursorY);
	int getWeaponID();
	int getArmourID();
	void setWeaponID(int weaponID);
	void setArmourID(int armourID);
	void addPotion(int quantity, int potionID);
	void showPotions();
	int getPotionQuantity(int potionID);
	string getPotionName(int potionID);
	int getPotionHeal(int potionID);

};

#endif // !PLAYER_H