#include "Items.h"
#include <fstream>
using namespace std;
#include <iostream>

Items::Items()
{
}


Items::~Items()
{
}

void Items::readItemDatabase()
{
	ifstream Item("ShopItems.txt");
	int i=0;
	getline(Item, tempStr);
	while (!Item.eof())
	{
		Item >> itemId[i];
		Item>> name[i] >> tempStr;
		name[i] += " " + tempStr;
		Item >> price[i] >> minAtk[i] >> maxAtk[i];
		i++;
	}
}