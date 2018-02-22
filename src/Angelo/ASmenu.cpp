
#include "ASmenu.h"
#include "ui_ASmenu.h"
#include <QGraphicsScene>
#include "JAgame.h"

MainMenu:: MainMenu(QWidget *parent, Game* game)	:
	QMainWindow(parent), ui(new Ui::MainWindow)
	{
		ui->setupUI(this);
	}

MainMenu::~MainMenu()
{
	delete ui;
}

void MainMenu::on_pushButton_clicked()
{
	game->start(1);
}
