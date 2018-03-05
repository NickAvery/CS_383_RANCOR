
#ifndef ASMENU_H
#define ASMENU_H

#include <QMainWindow>
#include "JAgame.h"

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
	void on_pushButton_2_clicked();
	void on_pushButton_3_clicked();

private:
	Ui::MainMenu *ui;
	Game* game1;

};

#endif
