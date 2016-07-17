#include "Activities.h"
#include "Time.h"
#include "BattleSystem.h"
#include "ConsoleWindow.h"
void randLearningMessage();

Activities::Activities()
{
}


Activities::~Activities()
{
}

int Activities::gym()
{
	return 0;
}

int Activities::school(){
	
	
	cout << "You decided to go to school.\n";
	randLearningMessage();
	
	return 0;
}

int Activities::adventure()
{
	return 0;
}

int Activities::home()
{	
	Time day;
	do {
		system("cls");
		ConsoleWindow::equalSignMaker9000(80);
		cout << "Welcome home. You have 5 hours before the monsters arrive.\nEvery action takes an hour. Choose wisely" << endl;
		cout << "1.Prepare your Weapons. (+2 Attack before the fight) [1 Hour]" << endl;
		cout << "2.Prepare your Defences. (+2 Health before the fight) [1 Hour]" << endl;
		cout << "3.Prepare scavanging. (2% chance higher of finding a random item from killing a monster) [1 Hour]" << endl;
		day.displayTime();
		ConsoleWindow::equalSignMaker9000(80);
		cin >> action;
		switch (action)
		{
		case 1:
		{
			day.calculateTime(1);
		}
		}
	}while (day.getHour() < 24);
	BattleSystem::battleSystem();
	return 0;
}

int Activities::work()
{
	return 0;
}

int Activities::shopping()
{
	return 0;
}

int Activities::fightCrime()
{
	return 0;
}


//randLearningMessage Function
void randLearningMessage() {
	Sleep(1000);
	int randNum = rand() % 16;
	int i = 0;
	ifstream infile("randLearningMessage.txt");
	string randCom[16];
	if (infile.fail()) {
		cout << "Error Opening File " << endl;
		system("pause");
		exit(1);
	}
	while (!infile.eof())
	{
		getline(infile, randCom[i]);
		if (randNum == i) {
			cout << randCom[i] << endl;
		}
		i++;
		
	}
	for (int a = 0; a < 80; a++) { cout << "="; };
	system("pause");
	Sleep(1000);
}