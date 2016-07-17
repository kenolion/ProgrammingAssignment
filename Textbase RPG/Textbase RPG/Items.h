#pragma once
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
	int itemId;
	int price;
	int maxAtk;
	int minAtk;
	string name;

};

