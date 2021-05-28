#include "domain.h"

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
