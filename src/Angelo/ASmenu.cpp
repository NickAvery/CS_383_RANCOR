
#include "ASmenu.h"
#include "ui_mainmenu.h"
#include <QGraphicsScene>

MainMenu:: MainMenu(QWidget *parent, Game* game) :
	QMainWindow(parent), 
	ui(new Ui::MainMenu)
	{
		ui->setupUi(this);
		game1 = game;
	}

MainMenu::~MainMenu()
{
	delete ui;
}

void MainMenu::on_pushButton_clicked() //start
{
    hide();
    delete ui;
    game1->start(1);
}

void MainMenu::on_pushButton_2_clicked() //test
{
   hide();
   delete ui;
   game1->StressStart(1);
}

void MainMenu::on_pushButton_3_clicked() //quit
{
    exit( EXIT_SUCCESS );
}
