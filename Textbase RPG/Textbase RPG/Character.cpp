#include "Character.h"





Character::Character()
{

}


Character::~Character()
{
	
}

int Character::attack() {


	return rand() % maxAtk + minAtk;
	
}

void Character::setMinAtk(int damage){
	minAtk = damage;
}

void Character::setMaxAtk(int damage){
	maxAtk = damage;
}



string Character::getCharacterName() {
	return characterName;
}

int Character::getHp()
{
	return hp;
}

void Character::setHp(int hp)
{

	this->hp = hp;
}
