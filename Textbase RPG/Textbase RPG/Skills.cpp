#include "Skills.h"



Skills::Skills()
{
}


Skills::~Skills()
{
}


void Skills::readSkillsDatabase()
{
	ifstream Skills("Skills.txt");

	while (!Skills.eof())
	{
		Skills >> character.skillID;
		getline(Skills, character.skillName, '|');
		Skills >> character.skillDamage >> character.skillManaCost;

		skillVector.push_back(character); // Pushback adds an array size to the vector 
	}
}

void Skills::assignPlayerSkills(int playerJob)
{
	if (playerJob == 1)
	{
		skillVector[0].profession = "Jock";
	
	}
	else if (playerJob == 2)
	{
	
		skillVector[1].profession = "ConMan";
	}
}