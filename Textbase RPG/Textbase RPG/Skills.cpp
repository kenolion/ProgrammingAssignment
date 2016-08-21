#include "Skills.h"



Skills::Skills()
{
}


Skills::~Skills()
{
}


void Skills::readSkillsDatabase(int job)
{
	string filename;
	switch(job){
case 1:
	filename = "ConManSkills.txt";
	break;
case 2:
	filename = "JockSkills.txt";
	break;
	}
	ifstream Skills(filename);

	while (!Skills.eof())
	{
		Skills >> character.skillID;
		getline(Skills, character.skillName, '|');
		Skills >> character.skillDamage >> character.skillManaCost;
		skillVector.push_back(character); // Pushback adds an array size to the vector 
	}
}

