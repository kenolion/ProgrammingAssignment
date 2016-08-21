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
	Skills skill;
	int armourID;
	int job;
	int intel;
	int str;
public:
	Player();
	Player(string name, int hp, int job, int money, int intel, int str, int minAtk, int maxAtk, Weapons weapon,Armours armour, Potions potion);
	~Player();
	///////////////////////// PLAYERS STATS SETTERS AND GETTERS
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
	int attack();				// <------------------- attack number generator
	void showItemandStats(int cursorX, int cursorY);
	///////////////////////// ARMOUR AND WEAPON GETTERS AND SETTERS
	int getWeaponID();
	int getArmourID();
	void setWeaponID(int weaponID);
	void setArmourID(int armourID);
	//////////////////////// POTION SETTERS AND GETTERS
	void addPotion(int quantity, int potionID);
	void showPotions();
	int getPotionQuantity(int potionID);
	string getPotionName(int potionID);
	int getPotionHeal(int potionID);
	///////////////////////// SKILLS SETTERS AND GETTERS
	void showSkills();
	int getSkillDmg(int skillID);
	int getSkillCost(int skillID);
	string getSkillName(int skillID);
	
};

#endif // !PLAYER_H