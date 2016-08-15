#ifndef SHOP_H
#define SHOP_H
#include "Items.h"
#include "Weapons.h"
#include "Armours.h"
#include <iostream>
using namespace std;
class Shop
{
public:
	Shop();
	~Shop();
	void displayWeapon(Weapons weapon);
	void displayArmour(Armours armour);

};

#endif // !SHOP_H
