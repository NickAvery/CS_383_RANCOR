#include "NAenemyupdater.h"
#include <QDebug>
EnemyUpdater::EnemyUpdater()
{
    mSpawner = new EnemySpawner();
    testCaseMax = 500;
    testCaseNum = 0;
    //qDebug() << "Enemy " << 1 << ": " << sEnemies.value(1)->getXPos() << ", " << sEnemies.value(1)->getYPos();
}

void EnemyUpdater::testCase(QGraphicsScene *scene)
{

    while (testCaseNum < testCaseMax)
    {
        //qDebug() << "makin em";
        newEnemy(rand()%690+40, rand()%490+40);
        scene->addItem(getEnemy(getEnemies().size()-1));
        testCaseNum++;
    }
}

bool EnemyUpdater::enemiesDead()
{
    return sEnemies.isEmpty();
}

void EnemyUpdater::update(qreal charX, qreal charY)
{
    qreal tempX;
    qreal tempY;
    qreal tempRotX;
    qreal tempRotY;
    qreal flip;
    qreal flipAdd;
    qreal tanResult;
    Enemy *e;
    for(int i = 0; i < sEnemies.size(); i++)
    {

        e = sEnemies.value(i);
        tempX = e->getXPos();
        tempY = e->getYPos();
        //qDebug() << tempX-charX << tempY-charY;
        if(((tempX <= charX+1.0 && tempX >= charX-1.0) && (tempY <= charY+1.0 && tempY >= charY-1.0)) || e->getHealth() == 0)
        {
            //qDebug() << "success";
            removeEnemy(i);
            continue;
        }
        flip = 1.0;
        flipAdd = 0.0;
        tempRotX = tempX-charX;
        tempRotY = tempY-charY;
        if (tempRotX < 0)
        {
            tempX+=1.0/5.0;
            if (tempRotY < 0)
            {
                flip = -1;
            }
            else
            {
                flip = -1;
            }
        }
        else
        {
            //tempRotX = tempX-charX;
            flipAdd = 180;
            tempX-=1.0/5.0;
        }
        if (tempRotY < 0)
        {
            //tempRotY = charY-tempY;
            tempY+=1.0/5.0;
        }
        else
        {
            //tempRotY = tempY-charY;
            tempY-=1.0/5.0;
        }
        e->move(tempX, tempY);
        tanResult = qFloor(qSin(tempRotY/qSqrt(qPow(tempRotX, 2) + qPow(tempRotY, 2))) *(180.0/3.14));
        if (tempRotX < 1 && tempRotX > -1)
        {
            //qDebug() << tanResult << "THE";
            if (tempRotY < 0)
            {
                e->setRotation(90.0);
            }
            else
            {
                e->setRotation(270.0);
            }
        }
        else if (tempRotY < 1 && tempRotY > -1)
        {
            if (tempRotX < 0)
            {
                e->setRotation(0.0);
            }
            else
            {
                e->setRotation(180.0);
            }
        }
        else
        {
            //qDebug() << tanResult << "bleh";
            e->setRotation(flip*(tanResult)+flipAdd);
        }
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

void EnemyUpdater::newEnemy(qreal x, qreal y)
{
    sEnemies.append(mSpawner->spawnEnemy(x, y));
}

Enemy *EnemyUpdater::getEnemy(int i)
{
    return sEnemies.value(i);
}

QList<Enemy *> EnemyUpdater::getEnemies()
{
    return sEnemies;
}
