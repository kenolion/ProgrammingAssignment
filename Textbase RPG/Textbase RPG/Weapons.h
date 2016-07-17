#pragma once
#include "Items.h"
using namespace std;
class Weapons :public Items
{
public:
	Weapons(string name, int atkPwr, int price);
	~Weapons();
protected:
	int itemNo;
	int attackPwr;
};

