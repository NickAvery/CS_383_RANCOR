#ifndef JTGOAL_H
#define JTGOAL_H

#include <QGraphicsItem>
#include <QObject>

class Goal: public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Goal * goal;
    Goal();
};

#endif // JTGOAL_H
