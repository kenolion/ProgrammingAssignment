#ifndef ITEM_H
#define ITEM_H

#include <string>
using namespace std;

class Items
{
public:
	Items();
	~Items();
protected:
	int itemId;
	int price;
	int maxAtk;
	int minAtk;
	string name;
};

#endif // !ITEM_H