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
    } else{
        tDoor=NULL;
    }
    if(rightDoor){
        sides=true;
        pass="Right";
        rDoor = new Door(sides,pass);
        //rDoor->setPos(730,260);
        rDoor->setPos(750,260);
    } else{
        rDoor=NULL;
    }
    if(bottomDoor){
        sides=false;
        pass="Bottom";
        bDoor = new Door(sides,pass);
        //bDoor->setPos(360, 530);
        bDoor->setPos(360, 550);
    } else{
        bDoor=NULL;
    }
    if(leftDoor){
        sides=true;
        pass="Left";
        lDoor = new Door(sides,pass);
        lDoor->setPos(40,260);
    } else{
        lDoor=NULL;
    }
}
