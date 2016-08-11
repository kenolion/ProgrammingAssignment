#ifndef ITEM_H
#define ITEM_H

#include <string>
using namespace std;

class Items
{
public:
	Items();
	~Items();
	void readItemDatabase();
protected:
	string tempStr;
	int itemId[10];
	int price[10];
	int maxAtk[10];
	int minAtk[10];
	string name[10];
};

#endif // !ITEM_H