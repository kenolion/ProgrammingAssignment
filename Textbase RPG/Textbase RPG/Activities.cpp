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
	

}