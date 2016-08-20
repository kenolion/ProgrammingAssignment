#include "Character.h"


Character::Character()
{

}




Character::~Character()
{
	
}

int Character::attack() {

	return rand() % character.maxAtk + character.minAtk;

}

void Character::setMinAtk(int damage){
	character.minAtk = damage;
}

void Character::setMaxAtk(int damage){
	character.maxAtk = damage;
}



string Character::getCharacterName() {
	return  character.characterName;
}

int Character::getHp()
{
	return  character.hp;
}

int Character::getHp(int monsterID)
{
	return characterVector[monsterID].hp;
}

void Character::setHp(int hp)
{
	character.hp = hp;
}
