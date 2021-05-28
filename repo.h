#pragma once

#include <iostream>
#include <string>
#include <vector>


using namespace std;


class RepoApp {
private:

	string numeFis;
	vector<string> cuvinte;

	void load();
	void addCuv(string& cuv);

public:

	RepoApp() = default;
	RepoApp(const RepoApp& ot) = delete;
	RepoApp(string numeFis) :numeFis{ numeFis } {
		load();
	}

	vector<string>& getAllCuv();

};


