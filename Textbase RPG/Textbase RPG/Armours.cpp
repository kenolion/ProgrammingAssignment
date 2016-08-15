#include "Armours.h"



Armours::Armours()
{
}


Armours::~Armours()
{
}


void Armours::readItemDatabase()
{
	ifstream Item("ArmoursDatabase.txt");
	getline(Item, item.tempStr);
	while (!Item.eof())
	{
		Item >> item.itemId;
		Item >> item.name >> item.tempStr;
		item.name += " " + item.tempStr;
		Item >> item.price >> item.defense;
		armourVector.push_back(item); // Pushback adds an array size to the vector 
	}
}