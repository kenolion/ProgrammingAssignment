#include "Weapons.h"



Weapons::Weapons()
{
}


Weapons::~Weapons()
{
}

void Weapons::readItemDatabase()
{
	ifstream Item("WeaponsDatabase.txt");
	getline(Item, item.tempStr);
	while (!Item.eof())
	{
		Item >> item.itemId;
		Item >> item.name >> item.tempStr;
		item.name += " " + item.tempStr;
		Item >> item.price >> item.minAtk >> item.maxAtk;
		weaponVector.push_back(item); // Pushback adds an array size to the vector 
	}
}
