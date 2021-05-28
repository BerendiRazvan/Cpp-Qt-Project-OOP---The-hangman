#pragma once




class Player {
private:

	int score=0;
	int lifes=0;
	

public:

	Player() = default;
	
	int getScore();
	int getLifes();

	void setScore(int);
	void setLives(int);

};