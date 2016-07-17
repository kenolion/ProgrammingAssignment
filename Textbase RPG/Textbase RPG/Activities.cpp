#include "Activities.h"
#include "Time.h"
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
	Player player;
	Time time;
	
	cout << "You decided to go to school.\n";
	randLearningMessage();
	
	player.addIntel(2);
	time.calculateTime(6);
}

int Activities::adventure()
{
	return 0;
}

int Activities::home()
{
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