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
#include "JTwalls.h"

#include <QLineF>
//#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <cmath>
#include <ctgmath>

#define PI 3.14159265358979323846264


Shot::Shot(double s, QLineF l)
    //:QGraphicsRectItem(l.x1(), l.y1(), size, size)
{
    //Draw Graphics
    setPixmap(QPixmap(":/images/Graphics/Lasers/laserGreen04.png"));


    //this->pixmap().rect().center();
    shotSpeed = s;
    line = l;
    //angle = l.angleTo(QLineF( 0.0,0.0,1.0, 0.0 ));
    //angle = l.angle();
    setRotation( 90-l.angle());
    //qDebug() << "Angle" << 90-l.angle();
    angle = (l.angle() * PI ) / 180;
    //QGraphicsRectItem::setRect( 0, 0, size, size );
    //QGraphicsRectItem::setPos( l.x1(), l.y1() );
    setPos( l.x1(), l.y1() );
    //myCharacter = c;
}

Shot::~Shot()
{
    //delete(this);
//qDebug() << "Shot death." << pos();
}

/*  mapToSpread()
 *
 *
 *
 */
double Shot::mapToSpread(double x, double spread, double inputStart, double inputEnd)
{
    //          static bool first = true;
    //https://stackoverflow.com/questions/5731863/mapping-a-numeric-range-onto-another
    //slope = 1.0 * (output_end - output_start) / (input_end - input_start)
    static double slope = 1.0 * (spread * 2) / (inputEnd - inputStart);
    return ( (slope * (x - inputStart)) - spread );
}


/* update()
 * Moves shot according to shotSpeed,
 * Checks for collisions with enemies and
 * Wall objects.
 */
int Shot::shotUpdate()
{
    //Move shot.
    double newX = x() + ( shotSpeed * cos(angle));
    double newY = y() - ( shotSpeed * sin(angle));
   //see header for details for why this ^ signage

    setPos( newX, newY );

    //Check collisions.
    QList<QGraphicsItem *> list = collidingItems() ;
    bool die = false;
    bool walls = false;
    foreach(QGraphicsItem * i , list)
    {
        Enemy * item= dynamic_cast<Enemy *>(i);
        if (item) {
            //Signal enemy Damage,

            //Remove Shot.
            //delete this;    //Note: Scary stuff to do this, handle with extreme care.
            item->attacked(damage);
            die = true;
        }
        Walls* wall = dynamic_cast<Walls *>(i);
        if (wall) {
            walls = true;
        }
    }
    if (die || !walls) {
        //qDebug() << "Hit Something!";
        delete this;
    }

}

/* This slot is initialized by calling function
 * It is used so that a single signal can be
 * connected to the shots to tell them to die,
 * that way control over them does not require
 * the pointer to the object.
 *
 */
void Shot::kill()
{
    delete this;
}
