#ifndef SHOP_H
#define SHOP_H
#include "Items.h"
#include "Weapons.h"
#include "Armours.h"
#include "Potions.h"
#include <iostream>
using namespace std;
class Shop
{
public:
	Shop();
	~Shop();
	void displayWeapon(Weapons weapon);
	void displayArmour(Armours armour);
	void displayPotions(Potions potion);

};

#endif // !SHOP_H
