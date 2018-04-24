/* Baylus Tunnicliff
 * 4-23-2018
 * ""
 *
 *
 */

#ifndef PLAYER_SHOT_H
#define PLAYER_SHOT_H

#include "BTshot.h"
#include "BTplayer.h"
#include "enemy.h"
#include "BTshot.h"

class PlayerShot : public Shot {
private:

public:
    PlayerShot(double s, QLineF l) : Shot(s, l) {}

    bool checkCollisions();

    /*
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
    */
private:
};

#endif
