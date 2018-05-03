#include <QApplication>
#include <QGraphicsScene>
#include <QList>

#include <QString>
#include <time.h>
#include <stdlib.h>
#include <QDebug>
#include <QTime>
#include <QLabel>
#include <QGraphicsPixmapItem>

#include "JTmap.h"
#include "JTWalls.h"
#include "JTroom.h"
#include "JTgoal.h"
#include "JAgame.h"
#include "JAaudio.h"
#include "JTBackground.h"
#include "JTgenerator.h"

int Map::sRoomX=51;
int Map::sRoomY=51;
int Map::sGoalX;
int Map::sGoalY;
bool Map::sDemo;
bool Map::sKarstinStressStorage=false;
bool Map::sBaylusStressStorage=false;

//consider making the floor array static within class
Map::Map(QGraphicsScene* scenePointer, bool demoMode, Game * gameObject)
{
    mGoal=NULL;
    sDemo=demoMode;
    mEnemies = gameObject->getEnemies();
    mScene=scenePointer;
    mGame=gameObject;

    //this section is only run during demo mode
    if(sDemo)
    {
        sGoalX = 55;
        sGoalY = 51;
        mSuccessPath="RRR";
        selectRoom(3);
        for(int i=0; i<SMAX_Y; i++)
        {
            for(int j=0; j<SMAX_X; j++)
            {
                mFloorArray[i][j]=16;
            }
        }

        mFloorArray[51][51]=3;
        mFloorArray[52][50]=4;
        mFloorArray[52][51]=14;
        mFloorArray[53][51]=10;
        mFloorArray[54][51]=10;
        mFloorArray[55][51]=5;
    }
    else
    {                             //this is run during normal gameplay
        Generator* mapGenerator = new Generator;
        mapGenerator->generate();
        mSuccessPath=mapGenerator->getPath();
        mapGenerator->getGoal(sGoalX, sGoalY);
        qDebug() << mSuccessPath;
        for(int i=0; i<SMAX_Y; i++)
        {
            for(int j=0; j<SMAX_X; j++)
            {
                mFloorArray[i][j]= (mapGenerator->mValues)[i][j];
            }
        }
        qDebug()<<"Map array"<< mFloorArray[51][51];
        selectRoom(mFloorArray[51][51]);
    }
}

void Map::selectRoom(int selection)
{
    QList<QPoint> enemyCoords;
    switch(selection)
    {
        case 1:
            mRoom = new Room(true, true, true, true, selection);         //this will be attached to the 4 door case
            break;
        case 2:
            mRoom = new Room(true, false, false, false, selection);         //this will be attached to the top door case
            break;
        case 3:
            mRoom = new Room(false, true, false, false, selection);         //this will be attached to the right door case
            break;
        case 4:
            mRoom = new Room(false, false, true, false, selection);         //this will be attached to the bottom door case
            break;
        case 5:
            mRoom = new Room(false, false, false, true, selection);         //this will be attached to the left door case
            break;
        case 6:
            mRoom = new Room(true, true, false, false, selection);         //this will be attached to the top && right door case
            break;
        case 7:
            mRoom = new Room(true, false, true, false, selection);         //this will be attached to the 2 vertical door case
            break;
        case 8:
            mRoom = new Room(true, false, false, true, selection);         //this will be attached to the top && left door case
            break;
        case 9:
            mRoom = new Room(false, true, true, false, selection);         //this will be attached to the right && bottom door case
            break;
        case 10:
            mRoom = new Room(false, true, false, true, selection);         //this will be attached to the 2 horizontal door case
            break;
        case 11:
            mRoom = new Room(false, false, true, true, selection);         //this will be attached to the bottom && left door case
            break;
        case 12:
            mRoom = new Room(false, true, true, true, selection);         //this will be attached to the not-top door case
            break;
        case 13:
            mRoom = new Room(true, false, true, true, selection);         //this will be attached to the not-right door case
            break;
        case 14:
            mRoom = new Room(true, true, false, true, selection);         //this will be attached to the not-bottom door case
            break;
        case 15:
            mRoom = new Room(true, true, true, false, selection);         //this will be attached to the not-left door case
            break;
        case 16:
        default:
            mRoom = new Room(false, false, false, false, selection);        //handles problem case. 0 doors.
            break;
    }

    //add room objects to scene
    if(mRoom->mWalls != NULL)
    {
        mScene->addItem(mRoom->mWalls);
    }
    if(mRoom->mLeftDoorObject != NULL)
    {
        mScene->addItem(mRoom->mLeftDoorObject);
    }
    if(mRoom->mRightDoorObject != NULL)
    {
        mScene->addItem(mRoom->mRightDoorObject);
    }
    if(mRoom->mTopDoorObject != NULL)
    {
        mScene->addItem(mRoom->mTopDoorObject);
    }
    if(mRoom->mBottomDoorObject != NULL)
    {
        mScene->addItem(mRoom->mBottomDoorObject);
    }
    if(mRoom->mBackgroundObject != NULL)
    {
        mScene->addItem(mRoom->mBackgroundObject);
    }
}

void Map::switchRooms(QString name)
{
    qDebug() <<"Room X: "<<sRoomX<<"\tRoom Y: "<<sRoomY;
    qDebug() <<"Goal X: "<<sGoalX<<"\tGoal Y: "<<sGoalY;
    if((mEnemies->enemiesDead()))
    {
        if(sKarstinStressStorage)
        {
            sKarstinStressStorage=false;
            mGame->getCharacter()->KNStressTest();
        }
        if(sBaylusStressStorage)
        {
            sBaylusStressStorage=false;
            mGame->getCharacter()->BTStressTest();
        }

        //remove objects from room completely
        mEnemies->removeEnemies();
        delete mRoom->mWalls;
        mRoom->mWalls=NULL;
        delete mRoom->mRightDoorObject;
        mRoom->mRightDoorObject=NULL;
        delete mRoom->mLeftDoorObject;
        mRoom->mLeftDoorObject=NULL;
        delete mRoom->mTopDoorObject;
        mRoom->mTopDoorObject=NULL;
        delete mRoom->mBottomDoorObject;
        mRoom->mBottomDoorObject=NULL;
        delete mRoom;
        mRoom=NULL;
        if(mGoal!=NULL)
        {
            delete mGoal;
        }
        mGoal=NULL;
        int roomChoice;

        //this is based on which door the player moves through, to make sure movement is continuous
        if(name=="Top")
        {
            sRoomX--;
            roomChoice=mFloorArray[sRoomY][sRoomX];
            selectRoom(roomChoice);
            mGame->getCharacter()->setPostition(QPointF(400,500));
            if(sDemo)
            {
                if (sRoomX==50)
                {
                    qDebug()<<"Enemy test.";
                    mEnemies->testCase(mScene);
                }
            }
        }
        else if(name=="Bottom")
        {
            sRoomX++;
            roomChoice=mFloorArray[sRoomY][sRoomX];
            selectRoom(roomChoice);
            mGame->getCharacter()->setPostition(QPointF(400,75));
            if(sDemo)
            {
                if(sRoomY==52)
                {
                    qDebug() << "Audio Stress Test";
                    AudioInter * test = new AudioInter(1,"");
                    test->stressTest();
                }
                else if(sRoomY==54)
                {
                    //QPixmap pic = QPixmap(":/images/Stairs.png");
                    mGoal = new Goal();
                }
                else if (sRoomX==51)
                {
                    qDebug()<<"Enemy test.";
                    mEnemies->testCase(mScene);
                }
            }
        }
        else if(name=="Right")
        {
            sRoomY++;
            roomChoice=mFloorArray[sRoomY][sRoomX];
            selectRoom(roomChoice);
            mGame->getCharacter()->setPostition(QPointF(100,275));
            if(sDemo)
            {
                if(sRoomY==52)
                {
                    qDebug() << "Audio Stress Test";
                    AudioInter * test = new AudioInter(1,"");
                    test->stressTest();
                }
                else if(sRoomY==53)
                {
                    qDebug() <<"Character stress test";
                    sKarstinStressStorage=true;
                    mGame->getCharacter()->KNStressTest();
                }
                else if(sRoomY==54)
                {
                    qDebug() << "Weapons stress test";
                    sBaylusStressStorage=true;
                    mGame->getCharacter()->BTStressTest();
                }
            }
        }
        else if(name=="Left")
        {
            sRoomY--;
            roomChoice=mFloorArray[sRoomY][sRoomX];
            selectRoom(roomChoice);
            mGame->getCharacter()->setPostition(QPointF(675,275));
            if(sDemo)
            {
                if(sRoomY==52)
                {
                    qDebug() << "Audio Stress Test";
                    AudioInter * test = new AudioInter(1,"");
                    test->stressTest();
                }
            }
        }
        else
        {
            qDebug() << "Failed to match a room";
            roomChoice=mFloorArray[sRoomY][sRoomX];
            selectRoom(roomChoice);
            mGame->getCharacter()->setPostition(QPointF(400,300));
        }
        qsrand(QTime::currentTime().msec());
        int seed1 =qrand()%10+1;
        int seed2 =qrand()%2+1;
        int amountEnemies =0;
        if(seed1<=1)
        {
            amountEnemies=0;
        }
        else if(seed1>1 && seed1<=8)
        {
            amountEnemies=seed1*seed2;
        }
        else if(seed1>8 && seed2==2)
        {
            amountEnemies=20;
        }
        else
        {
            amountEnemies=10;
        }
        mEnemies->removeEnemies();
        qDebug() << "sRoomX == sGoalY:" << sRoomX <<"=="<<sGoalY;
        qDebug() << "sRoomY == sGoalX:" << sRoomY <<"=="<<sGoalX;
        if(sRoomX==sGoalY && sRoomY==sGoalX)
        {
             qDebug() << "Tah dah!";
             Goal * g = new Goal();
             mGoal = g;
             g->setZValue(4);
             g->setPos((qreal)360,(qreal)260);
             mScene->addItem(g);
             //mGoal->show();
         }
         if(!sDemo){
            for(int i=0; i<amountEnemies; i++)
            {
                mEnemies->newEnemy(mScene, qrand()%690+40,qrand()%490+40);
            }
         }
    }
}

QString Map::getSuccessPath()
{
    return mSuccessPath;
}

QRectF Map::getWallsRect()
{
    return mRoom->mWalls->rect();
}

Map* Map::getMap(){
    return this;
}
