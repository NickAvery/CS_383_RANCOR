
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

void MainMenu::on_pushButton_clicked()
{
	game1->start(1);
}
