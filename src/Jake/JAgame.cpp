#include "JTmap.h"
#include "NAenemyupdater.h"
#include "BTcharacter.h"
#include "JAgame.h"
#include "ASmenu.h"
#include <QGraphicsTextItem>
#include <QMediaPlayer>
#include "JAaudio.h"

Game::Game()
{
  scene = new QGraphicsScene();
  scene->setSceneRect(0,0,800,600);
  setScene(scene);
    //creates a new scene object.
  Pause = false;
    //Set Pause to be false initially.
  AudioInter * music = new AudioInter(0, "qrc:/sounds/Sounds/Break-Down.mp3");
  music->PlaySound();
  music->SetVolume(10);

}


void Game::start(int CharClass)
{
  scene->clear();
  map = new Map(scene, false, this);
    //James(map designer) adds himself to the scene.

  eUpdater = new EnemyUpdater();

  Player = new Character(CharClass, this, scene);
    //Creates a new character CharClass represents the character that was chosen at the mainMenu.

  show();
    //Add's Player to scene and set him to be the focus.

  timer = new QTimer();
  connect(timer,SIGNAL(timeout()),this,SLOT(levelLoop()));
  timer->start(10);
  //starts and connects that timer that is leveLoop.

}

void Game::StressStart(int CharClass){
    scene->clear();
    map = new Map(scene, true, this); //somehow signal to James this is a stress test.

    eUpdater = new EnemyUpdater();

    Player = new Character(CharClass, 1, this, scene);
      //Creates a new character CharClass represents the character that was chosen at the mainMenu.

    show();

    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(levelLoop()));
    timer->start(10);

}

EnemyUpdater *Game::getEnemies()
{
   return eUpdater;
}

void Game::setPause(bool set)
{
    Pause = set;
    //sets the pause variable
}

Map *Game::getMap()
{
    return map;
}

Character* Game::getCharacter(){
    return Player;
}

void Game::levelLoop()
{
    if(!Pause){
    eUpdater->giveInfo(Player->getPosition().x(), Player->getPosition().y());
    Player->update();
    }
    //this loop updates the player and the enemy movements.
}


//QGraphicsScene* getScene(){
//  return scene;
  
//}


void Game::mainMenu(){
  MainMenu * menu = new MainMenu(0 ,this);
  menu->show();

    //creates new menu object, 0 stands for the initial value of parent to zero.
    //this passes in the current Game* object so that he can call the start method when the user presses play.
}

