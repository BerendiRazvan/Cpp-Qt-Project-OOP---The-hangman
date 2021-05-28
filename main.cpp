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
    //+hint (1-ofera categorie;2-ofera o litera;3-ofera cuvant nou)-fiecare hint poate fi utilizat o fingura data
    //+high score (scorurile raman salvate intr-un fisier cu data si ora ex: 100 pct. - 20/07/2021 12:30)
    //+categorie pt. cuvant (clasa pt cuv: cuv,categorie)
    //+cuvintele sa nu se repete

    //Testing
    TestingApp teste{};
    teste.runAllTests();
    
    runApp(argc,argv);

    return 0;
}
