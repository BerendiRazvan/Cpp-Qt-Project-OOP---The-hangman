#pragma once

#include "domain.h"
#include <iostream>
#include <string>
#include <vector>


using namespace std;


class RepoApp {
private:

	string numeFis;
	vector<Cuvant> cuvinte;

	void load();
	void addCuv(Cuvant& cuv);

public:

	RepoApp() = default;
	RepoApp(const RepoApp& ot) = delete;
	RepoApp(string numeFis) :numeFis{ numeFis } {
		load();
	}

	vector<Cuvant>& getAllCuv();

};


