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

  music = new AudioInter(0, "qrc:/sounds/Sounds/Break-Down.mp3");
  //sets the first song to be played to be this one

  music->playSound();
  music->setVolume(10);
  //sets its volume to 10 cause its kinda loud to begin with.
}

void Game::NextLevel()
{
    static int x =0;
    if(!x){
        music->setSound(QString("qrc:/sounds/Sounds/Light-Years_v001.mp3"));
        x++;
        music->setVolume(20);
    }
    else if( x == 1){
        music->setSound(QString("qrc:/sounds/Sounds/The-Creeping-Blob.mp3"));
        music->setVolume(70);
        x++;
    }else if(x == 2){
        music->setSound(QString("qrc:/sounds/Sounds/Break-Down.mp3"));
        music->setVolume(20);
        x =0;
    }
        music->playSound();

}

void Game::start(int CharClass)
{
  scene->clear();
  
  eUpdater = new EnemyUpdater();
  
  map = new Map(scene, false, this);
    //James(map designer) adds himself to the scene.
  

  Player = new Character(CharClass, this, scene);
    //Creates a new character CharClass represents the character that was chosen at the mainMenu.

  show();
    //Add's Player to scene and set him to be the focus.

  timer = new QTimer();
  connect(timer,SIGNAL(timeout()),this,SLOT(levelLoop()));
  timer->start(10);
  //starts and connects that timer that is leveLoop.

}


void Game::stressStart(int CharClass, bool autoPilot, bool successPath)
{
    scene->clear();
    eUpdater = new EnemyUpdater();
    map = new Map(scene, true, this); //somehow signal to James this is a stress test.
    

    Player = new Character(CharClass, autoPilot, successPath, this, scene);
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


Character* Game::getCharacter()
{
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




void Game::mainMenu()
{
  MainMenu * menu = new MainMenu(0 ,this);
  menu->show();

    //creates new menu object, 0 stands for the initial value of parent to zero.
    //this passes in the current Game* object so that he can call the start method when the user presses play.
}

