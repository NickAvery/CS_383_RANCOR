#include "enemy.h"

Enemy::Enemy(qreal xSet, qreal ySet, int size)
{
    mSize = size;
    mHealth = size*3;
    if(mSize <= 30)
    {
        mAtkValue = 40-size;
        mSpeed = mAtkValue/10.0;
    }
    else
    {
        mAtkValue = 5;
        mSpeed = 1;
    }
    //qDebug() << ;
    setPos(xSet, ySet);
    setTransformOriginPoint(size/2, size/2);
}

qreal Enemy::getXPos()
{
    return x();
}

qreal Enemy::getYPos()
{
    return y();
}

int Enemy::getHealth()
{
    return mHealth;
}

int Enemy::getAtkValue()
{
    return mAtkValue;
}

int Enemy::getSize()
{
    return mSize;
}

void Enemy::move(qreal playerX, qreal playerY)
{
    qreal tempX = getXPos();
    qreal tempY = getYPos();
    qreal tempRotX = playerX-tempX;
    qreal tempRotY = playerY-tempY;
    qreal flipAdd = 90.0;
    qreal hypot = sqrt((tempRotX*tempRotX)+(tempRotY*tempRotY)); //normalize the distance between player and enemy
    tempRotX /= hypot;
    tempRotY /= hypot;
    tempX+=tempRotX*((qreal)mSpeed/(1.0+(((qreal)mSize-40.0)/100)));
    tempY+=tempRotY*((qreal)mSpeed/(1.0+(((qreal)mSize-40.0)/100)));
    if (tempRotY < 0)
    {
        flipAdd = -90;
    }
    setPos(tempX, tempY);
    double degreeRot = -(qRadiansToDegrees(qAtan(tempRotX/tempRotY)));
    setRotation(degreeRot+flipAdd);
}

int Enemy::attack()
{
    //figure out some sort of cool attack things
    return mAtkValue;
}

void Enemy::makeDecision(qreal playerX, qreal playerY)
{
    int d = decide(playerX, playerY);
    move(playerX, playerY);
    makeAttack(playerX, playerY);
}

void Enemy::attacked(int damage)
{
    mHealth-=damage;
}

void Enemy::removeEnemy()
{
    scene()->removeItem(this);
    delete this;
}
