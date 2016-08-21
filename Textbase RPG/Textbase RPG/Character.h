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
		int maxHp;
		int currentHp;
		int minAtk;
		int maxAtk;
		string characterName;
		int characterID;
		int money;

		//SKILLS
		int profession;
		int skillID;
		string skillName;
		int skillManaCost;
		int skillDamage;
		int maxMana;
		int currentMana;
	};
	CharacterInfo character;

public:
	Character();
	~Character();																	 
	void setMinAtk(int damage);														 
	void setMaxAtk(int damage);														 
	string getCharacterName();														 
	int getHp();
	int getHp(int monsterID);
	void setHp(int hp);				  												 
	virtual int attack(); //Randomly generates the damage with minatk and maxatk			 
	int damage; //Temporary stores the damage of the character when attack is called 

	vector<CharacterInfo> characterVector;
	vector<CharacterInfo> skillVector;

									  												 
};						

#endif // !CHARACTER_H																					 