#ifndef JTROOM_H
#define JTROOM_H

#include "JTwalls.h"
#include "JTdoor.h"
#include <QGraphicsView>
class Room: public QGraphicsView{
private:
public:
    Room(QGraphicsScene* scene, bool topDoor, bool rightDoor, bool bottomDoor, bool leftDoor);
    //Room(bool topDoor, bool rightDoor, bool bottomDoor, bool leftDoor){
    Walls * walls;
    Door * lDoor;
    Door * rDoor;
    Door * bDoor;
    Door * tDoor;

};

#endif // JTROOM_H
