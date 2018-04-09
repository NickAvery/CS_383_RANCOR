#ifndef JTGOAL_H
#define JTGOAL_H

#include <QGraphicsItem>
#include <QObject>
#include <QGraphicsPixmapItem>

class Goal: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
private:
    Goal * mGoal;
public:
    Goal();
};

#endif // JTGOAL_H
