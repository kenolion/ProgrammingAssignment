#include <iostream>
#include <string>

using namespace std;
class Monster {
public:
	char monName[15];
	double totalSpd, spd;
	int addSpd;
	

};

int main() {
	int choice;
	int ldrSkill = 100;
	Monster mon[10];
	cout << "How many Monsters you want to compare?" << endl;
	cin >> choice;

		cout << "Enter your leader skill amount\n";
		cin >> ldrSkill;
		for (int i = 0; i < choice; i++) {
			cout <<i+1<< ".Monsters Name: ";
			cin >> mon[i].monName;
			cout << "Enter your unit's base speed\n";
			cin >> mon[i].spd;
			cout << "Plus How much speed?\n";
			cin >> mon[i].addSpd;
			mon[i].totalSpd = (mon[i].spd *1.15) + (mon[i].spd*ldrSkill / 100);

		}

		for (int i = 0; i < choice; i++) {
			cout <<i+1 <<"."<<mon[i].monName;
			cout << "\nBase speed: " << mon[i].spd << endl;
			cout << "Speed after tower: " << mon[i].spd *1.15 << endl;
			cout << "Speed after tower and leader skill: " << mon[i].totalSpd << endl;
			cout << "Final Speed after adding everything: " << mon[i].totalSpd + mon[i].addSpd << endl << endl;

		}
	
	system("pause");
}