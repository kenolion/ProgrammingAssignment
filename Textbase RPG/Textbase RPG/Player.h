#ifndef PLAYER_H
#define PLAYER_H
#include "ConsoleWindow.h"
#include "Character.h"
#include "Armours.h"
#include "Weapons.h"


class Player :public Character
{
public:
	Player();
	Player(string name, int hp, int job, int money, int intel, int str, int minAtk, int maxAtk);
	~Player();
	
	void setPlayerName(string name);
	int getStr();
	int getIntel();
	int getMoney();
	void addMoney(int money);
	void addIntel(int intel);
	void addStr(int str);
	int getJob();
	void setJob(int job);
	int attack();
	void showItemandStats(Weapons weapon, Armours armour,int cursorX, int cursorY);
	int getWeaponID();
	int getArmourID();
	void setWeaponID(int weaponID);
	void setArmourID(int armourID);
private:
	Armours armour;
	Weapons weapon;
	
	int weaponID;
	int armourID;
	int job;
	int intel;
	int str;
};

#endif // !PLAYER_H