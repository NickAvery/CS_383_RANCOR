
#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include <QMainWindow>

namespace UI{
	class MainMenu;
}

class MainMenu : public MainMenu
{
	Q_OBJECT


public:
	explicit MainMenu(QWidget *parent = 0, Game* game = NULL);
	~MainMenu();

private slots:
	void on_pushButton_clicked();

private:
	UI::MainMenu *ui;

};

#endif
