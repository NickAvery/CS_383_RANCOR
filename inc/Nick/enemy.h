#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QDebug>
class Enemy: public QGraphicsRectItem
{
private:
    qreal mXPos;
    qreal mYPos;
    int mHealth;
    int mAtkValue;
    int mSize;
public:
    Enemy(double x, double y, int size); //x = x-coordinate, y = y-coordinate, size = size of square
    double getXPos() {return x();} //gets the x-coordinate
    double getYPos() {return y();} //gets the y-coordinate
    int getHealth() {return mHealth;} //gets the health value
    int getAtkValue() {return mAtkValue;} //gets the attack value
    int getSize() {return mSize;}
    void move(qreal x, qreal y){setPos(x, y);} //sets the position to the (x, y) coordinate
    int attack();
};

#endif // ENEMY_H
