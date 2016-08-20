#include "Shop.h"
#include "ConsoleWindow.h"


Shop::Shop()
{
}


Shop::~Shop()
{
}

void Shop::displayWeapon(Weapons weapon)
{
	
	system("cls");
	ConsoleWindow::equalSignMaker9000(80);
	ConsoleWindow::SetDrawingPoint(0, weapon.weaponVector.size()+1);
	ConsoleWindow::equalSignMaker9000(80);
	ConsoleWindow::SetDrawingPoint(0, 1);
	cout << "   Item name\t\t";
	cout << "Item price\t";
	cout << "Weapon Damage\n";
	for (int column = 1; column < weapon.weaponVector.size()-1; column++) 
	{
		cout << weapon.weaponVector[column].itemId<<" ";
			cout << weapon.weaponVector[column].name <<"\t\t";
			cout << weapon.weaponVector[column].price << "\t\t";
			cout << weapon.weaponVector[column].minAtk << "-";
			cout << weapon.weaponVector[column].maxAtk << endl;

		    
		    
	}	    
}		    

void Shop::displayArmour(Armours armour)
{

	system("cls");
	ConsoleWindow::equalSignMaker9000(80);
	ConsoleWindow::SetDrawingPoint(0, armour.armourVector.size()+1);
	ConsoleWindow::equalSignMaker9000(80);
	ConsoleWindow::SetDrawingPoint(0, 1);
	cout << "  Item name\t\t";
	cout << "Item price\t";
	cout << "Defense\n";
	for (int column = 1; column < armour.armourVector.size()-1; column++) 
	{
		cout << armour.armourVector[column].itemId << " ";
		cout << armour.armourVector[column].name << "\t\t";
		cout << armour.armourVector[column].price << "\t\t";
		cout << armour.armourVector[column].defense << endl;


	}
}

void Shop::displayPotions(Potions potion)
{
	system("cls");
	ConsoleWindow::equalSignMaker9000(80);
	ConsoleWindow::SetDrawingPoint(0, potion.potionVector.size()+2);
	ConsoleWindow::equalSignMaker9000(80);
	ConsoleWindow::SetDrawingPoint(0, 1);

	cout << "   Potion Name\t\t";
	cout << "Price\t";
	cout << "Potion Heal(HP)\n";
	for (int column = 0; column < potion.potionVector.size()-1; column++)
	{
		cout << potion.potionVector[column].itemId << " ";
		cout << potion.potionVector[column].name << "\t\t";
		cout << potion.potionVector[column].price << "\t";
		cout << potion.potionVector[column].potionHeal << endl;


	}
}
		    