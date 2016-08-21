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
	ConsoleWindow::equalSignMaker9000(80);
	ConsoleWindow::SetDrawingPoint(0, weapon.weaponVector.size()+1);
	ConsoleWindow::equalSignMaker9000(80);
	ConsoleWindow::SetDrawingPoint(0, 1);
	cout << "   Item name\t\t";
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
	
	cout << weapon.weaponVector.size() << "Exit" << endl;
	////// VALIDATION CHECK
	cout << weapon.weaponVector[12].price;
	cout << "\n\nEnter the ID of the Weapon you would like to buy : ";
	do{
	while(!(cin >> choice) ||choice > weapon.weaponVector.size() || choice < 1){
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Enter a valid item number!";

	}
	if (player->getMoney() < weapon.weaponVector[choice].price) {

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
		    

int Shop::displayArmour(Armours armour,Player *player)
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
	cout << armour.armourVector.size() << "Exit" << endl;
	cout << "\n\nEnter the ID of the Armour you would like to buy : ";
	////// VALIDATION CHECK
	do {
		while (!(cin >> choice) || choice > armour.armourVector.size() || choice < 1) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Enter a valid item number!";

		}
		if (player->getMoney() < armour.armourVector[choice].price) {

			cout << "No money no talk! ";

		}
		else if (choice ==armour.armourVector.size()) {
			return 0;
		}
		
	} while (player->getMoney() <= armour.armourVector[choice].price);
	player->addMoney(-armour.armourVector[choice].price);
	player->setArmourID(choice);
	return 0;

}

int Shop::displayPotions(Potions potion,Player *player)
{
	system("cls");
	ConsoleWindow::equalSignMaker9000(80);
	ConsoleWindow::SetDrawingPoint(0, potion.potionVector.size()+2);
	ConsoleWindow::equalSignMaker9000(80);
	ConsoleWindow::getCursorXY();
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
	ConsoleWindow::SetDrawingPoint(ConsoleWindow::x, ConsoleWindow::y);
	cout << potion.potionVector.size() << ": Exit" << endl;
	////// VALIDATION CHECK
	do {
		cout << "Enter which potion you want to buy : ";
		while (!(cin >> choice) || choice > potion.potionVector.size() || choice < 1) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Enter a valid item number!";


		}
		if(choice != 4){
			if(player->getMoney() >= potion.potionVector[choice - 1].price){
			cout << "Enter how much you want to buy : ";
		while (!(cin >> quantity) || quantity > 99 || quantity < 1) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Enter a valid item number!\n";


		}
			}
		}
		else if (choice == potion.potionVector.size()) {
			return 0;
		}
		//////CALCULATIONS
		potion.potionVector[choice-1].price *= quantity;
		if (player->getMoney() < potion.potionVector[choice-1].price) {

			cout << "No money no talk! \n";

		}
		

	} while (player->getMoney() <= potion.potionVector[choice-1].price);
	
	player->addMoney(-potion.potionVector[choice-1].price);
	player->addPotion(quantity,choice-1);
	return 0;

}
		    