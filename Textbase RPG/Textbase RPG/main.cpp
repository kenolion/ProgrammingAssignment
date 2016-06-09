
#include <iostream>
using namespace std;

class Character {
	public:
	char name[15];
	int job; //1=Swordsman,2= Archer, 3= Deprived(not an actual class just decided to put it there)
	int hp;
	int minAtk;
	int maxAtk;
	int damageDealt;
};



int main() {
	int choice; //Temporary variable to store choices of player.
	Character player; // Players information
	Character monster;
	/////////////////// TEMPORARY DECLARATION AREA WILL BE REMOVED LATER FOR TESTING PURPOSES
	monster.hp = 100; // Lets assume its 10 for now. going to remove this line of code later
	player.maxAtk = 10;
	player.minAtk = 1;

	///////
	cout << "Please Enter your name: ";
	cin >> player.name;  //Gets player name
	cout << "Master " << player.name << ". What job do you want to choose next?" << endl;
	cout << "1.Swordsman" << endl << "2.Archer" << endl << "3.Deprived" << endl;
	cin >> player.job;
	cout << "Character Info" << endl; //Displays character Info
	cout << "Name : " << player.name << endl;
	cout << "Class : ";
	switch (player.job)
	{
	case 1:
		cout << "Swordsman";
		break;
	case 2:
		cout << "Archer";
		break;
	case 3:
		cout << "Deprived";
		break;
	}
	//////// Simeple ONE SIDED BATTLE SYSTEM   /////////
	cout << endl << "You have encountered a (monsters name)!" << endl;
	cout << "Monster Hp :" << monster.hp << endl;
	do {
		cout << "What would you do?" << endl;
		cout << "1.Attack" << endl << "2.Run" << endl;
		cin >> choice;
		if (choice == 1) {
			player.damageDealt = rand() % player.maxAtk + player.minAtk; // CALCULATING THE ATTACK RANGE
			monster.hp -= player.damageDealt; //MINUSING THE MONSTERS HP
			cout << "You did " << player.damageDealt << " damage." << endl;
			cout << "The monster now has " << monster.hp << "hp" << endl;
		}
	} while (monster.hp >= 0);
	system("pause");
}