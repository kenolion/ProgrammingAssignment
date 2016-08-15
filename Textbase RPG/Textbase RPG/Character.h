#pragma once
#include <iostream>
#include <string>
using namespace std;

class Character
{
public:
	Character();
	~Character();																	 
	void setMinAtk(int damage);														 
	void setMaxAtk(int damage);														 
	string getCharacterName();														 
	int getHp();					  												 
	void setHp(int hp);				  												 
	int attack(); //Randomly generates the damage with minatk and maxatk			 
	int damage; //Temporary stores the damage of the character when attack is called 
									  												 
									  												 
protected:							  												 
	int hp;							  												 
	int minAtk;						  												 
	int maxAtk;						  												 
	string characterName;			  												 
																					 
};																					 
																					 