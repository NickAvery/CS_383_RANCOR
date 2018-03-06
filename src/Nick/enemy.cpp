#include "enemy.h"

Enemy::Enemy(qreal x, qreal y, int size)
{
    //qDebug() << x << " " << y;
    mSize = size;
    mHealth = size;
    mAtkValue = 1;

    QPixmap p = QPixmap(":/images/enemy.png");
    p = p.scaled(size, size, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    setPixmap(p);
    setPos(x, y);
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

void Enemy::getAttacked(int damage)
{
    mHealth-=damage;
}

void Enemy::removeEnemy()
{
    scene()->removeItem(this);
    delete this;
}
