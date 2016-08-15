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
	};
	itemInfo item;
	virtual void readItemDatabase();
	vector<itemInfo> weaponVector; //vector<data type> vectorname;
	vector<itemInfo> armourVector;
	
};

#endif // !ITEM_H