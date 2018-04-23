#include "rangedenemy.h"
RangedEnemy::RangedEnemy(double xSet, double ySet, int size):Enemy(xSet, ySet, size)
{
    QPixmap pic = QPixmap(":/images/NAenemyRanged.png");
    pic = pic.scaled(size, size, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    setPixmap(pic);

}
void RangedEnemy::makeAttack(qreal playerX, qreal playerY)
{
    qreal tempX = getXPos();
    qreal tempY = getYPos();
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
}

int RangedEnemy::decide(qreal playerX, qreal playerY)
{
    qreal tempX = getXPos();
    qreal tempY = getYPos();
    qreal tempRotX = playerX-tempX;
    qreal tempRotY = playerY-tempY;
    qreal distance = sqrt((tempRotX*tempRotX)+(tempRotY*tempRotY));
    //attack player
    if(distance < 200 && getHealth() >30)
        return 1;
    else if(getHealth() <= 30)
        return 2;
    else
        return 0;
    return 0;
}

