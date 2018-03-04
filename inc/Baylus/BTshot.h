/*
 * BTshot.h
 * Baylus Tunnicliff    3/3/2018
 * Team Rancor      Space Shooter X
 * Shot Class Header
 *
 *
 *
 *
 */

#ifndef SHOT_H
#define SHOT_H

#include "NAenemyupdater.h"
//#include "BTcharacter.h"

#include <QLineF>


class Shot: public QObject, public QGraphicsRectItem
{
    Q_OBJECT

public:
    Shot( double s = 2.5, QLineF* l = NULL);
    ~Shot();
    //Shot(Character* c, double s = 2.5, QLineF* l);
    //Shot();
    /* Update moves the shots and checks collisions.  */
    int update();
private:
    double shotSpeed;
    QLineF* line;
    double angle;   //angle in radians
    double damage = 30;
    double size = 10;
    //Character* myCharacter;
};
#endif
