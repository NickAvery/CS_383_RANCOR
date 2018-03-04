#include <QApplication>
#include <QGraphicsScene>
#include <QList>

#include <QString>
#include <time.h>
#include <stdlib.h>
#include <QDebug>

#include "JTmap.h"
#include "JTwalls.h"
#include "JAgame.h"
#include "JTroom.h"

int Map::roomx=51;
int Map::roomy=51;

//consider making the floor array static within class

Map::Map(QGraphicsScene* scene, bool Demo){
    if(Demo){
        qDebug() << "Call debug functions here!";
    } else{
    //add in when map gen is finished
    //srand(time(NULL));
    //int goalx=10-rand()%10;      //the 10 in these two lines is the path length
    //int goaly=10-goalx;
    //goalx+=51;
    //goaly+=51;
    //QString coords = QString::number(roomx)+" "+QString::number(roomy);


    //qDebug() << coords;
   //room = selectRoom(1, scene);
    selectRoom(1,scene);

    //later, switch this out for real map creation
    //make sure to always add to the solution string
    for(int i=0; i<maxy; i++){
        for(int j=0; j<maxx; j++){
            floorarray[i][j]=room;
        }
    }

    scene->addItem(floorarray[roomy][roomx]->walls);
    scene->addItem(floorarray[roomy][roomx]->lDoor);
    scene->addItem(floorarray[roomy][roomx]->rDoor);
    scene->addItem(floorarray[roomy][roomx]->tDoor);
    scene->addItem(floorarray[roomy][roomx]->bDoor);
    }
}

void Map::selectRoom(int selection, QGraphicsScene* scene){
    //Room * room1;
    switch(selection){
    case 1:
        room = new Room(scene, true, true, true, true);         //this will be attached to the 4 door case
        break;
    case 2:
        room = new Room(scene, true, false, false, false);         //this will be attached to the top door case
        break;
    case 3:
        room = new Room(scene, false, true, false, false);         //this will be attached to the right door case
        break;
    case 4:
        room = new Room(scene, false, false, true, false);         //this will be attached to the bottom door case
        break;
    case 5:
        room = new Room(scene, false, false, false, true);         //this will be attached to the left door case
        break;
    case 6:
        room = new Room(scene, true, true, false, false);         //this will be attached to the top && right door case
        break;
    case 7:
        room = new Room(scene, true, false, true, false);         //this will be attached to the 2 vertical door case
        break;
    case 8:
        room = new Room(scene, true, false, true, false);         //this will be attached to the top && left door case
        break;
    case 9:
        room = new Room(scene, false, true, true, false);         //this will be attached to the right && bottom door case
        break;
    case 10:
        room = new Room(scene, false, true, false, true);         //this will be attached to the 2 horizontal door case
        break;
    case 11:
        room = new Room(scene, false, false, true, true);         //this will be attached to the bottom && left door case
        break;
    case 12:
        room = new Room(scene, false, true, true, true);         //this will be attached to the not-top door case
        break;
    case 13:
        room = new Room(scene, true, false, true, true);         //this will be attached to the not-right door case
        break;
    case 14:
        room = new Room(scene, true, true, false, true);         //this will be attached to the not-bottom door case
        break;
    case 15:
        room = new Room(scene, true, true, true, false);         //this will be attached to the not-left door case
        break;
    case 16:
    default:
        room = new Room(scene, false, false, false, false);        //handles problem case. 0 doors.
        break;

    }
    //return room1;
}

void Map::switchRooms(QString name){
    //scene->removeItem(floorarray[roomy][roomx]->walls);
    scene->removeItem(floorarray[roomy][roomx]->lDoor);
    //scene->removeItem(floorarray[roomy][roomx]->rDoor);
    //scene->removeItem(floorarray[roomy][roomx]->tDoor);
    //scene->removeItem(floorarray[roomy][roomx]->bDoor);

    if(name=="Top"){
        qDebug() << "Move up.";
        //roomx--;
    } else if(name=="Bottom"){
        qDebug() << "Move down.";
        //room++;
    } else if(name=="Right"){
        qDebug() << "Move right.";
        //roomy++;
    } else if(name=="Left"){
        //roomy--;
        qDebug() << "Move left.";
    } else {
        qDebug() << "Failed to match a room";
    }
    //scene->addItem(floorarray[roomy][roomx]->walls);
    //scene->addItem(floorarray[roomy][roomx]->lDoor);
    //scene->addItem(floorarray[roomy][roomx]->rDoor);
    //scene->addItem(floorarray[roomy][roomx]->tDoor);
    //scene->addItem(floorarray[roomy][roomx]->bDoor);
}
