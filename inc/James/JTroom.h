#ifndef JTROOM_H
#define JTROOM_H

#include "JTWalls.h"
#include "JTDoor.h"
#include "JTBackground.h"
#include <QGraphicsView>
class Room: public QGraphicsView
{
private:
public:
    Walls * mWalls;
    Door * mLeftDoorObject;
    Door * mRightDoorObject;
    Door * mBottomDoorObject;
    Door * mTopDoorObject;
    Background * mBackgroundObject;
    Room(bool topDoor, bool rightDoor, bool bottomDoor, bool mLeftDoorObject, int selection);
};

#endif // JTROOM_H
