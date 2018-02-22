#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTimer>
#include "NAenemyupdater.h"
//#include "BTcharacter.h"


class Game : public QGraphicsView{
  Q_OBJECT

 private:
  QGraphicsScene* scene;
  //the scene on which the enemies and the map will be displayed.
  //Character* Player;
  QTimer * timer;
  Enemy **enemies;
  EnemyUpdater* eUpdater;
 public:
  Game(QWidget* parent = NULL);


  void mainMenu();
    //Initializes a new game
  void start(int CharClass);
    //int CharClass represents the class(warrior, ranger, DR.BC) that the user choose
    //this will be called by UI once the player chooses their class and presses start game

public slots:
  void levelLoop();
};
  
