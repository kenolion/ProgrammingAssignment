#ifndef SHOP_H
#define SHOP_H
#define NOMINMAX
#include "Items.h"
#include "Weapons.h"
#include "Armours.h"
#include "Player.h"
#include <iostream>
using namespace std;
class Shop
{
public:

	Shop();
	~Shop();
	int displayWeapon(Weapons weapon, Player *player);
	void displayArmour(Armours armour, Player *player);
	int choice;
	int quantity;
};

#endif // !SHOP_H
