/* autopilot.h
 * Baylus Tunnicliff
 * Monday, March 5th, 2017
 * This class is intended to be an automatic input generator for the testing of the
 *      Space Shooter. The primary function will be mouse and keyboard input to get the player
 *      From one room to the next.
 *
 *
 *
 */

#ifndef AUTOPILOT_H
#define AUTOPILOT_H

//#include <QtTest/QTest>

#include "BTcharacter.h"
#include "BTplayer.h"

#include "enemy.h"
#include "NAenemyupdater.h"
#include "JTmap.h"
#include "JTdoor.h"
#include "JTroom.h"

#include "JAgame.h"

#include <QList>
#include <QKeyEvent>

class Autopilot : QObject {

public:
    Autopilot(Character *parent = NULL, Game *g = NULL, QString sPath = QString(), struct direction* move = NULL);
    Autopilot() : Autopilot(NULL, NULL, QString(), NULL) {}
    ~Autopilot();

    void autopilotUpdate(); //Called at some interval of tickrate.
    void newRoom();
    void playerSwitchRooms();

    /* Tells the autopilot to switch from current
     *  target.
     * Used to switch at a more regular interval.
     * Can switch from an outside class, or be called internally.
     *
     */
    void switchTarget();
private:
    //Private Functions.
    /*  NOTE: Reconsider the purpose/value that these functions provide.
     *  These functions were made at a time that i wasnt thinking clearly,
     *  so their purpose should be critically determined.
     *
     *  Do so when going back and providing documentation for each function.
     */
    void moveToCenter();
    void moveToDoor();
    void shootEnemy();
    void pathUpdate();
    void adjustPlayerMovement();

    QChar nextRoom();
    QString successPath;

    QChar c;
    QLineF mLine = QLineF();
    QList<Enemy*> mEnemies;
    Map* mMap = NULL;
    Walls* mWalls = NULL;
    EnemyUpdater* mEnemyUpdate = NULL;
    Character* mParent = NULL;
    Game* mGame = NULL;



    Enemy* mClosestEnemy = NULL;
    QPointF mMoveGoal = QPointF();  //Inevitable goal that player intends to reach.
    QLineF movePath = QLineF();     //Current Path being moved towards.

    bool mSPath = false;        //do we know successPath?
    bool mCentered = true;     //Have we reached the center of the room?
    bool mIsShooting = false;   //Are we currently shooting?
    bool checkEnemies = false;  //Do we need to check enemies after entering new room?

    struct direction* m = NULL;

    //QKeyPressEvent* p = NULL;


    //QMouseEvent* a = NULL;
    //QMouseEvent* m = NULL;
    //QMouseEvent* r = NULL;
};


#endif // AUTOPILOT_H
