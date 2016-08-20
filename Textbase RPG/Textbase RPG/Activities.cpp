#include "Activities.h"

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


int Activities::fightCrime(Player *player, Weapons weapon, Armours armour, Monster monster)
{
	cout << "You decided to FIGHT CRIME!\n";
	cout << "Crimes are harder to beat compared to normal monsters. However, the payout is higher.\n";
	int randNum;
	randNum = rand() % 2+4; // 4-6
	Game::battleSystem(player, weapon, armour, monster, 2);
	return 0;
}
int Activities::adventure()
{
	return 0;
}

int Activities::home(Player *player, Weapons weapon, Armours armour, Monster monster)
{	
	Time day;
	do {
		ConsoleWindow::getCursorXY();
		player->showItemandStats(weapon, armour, ConsoleWindow::x, ConsoleWindow::y);
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
	Game::battleSystem(player, weapon, armour, monster, 2);				// NEEDS TO BE EDITED AS WELL for now it will be 2
	return 0;
}

int Activities::randEvents(Player *player, Weapons weapon, Armours armour, Monster monster)
{

	static int randNum = 4;
	int playerinput;

	switch (randNum)
	{
	case 0:
		system("cls"); //SCENARIO START
		Sleep(1200);
		cout << "You see a hooded-muscular man walking towards you.";
		Sleep(1200);
		cout << "."; Sleep(200);cout << "."; Sleep(200);cout << "."; Sleep(200); cout << "."; Sleep(200);cout << "."; Sleep(200);cout << "."; Sleep(200);cout << ".\n\n\n";
		Sleep(1200);
		cout << "This is trouble...\n\n\n";
		Sleep(1200);
		system("pause");
		system("cls");
		Sleep(1200);
		cout << "Middle-aged Man : ....Hello there young man.\n\n\n";
		system("pause");
		system("cls");
		cout << "Middle-aged Man : ....Hello there young man.\n";
		Sleep(2500);
		cout << "Middle-aged Man : It's a dangerous move choosing to stay out here in the open..\n";
		Sleep(2500);
		cout << "Middle-aged Man : You've got quite an attractive sword right there.\n";
		Sleep(2500);
		cout<<"  Middle-aged Man : Mind If I take it from you ? \n\n\n";
		Sleep(3500); //SCENARIO END

		cout << " CHOOSE YOUR ACTION.\n";
		ConsoleWindow::equalSignMaker9000(80);
		cout << " 1. *Stay Silent*\n\n";
		cout << " 2. Mind your own business old bag. I'll give you 10 seconds to run before I\n\tshow 'YOU' an attractive beating.\n\n";
		cout << " 3. *Attempt to run away.*\n";
		ConsoleWindow::equalSignMaker9000(80);
		cout << "YOUR DECISION :";
		cin >> playerinput;

		if (playerinput == 1)
		{
			system("cls");
			cout << "You chose to stay silent.\n\n\n";
			Sleep(2500);
			cout << "Middle-aged Man : Hey, I asked you a question.\n\n";

			Sleep(2500);
			cout << "."; Sleep(500); cout << "."; Sleep(500); cout << "."; cout << "."; Sleep(500); cout << ".\n\n";

			Sleep(2500);
			cout << "Middle-aged Man : You deaf, kid?? Want me to make your mouth move?\n\n";

			Sleep(2500);
			cout << "."; Sleep(500); cout << "."; Sleep(500); cout << "."; cout << "."; Sleep(500); cout << ".\n\n";

			Sleep(2500);
			cout << "*The Man walks up to you and Grabs you by your shirt*\n\n"; 	

			Sleep(2500);
			cout << "*You shoved him away from you and ready your weapon.\n";

			Sleep(1500);
			Game::battleSystem(player,weapon,armour,monster,11);
		}
		else if (playerinput == 2)
		{
			system("cls");
			cout <<" You chose to say :' Mind your own business old bag. I'll give you 10 seconds to run before I\n\t show 'YOU' an attractive beating'.\n\n\n";
			Sleep(2500);
			cout << "Middle-aged Man : Woah now.\n";
			Sleep(2500);
			cout << "Middle-aged Man : Didn't your parents told you to respect your elders?\n\n";
			Sleep(3500);
			cout << "You can have my respect.\n";
			Sleep(2500);
			cout << "At your own grave once I'm done with you.\n";
			
			Sleep(2500);
			Game::battleSystem(player, weapon, armour, monster, 11);
		}
		else
		{
			system("cls");
			cout << "Middle-aged Man : You're not running anywhere!\n";
			Sleep(2500);
			Game::battleSystem(player, weapon, armour, monster, 11);
		}
		randNum++;
		break;

	case 1 :
	{
		system("cls"); //SCENARIO START
		Sleep(1200);
		cout << "You see a girl in highschool uniform walking on the opposite street.\n";
		Sleep(1200);
		cout << "."; Sleep(200); cout << "."; Sleep(200); cout << "."; Sleep(200); cout << "."; Sleep(200); cout << "."; Sleep(200); cout << "."; Sleep(200); cout << ".\n\n\n";
		Sleep(1200);
		cout << "Hell yeah. I'm going to score tonight.\n\n\n";
		Sleep(3500); //SCENARIO END

		cout << " CHOOSE YOUR ACTION.\n";
		ConsoleWindow::equalSignMaker9000(80);
		cout << " 1. Do bird calls to the girl in attempt to attract the girl's attention,\n\t(like the shameless dude you are.)\n\n";
		cout << " 2. *Attempt to act cool by balancing your blade with one finger*.\n\n";
		cout << " 3. Ignore her existance and focus on your objective.\n";
		ConsoleWindow::equalSignMaker9000(80);
		cout << "YOUR DECISION :";
		cin >> playerinput;

		if (playerinput == 1)
		{
			system("cls");
			cout << "You chose to do stupid bird calls to the girl.\n\n\n";
			Sleep(1200);
			cout << "*PEWWIT* "; Sleep(200); cout << "*PEWWIT* "; Sleep(200); cout << "*PEWWIT* "; Sleep(200); cout << "*PEWWIT* "; Sleep(200); cout << "*PEWWIT* "; Sleep(200); cout << "*PEWWIT* "; Sleep(200); cout << ".\n\n\n";
			Sleep(1200);
			cout << "Highschool Girl : SHUT UP!!!!!!!!!!!!!\n\n\n";
			Sleep(2500);
			cout << "*The highschool girl runs faster in an attempt to escape from your stupidity.*\n\n\n";
			Sleep(2500);
			cout << "...Well shit.\n\n\n";
			Sleep(2500);
			cout << "*The girl escaped.*\n";
			Sleep(2500);
			break;
		}
		else if (playerinput == 2)
		{
			system("cls");
			cout << "You chose to act cool by balancing your blade with one finger.\n\n\n";
			Sleep(1200);
			cout << "."; Sleep(200); cout << "."; Sleep(200); cout << "."; Sleep(200); cout << "."; Sleep(200); cout << "."; Sleep(200); cout << "."; Sleep(200); cout << ".\n\n\n";

			Sleep(500);
			cout << "."; Sleep(200); cout << "."; Sleep(200); cout << "."; Sleep(200); cout << "."; Sleep(200); cout << "."; Sleep(200); cout << "."; Sleep(200); cout << "."; Sleep(200); cout << "."; Sleep(200); cout << "."; Sleep(200); cout << "."; Sleep(200); cout << ".\n\n\n";
			Sleep(500);

			cout << "*..The girl didn't notice you..*\n\n\n";
			Sleep(2500);
			break;
		}
		else
		{
			system("cls");
			cout << "You chose to ignore her existance and focus on your objective.\n\n\n";
			Sleep(2500);
			cout << "Strangely, the girl walks towards you.\n\n\n";
			Sleep(2500);
			cout << "Highschool Girl : Today is your unlucky day sir.\n";
			Sleep(2500);
			cout << "Highschool Girl : I know you're trying to purge the world of evil creatures.\n\n";
			Sleep(2500);
			cout << "How so?\n\n";
			Sleep(2500);
			cout << "Highschool Girl : This is a popular spot where monsters will pass by.\n";
			Sleep(2500);
			cout << "Highschool Girl : Think of this as popular route for us to take.\n";
			Sleep(2500);
			cout << "Highschool Girl : No one just sits here silently like you do.\n\n";
			Sleep(2500);
			cout << "'Us'?\n\n";
			Sleep(1200);
			cout << "Highschool Girl : Whoops.\n\n";
			Sleep(2500);
			system("cls");
			Sleep(2500);
			cout << "Highschool Girl : I guess I said too much.\n\n";
			Sleep(2500);														
			Game::battleSystem(player, weapon, armour, monster, 1);			
		}
	
	break;
	}
		case 2:
		{
			system("cls"); //SCENARIO START
			Sleep(1200);
			cout << "."; Sleep(200); cout << "."; Sleep(200); cout << "."; Sleep(200); cout << "."; Sleep(200); cout << "."; Sleep(200); cout << "."; Sleep(200); cout << ".\n\n\n";
			Sleep(2500);
			cout << "It's too quiet....\n";
			Sleep(2500);
			cout << "."; Sleep(200); cout << "."; Sleep(200); cout << "."; Sleep(200); cout << "."; Sleep(200); cout << "."; Sleep(200); cout << "."; Sleep(200); cout << ".\n";
			cout << "I guess purging monsters isn't always an easy job.\n";
			Sleep(2500);
			cout << "."; Sleep(200); cout << "."; Sleep(200); cout << "."; Sleep(200); cout << "."; Sleep(200); cout << "."; Sleep(200); cout << "."; Sleep(200); cout << ".\n";
			cout << "It's a dirty job but someone's gotta do it.\n";
			Sleep(2500);
			cout << "."; Sleep(200); cout << "."; Sleep(200); cout << "."; Sleep(200); cout << "."; Sleep(200); cout << "."; Sleep(200); cout << "."; Sleep(200); cout << ".\n";
			system("cls");
			Sleep(2500);
			cout << ".....What's that smell?....\n";
			Sleep(2500);
			cout << ".........smells.......\n";
			Sleep(2500);
			cout << "....nice.....\n\n\n";
			Sleep(3500);
			ConsoleWindow::equalSignMaker9000(80);
			ConsoleWindow::SetDrawingPoint(0, 11);
			ConsoleWindow::equalSignMaker9000(80);
			ConsoleWindow::SetDrawingPoint(0, 6);
			cout << "\nPRESS UP AND DOWN RAPIDLY TO KEEP THE PLAYER AWAKE : \n";
			int bar = 0;
			cout << "(";
			for (int i = 0; i <= 59; i++) { cout << " "; } // PRINTS OUT 58 SPACES
			int c = 1;
			cout << ")";
			while (bar != 60)
			{
				_getch(); // IT WILL STRAIGHT AWAY REGISTER THAT KEY WITHOUT PRESSING ENTER
				char key = _getch();
				ConsoleWindow::SetDrawingPoint(c, 8);
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
			Sleep(2500);
			system("cls");
			cout << "\n\n\n*You manage to wake yourself up from the sleeping gas.*\n\n\n";
			Sleep(2500);
			cout << "WHO IS IT?\n";
			Sleep(2000);
			cout << "COME OUT AND FIGHT ME, COWARD.\n";
			Sleep(2500);
			system("cls");
			Sleep(2000);
			cout << "??? : Be careful on what you wish for, peasant.";
			Sleep(2500);
			Game::battleSystem(player, weapon, armour, monster, 3);			  //UNKNOWN MONSTER NEEDS TO BE EDITED
			break;
		}
		case 3:
		{
			system("cls"); //SCENARIO START
			Sleep(2500);
			cout << "*You see a small dot in the sky*\n\n";
			Sleep(2500);
			cout << "*The dot progressively grows bigger*\n\n";
			Sleep(2500);
			cout << "Wait a minute....\n";
			Sleep(2500);
			cout << "THAT'S A CREATURE FLYING TOWARDS ME.\n\n";
			Sleep(2500);
			Game::battleSystem(player, weapon, armour, monster, 4);
			break;
		}
		case 4:
		{
			system("cls");
			Sleep(1200);
			cout << "."; Sleep(200); cout << "."; Sleep(200); cout << "."; Sleep(200); cout << "."; Sleep(200); cout << "."; Sleep(200); cout << "."; Sleep(200); cout << "."; Sleep(200); cout << "."; Sleep(200); cout << "."; Sleep(200); cout << "."; Sleep(200); cout << ".\n\n\n";
			Sleep(2500);
			cout << "???? : Hello, Agent 1447.\n\n";
			Sleep(2500);
			cout << "???? : We meet again.\n\n";
			Sleep(2500);
			cout << "???? : I see you're trying to purge monsters as usual?\n\n";
			Sleep(2500);
			cout << "???? : Good...."; 	Sleep(2500); cout << "..Good...\n\n";
			Sleep(2500);
			cout << "???? : Consider this as a gift.\n\n";
			Sleep(2500);
			system("pause");
		}
	}
	return 0;
}

//randLearningMessage Function
void Activities::randLearningMessage(int textFileNo) {
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