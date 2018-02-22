#include <QApplication>
#include "JAgame.h"
//#include "menu.h"

Game* game;
int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  
  game = new Game();
  game->mainMenu();
  
  return a.exec();
}
