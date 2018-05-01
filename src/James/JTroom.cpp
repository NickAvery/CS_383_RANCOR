#include "JTRoom.h"
#include "JTWalls.h"
#include "JTDoor.h"

Room::Room(bool topDoor, bool rightDoor, bool bottomDoor, bool leftDoor, int selection)
{
    //add background
    mBackgroundObject = NULL;
    mBackgroundObject = new Background(selection);
    mBackgroundObject->setZValue(-1);

    //add walls
    mWalls = new Walls();
    bool sides;
    QString pass;

    //add doors
    if(topDoor)
    {
        sides=false;
        pass="Top";
        mTopDoorObject = new Door(sides,pass);
        mTopDoorObject->setZValue(-2);
        mTopDoorObject->setPos(370, 50);
    }
    else
    {
        mTopDoorObject=NULL;
    }
    if(rightDoor)
    {
        sides=true;
        pass="Right";
        mRightDoorObject = new Door(sides,pass);
        mRightDoorObject->setZValue(-2);
        mRightDoorObject->setPos(750,275);
    }
    else
    {
        mRightDoorObject=NULL;
    }
    if(bottomDoor)
    {
        sides=false;
        pass="Bottom";
        mBottomDoorObject = new Door(sides,pass);
        mBottomDoorObject->setZValue(-2);
        mBottomDoorObject->setPos(370, 550);
    }
    else
    {
        mBottomDoorObject=NULL;
    }
    if(leftDoor)
    {
        sides=true;
        pass="Left";
        mLeftDoorObject = new Door(sides,pass);
        mLeftDoorObject->setZValue(-2);
        mLeftDoorObject->setPos(40,275);
    }
    else
    {
        mLeftDoorObject=NULL;
    }
}
