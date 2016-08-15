#ifndef WEAPONS_H
#define WEAPONS_H
#include "Items.h"
#include <fstream>
using namespace std;
class Weapons :public Items
{
public:
	Weapons();
	~Weapons();
	void readItemDatabase();
	

};
#endif // !WEAPONS_H
