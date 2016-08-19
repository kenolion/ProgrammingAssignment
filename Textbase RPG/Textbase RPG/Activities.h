#ifndef ACTIVITIES_H
#define ACTIVITIES_H

#include "Player.h"
#include "Time.h"
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include "Monster.h"
using namespace std;

class Activities 
{
public:
	Activities();
	~Activities();
	int gym(Player *player);
	int school(Player *player);
	int adventure(Player *player);
	int home(Player *player, Weapons weapon, Armours armour, Monster monster);
	int	work(Player *player); 
	int fightCrime(Player *player, Weapons weapon, Armours armour, Monster monster);
	int randEvents(Player *player);
	//Time day;
	enum InputKey { KEY_UP = 72, KEY_DOWN = 80, KEY_LEFT = 75, KEY_RIGHT = 77 }; 
	int action;
};

#endif // !ACTIVITIES_H