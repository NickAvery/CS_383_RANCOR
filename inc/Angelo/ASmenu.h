
#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include <QMainWindow>

class MainMenu;

namespace UI{
	class MainMenu;
}

class MainMenu : public MainMenu
{
	Q_OBJECT


public:
	explicit MainMenu(QWidget *parent = 0, Game* game);
	~MainMenu();

private slots:
	void on_pushButton_clicked();

private:
	UI::MainMenu *ui;

};

#endif
