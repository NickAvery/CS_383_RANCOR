#include "JTroom.h"
#include "JTwalls.h"
#include "JTdoor.h"

Room::Room(bool topDoor, bool rightDoor, bool bottomDoor, bool leftDoor, int selection)
{
    //add background
    bg = NULL;
    bg = new Background(selection);
    bg->setZValue(-1);

    //add walls
    walls = new Walls();
    bool sides;
    QString pass;

    //add doors
    if(topDoor){
        sides=false;
        pass="Top";
        tDoor = new Door(sides,pass);
        tDoor->setZValue(-2);
        tDoor->setPos(370, 50);
    } else{
        tDoor=NULL;
    }
    if(rightDoor){
        sides=true;
        pass="Right";
        rDoor = new Door(sides,pass);
        rDoor->setZValue(-2);
        //rDoor->setPos(730,260);
        rDoor->setPos(750,275);
    } else{
        rDoor=NULL;
    }
    if(bottomDoor){
        sides=false;
        pass="Bottom";
        bDoor = new Door(sides,pass);
        bDoor->setZValue(-2);
        //bDoor->setPos(360, 530);
        bDoor->setPos(370, 550);
    } else{
        bDoor=NULL;
    }
    if(leftDoor){
        sides=true;
        pass="Left";
        lDoor = new Door(sides,pass);
        lDoor->setZValue(-2);
        lDoor->setPos(40,275);
    } else{
        lDoor=NULL;
    }
}
