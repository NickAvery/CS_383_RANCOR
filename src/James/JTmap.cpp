#include <QApplication>
#include <QGraphicsScene>
#include <QList>

#include <QString>
#include <time.h>
#include <stdlib.h>
#include <QDebug>

#include "JTmap.h"
#include "JTwalls.h"
#include "JTroom.h"
#include "JTgoal.h"
#include "JAgame.h"
#include "JAaudio.h"

int Map::roomx=51;
int Map::roomy=51;
bool Map::Demo;
bool Map::storage=false;

//consider making the floor array static within class

Map::Map(QGraphicsScene* a, bool D, Game * b){
    goal=NULL;
    Demo=D;
    enemies = b->getEnemies();
    scene=a;
    game=b;
    if(Demo){
        successPath="RRR";
        selectRoom(3,scene);
        for(int i=0; i<maxy; i++){
            for(int j=0; j<maxx; j++){
                floorarray[i][j]=16;
            }
        }

        floorarray[51][51]=3;
        floorarray[52][50]=4;
        floorarray[52][51]=14;
        //floorarray[53][51]=10;
        //floorarray[54][51]=10;
        //floorarray[55][51]=10;
        floorarray[53][51]=10;
        floorarray[54][51]=5;

        qDebug() << "Call debug functions here!";
    } else{
        successPath="";
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
        /*
        scene->addItem(room->walls);
        scene->addItem(room->lDoor);
        scene->addItem(room->rDoor);
        scene->addItem(room->tDoor);
        scene->addItem(room->bDoor);
        */
        //later, switch this out for real map creation
        //make sure to always add to the solution string
        for(int i=0; i<maxy; i++){
            for(int j=0; j<maxx; j++){
                floorarray[i][j]=16;
            }
        }
        floorarray[51][51]=1;
        floorarray[51][50]=4;
        floorarray[51][52]=2;
        floorarray[50][51]=3;
        floorarray[52][51]=5;
    }
}

void Map::selectRoom(int selection, QGraphicsScene* a){
    //Room * room1;
    QList<QPoint> enemyCoords;

    switch(selection){
    case 1:
        enemyCoords << QPoint(70,70) << QPoint(600,600) << QPoint(400,400);
        room = new Room(scene, true, true, true, true);         //this will be attached to the 4 door case
        break;
    case 2:
        enemyCoords << QPoint(300, 300) << QPoint(500,500);
        room = new Room(scene, true, false, false, false);         //this will be attached to the top door case
        break;
    case 3:
        enemyCoords << QPoint(250,600);
        room = new Room(scene, false, true, false, false);         //this will be attached to the right door case
        break;
    case 4:
        enemyCoords << QPoint(200,400);
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
    if(room->walls != NULL)
        scene->addItem(room->walls);
    if(room->lDoor != NULL)
        scene->addItem(room->lDoor);
    if(room->rDoor != NULL)
        scene->addItem(room->rDoor);
    if(room->tDoor != NULL)
        scene->addItem(room->tDoor);
    if(room->bDoor != NULL)
        scene->addItem(room->bDoor);
}

void Map::switchRooms(QString name){
    if(storage){
        storage=false;
        game->getCharacter()->KNStressTest();
    }
    //scene->removeItem(floorarray[roomy][roomx]->walls);
    delete room->walls;
    room->walls=NULL;
    delete room->rDoor;
    room->rDoor=NULL;
    delete room->lDoor;
    room->lDoor=NULL;
    delete room->tDoor;
    room->tDoor=NULL;
    delete room->bDoor;
    room->bDoor=NULL;
    delete room;
    room=NULL;
    if(goal!=NULL)
        delete goal;
    goal=NULL;
    //selectRoom(1, scene);
    int roomchoice;

    if(name=="Top"){
        roomx--;
        qDebug() << "TESTING AGAINST: " << roomx;
        qDebug() << roomx<<" "<<roomy;
        roomchoice=floorarray[roomy][roomx];
        selectRoom(roomchoice, scene);
        game->getCharacter()->setPostition(QPointF(400,500));
        if(Demo){
            if (roomx==50){
                qDebug()<<"Enemy test.";
                enemies->testCase(scene);
            }
        }
    } else if(name=="Bottom"){
        roomx++;
        qDebug() << roomx<<" "<<roomy;
        roomchoice=floorarray[roomy][roomx];
        selectRoom(roomchoice, scene);
        game->getCharacter()->setPostition(QPointF(400,175));
        if(Demo){
            if(roomy==52){
                qDebug() << "Audio Stress Test";
                AudioInter * test = new AudioInter(1,"");
                test->StressTest();
            } else if(roomy==54){
                Goal * g = new Goal();
                goal = g;
                goal->setPos(360,260);
                scene->addItem(goal);
            } else if (roomx==51){
                qDebug()<<"Enemy test.";
                enemies->testCase(scene);
            }
        }
    } else if(name=="Right"){
        roomy++;
        qDebug() << roomx<<" "<<roomy;
        roomchoice=floorarray[roomy][roomx];
        selectRoom(roomchoice, scene);
        game->getCharacter()->setPostition(QPointF(175,275));
        if(Demo){
            if(roomy==52){
                qDebug() << "Audio Stress Test";
                AudioInter * test = new AudioInter(1,"");
                test->StressTest();
            }else if(roomy==53){
                qDebug() <<"Character stress test";
                storage=true;
                game->getCharacter()->KNStressTest();
            }else if(roomy==54){
                Goal * g = new Goal();
                goal = g;
                goal->setPos(360,260);
                scene->addItem(goal);
            }
        }
    } else if(name=="Left"){
        roomy--;
        qDebug() << roomx<<" "<<roomy;
        roomchoice=floorarray[roomy][roomx];
        selectRoom(roomchoice, scene);
        game->getCharacter()->setPostition(QPointF(675,275));
        if(Demo){
            if(roomy==52){
                qDebug() << "Audio Stress Test";
                AudioInter * test = new AudioInter(1,"");
                test->StressTest();
            } else if(roomy==54){
                Goal * g = new Goal();
                goal = g;
                goal->setPos(360,260);
                scene->addItem(goal);
            }
        }
    } else {
        qDebug() << "Failed to match a room";
        roomchoice=floorarray[roomy][roomx];
        selectRoom(roomchoice, scene);
        game->getCharacter()->setPostition(QPointF(400,300));
    }
    //selectRoom(roomchoice, scene);
}

QString Map::getSuccessPath(){
    return successPath;
};
