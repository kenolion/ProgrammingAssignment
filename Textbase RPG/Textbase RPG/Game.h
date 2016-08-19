
#ifndef GAME_H
#define GAME_H
#include "Armours.h"
#include "Weapons.h"
#include <iostream>
#include "Player.h"
#include "Monster.h"
#include "ConsoleWindow.h"
#include "Time.h"
#include <windows.h>// to use the function sleep
class Game
{
public:
	Game();
	~Game();
	static void battleSystem(Player *player, Weapons weapon, Armours armour, Monster monster, int monsterID);
};

#endif