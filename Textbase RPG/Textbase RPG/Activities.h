#ifndef ACTIVITIES_H
#define ACTIVITIES_H

#include "Player.h"
#include "Time.h"
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
using namespace std;

class Activities 
{
public:
	Activities();
	~Activities();
	int gym();
	int school();
	int adventure();
	int home();
	int	work();
	int fightCrime();
	int randEvents();
	//Time day;
	enum InputKey { KEY_UP = 72, KEY_DOWN = 80, KEY_LEFT = 75, KEY_RIGHT = 77 }; 
	int action;
};

#endif // !ACTIVITIES_H