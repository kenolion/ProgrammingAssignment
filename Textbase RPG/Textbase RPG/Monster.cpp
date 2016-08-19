#include "Monster.h"

Monster::Monster()
{
}


Monster::~Monster()
{
}

void Monster::readMonsterDatabase()
{
	ifstream Monster("mons_database.txt");
	getline(Monster, temp);
	getline(Monster, temp);
	
	while (!Monster.eof())
	{
		Monster >> character.characterID;
		getline(Monster, character.characterName, '|');
		Monster >> character.minAtk >> character.maxAtk >> character.hp;
		characterVector.push_back(character); // Pushback adds an array size to the vector 
	}
}

int Monster::attack(int monsterID)
{
	return rand() % characterVector[monsterID].maxAtk + characterVector[monsterID].minAtk;
}

