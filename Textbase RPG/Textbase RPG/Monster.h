#ifndef MONSTER_H
#define MONSTER_H

#include "Character.h"
#include <fstream>
#include <string>

using namespace std;
class Monster:public Character
{
public:
	Monster();
	~Monster();
	
	string temp;
	void readMonsterDatabase();
	int attack(int monsterID,int playersArmour);
	int moneyDrop;

};
#endif // !MONSTER_H
