#include "JTmap.h"
#include "NAenemyupdater.h"
//#include "BTcharacter.h"
#include "JAgame.h"
//#include "ASmenu.h"
#include <QGraphicsTextItem>
#include <QMediaPlayer>


Game::Game(QWidget *parent)
{
  scene = new QGraphicsScene();
  scene->setSceneRect(0,0,800,600);
  setScene(scene);
}


void Game::start(int CharClass)
{
  scene->clear();
  Map * map = new Map(scene);


  eUpdater = new EnemyUpdater();
  enemies = eUpdater->sEnemies;
  scene->addItem(enemies[0]);
  scene->addItem(enemies[1]);


  //Character * Player = new Character(CharClass);
  //scene->addItem(Player);
  
  show();
  

  timer = new QTimer();
  connect(timer,SIGNAL(timeout()),this,SLOT(levelLoop()));
  timer->start(10);
}

void Game::levelLoop()
{
    eUpdater->giveInfo(200.0/*Player->getPosition()->x()*/, 200.0+200/*Player->getPosition()->y()*/);

}

//QGraphicsScene* getScene(){
//  return scene;
  
//}

void mainMenu(){
  //MMenu * menu = new MMenu();
  //scene->addItem(menu);

}
