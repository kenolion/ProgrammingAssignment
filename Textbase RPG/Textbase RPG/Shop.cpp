#include "Shop.h"
#include "ConsoleWindow.h"
#include "Player.h"

Shop::Shop()
{
}


Shop::~Shop()
{
}

int Shop::displayWeapon(Weapons weapon,Player *player)
{
	system("cls");
	cout << "No\t";
	cout << "Item name\t\t";
	cout << "Item price\t";
	cout << "Weapon Damage\n";
	for (int column = 1; column < weapon.weaponVector.size()-1; column++) 
	{
		cout << weapon.weaponVector[column].itemId <<"\t";
		cout << weapon.weaponVector[column].name <<"\t\t";
		cout << weapon.weaponVector[column].price << "\t";
		cout << weapon.weaponVector[column].maxAtk << "-";
		cout << weapon.weaponVector[column].minAtk << endl;
	}	
	////// VALIDATION CHECK
	cout << weapon.weaponVector.size() << "Exit" << endl;
	cout << weapon.weaponVector[12].price;
	do{
	while(!(cin >> choice) ||choice > weapon.weaponVector.size() || choice < 1){
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Enter a valid item number!";

	}
	if (player->getMoney() <= weapon.weaponVector[choice].price) {

		cout << "No money no talk";

	}else if(choice == weapon.weaponVector.size()){
		return 0;
	}
	} while (player->getMoney() <= weapon.weaponVector[choice].price);
	player->addMoney(-weapon.weaponVector[choice].price);
	player->setWeaponID(choice);
	system("pause");
	return 0;
}		    

void Shop::displayArmour(Armours armour,Player *player)
{

	system("cls");
	cout << "No\t";
	cout << "Item name\t\t";
	cout << "Item price\t";
	cout << "Defense\n";
	for (int column = 0; column < armour.armourVector.size()-1; column++) 
	{
		cout << armour.armourVector[column].itemId <<"\t";
		cout << armour.armourVector[column].name << "\t\t";
		cout << armour.armourVector[column].price << "\t";
		cout << armour.armourVector[column].defense << endl;
	}
	cout << armour.armourVector.size() << "Exit" << endl;
	do {
		while (!(cin >> choice) || choice > armour.armourVector.size() || choice < 1) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Enter a valid item number!";

		}
		if (player->getMoney() <= armour.armourVector[choice].price) {

			cout << "No money no talk! ";

		}
		
	} while (player->getMoney() <= armour.armourVector[choice].price);
	player->addMoney(-armour.armourVector[choice].price);
	player->setArmourID(choice);

}
		    