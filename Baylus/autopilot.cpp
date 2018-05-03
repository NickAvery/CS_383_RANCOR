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
        //Might end up just making this a thing that is done automatically.
        checkEnemies = false;
    }
    if (!mEnemies.isEmpty()) {
        shootEnemy();
        //qDebug() << mEnemies.count();
    } else {
        //qDebug() << "Enemies Dead";
    }




    //Not sure what this section does now.
}

/* newRoom()
 * Gets called everytime a new room is entered.
 * Ensures that player moves to center of room first.
 */
void Autopilot::newRoom()
{
    assert(mEnemyUpdate);

    checkEnemies = true;
    //if ()
    /*
    m->moveUp = false;
    m->moveDown = false;
    m->moveRight = false;
    m->moveLeft = false;
    */
    //mCentered = false;
    mMoveGoal = QPointF(720 / 2, 520 / 2);
//update Room
    /*
    if (mEnemyUpdate->enemiesDead()) {
        //mEnemies = QList();
    } else {
        //mEnemies = mEnemyUpdate->getEnemies();
        //Doesnt do anything, since enemies are updated about the room after player is updated.
    }
    */
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
    //moveToCenter();

    if(!mSPath) {
        m->moveUp = true;
        m->moveRight = true;
    }

    if (!mEnemies.isEmpty()) {
        shootEnemy();
    }
}


/*
 *  This functions seems really, really bad and worthless.
 *      I actively hate seeing all this trash and it is taking
 *      every ounce of my sanity not to remove it immediately.
 *
 */
/*
void Autopilot::moveToCenter()
{
    assert(mMap);
    assert(mParent);
    assert(m);

    mWallsRect = mMap->getWallsRect();
    assert(mWallsRect);
    mMoveGoal = mWallsRect.center();
    mLine = QLineF( mParent->getPosition(), mMoveGoal );
    qDebug() << "long way vs short way" << QPointF( (mWallsRect.width() / 2) + 40, (mWallsRect.height() / 2) + 40) << mWallsRect.center();
}
*/

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
    //assert(!mEnemies.isEmpty());
    assert(mParent);

    static int offset = 0;
    if ((++offset % 5)) {
        return;
    }


    mEnemies = mEnemyUpdate->getEnemies();
//QList
    static int lCount = 0;  //[Local Counter]
    if (!mEnemies.empty()) {
        Enemy* e = NULL;
        if (mEnemies.count() < 10) {    //If there are a lot of enemies to check.
            ++lCount;
            lCount = lCount % mEnemyUpdate->getEnemies().count();
            //mEnemies = ;
            //e = (mEnemies)[lCount];
            e = mEnemyUpdate->getEnemy(lCount);
        } else {    //else: find and target the closest enemy.
            //QLineF los = QLineF();    //Changed the variable to be a member variable
            los = QLineF();

            los.setP1(mParent->getCenter());
            double d = 1 << 31; // Really large value to hold the min-distance to find closest enemy.
            for (int i = 0; i < mEnemyUpdate->getEnemies().count(); ++i) {
                los.setP2( QPointF(mEnemyUpdate->getEnemy(i)->getXPos() , mEnemyUpdate->getEnemy(i)->getYPos()) );
                if (los.length() < d) { //If mEnemies[i] is closer than Enemy e;
                    d = los.length();
                    e = mEnemyUpdate->getEnemy(i);
                    qDebug() << "Enemy " << i << " out of " << mEnemyUpdate->getEnemies().count() <<" being used.";
                }
            }
            //Closest Enemy Found
        }

        if(!mIsShooting) {
            mIsShooting = true;
            mParent->toggleShooting();
        }
        if (e != NULL) {
           mParent->setMousePoint( QPointF( e->getXPos(), e->getYPos() ) );
        } else {
            e = mEnemyUpdate->getEnemy(0);
            if (e == NULL) return;
            mParent->setMousePoint( QPointF( e->getXPos(), e->getYPos() ) );
        }
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

    mMovePath.setPoints( mParent->getCenter() , mMoveGoal );
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
    if (mMovePath.length() > 15) {
        qreal qAngle = mMovePath.angle();
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
        assert( dir != -1 );
        if (lastDir != dir) {
            lastDir = dir;
            switch(dir) {
                case 0:
                    m->moveRight = true;

                    m->moveUp = false;
                    m->moveLeft = false;
                    m->moveDown = false;
                    break;
                case 1:
                    m->moveRight = true;
                    m->moveUp = true;

                    m->moveLeft = false;
                    m->moveDown = false;
                    break;
                case 2:
                    m->moveRight = false;
                    m->moveUp = true;
                    m->moveLeft = false;
                    m->moveDown = false;
                    break;
                case 3:
                    m->moveRight=   false;
                    m->moveUp   =   true;
                    m->moveLeft =   true;
                    m->moveDown =   false;
                    break;
                case 4:
                    m->moveRight=   false;
                    m->moveUp   =   false;
                    m->moveLeft =   true;
                    m->moveDown =   false;
                    break;
                case 5:
                    m->moveRight=   false;
                    m->moveUp   =   false;
                    m->moveLeft =   true;
                    m->moveDown =   true;
                    break;
                case 6:
                    m->moveRight=   false;
                    m->moveUp   =   false;
                    m->moveLeft =   false;
                    m->moveDown =   true;
                    break;
                case 7:
                    m->moveRight=   true;
                    m->moveUp   =   false;
                    m->moveLeft =   false;
                    m->moveDown =   true;
                    break;
            }
        }
    }
}
