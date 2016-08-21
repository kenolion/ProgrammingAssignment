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
	getline(Monster, temp,'|');	
	
	while (!Monster.eof())
	{
		Monster >> character.characterID;
		getline(Monster, character.characterName, '|');
		Monster >> character.minAtk >> character.maxAtk >> character.hp >> character.money;
		characterVector.push_back(character); // Pushback adds an array size to the vector 
	}
}

int Monster::attack(int monsterID,int playersArmour)
{
	unsigned int damage = ((rand() % (characterVector[monsterID].maxAtk - characterVector[monsterID].minAtk)) + characterVector[monsterID].minAtk) - playersArmour;
	return damage;
}

