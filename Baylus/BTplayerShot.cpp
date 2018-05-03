/*  Baylus Tunnicliff
 *  4/23/2018
 *
 *
 *
 *
 */

#include "BTplayerShot.h"


bool PlayerShot::checkCollisions() {
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
    } else {
        return false;
    }
}
