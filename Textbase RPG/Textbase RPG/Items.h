#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <vector>
using namespace std;

class Items
{
public:
	Items();
	~Items();
	struct itemInfo {
		string tempStr;
		int itemId;
		int price;
		int maxAtk;
		int minAtk;
		int defense;
		string name;

		//POTIONS
		int potionQuantity;
		int potionHeal;
		
	};
	itemInfo item;

	virtual void readItemDatabase();

	vector<itemInfo> weaponVector; //vector<data type> vectorname;
	vector<itemInfo> armourVector;
	vector<itemInfo> potionVector;
	
};

#endif // !ITEM_H