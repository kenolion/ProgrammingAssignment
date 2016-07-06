#pragma once

class Character
{
public:
	Character();
	~Character();
	char name[15];
	int job; //1=Swordsman,2= Archer, 3= Deprived(not an actual class just decided to put it there in the mean time)
	int hp;
	
	int str;
	int energy;
	int intell;
	int weaboo;
	int damage;
	int getExp();
	int damageDealt();
	void setMinAtk(int damage);
	void setMaxAtk(int damage);
	
private:
	int exp;
	int minAtk;
	int maxAtk;

};

