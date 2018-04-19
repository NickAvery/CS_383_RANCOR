#include "rangedenemy.h"
RangedEnemy::RangedEnemy(double xSet, double ySet, int size):Enemy(xSet, ySet, size)
{
    QPixmap pic = QPixmap(":/images/NAenemyRanged.png");
    pic = pic.scaled(size, size, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    setPixmap(pic);

}
void RangedEnemy::makeAttack(qreal playerX, qreal playerY)
{

}

int RangedEnemy::decide(qreal playerX, qreal playerY)
{

}
