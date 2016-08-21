#ifndef SKILLS_H
#define SKILLS_H

#include "Character.h"
#include <fstream>

class Skills : public Character
{
public:
	Skills();
	~Skills();

	void readSkillsDatabase(int job);
};

#endif