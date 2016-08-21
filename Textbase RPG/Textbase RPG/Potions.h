#ifndef POTIONS_H
#define POTIONS_H

#include <fstream>
#include <string>
#include "Items.h"

using namespace std;
class Potions :public Items
{
public:
	Potions();
	~Potions();

	int quantity;
	void readItemDatabase();
	/*void givePotion(int potionID, int potionQuantity);*/


};



#endif