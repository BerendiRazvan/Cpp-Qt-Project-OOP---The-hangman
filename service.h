#pragma once

#include "repo.h"
#include "domain.h"


class ServApp {
private:
	
	RepoApp& repo;
	Player jucator{};
	string cuvAct;
	string cuvAscuns;
	bool cuvNouGenerat = false;
public:


	ServApp() = default;
	ServApp(const ServApp& ot) = delete;
	ServApp(RepoApp& repo) :repo{ repo } {};

	void newGame();
	string getCuv();
	int getLives();
	int getScore();
	void verifCuv(string lit);
	string updateCuv();
	string getCuvantFinal();
	bool actualizare();

};