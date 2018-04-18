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
#include <QGraphicsPixmapItem>

struct weaponStats {
    int* shotSpeed = NULL;          //bullet travel speed
    int* shotSize = NULL;           //
    int* shotDamage = NULL;         //damage on impact
    int* shotCooldown = NULL;       // Related to frequency that player is allowed to fire.

    double* multiShotOffset = NULL; //the horizontal offset of the bullets from one another. (i.e. not angle of them)
    int* multiShotNumber = NULL;    //Number of shots per weapon-fire.
    double* multiShotAngle = NULL;  //The angle between each of the several bullets.

    bool* doesBulletSplit = NULL;   //bullet splitting upon impact.

};


class Shot: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Shot(double s = 2.5, QLineF l = QLineF(0,0,0,1));
    //Shot() : Shot(2.5 , QLineF(0,0,0,1) ) {}
    ~Shot();
    //Shot(Character* c, double s = 2.5, QLineF* l);
    //Shot();
    /* Update moves the shots and checks collisions.  */
private:
    double shotSpeed;
    QLineF line;
    double mapToSpread(double x = 0, double spread = 5.0, double inputStart = 0, double inputEnd = 1);
    //Note: This angle is not how you think it works, have to reverse the y axis.
    double angle;   //angle in radians
    double damage = 30;
    double size = 10;
    double spread = 5.0;
    //Character* myCharacters;
public slots:
    int shotUpdate();
    void kill();
};
#endif
