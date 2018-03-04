#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTimer>
#include "NAenemyupdater.h"
#include "BTcharacter.h"
#include "JTmap.h"

class Character;

class Game : public QGraphicsView{
  Q_OBJECT

 private:
  QGraphicsScene* scene;
  //the scene on which the enemies and the map will be displayed.

  Character* Player;
  //the player object that is currently the player

  Map * map;

  QTimer * timer;
  //The timer that loops levelLoop();

  Enemy **enemies;
  //The enemies that are currently loaded into memory.

  EnemyUpdater* eUpdater;
  //The updater object that allows for access to updating the enemy movements

  bool Pause;
  //pause is initialy set to False.


 public:
  Game(QWidget* parent = NULL);
    //Initializes a new game
    //Creates a new scene object

  void mainMenu();
    //mainMenu creates a new main menu object and shows it.


  void start(int CharClass);
    //Start is called by the MainMenu when the user clicks the start button for the game
    //It creates a Map/Character/Enemy objects and sets them into the scene.
    //It also starts the levelLoop and the timer associated with them.
    //int CharClass represents the class(warrior, ranger, DR.BC) that the user choose
    //this will be called by UI once the player chooses their class and presses start game

  void setPause(bool);
  //This function sets the value of the Pause variable.
  //Pause determines whether or not the game objects are being updated on the game timer.

  Map* getMap();

  //QGraphicsScene* getScene();


public slots:
  void levelLoop();
    //This is a public slot that runs if Pause is set to False and runs on a timer delay of 10.
    //This levelLoop loops both the player's move() method and also the eupdater method.
};
  
#endif
