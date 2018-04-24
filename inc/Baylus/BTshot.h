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

    QPixmap* myPixMap = NULL;
};

#include "NAenemyupdater.h"
//#include "BTcharacter.h"
//#include "BTcharacter.h"
#include "BTplayer.h"
#include "JTwalls.h"


class Character;


class Player;

//template <class T>

class Shot: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Shot( double s = 2.5, QLineF l = QLineF(0,0,0,1));
    //Shot() : Shot(2.5 , QLineF(0,0,0,1) ) {}
    ~Shot();

    double getDamage() { return damage; }
    //Shot(Character* c, double s = 2.5, QLineF* l);
    //Shot();
    /* Update moves the shots and checks collisions.  */
private:
    //T parentType;

    double shotSpeed;
    QLineF line;
    double mapToSpread(double x = 0, double spread = 5.0, double inputStart = 0, double inputEnd = 1);
    //Note: This angle is not how you think it works, have to reverse the y axis.
    double angle;   //angle in radians
    double damage = 30;
    double size = 10;
    double spread = 5.0;

    virtual bool checkCollisions() = 0;

    static struct weaponStats* sWeapon; //Static weapon variable.
    //Character* myCharacters;
signals:
    void hitEnemy();
public slots:
    int shotUpdate();
    void kill();
};

class Player;

/*
class EnemyShot : public Shot {
public:
    EnemyShot(double s, QLineF l, double dmg) : Shot(s, l) {mEnemyDmg = dmg;}

    bool checkCollisions();
    / *
    bool checkCollisions() {
        QList<QGraphicsItem *> list = collidingItems(Qt::IntersectsItemShape) ;
        bool die = false;
        bool walls = false;
        foreach(QGraphicsItem * i , list)
        {
            Walls* wall = dynamic_cast<Walls *>(i);
            if (wall) {
                walls = true;
            }

            Player* p = dynamic_cast<Player *>(i);
            if ( p ) {  //If the shot is hitting the (a(?)) player.
                //i ( typeid(parentType) != typeid(Player) ) {
                //The shot was not from the player.

                //Deal damage to the player.
                p->dealDamageToPlayer(mEnemyDmg);
                die = true; //Shot dies after checking collisions.
                //}   //If the shot is from a player, dont damage player.


            }
        }
        if (die || !walls) {
            //qDebug() << "Hit Something!";
            delete this;
        }
    }
    * /

private:
    double mEnemyDmg = 0;

};
*/

/*
class PlayerShot : public Shot {
private:

public:
    PlayerShot(double s, QLineF l) : Shot(s, l) {}

    bool checkCollisions() {
        QList<QGraphicsItem *> list = collidingItems(Qt::IntersectsItemShape) ;

        bool die = false;
        bool walls = false;
        foreach(QGraphicsItem * i , list)
        {
            Enemy * item= dynamic_cast<Enemy *>(i);
            if (item) { //If enemy has been hit.
                //Signal enemy Damage,

                item->attacked(getDamage());
                die = true;

            }
            Walls* wall = dynamic_cast<Walls *>(i);
            if (wall) {
                walls = true;
            }



        }
        if (die || !walls) {
            //if shot should die.
            return true;

            //qDebug() << "Hit Something!";

            //delete this;
        }
    }

private:
};

*/

#endif
