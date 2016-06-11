/*
C++ Programming Assignment
Text Based RPG Game
By : Keith, Ben and Zer
Date : 10/6/2016
*/
#include <iostream>
#include <time.h> // to use the rand() function
#include <windows.h>// to use the function sleep
#include <string> //STRING DATA TYPE?!
int BattleSystem();
int DaySystem(int choice);
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
	int hour;
	int timeSpent;

	int CalculateTime(int hour) {
		day.hour += hour;
		if (day.hour>24) {
			day.hour -= 24; // This changes the actual value of day.hour
		}
		
		return day.hour;
	}
}day;
int choice; ////Temporary variable to store choices of player.


int main() {
	Character player;
	day.hour = 24;
	
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
	/*
	////////// TIMER COUNTDOWN SYSTEM(MAYBE USE TO KEEP THE SUSPENSE OF UPGRADING WEAPONS?
	for (int a = 5; a >=0; a--) {
		cout << endl << a << "...";
		Sleep(1000); // time is measured in milli second
	}
	*/
	// DAY NIGHT SYSTEM
	while (choice != 3) {
		system("cls");
		cout << "Time now is: ";
		
		if ( day.hour >12 || day.hour>=24) { // Check if its 12 p.m to avoid 0 p.m.
			cout << day.hour - 12;  // this equation only Displays the time, It does not change day.hour value
		}
		else {
			cout << day.hour; // otherwise the time will be displayed normally
		}
		if (day.hour > 11 && day.hour <= 23) {  // to check if the time is PM or AM
			
			cout << " p.m." << endl;
			}
		
		else{
			
			cout << " a.m." << endl;
		}
		cout<< endl << "2.Add 1 hour(Temp function to test day/night)";
		cin >> choice;
		DaySystem(choice);
		
		
	}
	system("pause");
}

int BattleSystem() {
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
	return 0;
}

int DaySystem(int choice) {
	/*
	if (choice == 1) {
		cout << "Time now is " << day.hour;    // This section tells the player the time if they use check time
		if (day.hour > 11 && day.hour <= 23) { // It is now commented out for the time being.
			cout << " p.m" << endl;
		}
		else {
			cout << " a.m" << endl;
		}
		
	}*/
	 if (choice == 2) {
		 day.CalculateTime(4);
		

	}
	return 0;
}