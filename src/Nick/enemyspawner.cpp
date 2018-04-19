#include "enemyspawner.h"

EnemySpawner::EnemySpawner()
{
    //will be implementing after tests for week 3
    QFile mEnemyDatabase(":/databases/NAenemydatabase.txt");//, std::ifstream::in);
    assert(mEnemyDatabase.open(QIODevice::ReadOnly));
    QTextStream dataInput(&mEnemyDatabase);
    dataInput >> mTempSize;//>> mTempY >> mTempSize;
    qDebug() << "Template test" << mTempSize;
    //should plan for things like attack speed, attack values, health, etc...
    mEnemyDatabase.close();
    srand(time(NULL));
    //mTempSize = 30;
}

Enemy * EnemySpawner::spawnEnemy(qreal x, qreal y)
{
   //will need to work with James on getting these x, y values from the map itself
   int temp = rand() % 10;
   int temp2 = rand() & 2;
   QPixmap pic;
   if(temp2)
   {
       if (temp < 3)
       {
           return new RangedEnemy(x, y, mTempSize-10);
       }
       else if (temp >= 3 && temp <= 8)
       {
           return new RangedEnemy(x, y, mTempSize);
       }
       else
       {
           return new RangedEnemy(x, y, mTempSize+20);
       }
   }
   else
   {
       if (temp < 3)
       {
           return new MeleeEnemy(x, y, mTempSize-10);
       }
       else if (temp >= 3 && temp <= 8)
       {
           return new MeleeEnemy(x, y, mTempSize);
       }
       else
       {
           return new MeleeEnemy(x, y, mTempSize+30);
       }
   }

}
