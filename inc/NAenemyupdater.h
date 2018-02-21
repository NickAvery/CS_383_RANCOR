#ifndef ENEMYUPDATER_H
#define ENEMYUPDATER_H

#include "enemy.h"
#include <cmath>

class EnemyUpdater
{
private:

    void update(double, double);
public:
    EnemyUpdater();
    Enemy **sEnemies;
    void giveInfo(Enemy **enemies, double charX, double charY);
};

#endif // ENEMYUPDATER_H
