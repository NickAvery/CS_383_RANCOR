#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QDebug>
#include <QGraphicsPixmapItem>
#include <QtMath>
class Enemy: public QGraphicsPixmapItem
{
    //QGraphicsPixmapItem holds things such as position and the image.
private:
    int mHealth;
    int mAtkValue;
    int mSize;
public:
    Enemy(double x, double y, int size);    //x = x-coordinate, y = y-coordinate, size = size of square
    qreal getXPos();                        //gets the x-coordinate
    qreal getYPos();                        //gets the y-coordinate
    int getHealth();                        //gets the health value
    int getAtkValue();                      //gets the attack value
    int getSize();                          //get the size of an enemy
    void move(qreal, qreal);            //sets the position to the (x, y) coordinate
    int attack();                           //enemy deals damage
    void getAttacked(int);           //enemy is hit
    void removeEnemy();                     //if an enemy dies or gets removed for another reason, use this
};

#endif // ENEMY_H
