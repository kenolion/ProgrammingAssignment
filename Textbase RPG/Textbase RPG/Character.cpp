#include "Character.h"
#include "iostream"
using namespace std;



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
