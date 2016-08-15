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
	cout << "Item name\t\t";
	cout << "Item price\t";
	cout << "Weapon Damage\n";
	for (int column = 0; column < 10; column++) 
	{
			cout << weapon.weaponVector[column].name <<"\t\t";
			cout << weapon.weaponVector[column].price << "\t";
			cout << weapon.weaponVector[column].maxAtk << "-";
			cout << weapon.weaponVector[column].minAtk << endl;
		    
		    
	}	    
}		    

void Shop::displayArmour(Armours armour)
{

	system("cls");
	cout << "Item name\t\t";
	cout << "Item price\t";
	cout << "Defense\n";
	for (int column = 0; column < 10; column++) 
	{
		cout << armour.armourVector[column].name << "\t\t";
		cout << armour.armourVector[column].price << "\t";
		cout << armour.armourVector[column].defense << endl;


	}
}
		    