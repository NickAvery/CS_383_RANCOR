#ifndef JTMAP_H
#define JTMAP_H

#include "JTwalls.h"
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>

class Map: public QGraphicsView{
private:
public:
    QGraphicsScene * scene;
    Walls * walls;
    Map(QGraphicsScene* scene);
};

#endif // JTMAP_H
