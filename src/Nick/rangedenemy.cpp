#include "rangedenemy.h"
#include "BTenemyShot.h"
RangedEnemy::RangedEnemy(double xSet, double ySet, int size):Enemy(xSet, ySet, size)
{
    QPixmap pic = QPixmap(":/images/NAenemyRanged.png");
    pic = pic.scaled(size, size, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    setPixmap(pic);
    shotCooldown = size*4;
    tempCooldown = 0;
}

RangedEnemy::~RangedEnemy()
{
    shotKill();
}
void RangedEnemy::makeAttack(qreal playerX, qreal playerY)
{
    qreal tempX = x();
    qreal tempY = y();
    qreal tempRotX = playerX-tempX;
    qreal tempRotY = playerY-tempY;
    qreal flipAdd = 90.0;

    //normalize the distance between player and enemy
    qreal hypot = sqrt((tempRotX*tempRotX)+(tempRotY*tempRotY));
    tempRotX /= hypot;
    tempRotY /= hypot;

    if (tempRotY < 0)
    {
        flipAdd = -90;
    }
    setPos(tempX, tempY);
    double degreeRot = -(qRadiansToDegrees(qAtan(tempRotX/tempRotY)));
    setRotation(degreeRot+flipAdd);

    //shoot a bullet
    if(++tempCooldown >= shotCooldown)
    {
        EnemyShot* es = new EnemyShot(getSpeed()*1.5,QLineF(x(),y(),playerX,playerY),getAtkValue());
        connect(this, SIGNAL(shotTick()), es, SLOT(shotUpdate()));
        connect(this, SIGNAL(shotKill()), es, SLOT(kill()));
        scene()->addItem(es);
        tempCooldown = 0;
    }

}

int RangedEnemy::decide(qreal playerX, qreal playerY)
{
    qreal tempX = x();
    qreal tempY = y();
    qreal tempRotX = playerX-tempX;
    qreal tempRotY = playerY-tempY;
    qreal distance = sqrt((tempRotX*tempRotX)+(tempRotY*tempRotY));
    shotTick();
    //attack player
    if(distance < 200 && getHealth() >30)
        return 1;
    else if(getHealth() <= 30)
        return 2;
    else
        return 0;
    return 0;
}

