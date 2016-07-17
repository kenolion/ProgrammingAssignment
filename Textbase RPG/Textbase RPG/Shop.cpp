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
	Items ShopItem;
	system("cls");
	ConsoleWindow::SetDrawingPoint(0, 0);
	for (int column = 0; column <= 10; column++) //column = x axis
	{
		for (int row = 0; row <= 10; row++) 
		{
			cout << "Item name:\n";
			cout << ShopItem.name[row][column];
			ConsoleWindow::SetDrawingPoint(10, 0);
			cout << "Item price:\n";
			cout << ShopItem.price;
			ConsoleWindow::SetDrawingPoint(20, 0);
			cout << "Item Maximum Damage:\n";
			cout << ShopItem.maxAtk;
			ConsoleWindow::SetDrawingPoint(30, 0);
			cout << "Item Minimum Damage:\n";
			cout << ShopItem.minAtk;

		}
	}
}
