#ifndef ACTIVITIES_H
#define ACTIVITIES_H

#include "Player.h"
#include "Time.h"
#include <iostream>
#include <fstream>
#include <string>
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
	int action;
};

#endif // !ACTIVITIES_H