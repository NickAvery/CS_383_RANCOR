#include "JTmap.h"
#include "NAenemyupdater.h"
#include "BTcharacter.h"
#include "JAgame.h"
#include "ASmenu.h"
#include <QGraphicsTextItem>
#include <QMediaPlayer>


Game::Game(QWidget *parent)
{
  scene = new QGraphicsScene();
  scene->setSceneRect(0,0,800,600);
  setScene(scene);
  Pause = false;
}


void Game::start(int CharClass)
{
  scene->clear();
  Map * map = new Map(scene);


  eUpdater = new EnemyUpdater();
  enemies = eUpdater->sEnemies;
  scene->addItem(enemies[0]);
  scene->addItem(enemies[1]);


  Player = new Character(CharClass);

  scene->addItem(Player);
  Player->setFlag(QGraphicsItem::ItemIsFocusable);
  Player->QGraphicsRectItem::setFocus();
  show();
  

  timer = new QTimer();
  connect(timer,SIGNAL(timeout()),this,SLOT(levelLoop()));
  timer->start(10);
}

void Game::SetPause(bool set)
{
    Pause = set;
}

void Game::levelLoop()
{
    if(!Pause){
    eUpdater->giveInfo(Player->getPosition().x(), Player->getPosition().y());
    Player->move();
    }
}

//QGraphicsScene* getScene(){
//  return scene;
  
//}

void Game::mainMenu(){
  MainMenu * menu = new MainMenu(0 ,this);
  menu->show();

}
