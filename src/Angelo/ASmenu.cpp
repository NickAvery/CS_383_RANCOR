
#include "asmenu.h"
#include "ui_asmenu.h"
#include <QGraphicsScene>
#include <JAgame.h>

MainMenu:: MainMenu(QWidget *parent)	:
	QMainWindow(parent), ui(new Ui::MainWindow)
	{
		ui->setupUI(this);
	}

MainMenu::~MainMenu()
{
	delete ui;
}

void MainMenu::on_pushButton_clicked(Game)
{
	Game game;
	game->start();
}
