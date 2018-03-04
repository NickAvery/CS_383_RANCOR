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
    Shot(double s = 2.5, QLineF l = QLineF(0,0,0,1));
    ~Shot();
    //Shot(Character* c, double s = 2.5, QLineF* l);
    //Shot();
    /* Update moves the shots and checks collisions.  */
private:
    double shotSpeed;
    QLineF line;
    //Note: This angle is not how you think it works, have to reverse the y axis.
    double angle;   //angle in radians
    double damage = 30;
    double size = 10;
    //Character* myCharacter;
public slots:
    int shotUpdate();
    void kill();
};
#endif
