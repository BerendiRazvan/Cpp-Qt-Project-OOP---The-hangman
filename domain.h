#pragma once
#include <string>

using namespace std;

class Cuvant {
private:
	string cuvant;
	string domeniu;

public:

	Cuvant(string cuvant, string domeniu) :cuvant{ cuvant }, domeniu{domeniu} {};

	void setCUVANT(string a);
	void setDOMENIU(string a);
	string getCUVANT();
	string getDOMENIU();

};



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