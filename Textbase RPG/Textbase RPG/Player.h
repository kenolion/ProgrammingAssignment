#pragma once
#include "Character.h"
class Player :public Character
{
public:
	Player();
	~Player();
	int weaboo;
	void setPlayerName(string name);
	int getStr();
	int getIntel();
	int getExp();
	int getMoney();
	int getEnergy();
	void addIntel(int intel);
	void addStr(int str);
	int getJob();
	int setJob(int job);


private:
	int job;
	int exp;
	int money;
	int energy = 10;
	int intel = 5;
	int str = 5;
};

