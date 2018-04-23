#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QDebug>
#include <QGraphicsPixmapItem>
#include <QtMath>
#include <cassert>
#include <QUrl>
class Enemy: public QGraphicsPixmapItem
{
    //QGraphicsPixmapItem holds things such as position and the image.
private:
    int mHealth;
    int mAtkValue;
    int mSize;
    int mSpeed;
public:
    Enemy(double, double, int);    //x = x-coordinate, y = y-coordinate, size = size of square
    qreal getXPos();                        //gets the x-coordinate
    qreal getYPos();                        //gets the y-coordinate
    int getHealth();                        //gets the health value
    int getAtkValue();                      //gets the attack value
    int getSize();                          //get the size of an enemy
    int getSpeed();                         //get the speed of an enemy
    void move(qreal, qreal);                //sets the position to the (x, y) coordinate
    int attack();                           //enemy deals damage
    virtual void makeAttack(qreal, qreal) = 0;
    virtual int decide(qreal, qreal) = 0;
    void runAway(qreal, qreal);
    void makeDecision(qreal, qreal);
    void attacked(int);                     //enemy is hit
    void removeEnemy();                     //if an enemy dies or gets removed for another reason, use this
};

#endif // ENEMY_H
