#include "Items.h"
#include <fstream>


using namespace std;

Items::Items()
{
}


Items::~Items()
{
}

void Items::readItemDatabase()
{
	ifstream Item("ShopItems.txt");
	getline(Item, tempStr);
	while (!Item.eof())
	{
		Item >> itemId;
		getline(Item,name);
		getline(Item, tempStr);
		name += tempStr;
		Item >> price >> minAtk >> "-" >> maxAtk;

	}

}

