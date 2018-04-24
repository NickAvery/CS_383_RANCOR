#ifndef RANGEDENEMY_H
#define RANGEDENEMY_H


#include "enemy.h"

class RangedEnemy : public QObject, public Enemy {

    Q_OBJECT
public:
    RangedEnemy(double, double, int);
    ~RangedEnemy();
    void makeAttack(qreal, qreal);
    int decide(qreal, qreal);
private:
    int shotCooldown;
    int tempCooldown;
signals:
    void shotTick();
    void shotKill();
};

#endif // RANGEDENEMY_H
