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
    assert(mEnemyUpdate);   //Ensure that the getter variables are assigned.
    assert(mParent);

    //static QChar c;
    //Check Player Position

    if (checkEnemies) { //Checking enemies after entering new room.
        mEnemies = mEnemyUpdate->getEnemies();
    }
    if (!mEnemies.isEmpty()) {
        shootEnemy();
        //qDebug() << mEnemies.count();
    } else {
        //qDebug() << "Enemies Dead";
    }
    //Not sure what this section does now.
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

}

/* newRoom()
 * Gets called everytime a new room is entered.
 * Ensures that player moves to center of room first.
 */
void Autopilot::newRoom()
{
    checkEnemies = true;
    //if ()
    /*
    m->moveUp = false;
    m->moveDown = false;
    m->moveRight = false;
    m->moveLeft = false;
    */
    mCentered = false;
    mMoveGoal = QPointF(720 / 2, 520 / 2);
    //update Room
    if (mEnemyUpdate->enemiesDead()) {
        //mEnemies = QList();
    } else {
        //mEnemies = mEnemyUpdate->getEnemies();
        //Doesnt do anything, since enemies are updated about the room after player is updated.
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
    /*
    if(!mSPath) {
        m->moveUp = true;
        m->moveRight = true;
    }
    */
    if (!mEnemies.isEmpty()) {
        shootEnemy();
    }
}
//Looks obsolete
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
 * Fires at a "random" within the list of enemies provided by the enemy updater class.
 *
 *  How it works:
 *      Uses several functions in the Character class. "toggleShooting()",
 *          "setMousePoint(qPointF)"
 *      These are used to emulate the mouse input that a user provides to shoot.
 *
 * Used to use QMouseEvents, but these were possibly not-functional, it was never
 *  investigated thoroughly in order to determine the issues with the solution method.
 *
 *
 */

void Autopilot::shootEnemy()
{
    static int sCounter = 0;
    if (!mEnemies.empty()) {
        Enemy* e = NULL;
        if (mEnemies.count() > 10) {    //If there are a lot of enemies to check.
            sCounter = ++sCounter % mEnemies.count();
            //mEnemies = ;
            e = (mEnemies)[sCounter];
        } else {    //else: find and target the closest enemy.
            QLineF los = QLineF();
            los.setP1(mParent->getCenter());
            double d = 1 << 32; // Really large value to hold the min-distance to find closest enemy.
            for (int i = 0; i < mEnemies.count(); ++i) {
                los.setP2( QPointF(mEnemies[i]->getXPos() , mEnemies[i]->getYPos()) );
                if (los.length() < d) { //If mEnemies[i] is closer than Enemy e;
                    d = los.length();
                    e = mEnemies[i];
                }
            }
        }

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

/*  pathUpdate()
 *
 * Will update the current direction player is traveling
 * such that they are moving towards the "movePath".
 *
 *  Should be called after updating the movePath point.
 *
 *
 */
void Autopilot::pathUpdate()
{

    movePath.setPoints( mParent->getCenter() , mMoveGoal );
}

/*  adjustPlayerMovement()
 *
 *  Will use the "movePath" to find the best way to
 *      reach the end destination.
 *
 *  Should be called every "autopilotUpdate()"
 *
 *
 */
void Autopilot::adjustPlayerMovement()
{
    static int lastDir = -1;
    int dir = -1;
    //m->moveRight = false;
    //m->moveLeft = false;
    if (movePath.length() > 15) {
        qreal qAngle = movePath.angle();
        if ( (qAngle >= 22.5) && (qAngle < 67.5) ) {
            dir = 1;
        } else if ( (qAngle >= 67.5) && (qAngle < 112.5) ) {
            dir = 2;
        } else if ( (qAngle >= 112.5) && (qAngle < 157.5) ) {
            dir = 3;
        } else if ( (qAngle >= 157.5) && (qAngle < 202.5) ) {
            dir = 4;
        } else if ( (qAngle >= 202.5) && (qAngle < 247.5) ) {
            dir = 5;
        } else if ( (qAngle >= 247.5) && (qAngle < 292.5) ) {
            dir = 6;
        } else if ( (qAngle >= 292.5) && (qAngle < 337.5) ) {
            dir = 7;
        } else {
            dir = 0;
        }

        if (lastDir != dir) {
            lastDir = dir;
            switch(dir) {
                case 0:

                    break;
                case 1:

                    break;
                case 2:

                    break;
                case 3:

                    break;
                case 4:

                    break;
                case 5:

                    break;
                case 6:

                    break;
                case 7:

                    break;
            }
        }
    }
}
