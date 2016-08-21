
#ifndef GAME_H
#define GAME_H
#include "Armours.h"
#include "Weapons.h"
#include <iostream>
#include "Player.h"
#include "Monster.h"
#include "ConsoleWindow.h"
#include "Time.h"
#include "Potions.h"
#include <windows.h>// to use the function sleep
class Game
{
public:
	Game();
	~Game();
	static void timeDISPLAY9000();
	static int battleSystem(Player *player, Monster monster, int monsterID);
};

#endif