#pragma once
#include "Girls.h"

using namespace std;

class Harem : public Girls
{

private:

	int playerSelection;
	int girlHistory;
	int girlQuestion;
	int dialogue;
	


public:
	Harem();
	~Harem();

	int menu();

	int chooseGirl(int input);
	void talk(int input);
	void findGirl();
	void dateGirl();
	void showGirlTraits();
	void showGirls();
};

