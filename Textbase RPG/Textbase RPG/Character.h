#pragma once
#include <iostream>
#include <string>
using namespace std;

class Character
{
public:
	Character();
	~Character();
	
	int job; //1=Swordsman,2= Archer, 3= Deprived(not an actual class just decided to put it there in the mean time)
	int hp;
	
	int str;
	int energy;
	int intell;
	int weaboo;
	int damage;
	int getExp();
	int damageDealt();
	void setMinAtk(int damage);
	void setMaxAtk(int damage);
	string getPlayerName();
	void setPlayerName(string name);

private:
	int exp;
	int minAtk;
	int maxAtk;
	string PlayerName;

};

