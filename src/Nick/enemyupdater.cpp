#include "enemyupdater.h"
#include <QDebug>
void EnemyUpdater::update(double charX, double charY)
{
    Enemy *temp = new Enemy(0,0,0);
    for(int i = 0; i < 2; i++)
    {
        //temp = sEnemies[i];
        qDebug() << sEnemies[i]->getXPos()+abs(sEnemies[i]->getXPos()-charX)/10.0;
        if (sEnemies[i]->getXPos()-charX < 0)
            sEnemies[i]->move(sEnemies[i]->getXPos()+abs(sEnemies[i]->getXPos()-charX)/10.0,
                              sEnemies[i]->getYPos());
        else
            sEnemies[i]->move(sEnemies[i]->getXPos()-abs(sEnemies[i]->getXPos()-charX)/10.0,
                              sEnemies[i]->getYPos());
        if (sEnemies[i]->getYPos()-charY < 0)
            sEnemies[i]->move(sEnemies[i]->getXPos(),
                              sEnemies[i]->getYPos()+abs(sEnemies[i]->getYPos()-charY)/10.0);
        else
            sEnemies[i]->move(sEnemies[i]->getXPos(),
                              sEnemies[i]->getYPos()-abs(sEnemies[i]->getYPos()-charY)/10.0);
        qDebug() << "Enemy 0: " << sEnemies[i]->getXPos() << ", " << sEnemies[i]->getYPos();
        //sEnemies[i] = temp;
    }
}

EnemyUpdater::EnemyUpdater()
{
    sEnemies = new Enemy*[2];
    sEnemies[0] = new Enemy(0.0, 0.0, 5);
    sEnemies[1] = new Enemy(7.0, 2.0, 6);
}

void EnemyUpdater::giveInfo(Enemy **enemies, double charX, double charY)
{
    //sEnemies = enemies;
    update(charX, charY);
    //enemies = sEnemies;
}
