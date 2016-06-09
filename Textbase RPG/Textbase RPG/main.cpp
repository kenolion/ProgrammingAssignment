#include <iostream>
using namespace std;

class character {
	public:
	char name[15];
	int job; //1=Swordsman,2= Archer, 3= Deprived(not an actual class just decided to put it there)


};

int main() {
	int choice; //Temporary variable to store choices of player.
	character player; // Players information

	cout << "Please Enter your name: "; 
	cin >> player.name;  //Gets player name
	cout << "Master " << player.name <<". What job do you want to choose next?"<< endl;
	cout << "1.Swordsman" << endl << "2.Archer" << endl << "3.Deprived" << endl;
	cin >> player.job;
	cout << "Character Info" << endl;
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
	cout << endl;

	system("pause");
}

