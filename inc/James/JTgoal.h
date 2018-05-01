/*#ifndef JTGOAL_H
#define JTGOAL_H

#include <QGraphicsItem>
#include <QObject>
#include <QGraphicsPixmapItem>
#include "JTCollidable.h"

class Goal: public Collidable
{
    Q_OBJECT
private:
    Goal * mGoal;
public:
    Goal(QPixmap *pic, QGraphicsScene* scene);
};

#endif // JTGOAL_H
*/

#ifndef JTGOAL_H
#define JTGOAL_H

#include <QGraphicsItem>
#include <QObject>
#include <QGraphicsPixmapItem>

class Goal: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
private:
    //Goal * goal;
public:
    Goal();
};

#endif // JTGOAL_H
