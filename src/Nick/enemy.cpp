#include "enemy.h"

Enemy::Enemy(qreal x, qreal y, int size)
{
    //qDebug() << x << " " << y;
    mXPos = x;
    mYPos = y;
    mSize = size;
    mHealth = 5;
    mAtkValue = 1;
    setRect(mXPos, mYPos, size, size);
    setPos(mXPos, mYPos);
}

int Enemy::attack()
{
    //figure out some sort of cool attack things
    return mAtkValue;
}
