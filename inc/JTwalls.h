#ifndef JTWALLS_H
#define JTWALLS_H

#include <QGraphicsItem>
#include <QObject>

class Walls: public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Walls * walls;
    Walls();
};

#endif // JTWALLS_H
