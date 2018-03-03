#ifndef JTMAP_H
#define JTMAP_H

#include "JTwalls.h"
#include "JTroom.h"
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>

class Map: public QGraphicsView{
private:
public:
    QGraphicsScene * scene;
    Walls * walls;
    Map(QGraphicsScene* scene);
    Room * selectRoom(int selection, QGraphicsScene* scene);
    static int roomx;
    static int roomy;
    static int maxx;
    static int maxy;
};

#endif // JTMAP_H
