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
		getline(Item, item.name, '|');
		//item.name += " " + item.tempStr;
		Item >> item.price >> item.minAtk >> item.maxAtk;
		weaponVector.push_back(item); // Pushback adds an array size to the vector 
	}
}
