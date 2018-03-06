#ifndef ENEMYUPDATER_H
#define ENEMYUPDATER_H

#include "enemy.h"
#include "enemyspawner.h"
#include <cmath>
#include <QList>
#include <QGraphicsScene>

class EnemyUpdater
{
private:
    QList<Enemy*> sEnemies;    //List of all live Enemies in the game
    EnemySpawner *mSpawner;    //Enemy Spawner
    int testCaseMax;           //test case var
    int testCaseNum;           //test case var
    void update(qreal, qreal); //updates all enemies. used in giveInfo

public:
    EnemyUpdater();                             //constructor, creates enemy spawner and enemylist
    void giveInfo(qreal charX, qreal charY);    //give the player info to the enemyUpdater
    void newEnemy(qreal x, qreal y);            //create a new enemy using the spawner
    Enemy *getEnemy(int i);                     //get an enemy from the list
    QList<Enemy*> getEnemies();                 //get the entire list of enemies
    void testCase(QGraphicsScene * scene);      //run the test case
    bool enemiesDead();                         //true if all enemies are dead/there are no enemies
    void removeEnemy(int i);                    //remove an enemy from sEnemies. used in update
    void removeEnemies();                    //remove an enemy from sEnemies. used in update
};

#endif // ENEMYUPDATER_H




