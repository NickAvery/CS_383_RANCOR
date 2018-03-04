#ifndef JTWALLS_H
#define JTWALLS_H

#include <QGraphicsItem>
#include <QObject>
#include <QGraphicsPixmapItem>

class Walls: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    //Walls * walls;
    Walls();
};

#endif // JTWALLS_H
