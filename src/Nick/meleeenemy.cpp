#include "meleeenemy.h"
MeleeEnemy::MeleeEnemy(double xSet, double ySet, int size):Enemy(xSet, ySet, size)
{
    QPixmap pic = QPixmap(":/images/NAenemyMelee.png");
    pic = pic.scaled(size, size, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    setPixmap(pic);

}
void MeleeEnemy::makeAttack(qreal playerX, qreal playerY)
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

    tempX+=tempRotX*(((qreal)getSpeed()*2)/(1.0+(((qreal)getSpeed()-40.0)/100)));
    tempY+=tempRotY*(((qreal)getSpeed()*2)/(1.0+(((qreal)getSpeed()-40.0)/100)));
    if (tempRotY < 0)
    {
        flipAdd = -90;
    }
    setPos(tempX, tempY);
    double degreeRot = -(qRadiansToDegrees(qAtan(tempRotX/tempRotY)));
    setRotation(degreeRot+flipAdd);
}

int MeleeEnemy::decide(qreal playerX, qreal playerY, int playerDamage, int playerLife)
{
    qreal tempX = x();
    qreal tempY = y();
    qreal tempRotX = playerX-tempX;
    qreal tempRotY = playerY-tempY;
    qreal distance = sqrt((tempRotX*tempRotX)+(tempRotY*tempRotY));
    //attack player
    if(distance < 70 && (getHealth() >30 || playerLife <= getAtkValue()))
        return 1;
    else if(getHealth() <= playerDamage)
        return 2;
    else
        return 0;
}

