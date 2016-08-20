#include "Potions.h"
#include <iostream>


Potions::Potions()
{
}


Potions::~Potions()
{
}

void Potions::readItemDatabase()
{
	ifstream Potions("Potions.txt");
	
	while (!Potions.eof())
	{
		Potions >> item.itemId;
		getline(Potions, item.name, '|');
		Potions >> item.price >> item.potionHeal >> item.potionQuantity;
		
		potionVector.push_back(item); // Pushback adds an array size to the vector 
	}
}

void Potions::givePotion(int potionID, int potionQuantity)
{
	quantity += potionQuantity;
   potionVector[potionID].potionQuantity += potionQuantity;

}