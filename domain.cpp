#include "domain.h"

void Cuvant::setCUVANT(string a) {
	cuvant = a;
}

void Cuvant::setDOMENIU(string a) {
	domeniu = a;
}

string Cuvant::getCUVANT() {
	return cuvant;
}

string Cuvant::getDOMENIU() {
	return domeniu;
}




int Player::getScore()
{
	return score;
}

int Player::getLifes()
{
	return lifes;
}

void Player::setScore(int a)
{
	score = a;
}

void Player::setLives(int a)
{
	lifes = a;
}
