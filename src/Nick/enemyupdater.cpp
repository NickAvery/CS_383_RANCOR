#include "NAenemyupdater.h"
#include <QDebug>
void EnemyUpdater::update(qreal charX, qreal charY)
{
    for(int i = 0; i < 2; i++)
    {
        //qDebug() << sEnemies[i]->getXPos();
        if (sEnemies[i]->getXPos()-charX < 0)
            sEnemies[i]->move(sEnemies[i]->getXPos()+1,
                              sEnemies[i]->getYPos());
        else
            sEnemies[i]->move(sEnemies[i]->getXPos()-1,
                              sEnemies[i]->getYPos());
        if (sEnemies[i]->getYPos()-charY < 0)
            sEnemies[i]->move(sEnemies[i]->getXPos(),
                              sEnemies[i]->getYPos()+1;
        else
            sEnemies[i]->move(sEnemies[i]->getXPos(),
                              sEnemies[i]->getYPos()-1;
        //qDebug() << "Enemy " << i << ": " << sEnemies[i]->getXPos() << ", " << sEnemies[i]->getYPos();
    }
}

EnemyUpdater::EnemyUpdater()
{
    sEnemies = new Enemy*[2];
    sEnemies[0] = new Enemy(100.0, 50.0, 10);
    sEnemies[1] = new Enemy(100.0, 200.0, 5);
    //qDebug() << "Enemy " << 1 << ": " << sEnemies[1]->getXPos() << ", " << sEnemies[1]->getYPos();
}

void EnemyUpdater::giveInfo(qreal charX, qreal charY)
{
    //sEnemies = enemies;
    update(charX, charY);
    //enemies = sEnemies;
}
