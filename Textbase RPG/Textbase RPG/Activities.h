#pragma once
#include "Player.h"
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
	int shopping(); //Zer added shopping() and fightcrime()
	int fightCrime();
};

