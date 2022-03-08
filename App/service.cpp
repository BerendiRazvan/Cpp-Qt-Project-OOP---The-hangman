#include "service.h"

#include <random>
#include <fstream>

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

	nrC = randNr;
	cuvAct.setCUVANT(repo.getAllCuv()[randNr].getCUVANT());

	int k = (int)cuvAct.getCUVANT().size();
	cuvAscuns.setCUVANT("");
	while (k) {
		cuvAscuns.setCUVANT(cuvAscuns.getCUVANT() + "_ ");
		k--;
	}

	return cuvAscuns.getCUVANT();
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
		for (int j = 0; j < cuvAct.getCUVANT().size(); j++) {
			if (toupper(lit[i]) == toupper(cuvAct.getCUVANT()[j])) {
				int ok = 1;
				for (int k = 0; k < cuvAscuns.getCUVANT().size(); k++)
					if (cuvAscuns.getCUVANT()[k] == toupper(lit[i])) {
						ok = 0;
					}
				exista = true;
				string c = cuvAscuns.getCUVANT();
				c[j*2] = cuvAct.getCUVANT()[j];
				cuvAscuns.setCUVANT(c);
				
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
	for (int i = 0; i < cuvAscuns.getCUVANT().size(); i++)
		if (cuvAscuns.getCUVANT()[i] == '_') {
			complect = false;
			break;
		}

	if (complect) {
		jucator.setScore(jucator.getScore() + 10);
		cuvAscuns.setCUVANT(getCuv());
		jucator.setLives(6);//dupa ce se adauga hinturile lives++; resetare hinturi
	}
	return cuvAscuns.getCUVANT();
}

string ServApp::getCuvantFinal()
{
	return cuvAct.getCUVANT();
}

bool ServApp::actualizare()
{
	return cuvNouGenerat;
}


void ServApp::lifeBack() {
	jucator.setLives(jucator.getLifes() + 1);
}

string ServApp::domeniu() {
	return repo.getAllCuv()[nrC].getDOMENIU();
}

string ServApp::literaExtr() {
	string litera;
	while (true) {
		std::mt19937 mt{ std::random_device{}() };
		const std::uniform_int_distribution<> dist(0, (int)cuvAct.getCUVANT().size() - 1);
		const int randNr = dist(mt);// numar aleator intre [0,size-1]
		int poz = randNr;

		if (cuvAscuns.getCUVANT()[poz * 2] == '_') {
			litera = cuvAct.getCUVANT()[poz];

			for (int j = 0; j < cuvAct.getCUVANT().size(); j++) {
				if (toupper(litera[0]) == toupper(cuvAct.getCUVANT()[j])) {
					int ok = 1;
					for (int k = 0; k < cuvAscuns.getCUVANT().size(); k++)
						if (cuvAscuns.getCUVANT()[k] == toupper(litera[0])) {
							ok = 0;
						}
					string c = cuvAscuns.getCUVANT();
					c[j * 2] = cuvAct.getCUVANT()[j];
					cuvAscuns.setCUVANT(c);

				}
			}
			break;
		}

	}
	return litera;
}



string ServApp::topPl(){
	
	ifstream in("dataTopScore.txt");
	string top;

	if (!in.is_open())
		throw exception();
	int i = 1;
	while (!in.eof()) {
		string s,t;

		t = t + to_string(i) + ". ";

		if (in.eof())break;
		getline(in, s, ';');
		t = t + s + " - ";

		if (in.eof())break;
		getline(in, s, ';');
		t = t + s + " pct. - ";

		if (in.eof())break;
		getline(in, s, '\n');
		t = t + s + "\n";

		top = top + t;
		i++;
	}

	in.close();

	return top;
}
