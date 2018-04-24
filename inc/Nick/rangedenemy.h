#ifndef RANGEDENEMY_H
#define RANGEDENEMY_H


#include "enemy.h"

class RangedEnemy : public Enemy {
public:
    RangedEnemy(double, double, int);
    void makeAttack(qreal, qreal);
    int decide(qreal, qreal);
};

#endif // RANGEDENEMY_H
