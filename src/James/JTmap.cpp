#include <QApplication>
#include <QGraphicsScene>
#include <QList>

#include <QString>
#include <time.h>
#include <stdlib.h>
#include <QDebug>
#include <QTime>

#include "JTmap.h"
#include "JTwalls.h"
#include "JTroom.h"
#include "JTgoal.h"
#include "JAgame.h"
#include "JAaudio.h"
#include "JTbackground.h"

int Map::roomX=51;
int Map::roomY=51;
bool Map::demo;
bool Map::storage=false;

//consider making the floor array static within class
Map::Map(QGraphicsScene* scenePointer, bool demoMode, Game * gameObject)
{
    goal=NULL;
    demo=demoMode;
    enemies = gameObject->getEnemies();
    scene=scenePointer;
    game=gameObject;

    if(demo){                           //this section is only run during demo mode
        successPath="RRR";
        //selectRoom(3,scene);
        selectRoom(3);
        for(int i=0; i<MAX_Y; i++){
            for(int j=0; j<MAX_X; j++){
                floorArray[i][j]=16;
            }
        }

        floorArray[51][51]=3;
        floorArray[52][50]=4;
        floorArray[52][51]=14;
        floorArray[53][51]=10;
        floorArray[54][51]=5;
    } else{                             //this is run during normal gameplay
        successPath="";
                                                                        //add in when map gen is finished
                                                                        //srand(time(NULL));
                                                                        //int goalx=10-rand()%10;      //the 10 in these two lines is the path length
                                                                        //int goaly=10-goalx;
                                                                        //goalx+=51;
                                                                        //goaly+=51;
                                                                        //QString coords = QString::number(roomx)+" "+QString::number(roomy);
                                                                        //room = selectRoom(1, scene);
                                                                        //selectRoom(1,scene);
        selectRoom(1);

        //later, switch this out for real map creation
        //make sure to always add to the solution string
        for(int i=0; i<MAX_Y; i++){
            for(int j=0; j<MAX_X; j++){
                floorArray[i][j]=16;
            }
        }
        floorArray[51][51]=1;
        floorArray[51][50]=4;
        floorArray[51][52]=2;
        floorArray[50][51]=3;
        floorArray[52][51]=5;
    }
}

void Map::selectRoom(int selection)
{
    QList<QPoint> enemyCoords;
    switch(selection){
    case 1:
        //enemyCoords << QPoint(70,70) << QPoint(600,600) << QPoint(400,400);
        room = new Room(true, true, true, true, selection);         //this will be attached to the 4 door case
        break;
    case 2:
        //enemyCoords << QPoint(300, 300) << QPoint(500,500);
        room = new Room(true, false, false, false, selection);         //this will be attached to the top door case
        break;
    case 3:
        //enemyCoords << QPoint(250,600);
        room = new Room(false, true, false, false, selection);         //this will be attached to the right door case
        break;
    case 4:
        //enemyCoords << QPoint(200,400);
        room = new Room(false, false, true, false, selection);         //this will be attached to the bottom door case
        break;
    case 5:
        room = new Room(false, false, false, true, selection);         //this will be attached to the left door case
        break;
    case 6:
        room = new Room(true, true, false, false, selection);         //this will be attached to the top && right door case
        break;
    case 7:
        room = new Room(true, false, true, false, selection);         //this will be attached to the 2 vertical door case
        break;
    case 8:
        room = new Room(true, false, true, false, selection);         //this will be attached to the top && left door case
        break;
    case 9:
        room = new Room(false, true, true, false, selection);         //this will be attached to the right && bottom door case
        break;
    case 10:
        room = new Room(false, true, false, true, selection);         //this will be attached to the 2 horizontal door case
        break;
    case 11:
        room = new Room(false, false, true, true, selection);         //this will be attached to the bottom && left door case
        break;
    case 12:
        room = new Room(false, true, true, true, selection);         //this will be attached to the not-top door case
        break;
    case 13:
        room = new Room(true, false, true, true, selection);         //this will be attached to the not-right door case
        break;
    case 14:
        room = new Room(true, true, false, true, selection);         //this will be attached to the not-bottom door case
        break;
    case 15:
        room = new Room(true, true, true, false, selection);         //this will be attached to the not-left door case
        break;
    case 16:
    default:
        room = new Room(false, false, false, false, selection);        //handles problem case. 0 doors.
        break;

    }

    //add room objects to scene
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
    if(room->bg != NULL)
        scene->addItem(room->bg);
}

void Map::switchRooms(QString name)
{
    if(storage){    //storage here is the switch for Karstin's test
        storage=false;
        game->getCharacter()->KNStressTest();
    }

    //remove objects from room completely
    enemies->removeEnemies();
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
    int roomChoice;

    //this is based on which door the player moves through, to make sure movement is continuous
    if(name=="Top"){
        roomX--;
        roomChoice=floorArray[roomY][roomX];
        selectRoom(roomChoice);
        game->getCharacter()->setPostition(QPointF(400,500));
        if(demo){
            if (roomX==50){
                qDebug()<<"Enemy test.";
                enemies->testCase(scene);
            }
        }
    } else if(name=="Bottom"){
        roomX++;
        //qDebug() << roomx<<" "<<roomy;
        roomChoice=floorArray[roomY][roomX];
        selectRoom(roomChoice);
        game->getCharacter()->setPostition(QPointF(400,75));
        if(demo){
            if(roomY==52){
                qDebug() << "Audio Stress Test";
                AudioInter * test = new AudioInter(1,"");
                test->stressTest();
            } else if(roomY==54){
                Goal * g = new Goal();
                goal = g;
                goal->setPos(360,260);
                scene->addItem(goal);
            } else if (roomX==51){
                qDebug()<<"Enemy test.";
                enemies->testCase(scene);
            }
        }
    } else if(name=="Right"){
        roomY++;
        //qDebug() << roomx<<" "<<roomy;
        roomChoice=floorArray[roomY][roomX];
        selectRoom(roomChoice);
        game->getCharacter()->setPostition(QPointF(100,275));
        if(demo){
            if(roomY==52){
                qDebug() << "Audio Stress Test";
                AudioInter * test = new AudioInter(1,"");
                test->stressTest();
            }else if(roomY==53){
                qDebug() <<"Character stress test";
                storage=true;
                game->getCharacter()->KNStressTest();
            }else if(roomY==54){
                Goal * g = new Goal();
                goal = g;
                goal->setPos(360,260);
                scene->addItem(goal);
            }
        }
    } else if(name=="Left"){
        roomY--;
        //qDebug() << roomx<<" "<<roomy;
        roomChoice=floorArray[roomY][roomX];
        selectRoom(roomChoice);
        game->getCharacter()->setPostition(QPointF(675,275));
        if(demo){
            if(roomY==52){
                qDebug() << "Audio Stress Test";
                AudioInter * test = new AudioInter(1,"");
                test->stressTest();
            } else if(roomY==54){
                Goal * g = new Goal();
                goal = g;
                goal->setPos(360,260);
                scene->addItem(goal);
            }
        }
    } else {
        qDebug() << "Failed to match a room";
        roomChoice=floorArray[roomY][roomX];
        selectRoom(roomChoice);
        game->getCharacter()->setPostition(QPointF(400,300));
    }
    qsrand(QTime::currentTime().msec());
    enemies->removeEnemies();
    for(int i=0; i<5; i++){
        enemies->newEnemy(scene, qrand()%690+40,qrand()%490+40);
    }
}

QString Map::getSuccessPath()
{
    return successPath;
};

QRectF Map::getWallsRect(){
    return room->walls->rect();
}
