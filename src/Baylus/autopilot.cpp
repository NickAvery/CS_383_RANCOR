/* autopilot.cpp
 * Baylus Tunnicliff
 * Monday, March 5th, 2017
 * This class is intended to be an automatic input generator for the testing of the
 *      Space Shooter. The primary function will be mouse and keyboard input to get the player
 *      From one room to the next.
 *
 *
 *
 */



#include "autopilot.h"
#include "BTcharacter.h"

#include "enemy.h"
#include "NAenemyupdater.h"

#include "JTroom.h"
#include "JTdoor.h"
#include "JTwalls.h"
#include "JTgoal.h"
#include "JTmap.h"

#include <QMouseEvent>

Autopilot::Autopilot(Character *parent, Game* g, QString sPath, struct direction* move)
{
    mGame = g;
    mEnemyUpdate = mGame->getEnemies();
    mMap = mGame->getMap();
    mParent = parent;
    if (sPath.isNull()) {
        mSPath = false;
    } else {
        mSPath = true;
        successPath = sPath;
    }
    m = move;
    m->moveRight = true;
}

Autopilot::~Autopilot()
{

}

/* autopilotUpdate()
 * Sends move commands.
 * Sends Shoot commands.
 *
 */

void Autopilot::autopilotUpdate()
{
    //static QChar c;
    //Check Player Position
    if (!mEnemies.isEmpty()) {
        shootEnemy();
    }
    /*
    if(!mCentered) {
        if (mParent->Contains(mMoveGoal, false)) { //Center Reached
            qDebug()<< "Ive Reached the center";
            mCentered = true;
            if (!successPath.isEmpty()) {
                c = 'R';
                //c = nextRoom();
            } else {    //No path to follow
                if (mMap->room->tDoor == NULL) {
                    c = 'R';
                } else {
                    c = 'U';
                }
            }
            if (c == 'R') {
                m->moveRight = true;
            } else if (c == 'U') {
                m->moveUp = true;
            }
        }
    }
    */
}

/* newRoom()
 * Gets called everytime a new room is entered.
 * Ensures that player moves to center of room first.
 */
void Autopilot::newRoom()
{
    /*
    m->moveUp = false;
    m->moveDown = false;
    m->moveRight = false;
    m->moveLeft = false;
    */
    mCentered = false;
    mMoveGoal = QPointF();
    //update Room
    if (mEnemyUpdate->enemiesDead()) {
        //mEnemies = QList();
    } else {
        mEnemies = mEnemyUpdate->getEnemies();
    }
    //check for goal.
    /*
    if (mMap->goal != NULL) {
        //Goal is in the room.
        mMoveGoal = mMap->goal->pos();
        mLine = QLineF(mParent->getPosition(), mMoveGoal);
        if (mMoveGoal)
    }*/
    //Update move goal.
    //mMoveGoal = QPointF( (mWalls->rect().width() / 2) + 40, (mWalls->rect().height() / 2) + 40);
    moveToCenter();
    if(!mSPath) {
        m->moveUp = true;
        m->moveRight = true;
    }
    if (!mEnemies.isEmpty()) {
        shootEnemy();
    }
}

void Autopilot::playerSwitchRooms()
{
    m->moveUp = false;
    m->moveDown = false;
    m->moveRight = false;
    m->moveLeft = false;

}

/*
 *
 *
 */
void Autopilot::moveToCenter()
{
    mWalls = mMap->room->walls;
    mMoveGoal = mWalls->rect().center();
    mLine = QLineF( mParent->getPosition(), mMoveGoal );
    qDebug() << "long way vs short way" << QPointF( (mWalls->rect().width() / 2) + 40, (mWalls->rect().height() / 2) + 40) << mWalls->rect().center();

    if (c == 'R') {
        //Came from left
        m->moveRight = true;
    } else if (c == 'U') {   //Came in from the bottom.
        m->moveUp = true;
    } else if (c == 'L') {  //came from right
        m->moveLeft = true;
    } else if (c == 'D') {  //came from top
        m->moveDown = true;
    }

    /*
    if (mLine.angle() == 0) {   //Came From left door.
        m->moveRight = true;
    } else if (mLine.angle() == 90) {   //Came in from the bottom.
        m->moveUp = true;
    } else if (mLine.angle() == 180) {  //came from right
        m->moveLeft = true;
    } else if (mLine.angle() == 270) {  //came from top
        m->moveDown = true;
    }*/
}

void Autopilot::moveToDoor()
{

}

/* shootEnemy()
 * Fires at enemies closest to the player.
 *
 *
 */

void Autopilot::shootEnemy()
{
    static int i = 0;
    if (!mEnemies.empty()) {
        i = ++i % mEnemies.count();
        //mEnemies = ;
        Enemy* e = (mEnemies)[i];
        if(!mIsShooting) {
            mIsShooting = true;
            mParent->toggleShooting();
        }
        mParent->setMousePoint( QPointF( e->getXPos(), e->getYPos() ) );
        /*
        if (!mIsShooting) {     //Not currently shooting.
            a = new QMouseEvent( QEvent::MouseButtonPress, QPointF(), QPointF(e.getXPos(),e.getYPos()), Qt::LeftButton, Qt::LeftButton,  Qt::NoModifier);
            mIsShooting = true;
        } else {
            if (m != NULL) {    //if there is a previous move event.
                delete m;
                m = NULL;
            } else {            //no previous move event.
                m = new QMouseEvent( QEvent::MouseMove, QPointF(), QPointF(e.getXPos(),e.getYPos()), Qt::NoButton, Qt::NoButton, Qt::NoModifier);
            }
        }*/
    } else if (mIsShooting) {        //Enemies are dead.
        mParent->toggleShooting();
        mParent->setMousePoint( QPointF() );
        mIsShooting = false;
        /*
        if (r != NULL) {
            delete r;
            r = NULL;
        }
        if (a != NULL) {
            delete a;
            a = NULL;
        }
        if (m != NULL) {
            delete m;
            m = NULL;
        }
        r = new QMouseEvent(QEvent::MouseButtonRelease, QPointF(), Qt::LeftButton, Qt::LeftButton, Qt::NoModifier);
        */
    }
}
