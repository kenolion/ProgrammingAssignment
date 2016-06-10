
#include <iostream>
#include <time.h> // to use the rand() function
#include <windows.h>// to use the function sleep
using namespace std;

class Character {
	public:
	char name[15];
	int job; //1=Swordsman,2= Archer, 3= Deprived(not an actual class just decided to put it there in the mean time)
	int hp;
	int minAtk;
	int maxAtk;
	int damageDealt;
};

class Time {
	public:
	static int hour;
	int timeSpent;


};



int main() {
	Time day;
	day.hour = 0;
	int choice; //Temporary variable to store choices of player.
	Character player; // Players information
	Character monster;
	/////////////////// TEMPORARY DECLARATION AREA WILL BE REMOVED LATER FOR TESTING PURPOSES
	monster.hp = 100; // Lets assume its 10 for now. going to remove this line of code later
	player.maxAtk = 10;
	player.minAtk = 1;
	player.hp = 100;
	monster.maxAtk = 5;
	monster.minAtk = 0;

	///////////////////////
	cout << "Please Enter your name: ";
	cin >> player.name;  //Gets player name
	cout << "Master " << player.name << ". What job do you want to choose next?" << endl;
	cout << "1.Swordsman" << endl << "2.Archer" << endl << "3.Deprived" << endl;
	cin >> player.job;  // Getting input from player to choose their job
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
	////////// TIMER COUNTDOWN SYSTEM(MAYBE USE TO KEEP THE SUSPENSE OF UPGRADING WEAPONS?
	for (int a = 5; a >=0; a--) {
		cout << endl << a << "...";
		Sleep(1000);
	}
	//////// Simeple BATTLE SYSTEM   /////////
	system("cls");
	srand(time(NULL));
	cout << endl << "You have encountered a (monsters name)!" << endl;
	cout << "Monster Hp :" << monster.hp << endl;
	do {																	// do while loop to enable a turn based like battle system
		cout << "What would you do?" << endl;
		cout << "1.Attack" << endl << "2.Run" << endl;
		cin >> choice;
		system("cls");
		if (choice == 1) {
			player.damageDealt = rand() % player.maxAtk + player.minAtk; // CALCULATING THE ATTACK RANGE
			monster.damageDealt = rand() % monster.maxAtk + monster.minAtk; // calculating monster attack
			monster.hp -= player.damageDealt; //MINUSING THE MONSTERS HP
			player.hp -= monster.damageDealt; // Monster turn to attack
			cout << "You did " << player.damageDealt << " damage." << endl;
			cout << "The monster did " << monster.damageDealt << " damage" << endl;
			cout << "You now have " << player.hp << " hp left" << endl;
			cout << "The monster now has " << monster.hp << "hp" << endl;
		}
	} while (monster.hp > 0 || player.hp >0);
	system("pause");
}

int DurationSystem() {
	

}
