#include "OOP_Antrenament_2.h"
#include <QtWidgets/QApplication>

#include "teste.h"
#include "gui.h"
#include "domain.h"
#include "service.h"
#include "repo.h"



void runApp(int argc, char* argv[]) {

    QApplication a(argc, argv);
    

    //App
    RepoApp repo{ "data.txt" };
    ServApp serv{ repo };

    //GUI
    GuiApp* console=new GuiApp(serv);
    console->showMaximized();
    
    a.exec();
}



int main(int argc, char *argv[])
{
    //Tasks:
    //+high score (scorurile raman salvate intr-un fisier cu nume si scor si data:Razvan - 100 pct. - 20/07/2021 12:30)
    //+cuvintele sa nu se repete (lista cu cuv. folosite)
    //+admin mode (poate edita/sterge/adauga cuvintele/topPl si are parola(o poate schimba))
    //+fereastra meniu: Joc/Admin Mode/Top pl (fiecare separat)

    //Testing
    TestingApp teste{};
    teste.runAllTests();
    
    runApp(argc,argv);

    return 0;
}
