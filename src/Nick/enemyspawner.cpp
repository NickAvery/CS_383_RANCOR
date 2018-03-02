#include "enemyspawner.h"

EnemySpawner::EnemySpawner()
{
    std::ifstream mEnemyDatabase;
    mEnemyDatabase.open("enemyTemplates.txt", std::ifstream::in);
    if(mEnemyDatabase.is_open())
    {
        qDebug() << "is open";
    }
    int x = 0;
    mEnemyDatabase >> x;//>> mTempY >> mTempSize;
    qDebug() << x;
    //should plan for things like attack speed, attack values, health, etc...
    mEnemyDatabase.close();
}

Enemy * EnemySpawner::spawnEnemy(qreal x, qreal y)
{
   //will need to work with James on getting these x, y values from the map itself
   return new Enemy(x, y, 5);
}
