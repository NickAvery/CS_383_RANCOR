
#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include <QMainWindow>

class MainMenu;

namespace Ui{
	class MainMenu;
}

class MainMenu : public MainMenu
{
	Q_OBJECT


public:
	explicit MainMenu(QWidget *parent = 0);
	~MainMenu();

private slots:
	void on_pushButton_clicked(Game game);

private:
	UI::MainMenu *ui;

};

#endif
