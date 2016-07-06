#include "Character.h"





Character::Character()
{
	cout << "This is accessing the ";
}


Character::~Character()
{
	
}

int Character::getExp()
{
	return this->exp;
}

int Character::damageDealt() {

	return rand() % maxAtk + minAtk;

}

void Character::setMinAtk(int damage){
	minAtk = damage;
}

void Character::setMaxAtk(int damage){
	maxAtk = damage;
}

void Character::setPlayerName(string name){
	PlayerName = name;
}

string Character::getPlayerName() {
	return PlayerName;
}
