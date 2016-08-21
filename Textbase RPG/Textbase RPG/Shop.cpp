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
	cout << "WeaponID Item name\t\t";
	cout << "Item price\t";
	cout << "Weapon Damage\n";

	for (int column = 1; column < weapon.weaponVector.size()-1; column++) 
	{
		cout << weapon.weaponVector[column].itemId <<"\t";
		cout << weapon.weaponVector[column].name <<"\t\t";
		cout << weapon.weaponVector[column].price << "\t\t";
		cout << weapon.weaponVector[column].maxAtk << "-";
		cout << weapon.weaponVector[column].minAtk << endl;
	}	
	
	cout << weapon.weaponVector.size() << "Exit" << endl;
	////// VALIDATION CHECK
	anger = 0; // ZER ADDED THIS
	Sleep(1000);
	cout << "\n\nShopkeeper : What would you like to buy? (Enter WeaponID) : ";
	do{
	while(!(cin >> choice) ||choice > weapon.weaponVector.size() || choice < 1){
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Enter a valid item number!";

	}
	if (anger == 2) 
	{
		Sleep(1000); 
		cout << "\nShopkeeper : Fuck off.\n\n"; // ZER ADDED THIS
		Sleep(2500);
		cout << "*You have been kicked out from the shop*\n"; // ZER ADDED THIS
		Sleep(2500);
		return 0;
	}
	if (player->getMoney() < weapon.weaponVector[choice].price) {

		Sleep(1000);
		cout << "\nShopkeeper : No money no talk! \n"; // ZER ADDED THIS
		Sleep(1000);
		cout << "Shopkeeper : Pick something you can buy, you peasant! (12 to exit) : "; // ZER ADDED THIS
		anger++;

	}else if(choice == weapon.weaponVector.size()){
		return 0;
	}
	} while (player->getMoney() <= weapon.weaponVector[choice].price);
	player->addMoney(-weapon.weaponVector[choice].price);
	player->setWeaponID(choice);
	Sleep(1000);
	cout << "\nShopkeeper : Enjoy your new weapon! Please come again!\n";
	Sleep(2500);
	
	return 0;
		    
		    
	}	    
		    

int Shop::displayArmour(Armours armour,Player *player)
{
	system("cls");
	ConsoleWindow::equalSignMaker9000(80);
	ConsoleWindow::SetDrawingPoint(0, armour.armourVector.size()+1);
	ConsoleWindow::equalSignMaker9000(80);
	ConsoleWindow::getCursorXY();
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

	ConsoleWindow::SetDrawingPoint(ConsoleWindow::x, ConsoleWindow::y);
	cout << armour.armourVector.size() << ": Exit" << endl;
	Sleep(1000);


	cout << "\nShopkeeper : What would you like to buy? (Enter ArmourID) : ";
	////// VALIDATION CHECK
	anger = 0; // ZER ADDED THIS
	do {
		while (!(cin >> choice) || choice > armour.armourVector.size() || choice < 1) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Enter a valid item number!";

		}
		if (anger == 2)
		{
			Sleep(1000);
			cout << "\nShopkeeper : Fuck off.\n\n"; // ZER ADDED THIS
			Sleep(2500);
			cout << "*You have been kicked out from the shop*\n"; // ZER ADDED THIS
			Sleep(2500);
			return 0;
		}
		if (player->getMoney() < armour.armourVector[choice].price) {
		
		
			Sleep(1000);
			cout << "\nShopkeeper : No money no talk! \n"; // ZER ADDED THIS
			Sleep(1000);
			cout << "Shopkeeper : Pick something you can buy, you peasant! (12 to exit) : "; // ZER ADDED THIS
			anger++;
			
		}
		else if (choice ==armour.armourVector.size()) {
			return 0;
		}
		
	} while (player->getMoney() <= armour.armourVector[choice].price);
	player->addMoney(-armour.armourVector[choice].price);
	player->setArmourID(choice);
	Sleep(1000);
	cout << "\nShopkeeper : Enjoy your new suit! Please come again!\n";
	Sleep(2500);
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
	Sleep(1000);
	cout << "\nShopkeeper : What would you like to buy? (Enter PotionID) : ";
	////// VALIDATION CHECK
	anger = 0; // ZER ADDED THIS
	do {
		while (!(cin >> choice) || choice > potion.potionVector.size() || choice < 1) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Enter a valid item number!";

		

		}
		if (choice != 4) {
			if (player->getMoney() >= potion.potionVector[choice - 1].price) {
				cout << "Enter how much you want to buy : ";
				while (!(cin >> quantity) || quantity > 99 || quantity < 1) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Enter a valid item number!\n";


				}
			}
			if (anger == 2)
			{
				Sleep(1000);
				cout << "\nShopkeeper : Fuck off.\n\n"; // ZER ADDED THIS
				Sleep(2500);
				cout << "*You have been kicked out from the shop*\n"; // ZER ADDED THIS
				Sleep(2500);
				return 0;
			}
		}
		else if (choice == potion.potionVector.size()) {
			return 0;
		}
		else if (choice == potion.potionVector.size()) {
			return 0;
		}
		//////CALCULATIONS
		potion.potionVector[choice-1].price *= quantity;
		if (player->getMoney() < potion.potionVector[choice-1].price) {
			Sleep(1000);
			cout << "\nShopkeeper : No money no talk! \n"; // ZER ADDED THIS
			Sleep(1000);
			cout << "Shopkeeper : Pick something you can buy, you peasant! (4 to exit) : "; // ZER ADDED THIS
			anger++;
		}

		potion.potionVector[choice - 1].price /= quantity;
	} while (player->getMoney() < potion.potionVector[choice-1].price);
	
	player->addMoney(-potion.potionVector[choice-1].price);
	player->addPotion(quantity,choice-1);
	Sleep(1000);
	cout << "\nShopkeeper : Enjoy your potions! Please come again!\n";
	Sleep(2500);

	return 0;

}
		    