#ifndef ENEMYSPAWNER_H
#define ENEMYSPAWNER_H

#include "enemy.h"
#include <fstream>
#include <cstdlib>
#include <ctime>
class EnemySpawner
{
private:
    int mTempSize;
public:
    EnemySpawner();
    Enemy * spawnEnemy(qreal x, qreal y);
};

#endif // ENEMYSPAWNER_H
