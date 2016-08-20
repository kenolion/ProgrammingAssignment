#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Character
{
protected:
	struct CharacterInfo {
		int hp;
		int minAtk;
		int maxAtk;
		string characterName;
		int characterID;
		int money;
	};
	CharacterInfo character;

public:
	Character();
	~Character();																	 
	void setMinAtk(int damage);														 
	void setMaxAtk(int damage);														 
	string getCharacterName();														 
	int getHp();					  												 
	void setHp(int hp);				  												 
	virtual int attack(); //Randomly generates the damage with minatk and maxatk			 
	int damage; //Temporary stores the damage of the character when attack is called 
	vector<CharacterInfo> characterVector;
									  												 
									  												 

	
};						

#endif // !CHARACTER_H																					 