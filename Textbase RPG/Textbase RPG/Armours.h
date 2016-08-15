#ifndef ARMOURS_H
#define ARMOURS_H

#include "Items.h"
#include <fstream>
#include <string>
using namespace std;
class Armours:public Items
{
public:
	Armours();
	~Armours();
	void readItemDatabase();
	
};

#endif // !ARMOURS_H