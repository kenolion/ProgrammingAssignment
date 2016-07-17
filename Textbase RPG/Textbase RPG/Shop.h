#ifndef SHOP_H
#define SHOP_H
#include "Items.h"
#include <iostream>
using namespace std;
class Shop:public Items
{
public:
	Shop();
	~Shop();
	void displayItems();
};

#endif // !SHOP_H
