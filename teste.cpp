#include "teste.h"
#include "qdebug.h"
#include "domain.h"
#include "service.h"
#include "repo.h"

void testDomain() {
	Player p{};
	assert(p.getLifes() == 0);
	assert(p.getScore() == 0);

	p.setLives(10);
	p.setScore(20);

	assert(p.getLifes() == 10);
	assert(p.getScore() == 20);

}

void testRepo() {
	RepoApp repo("dataTestare.txt");

	assert(repo.getAllCuv().size() == 3);
	assert(repo.getAllCuv()[0] == "ALGORITI");
	assert(repo.getAllCuv()[1] == "ALGORITE");
	assert(repo.getAllCuv()[2] == "ALGORITM");

}

void testService() {
	RepoApp repo("dataTestare.txt");
	ServApp serv{ repo };

	serv.newGame();
	assert(serv.getLives() == 6);
	assert(serv.getScore() == 0);

	assert(serv.getCuv().size()==8*2);

	serv.verifCuv("A");

	assert(serv.updateCuv() == "A _ _ _ _ _ _ _ ");

	assert(serv.getLives() == 6);
	assert(serv.getScore() == 1);
	serv.verifCuv("A");
	assert(serv.getLives() == 6);
	assert(serv.getScore() == 2);
	serv.verifCuv("X");
	assert(serv.getLives() == 5);
	assert(serv.getScore() == 2);

	assert(serv.actualizare()==false);

}


void TestingApp::runAllTests()
{

	testDomain();
	testRepo();
	testService();

	qDebug() << "All tests passed :)";
}
