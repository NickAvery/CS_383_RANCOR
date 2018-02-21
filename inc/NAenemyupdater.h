#ifndef ENEMYUPDATER_H
#define ENEMYUPDATER_H

#include "enemy.h"
#include <cmath>

class EnemyUpdater
{
private:

    void update(qreal, qreal);
public:
    EnemyUpdater();
    Enemy **sEnemies;
    void giveInfo(qreal charX, qreal charY);
};

#endif // ENEMYUPDATER_H
