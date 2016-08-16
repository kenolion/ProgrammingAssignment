#include "Activities.h"
#include "Time.h"
#include "ConsoleWindow.h"
#include "Game.h"
#include "Monster.h"
void randLearningMessage(int textFileNo);

Activities::Activities()
{
}


Activities::~Activities()
{
}

int Activities::gym()
{
	cout << "You decided to go to the gym.\n"; 
	cout << "Press THE UP AND DOWN ARROW KEY TO INCREASE THE *ACTIVITIES BAR* \nAND WORK OUT IN THE GYM!!!\n\n";
	int bar = 0;
	cout << "(";
	for (int i = 0; i <= 59; i++) { cout << " "; } // PRINTS OUT 58 SPACES
	int c = 1;
	cout << ")";
	while (bar != 60)
	{
		_getch(); // IT WILL STRAIGHT AWAY REGISTER THAT KEY WITHOUT PRESSING ENTER
		char key = _getch();
		ConsoleWindow::SetDrawingPoint(c, 5);
		switch (key) {
		case KEY_UP:
		{
			cout << "|";
			bar++;
			c++;
			break;
		}
		case KEY_DOWN:
		{

			cout << "|";
			bar++;
			c++;
			break;
		}
	
		}
	}
	cout << "\n\n";
	randLearningMessage(2);
	ConsoleWindow::equalSignMaker9000(80);
	system("pause");
	return 0;
}

int Activities::school(){

	cout << "You decided to go to school.\n";
	cout << "Press THE UP AND DOWN ARROW KEY TO INCREASE THE *ACTIVITIES BAR* \nAND LEARN AT SCHOOL!!!\n\n";
	int bar = 0;
	cout << "("; 
	for (int i = 0; i <= 59; i++) { cout << " "; } // PRINTS OUT 58 SPACES
	int c = 1;
	cout << ")";
	while (bar != 60)
	{
		_getch(); // IT WILL STRAIGHT AWAY REGISTER THAT KEY WITHOUT PRESSING ENTER
		char key = _getch();
		ConsoleWindow::SetDrawingPoint(c, 5);
		switch (key) {
		case KEY_UP:
		{
			cout << "|";
			bar++;
			c++;
			break;
		}
		case KEY_DOWN:
		{

			cout << "|";
			bar++;
			c++;
			break;
		}

		}
	}
	cout << "\n\n";
	randLearningMessage(1);
	ConsoleWindow::equalSignMaker9000(80);
	system("pause");
	return 0;
}

int Activities::work()
{
	cout << "You decided to go to work at your local McDonalds! You're loving it!\n";
	cout << "Press THE UP AND DOWN ARROW KEY TO INCREASE THE *ACTIVITIES BAR* \nAND WORK FOR MONEY!!!\n\n";
	int bar = 0;
	cout << "(";
	for (int i = 0; i <= 59; i++) { cout << " "; } // PRINTS OUT 58 SPACES
	int c = 1;
	cout << ")";
	while (bar != 60)
	{
		_getch(); // IT WILL STRAIGHT AWAY REGISTER THAT KEY WITHOUT PRESSING ENTER
		char key = _getch();
		ConsoleWindow::SetDrawingPoint(c, 5);
		switch (key) {
		case KEY_UP:
		{
			cout << "|";
			bar++;
			c++;
			break;
		}
		case KEY_DOWN:
		{

			cout << "|";
			bar++;
			c++;
			break;
		}

		}
	}
	cout << "\n\n";
	randLearningMessage(3);
	ConsoleWindow::equalSignMaker9000(80);
	system("pause");
	return 0;
}


int Activities::fightCrime()
{
	cout << "You decided to FIGHT CRIME!\n";
	cout << "Crimes are harder to beat compared to normal monsters.\n";
	Game::battleSystem();
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
		Game::showItemandStats();
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
			break;
			//Attack + 2
		}
		case 2:
		{
			day.calculateTime(1);
			break;
			//Health + 2
		}
		case 3:
		{
			day.calculateTime(1);
			break;
			//Chance to find items +2
		}
		}
	}while (Time::getHour() < 24);
	Game::battleSystem();
	return 0;
}


int Activities::randEvents()
{
//	cout << "You decided to FIGHT CRIME!\n";
	return 0;
}

//randLearningMessage Function
void randLearningMessage(int textFileNo) {
	int randNum;
	int i = 0;
	ifstream infile("randLearningMessage.txt");

	if ( textFileNo == 1) { //School Random Messages
		randNum = rand() % 16; // 0 - 15
		Sleep(1000);
	}
	else if (textFileNo == 2) { //Gym Random Messages
		randNum = rand() % 16+16; // 16 - 32
		Sleep(1000);
	}
	else if (textFileNo == 3) { //Working Random Messages
		randNum = rand() % 9+33; // 33 - 42
		Sleep(1000);
	}
	else if (textFileNo == 4) { // Workout Motivational Messages
		randNum = rand() % 10 + 43; // 43 - 53
	}

	string randCom[100];

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
}