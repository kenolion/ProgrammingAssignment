#pragma once
#include "Items.h"
using namespace std;
class Weapons :public Items
{
public:
	Weapons();
	~Weapons();
protected:
	int attackPwr;
};

