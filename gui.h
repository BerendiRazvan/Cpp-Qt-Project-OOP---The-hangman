#pragma once
#include "qwidget.h"
#include "qpushbutton.h"
#include "qlabel.h"
#include "qtextedit.h"
#include "qlineedit.h"
#include "service.h"
#include "qlayout.h"


class GuiApp :public QWidget {
private:

	ServApp& serv;

	//buttons
	QPushButton* btnSubmit = new QPushButton;
	//QPushButton* btnChar = new QPushButton;
	//labels
	QLabel* lbScor = new QLabel;
	QLabel* lbTitle = new QLabel;
	QLabel* lbCuv = new QLabel;
	QLabel* lbCuvINFO = new QLabel;
	QLabel* lbLitera = new QLabel;
	QLabel* img = new QLabel;
	
	//layouts
	QVBoxLayout* lyMain = new QVBoxLayout;
	QHBoxLayout* lyGame = new QHBoxLayout;
	QVBoxLayout* lyStGame = new QVBoxLayout;
	QVBoxLayout* lyDrGame = new QVBoxLayout;
	QHBoxLayout* lyInserareLit = new QHBoxLayout;
	QVBoxLayout* lyLitere = new QVBoxLayout;
	QHBoxLayout* lyInserareLit1 = new QHBoxLayout;
	QHBoxLayout* lyInserareLit2 = new QHBoxLayout;
	QHBoxLayout* lyInserareLit3 = new QHBoxLayout;


	//other...
	QLineEdit* txtGetLit = new QLineEdit;
	
	bool generated = false;
	bool actTastatura = false;
	bool dead=true;
			
	void initGui();
	void genereareButoane();
	void connectGui();


public:

	GuiApp() = default;
	GuiApp(const ServApp& ot) = delete;
	
	GuiApp(ServApp& serv) :serv{ serv } {
		initGui();
		connectGui();
	};

};




