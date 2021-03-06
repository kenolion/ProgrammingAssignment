#ifndef ACTIVITIES_H
#define ACTIVITIES_H

#include "Player.h"
#include "Time.h"
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include "Monster.h"
#include "Game.h"
#include "Potions.h"
using namespace std;

class Activities 
{
public:
	Activities();
	~Activities();
	int gym();
	int school();
	int adventure();
	int home( Player *player, Monster monster);
	int	work(); 
	int fightCrime( Player *player, Monster monster);
	int randEvents( Player *player, Monster monster);
	void randLearningMessage(int textFileNo);
	//Time day;
	enum InputKey { KEY_UP = 72, KEY_DOWN = 80, KEY_LEFT = 75, KEY_RIGHT = 77 }; 
	int action;
};

#endif // !ACTIVITIES_H