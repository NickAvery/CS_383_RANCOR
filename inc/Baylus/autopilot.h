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

    void autopilotUpdate();
    void newRoom();
    void playerSwitchRooms();
private:
    void moveToCenter();
    void moveToDoor();
    void shootEnemy();
    void pathUpdate();
    void adjustPlayerMovement();


    QChar nextRoom();
    QString successPath;

    QChar c;
    QLineF mLine = QLineF();
    Map* mMap = NULL;
    Walls* mWalls = NULL;
    EnemyUpdater* mEnemyUpdate = NULL;
    Character* mParent = NULL;
    Game* mGame = NULL;
    QList<Enemy*> mEnemies;
    //Enemy* mCloseEnemy = NULL;   //Closest Enemy since last check.
    //Cannot do the pointer to the Enemy, if the enemy dies,
    //Then theres the possibility that autopilot uses the pointer, which
    //will cause seg fault.
    double mLosDistance = 0.0;   //[Line of Sight - Distance]Distance from the closest enemy.
    QLineF los = QLineF();


    QPointF mMoveGoal = QPointF();
    QLineF mMovePath = QLineF();    //[M_ember Move Pathway ]Line that shows the path that is being traveled by the autopilot.

    bool mSPath = false;        //do we know successPath?
    bool mCentered = true;     //Have we reached the center of the room?
    bool mIsShooting = false;   //Are we currently shooting?
    bool checkEnemies = false; //Do Enemies need to be checked?

    struct direction* m = NULL;

    //QKeyPressEvent* p = NULL;


    //QMouseEvent* a = NULL;
    //QMouseEvent* m = NULL;
    //QMouseEvent* r = NULL;
};


#endif // AUTOPILOT_H
