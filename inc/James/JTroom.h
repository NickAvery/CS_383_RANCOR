#ifndef JTROOM_H
#define JTROOM_H

#include "JTwalls.h"
#include "JTdoor.h"
#include "JTbackground.h"
#include <QGraphicsView>
class Room: public QGraphicsView{
private:
public:
    Room(bool topDoor, bool rightDoor, bool bottomDoor, bool leftDoor, int selection);
    Walls * walls;
    Door * lDoor;
    Door * rDoor;
    Door * bDoor;
    Door * tDoor;
    Background * bg;
};

#endif // JTROOM_H
