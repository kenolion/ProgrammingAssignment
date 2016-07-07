#pragma once
#include "Character.h"

class Player:public Character
{
public:
	Player();
	~Player();
	int energy;
	int intell;
	int weaboo;
	int getExp();
	void setPlayerName(string name);
	
private:
	int exp;
};

