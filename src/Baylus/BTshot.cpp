/*
 * BTshot.cpp
 * Baylus Tunnicliff    3/3/2018
 * Team Rancor      Space Shooter X
 * Shot Class Implementation
 *
 *
 *
 *
 */



#include "BTshot.h"
#include "NAenemyupdater.h"

#include <QLineF>
#include <QGraphicsRectItem>
#include <cmath>
#include <ctgmath>

#define PI 3.14159265358979323846264


Shot::Shot(double s, QLineF *l)
    :QGraphicsRectItem(0, 0, size, size)
{
    shotSpeed = s;
    line = l;

    angle = (l->angle() * PI ) / 180;
   // QGraphicsRectItem::setRect( 0, 0, size, size );
    QGraphicsRectItem::setPos( l->x1(), l->y1() );
    //myCharacter = c;
}

Shot::~Shot()
{
    delete(this);
}

/* update()
 * Moves shot according to shotSpeed,
 * Checks for collisions with enemies and
 * Wall objects.
 */
int Shot::update()
{
    //Move shot.
    double newX = QGraphicsRectItem::x() + ( shotSpeed * cos(angle));
    double newY = QGraphicsRectItem::y() + ( shotSpeed * sin(angle));

    setPos( newX, newY );

    //Check collisions.
    QList<QGraphicsItem *> list = collidingItems() ;

    foreach(QGraphicsItem * i , list)
    {
        Enemy * item= dynamic_cast<Enemy *>(i);
        //if (item) myWalls = item;
    }
    if (!list.isEmpty()) {
        qDebug() << "Hit Something!";
       // free(this);
    }

}
