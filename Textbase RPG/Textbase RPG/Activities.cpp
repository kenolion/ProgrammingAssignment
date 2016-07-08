#include "Activities.h"


Activities::Activities()
{
}


Activities::~Activities()
{
}

int Activities::school(){
	Player player;
	
	cout << "You decided to go to school";
	player.addIntel(2);
}

int Activities::gym() {

	Player player;
	cout << "You decided to visit the gym!";
	player.addStr(2);
}

int Activities::home() {
	cout << "What do you want to do at home?";
	cout << "1.Sleep";

}

