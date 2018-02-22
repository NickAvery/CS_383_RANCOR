
#ifndef ASMENU_H
#define ASMENU_H

#include <QMainWindow>
#include "JAgame.h"

class Game;

namespace Ui{
	class MainMenu;
}

class MainMenu : public QMainWindow
{
	Q_OBJECT


public:
	explicit MainMenu(QWidget *parent = 0, Game* game = NULL);
	~MainMenu();

private slots:
	void on_pushButton_clicked();

private:
	Ui::MainMenu *ui;

};

#endif
