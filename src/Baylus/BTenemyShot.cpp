/*  Baylus Tunnicliff
 *  Enemy Shot Class
 *  4/23/2018
 *
 */

#include "BTenemyShot.h"
#include "JTwalls.h"
#include "BTplayer.h"


#include <QGraphicsItem>


bool EnemyShot::checkCollisions() {
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

