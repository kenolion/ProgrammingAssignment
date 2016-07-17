#include "Shop.h"
#include "ConsoleWindow.h"


Shop::Shop()
{
}


Shop::~Shop()
{
}

void Shop::displayItems()
{

	cout << "Item name:\t    ";
	cout << "Item price:\t";
	cout << "Item Maximum Damage:\t"; 
	cout << "Item Minimum Damage:\n";

		for (int row = 0; row < 10; row++) 
		{
			cout << name[row] << "\t";
			cout << price[row] << "\t\t";
			cout << maxAtk[row] << "\t\t\t";
			cout << minAtk[row] << "\t";
			cout << endl;
		}

}
