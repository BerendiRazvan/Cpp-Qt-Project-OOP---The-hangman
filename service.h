#pragma once

#include "repo.h"


class ServApp {
private:
	
	RepoApp& repo;
	Player jucator{};
	Cuvant cuvAct{"",""};
	Cuvant cuvAscuns{"",""};
	bool cuvNouGenerat = false;
	int nrC;
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
	void lifeBack();
	string domeniu();
	string literaExtr();
	string topPl();

};