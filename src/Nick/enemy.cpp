#include "enemy.h"

Enemy::Enemy(double x, double y, int size)
{
    mXPos = x;
    mYPos = y;
    mSize = size;
    mHealth = 5;
    mAtkValue = 1;
}

int Enemy::attack()
{
    //figure out some sort of cool attack things
    return mAtkValue;
}
