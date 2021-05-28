#include "service.h"
#include <random>


using namespace std;

void ServApp::newGame() {
	jucator.setLives(6);
	jucator.setScore(0);
}


string ServApp::getCuv() {
	cuvNouGenerat = true;

	std::mt19937 mt{ std::random_device{}() };
	const std::uniform_int_distribution<> dist(0, (int)repo.getAllCuv().size() - 1);
	const int randNr = dist(mt);// numar aleator intre [0,size-1]

	cuvAct=repo.getAllCuv()[randNr];

	int k = (int)cuvAct.size();
	cuvAscuns = "";
	while (k) {
		cuvAscuns = cuvAscuns + "_ ";
		k--;
	}

	return cuvAscuns;
}

int ServApp::getLives() {
	return jucator.getLifes();
}

int ServApp::getScore() {
	return jucator.getScore();
}

void ServApp::verifCuv(string lit) {
	cuvNouGenerat = false;
	for (int i = 0; i < lit.size(); i++) {
		bool exista = false;
		for (int j = 0; j < cuvAct.size(); j++) {
			if (toupper(lit[i]) == toupper(cuvAct[j])) {
				int ok = 1;
				for (int k = 0; k < cuvAscuns.size(); k++)
					if (cuvAscuns[k] == toupper(lit[i])) {
						ok = 0;
					}
				exista = true;
				cuvAscuns[j*2] = cuvAct[j];
				
				//if(ok==1)
				jucator.setScore(jucator.getScore() + 1);
			}
		}
		if (!exista)
			jucator.setLives(jucator.getLifes() - 1);
	}
}

string ServApp::updateCuv(){
	cuvNouGenerat = false;
	bool complect = true;
	for (int i = 0; i < cuvAscuns.size(); i++)
		if (cuvAscuns[i] == '_') {
			complect = false;
			break;
		}

	if (complect) {
		jucator.setScore(jucator.getScore() + 10);
		cuvAscuns = getCuv();
		jucator.setLives(6);//dupa ce se adauga hinturile lives++; resetare hinturi
	}
	return cuvAscuns;
}

string ServApp::getCuvantFinal()
{
	return cuvAct;
}

bool ServApp::actualizare()
{
	return cuvNouGenerat;
}
