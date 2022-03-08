#include "gui.h"
#include "qlayout.h"
#include "qstring.h"
#include "qlistwidget.h"
#include "qpixmap.h"
#include "qmessagebox.h"
#include "qevent.h"

void GuiApp::initGui()
{
	btnSubmit->setText("&Start joc");
	setStyleSheet("QWidget { background: white; }");
	setWindowIcon(QIcon("./ImgIcon.png"));
	setWindowTitle("Spanzuratoarea");
	
	setLayout(lyMain);

	lbTitle->setStyleSheet("QLabel { font: bold 45pt 'Segoe Script'; }");

	lbTitle->setText("SPANZURATOAREA");
	lbTitle->setAlignment(Qt::AlignCenter);
	lyMain->addSpacing(20);
	lyMain->addWidget(lbTitle);
	lyMain->addSpacing(20);
	QHBoxLayout* lyBtnTop = new QHBoxLayout;
	btnTop->setMinimumSize(100, 100);
	btnTop->setMaximumSize(100, 100);

	btnTop->setStyleSheet("QPushButton{ border-image: url(img_podium1) }"
		"QPushButton:hover{border-image: url(img_podium1_c)}"
		"QPushButton:pressed{border-image: url(img_podium1_c)}" "QPushButton { border: 0px; }");

	lyBtnTop->addStretch();
	//lyBtnTop->addWidget(btnTop);//<----------------------Buton Top
	lyBtnTop->addStretch();
	lyMain->addLayout(lyBtnTop);
	
	lyMain->addStretch();

	lbCuv->setStyleSheet("QLabel { font: bold 20pt 'Segoe Script'; }");
	lbCuvINFO->setStyleSheet("QLabel { font: bold 20pt 'Segoe Script'; }");

	
	lbScor->setStyleSheet("QLabel { font: bold 30pt 'Segoe Script'; }");


	lbCuv->setText("CUVANT:");
	lbCuvINFO->setText("- cuvantul care trebuie ghicit -");
	lbScor->setText("Scorul dumneavoastra este: 0");
	txtGetLit->hide();

	lyStGame->addStretch();
	lyStGame->addWidget(lbScor);
	lyStGame->addStretch();


	lyStGame->addWidget(lbCuv);
	lyStGame->addWidget(lbCuvINFO);

	lyStGame->addStretch();

	lbHints->setText("Hint-uri: ");
	lbHints->setStyleSheet("QLabel { font: bold 18pt 'Segoe Script'; }");
	

	lyStGame->addLayout(lyHints);
	lyHints->addWidget(lbHints);
	lyHints->addSpacing(20);
	lyHints->addWidget(btnExtrLife);
	lyHints->addSpacing(25);
	lyHints->addWidget(btnLitera);
	lyHints->addSpacing(25);
	lyHints->addWidget(btnDomeniu);
	lyHints->addStretch();
	lyStGame->addStretch();

	

	btnExtrLife->setMinimumSize(50, 50);
	btnExtrLife->setMaximumSize(50, 50);
	btnExtrLife->setStyleSheet("QPushButton{ border-image: url(img_el1) }"
		"QPushButton:hover{border-image: url(img_el1_c)}"
		"QPushButton:pressed{border-image: url(img_el1_c)}" "QPushButton { border: 0px; }");

	btnLitera->setMinimumSize(50, 50);
	btnLitera->setMaximumSize(50, 50);
	btnLitera->setStyleSheet("QPushButton{ border-image: url(img_lit) }"
		"QPushButton:hover{border-image: url(img_lit_c)}"
		"QPushButton:pressed{border-image: url(img_lit_c)}" "QPushButton { border: 0px; }");

	btnDomeniu->setMinimumSize(50, 50);
	btnDomeniu->setMaximumSize(50, 50);
	btnDomeniu->setStyleSheet("QPushButton{ border-image: url(img_dom1) }"
		"QPushButton:hover{border-image: url(img_dom1_c)}"
		"QPushButton:pressed{border-image: url(img_dom1_c)}" "QPushButton { border: 0px; }");


	lbLitera->setText("Litere disponibile:");
	
	lbLitera->setStyleSheet("QLabel { font: bold 20pt 'Segoe Script'; }");


	lyInserareLit->addWidget(lbLitera);
	lyInserareLit->addWidget(txtGetLit);
	lyInserareLit->addSpacing(100);
	lyInserareLit->addWidget(btnSubmit);
	btnSubmit->setStyleSheet("QPushButton:hover{background-color: #58CCED}" "QPushButton { font: bold 15pt 'Segoe Script'; background: #F0F0F0; }");
	lyInserareLit->addSpacing(100);

	lyStGame->addLayout(lyInserareLit);
	

	img->setPixmap(QPixmap("ImgStart.png"));
	img->show();
	lyDrGame->addWidget(img);//img spanzurat


	lyGame->addSpacing(50);
	lyGame->addLayout(lyStGame);
	lyGame->addStretch();



	lyGame->addLayout(lyDrGame);
	lyGame->addSpacing(50);
	

	lyMain->addLayout(lyGame);
	lyMain->addSpacing(50);

	txtGetLit->hide();
	lbLitera->hide();
	lbHints->hide();
	btnDomeniu->hide();
	btnExtrLife->hide();
	btnLitera->hide();

}

void GuiApp::genereareButoane()
{

	//code btn tastatura here
	string charBtnLit = "A";
	while (charBtnLit <= "Z") {
		QPushButton* btnChar = new QPushButton(QString::fromStdString(charBtnLit));
		btnChar->setStyleSheet("QPushButton:hover{background-color: #58CCED}" "QPushButton { font: bold 13pt 'Segoe Script'; background: #F0F0F0; }");
		if (charBtnLit[0] < 'J')
			lyInserareLit1->addWidget(btnChar);
		else {
			if (charBtnLit[0] < 'R')
				lyInserareLit2->addWidget(btnChar);
			else
				lyInserareLit3->addWidget(btnChar);
		}
		charBtnLit[0]++;
		


		QObject::connect(btnChar, &QPushButton::clicked, [this,btnChar]() {

			txtGetLit->setText(btnChar->text());
			btnSubmit->click();
			if(actTastatura == false)
				btnChar->hide();
			});

		QObject::connect(btnSubmit, &QPushButton::clicked, [this, btnChar]() {
			if (btnSubmit->text() == "&Start joc")
				btnChar->show();
			if (actTastatura == true)
				btnChar->show();
			if (btnSubmit->text() == "&Start joc nou" && dead == true) {
				btnChar->hide();
			}

			});

		

	}
	lyLitere->addLayout(lyInserareLit1);
	lyLitere->addLayout(lyInserareLit2);
	lyLitere->addLayout(lyInserareLit3);


	lyStGame->addLayout(lyLitere);//pt. tastatura
	lyStGame->addStretch();

}


void GuiApp::connectGui()
{
	QObject::connect(btnSubmit, &QPushButton::clicked, [&]() {

		if (dead == true) {
			btnSubmit->hide();
			txtGetLit->hide();
			lbLitera->show();
			lbHints->show();
			btnDomeniu->show();
			btnExtrLife->show();
			btnLitera->show();

			btnSubmit->setText("&Incearca");
			lbCuv->setText("CUVANT:");
			lbScor->setText(QString::fromStdString("Scorul dumneavoastra este: 0"));
			QString imgCOD;
			imgCOD = QString::fromStdString("Img0.png");
			img->setPixmap(QPixmap(imgCOD));
			serv.newGame();
			lbCuvINFO->setText(QString::fromStdString(serv.getCuv()));
			actTastatura = true;
			dead = false;
			if (generated == false)
				genereareButoane(), generated = true;
		}
		else {
			
			actTastatura = false;
			btnSubmit->hide();
			txtGetLit->hide();
			lbLitera->show();
			lbHints->show();
			btnDomeniu->show();
			btnExtrLife->show();
			btnLitera->show();
			btnSubmit->setText("&Incearca");

			//verif litera
			QString incercare;
			incercare = txtGetLit->text();
			serv.verifCuv(incercare.toStdString());
			txtGetLit->clear();

			//update litera
			lbCuvINFO->setText(QString::fromStdString(serv.updateCuv()));
			lbScor->setText(QString::fromStdString("Scorul dumneavoastra este: " + to_string(serv.getScore())));

			QString imgCOD;
			imgCOD = QString::fromStdString("Img" + to_string(6 - serv.getLives()) + ".png");
			img->setPixmap(QPixmap(imgCOD));

			if (serv.actualizare()) {
				actTastatura = true;
			}
			else
				actTastatura = false;


			if (serv.getLives() <= -1) {
				txtGetLit->hide();
				lbLitera->hide();

				lbHints->hide();
				btnDomeniu->hide();
				btnExtrLife->hide();
				btnLitera->hide();

				lbCuv->setText("ATI MURIT!");
				lbCuvINFO->setText("Cuvantul era : " + QString::fromStdString(serv.getCuvantFinal()));
				imgCOD = QString::fromStdString("ImgMORT.png");
				img->setPixmap(QPixmap(imgCOD));
				

				//QMessageBox::information(nullptr, "GAME OVER", "ATI MURIT! \nCuvantul era: " + QString::fromStdString(serv.getCuvantFinal()) + "\nScorul dvs. este " + QString::fromStdString(to_string(serv.getScore())));

				dead = true;

				//lbScor->setText(QString::fromStdString("Scorul dumneavoastra este: 0"));
				btnSubmit->setText("&Start joc nou");
				btnSubmit->show();

				
				btnExtrLife->setStyleSheet("QPushButton{ border-image: url(img_el1) }"
					"QPushButton:hover{border-image: url(img_el1_c)}"
					"QPushButton:pressed{border-image: url(img_el1_c)}" "QPushButton { border: 0px; }");

				btnLitera->setStyleSheet("QPushButton{ border-image: url(img_lit) }"
					"QPushButton:hover{border-image: url(img_lit_c)}"
					"QPushButton:pressed{border-image: url(img_lit_c)}" "QPushButton { border: 0px; }");
				
				btnDomeniu->setStyleSheet("QPushButton{ border-image: url(img_dom1) }"
					"QPushButton:hover{border-image: url(img_dom1_c)}"
					"QPushButton:pressed{border-image: url(img_dom1_c)}" "QPushButton { border: 0px; }");

				btnExtrLife->setEnabled(true);
				btnLitera->setEnabled(true);
				btnDomeniu->setEnabled(true);

			}

		}

		});

	
	QObject::connect(btnTop, &QPushButton::clicked, [&]() {
			
			QMessageBox::information(nullptr, "Top Players", "Soon...");
			//QMessageBox::information(nullptr,"Top Players",QString::fromStdString(serv.topPl()));
			//cod care deschide fereastra cu top 10; QMessageBox

			});
	

	QObject::connect(btnDomeniu, &QPushButton::clicked, [&]() {
		btnDomeniu->setStyleSheet("QPushButton{ border-image: url(img_dom1_used) }"
			"QPushButton:hover{border-image: url(img_dom1_used)}"
			"QPushButton:pressed{border-image: url(img_dom1_used)}" "QPushButton { border: 0px; }");
		btnDomeniu->setEnabled(false);

		QMessageBox::information(nullptr,"HINT - Domeniu","Domeniul cuvantului este: "+ QString::fromStdString(serv.domeniu()));

		});

	QObject::connect(btnLitera, &QPushButton::clicked, [&]() {
		btnLitera->setStyleSheet("QPushButton{ border-image: url(img_lit_used) }"
			"QPushButton:hover{border-image: url(img_lit_used)}"
			"QPushButton:pressed{border-image: url(img_lit_used)}" "QPushButton { border: 0px; }");
		btnLitera->setEnabled(false);
		
		QMessageBox::information(nullptr, "HINT - Litera", "Cuvantul contine litera: " + QString::fromStdString(serv.literaExtr()));

		});

	QObject::connect(btnExtrLife, &QPushButton::clicked, [&]() {
		if (serv.getLives() == 6) {
			QMessageBox::information(nullptr,"Atentie!","Aveti numar maxim de vieti");
		}
		else {
			btnExtrLife->setStyleSheet("QPushButton{ border-image: url(img_el1_used) }"
				"QPushButton:hover{border-image: url(img_el1_used)}"
				"QPushButton:pressed{border-image: url(img_el1_used)}" "QPushButton { border: 0px; }");
			btnExtrLife->setEnabled(false);

			serv.lifeBack();
			QString imgCOD;
			imgCOD = QString::fromStdString("Img" + to_string(6 - serv.getLives()) + ".png");
			img->setPixmap(QPixmap(imgCOD));

			QMessageBox::information(nullptr, "Extra Life", "Ati primit inca o viata \nMai aveti " + QString::fromStdString(to_string(serv.getLives()+1))+" incercari");
		}
		});

	
	

}



