#include "enemy.h"

Enemy::Enemy(qreal xSet, qreal ySet, int size, QPixmap pic)
{
    //qDebug() << x << " " << y;
    mSize = size;
    mHealth = size;
    mAtkValue = 40-size;

    pic = pic.scaled(size, size, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    setPixmap(pic);
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

void Enemy::move(qreal xNew, qreal yNew)
{
    setPos(xNew, yNew);
}

int Enemy::attack()
{
    //figure out some sort of cool attack things
    return mAtkValue;
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
