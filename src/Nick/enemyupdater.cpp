#include "NAenemyupdater.h"
#include <QDebug>
EnemyUpdater::EnemyUpdater()
{
    mSpawner = new EnemySpawner();
    testCaseMax = 200;
    testCaseNum = 0;
    //qDebug() << "Enemy " << 1 << ": " << sEnemies.value(1)->getXPos() << ", " << sEnemies.value(1)->getYPos();
}

void EnemyUpdater::testCase(QGraphicsScene *scene)
{

    while (testCaseNum < testCaseMax)
    {
        //qDebug() << "makin em";
        newEnemy(scene, rand()%690+40, rand()%490+40);
        testCaseNum++;
    }
}

bool EnemyUpdater::enemiesDead()
{
    return sEnemies.isEmpty();
}

int EnemyUpdater::numOfEnemies()
{
    return sEnemies.size();
}

void EnemyUpdater::update(qreal playerX, qreal playerY)
{
    Enemy *temp;
    for(int i = 0; i < sEnemies.size(); i++)
    {
        temp = sEnemies.value(i);
        //qDebug() << tempX-charX << tempY-charY;
        if( temp->getHealth() <= 0)
        {
            //qDebug() << "success";
            removeEnemy(i);
            continue;
        }
        temp->makeDecision(playerX, playerY);
        //qDebug() << "Enemy " << i << ": " << (int)sEnemies.value(i)->getXPos() << ", " << (int)sEnemies.value(i)->getYPos();
    }
}

void EnemyUpdater::removeEnemy(int i)
{
   sEnemies.takeAt(i)->removeEnemy();
}

void EnemyUpdater::removeEnemies()
{
    for(int i = 0; i < sEnemies.size(); i++)
    {
        removeEnemy(i);
    }
}

void EnemyUpdater::giveInfo(qreal charX, qreal charY)
{
    update(charX, charY);
}

void EnemyUpdater::newEnemy(QGraphicsScene *scene, qreal x, qreal y)
{
    sEnemies.append(mSpawner->spawnEnemy(x, y));
    scene->addItem(getEnemy(getEnemies().size()-1));
}

Enemy *EnemyUpdater::getEnemy(int i)
{
    return sEnemies.value(i);
}

QList<Enemy *> EnemyUpdater::getEnemies()
{
    return sEnemies;
}
