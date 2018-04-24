/* Baylus Tunnicliff
 * 4-23-2018
 * ""
 *
 *
 */

#ifndef ENEMY_SHOT_H
#define ENEMY_SHOT_H

#include "BTshot.h"


class EnemyShot : public Shot {
public:
    EnemyShot(double s, QLineF l, double dmg) : Shot(s, l) {mEnemyDmg = dmg;}

    bool checkCollisions();
    /*
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
    */

private:
    double mEnemyDmg = 0;

};

#endif

