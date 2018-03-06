#include "enemyspawner.h"

EnemySpawner::EnemySpawner()
{
    //will be implementing after tests for week 3
    /*std::ifstream mEnemyDatabase;
    mEnemyDatabase.open("enemyTemplates.txt", std::ifstream::in);
    if(mEnemyDatabase.is_open())
    {
        qDebug() << "is open";
    }
    int x = 0;
    mEnemyDatabase >> x;//>> mTempY >> mTempSize;
    qDebug() << x;
    //should plan for things like attack speed, attack values, health, etc...
    mEnemyDatabase.close();*/
    srand(time(NULL));
    mTempSize = 30;
}

Enemy * EnemySpawner::spawnEnemy(qreal x, qreal y)
{
   //will need to work with James on getting these x, y values from the map itself
   int temp = rand() % 10;
   if (temp < 3){
       return new Enemy(x, y, mTempSize-10);
   }
   else if (temp >= 3 && temp <= 8)
   {
       return new Enemy(x, y, mTempSize);
   }
   else
   {
       return new Enemy(x, y, mTempSize+10);
   }
   //return new Enemy(x, y, mTempSize);
}
