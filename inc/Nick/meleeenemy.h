#ifndef MELEEENEMY_H
#define MELEEENEMY_H

#include "enemy.h"

class MeleeEnemy : public Enemy {
public:
    MeleeEnemy(double, double, int);
    void makeAttack(qreal, qreal);
    int decide(qreal, qreal, int, int);
};

#endif // MELEEENEMY_H
