/* Baylus Tunnicliff
 * 4/11/2018
 * Entity Superclass - "BTentity.h"
 * Creates a framework for which the player and the enemies can
 * inherit from and create a inheritance structure.
 *
 *
 *
 *
 *
 */

#ifndef ENTITY_H
#define ENTITY_H

#include <QGraphicsPixmapItem>

class Entity : public QGraphicsPixmapItem{
public:
    Entity(QPixmap p);
    Entity() : Entity(QPixmap()) {} //Default Constructor mapped to the regular constructor.

    virtual void move();
    virtual void update();
    //virtual void


    void setGraphic(const QPixmap &graphic);

private:
    QPixmap mGraphic;
};


#endif

