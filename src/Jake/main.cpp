#include <QApplication>
#include "JAgame.h"
//#include "menu.h"

Game* game;
int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  
  game = new Game();
  game->start(1);
  
  return a.exec();
}
