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

void randLearningMessage() {
	string randCom[2];
	int num = rand() % 2;
	int i = 0;
	string finalCom;
	ifstream infile("randLearningMessage.txt");

	while (infile.eof() >> randCom[i])
	{
		if (num = i) {
			cout << randCom[num];
		}
		i++;
	}
	system("pause");
}