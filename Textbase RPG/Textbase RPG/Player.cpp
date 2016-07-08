#include "Player.h"
Player::Player()
{
}


Player::~Player()
{
}


int Player::getExp()
{
	return this->exp;
}
void Player::setPlayerName(string name) {
	characterName = name;
}

int Player::getStr(){
	return this->str;
}
int Player::getIntel(){
	return this->intel;
}
int Player::getMoney(){
	return this->money;
}

int Player::getEnergy(){
	return this->energy;
}
void Player::addIntel(int intel){
	this->intel += intel;
}
void Player::addStr(int str){
	this->str += str;
}