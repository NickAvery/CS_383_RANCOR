#include "JTmap.h"
#include "NAenemyupdater.h"
//#include "JTcharacter.h"
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


void Game::start(/*int CharClass*/)
{
  scene->clear();
  Map * map = new Map(scene);


  EnemyUpdater* eUpdater = new EnemyUpdater();
  Enemy **enemies = eUpdater->sEnemies;
  scene->addItem(enemies[0]);
  scene->addItem(enemies[1]);


  Character * Player = new Character();
  scene->addItem(Player);
  
  show();
  
}

//QGraphicsScene* getScene(){
//  return scene;
  
//}

void mainMenu(){
  MMenu * menu = new MMenu();
  scene->clear();
  scene->addItem(menu);
}
