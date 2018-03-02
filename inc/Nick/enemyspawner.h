#ifndef ENEMYSPAWNER_H
#define ENEMYSPAWNER_H

#include "enemy.h"
#include <fstream>
class EnemySpawner
{
private:
    int mTempX;
    int mTempY;
    int mTempSize;
public:
    EnemySpawner();
    Enemy * spawnEnemy(qreal x, qreal y);
};

#endif // ENEMYSPAWNER_H
