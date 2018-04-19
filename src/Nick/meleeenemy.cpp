#include "meleeenemy.h"
MeleeEnemy::MeleeEnemy(double xSet, double ySet, int size):Enemy(xSet, ySet, size)
{
    QPixmap pic = QPixmap(":/images/NAenemyMelee.png");
    pic = pic.scaled(size, size, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    setPixmap(pic);

}
void MeleeEnemy::makeAttack(qreal playerX, qreal playerY)
{

}

int MeleeEnemy::decide(qreal playerX, qreal playerY)
{

}
