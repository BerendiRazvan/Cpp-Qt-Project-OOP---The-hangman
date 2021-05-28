#include "gui.h"
#include "qlayout.h"
#include "qstring.h"
#include "qlistwidget.h"
#include "qpixmap.h"
#include "qmessagebox.h"

void GuiApp::initGui()
{
	btnSubmit->setText("&Start joc");
	setStyleSheet("QWidget { background: white; }");
	setWindowIcon(QIcon("./ImgIcon.png"));

	
	setLayout(lyMain);

	lbTitle->setStyleSheet("QLabel { font: bold 45pt 'Segoe Script'; }");

	lbTitle->setText("SPANZURATOAREA");
	lbTitle->setAlignment(Qt::AlignCenter);
	lyMain->addSpacing(20);
	lyMain->addWidget(lbTitle);
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

	
	lbLitera->setText("Litere disponibile:");
	
	lbLitera->setStyleSheet("QLabel { font: bold 20pt 'Segoe Script'; }");
	
	btnSubmit->setStyleSheet("QPushButton { font: bold 15pt 'Segoe Script'; background: #F0F0F0; }");
	
	lyInserareLit->addWidget(lbLitera);
	lyInserareLit->addWidget(txtGetLit);
	lyInserareLit->addStretch();
	lyInserareLit->addWidget(btnSubmit);


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

}

void GuiApp::genereareButoane()
{

	//code btn tastatura here
	string charBtnLit = "A";
	while (charBtnLit <= "Z") {
		QPushButton* btnChar = new QPushButton(QString::fromStdString(charBtnLit));
		btnChar->setStyleSheet("QPushButton { font: bold 13pt 'Segoe Script'; background: #F0F0F0; }");
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
			btnSubmit->setText("&Incearca");
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
				lbCuvINFO->setText("- cuvantul care trebuie ghicit -");
				imgCOD = QString::fromStdString("ImgMORT.png");
				img->setPixmap(QPixmap(imgCOD));
				QMessageBox::information(nullptr, "GAME OVER", "ATI MURIT! \nCuvantul era: " + QString::fromStdString(serv.getCuvantFinal()) + "\nScorul dvs. este " + QString::fromStdString(to_string(serv.getScore())));
				dead = true;
				lbScor->setText(QString::fromStdString("Scorul dumneavoastra este: 0"));
				btnSubmit->setText("&Start joc nou");
				btnSubmit->show();
			}

		}

		});
}



