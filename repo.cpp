#include "repo.h"
#include <fstream>
#include <exception>


void RepoApp::load()
{
	ifstream in(numeFis);

	if (!in.is_open())
		throw exception();

	while (!in.eof()) {
		if (in.eof())break;
		string cuv;
		getline(in, cuv, '\n');
	
		addCuv(cuv);
	
	}

	in.close();

}

void RepoApp::addCuv(string& cuv)
{
	cuvinte.push_back(cuv);
}

vector<string>& RepoApp::getAllCuv()
{
	return cuvinte;
}
