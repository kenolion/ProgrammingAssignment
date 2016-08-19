#pragma once
#include "Character.h"
class Player :public Character
{
public:
	Player();
	~Player();
	
	void setPlayerName(string name);
	int getStr();
	int getIntel();
	int getExp();
	int getMoney();
	int getEnergy();
	void addIntel(int intel);
	void addStr(int str);
	int getJob();
	void setJob(int job);

	

private:
	int job;
	int exp;
	int money;
	int energy;
	int intel;
	int str;
	int weaboo;
};

