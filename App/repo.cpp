#include "repo.h"
#include <fstream>
#include <exception>


void RepoApp::load()
{
	ifstream in(numeFis);

	if (!in.is_open())
		throw exception();

	while (!in.eof()) {
		string c, d;

		if (in.eof())break;
		getline(in, c, ';');

		if (in.eof())break;
		getline(in, d, '\n');
	
		Cuvant cuv{ c,d };

		addCuv(cuv);
	
	}

	in.close();

}

void RepoApp::addCuv(Cuvant& cuv)
{
	cuvinte.push_back(cuv);
}

vector<Cuvant>& RepoApp::getAllCuv()
{
	return cuvinte;
}
