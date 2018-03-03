#include "JTroom.h"
#include "JTwalls.h"
#include "JTdoor.h"

Room::Room(QGraphicsScene* scene, bool topDoor, bool rightDoor, bool bottomDoor, bool leftDoor){
//Room::Room(bool topDoor, bool rightDoor, bool bottomDoor, bool leftDoor){
    //add walls
    walls = new Walls();
    bool sides;
    QString pass;
    //add doors
    if(topDoor){
        sides=false;
        pass="Top";
        tDoor = new Door(sides,pass);
        tDoor->setPos(360, 40);
    }
    if(rightDoor){
        sides=true;
        pass="Right";
        rDoor = new Door(sides,pass);
        rDoor->setPos(730,260);
    }
    if(bottomDoor){
        sides=false;
        pass="Bottom";
        bDoor = new Door(sides,pass);
        bDoor->setPos(360, 530);
    }
    if(leftDoor){
        sides=true;
        pass="Left";
        lDoor = new Door(sides,pass);
        lDoor->setPos(40,260);
    }
}
