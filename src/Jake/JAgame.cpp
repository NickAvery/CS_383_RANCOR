#include "Map.h"
#include "Enemy.h"
#include "Character.h"
#include "JAgame.h"
#include "menu.h"
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
  
  
  Enemy * NPC = new Enemy();
  Enemy * NPC2 = new Enemy();
  scene->addItem(NPC);
  scene->addItem(NPC2);
  
  Character * Player = new Character(CharClass);
  scene->addItem(Player);
  
  show();
  
}

QGraphics* getScene(){
  return scene;
  
}

void mainMenu(){
  MMenu * menu = new MMenu();
  scene->clear();
  scene->addItem(menu);
}
