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
    //Walls * walls;
    Room * room;
    Map(QGraphicsScene* scene, bool Demo);
    void selectRoom(int selection, QGraphicsScene* scene);
    void switchRooms(QString name);
    static int roomx;
    static int roomy;
    const static int maxx=101;
    const static int maxy=101;
    Room * floorarray[101][101];
};

#endif // JTMAP_H
