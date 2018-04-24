/*  Baylus Tunnicliff
*   Character Class - "BTcharacter.cpp"
*
*   Controls player movement, player shooting, player interactions
*       player interfacing, player graphics.
*
*
*/

#include "ASVictoryScreen.h"

#include "BTcharacter.h"
#include "BTplayer.h"
//#include "BTshot.h"
#include "BTplayerShot.h"

#include "JTwalls.h"
#include "KNSkillManager.h"
#include "JAgame.h"
#include "JAaudio.h"

#include <iostream>
#include <QPoint>
#include <QProcess>
#include <QWidget>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QDebug>
#include <cmath>
//#include <cstring>
#include <QString>
#include <QCursor>  //QCursor:: pos()[ Shooting ],
#include <BTcharacter.h>

/*
//No real reason why to have this intermediate constructor, just assume the value is 0 if not given.
Character::Character(QWidget *parent)
    : QWidget(parent)
{
    //tick = new QTimer(this);
    Character( parent, 0 );
}
*/

/*
 * Character is the main facing class of the character movement, player input,
 * Player projectiles, provides interfaces between enemy and Skillmanager.
 *
 */

class Player;

Character::Character(int characterNumber , bool autopilot, bool successPath, Game *parent, QGraphicsScene *s)
{
    if (autopilot) {
        qDebug() << "Autopilot activated!";
    }
    if (successPath) {
        qDebug() << "and I know the way to victory!";
    }
    mIsAutopilot = autopilot;
    mSuccessPath = successPath;
    //int length = 40;
    Character::myGame = parent;
    //player = new QGraphicsRectItem();
    mySkillManager = new SkillManager( this, characterNumber );
    myMap = myGame->getMap();  //Get map from the game.
    //myWalls = myMap->walls;     //Get Walls from the map.
    //x = 400;
    //y = 300;
    scene = s;
    myMove = new struct direction;
    myMove->moveUp =    false;
    myMove->moveDown =  false;
    myMove->moveRight = false;
    myMove->moveLeft =  false;

    //Make Player and add them to scene.
    myPlayer = new Player(this, myMove, myGame);

    mEnemyUpdater = myGame->getEnemies();

    s->addItem(myPlayer);
    //myPlayer->setFlag(QGraphicsItem::ItemIsFocusable);

    //Set up focus events for grabbing input
    setFocusPolicy(Qt::StrongFocus);
    //myPlayer->QGraphicsRectItem::setFocus();


    //To fix the keyboard and mouse issues.
    //Consider trying "setSelected(bool selected)"
    grabKeyboard();
    grabMouse();

    setMouseTracking(true);

    //https://stackoverflow.com/questions/23533691/qt-collision-detection-with-custom-qgraphicsitem-classes

    //Set up Audio Objects
    mLaser = new AudioInter(1, "qrc:/sounds/Sounds/Laser.wav");
    mLaser->setVolume(5);

    sDamage = new AudioInter(1, "qrc:/sounds/Sounds/damage1.wav");
    sDamage->setVolume(15);

    //Load the shot image into cache
    //QPixmap::load(":/images/Graphics/Lasers/laserGreen04.png");

    mMousePoint = QPointF(0,0);

    //Fire initial shot to load graphics
    //Shot();

    if (autopilot) {
        if (successPath) {
            mAP = new Autopilot(this, myGame, myMap->getSuccessPath(), myMove);
        } else {
            mAP = new Autopilot(this, myGame, QString(), myMove);
        }
    }

    //Set up weapon stats.
/*
struct DataBank {
  int size[2];
  int totalHealth;
  int currentHealth;
  int speed;
  int damage;
  int fireRate;
  int shotSpeed;
};

struct weaponStats {
    int* shotSpeed = NULL;          //bullet travel speed
    int* shotSize = NULL;           //
    int* shotDamage = NULL;         //damage on impact
    int* shotCooldown = NULL;       // Related to frequency that player is allowed to fire.

    double* multiShotOffset = NULL; //the horizontal offset of the bullets from one another. (i.e. not angle of them)
    int* multiShotNumber = NULL;    //Number of shots per weapon-fire.
    double* multiShotAngle = NULL;  //The angle between each of the several bullets.

    bool* doesBulletSplit = NULL;   //bullet splitting upon impact.

};
*/

}

Character::~Character()
{
    //delete(player);
    //player = NULL;
    emit(shotKill());
    delete(mySkillManager);
    mySkillManager = NULL;
    delete(myPlayer);
    myPlayer = NULL;
}

/*
Obsolete. Not used anymore.
void Character::setSpeed(double newSpeed)
{
    if (speed >= 0) speed = newSpeed;
}

*/

QPointF Character::getPosition()
{
    if( myPlayer ) {
        //return myPlayer->pixmap().rect().center();
        //return QPointF( myPlayer->pixmap().rect().x() , myPlayer->pixmap().rect().y() );
        return myPlayer->pos();
    } else {
        qDebug() << "Real bad errors.";
    }
    return QPointF();
}

void Character::setPostition(QPointF point)
{
    //emit(shotKill());
    shotKill(); //Clean room of shots.
    myPlayer->put(point);
    if (mAP) {
        mAP->newRoom();
    }
}


/* This function assumes traditional coordinate system plane internally.
 */
int Character::getMoveDirection()
{
    int deltaX = (myMove->moveRight) - (myMove->moveLeft);
    int deltaY = (myMove->moveUp) - (myMove->moveDown);
    //aaaaaaqDebug() << "Deltas " << deltaX << deltaY;
    if (deltaX && deltaY) { //moving in both x and y directions.
        if ( (deltaX == 1) && (deltaY == 1) )
            return 1;
        else if ( (deltaX == -1) && (deltaY == 1) )
            return 3;
        else if ( (deltaX == -1) && (deltaY == -1) )
            return 5;
        else if ( (deltaX == 1) && (deltaY == -1) )
            return 7;
    } else if (deltaX) {    //moving in just X direction.
        if (myMove->moveRight) {
            //If moving right
            return 0;
        } else {
            //Moving left.
            return 4;
        }
    } else if (deltaY) {    //moving in just Y direction.
        if (myMove->moveUp) {
            //Moving up
            return 2;
        } else {
            //Moving down.
            return 6;
        }
    }
    //If not moving.
    //qDebug() << "Player not moving, myMove is" << myMove->moveRight << myMove->moveUp << myMove->moveLeft  << myMove->moveDown;
    return -1;
}

void Character::enemyHit()
{
    ++mTempScore;
}

/*
struct direction {
    int num;    //0 for right, 1 for up-right, 2 for up, 3 for up-left, etc.
    char dirStr[4]; //char represents boolean value. { (Down), (Left), (Up), (Right) }
    bool moveUp;
    bool moveDown;
    bool moveRight;
    bool moveLeft;
};
*/

/*
 * Controls the movement direction struct responsible for
 * providing info to the player on where to move.
 *
 * In order to get the move direction part of the struct correct,
 * I am using a system that assigns a number to each key that is pressed.
 *      { Right = 1, Up = 3, Left = 5, Down = 7 }
 * The number in the move struct is initialized to -1, meaning that after adding the value
 * of the Right key being pressed to the default number, the result is 0, there are 0-7 directions
 * possible
 * !IMPORTANT!
 *
 *
 */
void Character::keyPressEvent(QKeyEvent *event)
{
    assert(myMove);
    //bool isNotMoving = (myMove->dirNum == -1);

    //if (isNotMoving) ++myMove->dirNum;

   // bool newPress = false;  //Checks whether the event is a new key being pressed or not.
    switch ( event->key() ) {
        case Qt::Key_Right:
        case Qt::Key_D:
            {
                if (myMove->moveRight == false) {

                    myMove->moveRight = true;
                   //Adjust move direction
                    myMove->dirNum = getMoveDirection();
                    //newPress = true;
                }
            }
            break;
        case Qt::Key_Up:
        case Qt::Key_W:
            {
                if (myMove->moveUp == false) {
                    myMove->moveUp = true;
                    //Adjust move direction
                    myMove->dirNum = getMoveDirection();
                    //newPress = true;
                }
            }
            break;
        case Qt::Key_Left:
        case Qt::Key_A:
            {
       // qDebug() << "Left being pressed, moveLeft is" << myMove->moveLeft;
                if (myMove->moveLeft == false) {
                    myMove->moveLeft = true;
                    //Adjust move direction
                    myMove->dirNum = getMoveDirection();
                    //newPress = true;
                }
            }
            break;
        case Qt::Key_Down:
        case Qt::Key_S:
            {
                if (myMove->moveDown == false) {
                    myMove->moveDown = true;
                    //Adjust move direction
                    myMove->dirNum = getMoveDirection();
                   // newPress = true;
                }
            }
            break;
        case Qt::Key_P:
            static bool state = false;
            state = !state;
            if (myGame != NULL) myGame->setPause(state);
            //return;
            //^^Critical that this is set. If no movement key was entered,
                //and the math after the switch-case occurs, then the myMove->num will be all messed up.
            break;
        default:
           // --myMove->dirNum;
            event->ignore();
            break;
    }

    //event->ignore();
}

void Character::keyReleaseEvent(QKeyEvent *event)
{
    assert(myMove);
    //are Up and Down being pressed?
    //bool UpDown = (myMove->moveUp && myMove->moveDown);
    //are Right and Left being pressed?
    //bool RightLeft = (myMove->moveRight && myMove->moveLeft);

    switch ( event->key() ) {
        case Qt::Key_Up:
        case Qt::Key_W:
            myMove->moveUp = false;
            //Adjust move direction
            myMove->dirNum = getMoveDirection();
            break;
        case Qt::Key_Down:
        case Qt::Key_S:
             myMove->moveDown = false;
             //Adjust move direction
             myMove->dirNum = getMoveDirection();
            break;
        case Qt::Key_Right:
        case Qt::Key_D:
            myMove->moveRight = false;
            //Adjust move direction
            myMove->dirNum = getMoveDirection();
            break;
        case Qt::Key_Left:
        case Qt::Key_A:

            myMove->moveLeft = false;
            //Adjust move direction
            myMove->dirNum = getMoveDirection();
            break;
        default:
            event->ignore();
            break;
    }

}




void Character::mousePressEvent(QMouseEvent *event)
{
    switch(event->button()) {
        case Qt::LeftButton:
            {
                //Fire a shot
                mIsShooting = true;
                //QRectF r = myPlayer->rect();
                //QPointF c = mapToGlobal(r.center().toPoint());
                //QPointF t( c.x(), c.y() + 1 );
                /*
                if ( 0 ) {                              //Temporary Until shooting fix is ensured.
                    QPointF p = myPlayer->pos();
                    //qDebug() << "Firing a shot" << p << " to " << event->windowPos();
                    Shot<Player*>* s = new Shot<Player*>( myPlayer, 3, QLineF(p , event->windowPos()) );
                    connect(this, SIGNAL(shotTick()), s, SLOT(shotUpdate()));
                    connect(this, SIGNAL(shotKill()), s, SLOT(kill()));

                    scene->addItem(s);
                    mLaser->playSound();
                }
                */

            }
            break;
        default:
            event->ignore();
            break;
    }
}

void Character::mouseReleaseEvent(QMouseEvent *event)
{
    switch(event->button()) {
        case Qt::LeftButton:
            {
                //Not firing.
                mIsShooting = false;

            }
            break;
        default:
            event->ignore();
            break;
    }
}

void Character::mouseMoveEvent(QMouseEvent *event)
{
    //BT::windowPos();
    mMoveEvent = event;
    mMousePoint = event->windowPos();
}

//Obsolete

/* *
 *
 * Only update the player's rotation every .1 seconds. This
 *  makes it easier to stop while facing a diagonal.
 */
void Character::update()
{
    static int tickCounter = 0;
    ++tickCounter;
    //qDebug() << "myMove.dirNum is " << myMove->dirNum;
    if (mAP) {
        mAP->autopilotUpdate();
    }
    myPlayer->move();
    if (isInvulnernable) {
        isInvulnernable = invincibilityFrameCount(0);
    }
    if (mShotCooldown) {
        //Shot is on Cooldown.
        mShotCooldown = shotCooldownCount(0);
    }
    //emit(SIGNAL(shotTick()));
    if (mIsShooting) {
        //Trying to shoot a bullet.
        QLineF fireLine = QLineF( myPlayer->pos(), mMousePoint  );
        myPlayer->setRotation( 90 - fireLine.angle() );
        (void) shoot(fireLine); //Do not need return from this yet. Consider removing.
    } else {
        //Player not trying to shoot.
        //Player faces move direction.
        if (myMove->dirNum != -1 && ( (tickCounter % 10) == 0 )) {
            //If player isn't stopped and it is the 10th tick.

            double a = 0;
            a = 45 * myMove->dirNum;    //Gives proper angle since we are breaking it up into 8 parts.
            myPlayer->setRotation( 90 - a );
        }
    }

    shotTick();
    //Karstin's stress Test
    if (mKNStressTest) {
        mySkillManager->addExperience(10);
    }
}

void Character::doDamage(double damage)
{
    if (isInvulnernable) return;

    qDebug() << "Before Damage: " << mStats->currentHealth;
    if ((mStats->currentHealth -= damage) <= 0 ) {
        //Player Died

        //Signal Player Death


        //Temporary Solution
        exit( EXIT_FAILURE );
    }
    sDamage->playSound();
    //qDebug() << "After Damgage: " << mStats->currentHealth;

    //Make Player Invincible
    //isInvulnernable = true;
    invincibilityFrameCount(100);   //Makes player invulnerable for 1000 miliseconds. [100 updates * 10 ticks / update].

//scene->removeItem();
}






/*
 *  This function just seemed to not be useful, was created
 *      with a poor design mindset at the time.
 *  Most of the code from this period is going to be removed because
 *      it is unhelpful and clunky.
 *
 *
bool Character::Contains(QPointF& p, bool proper)
{
    / *
    //return myPlayer->pixmap().rect().contains(p, proper);
    //return myPlayer->pixmap().rect().contains( p.x(), p.y());
    QLineF line = QLineF ( myPlayer->pos(), QPointF(p.x(), p.y()) );
    if (line.length() < 25) {
        return true;
    }* /
    return false;
}
*/



void Character::gameWin()
{
    //Send score
    char* s;
/*std::string s;*/
    QProcess *proc = new QProcess();
    QStringList cmdArgList;
    cmdArgList << "52.160.46.238";
    cmdArgList << "1";
    cmdArgList << "SPACE MAN";
    itoa(mTempScore, s, 10);
    cmdArgList << s;
    proc->start("C:\\Users\\irish\\Downloads\\hssclient",
    cmdArgList);

    VictoryScreen win;
    win.display();
    //win.show();
}

#define INVINC_FRAMES 100
/*  invincFrame()
 *  INVINC_FRAMES represents how many ticks the player
 *      will be invulnerable for (Ticks defined as 10 miliseconds currently).
 *  Intended to be called in update() if the player is invulnerable. Will be called
 *      every tick, and return the boolean value of whether the player is invulnerable.
 */
bool Character::invincibilityFrameCount(int frames)
{
    static int i = 0;
    static int frameCount = 0;

    if (frames != 0) {
        frameCount = frames;
        isInvulnernable = true;
        return true;
    }

    //i = ++i % INVINC_FRAMES;
    ++i;
    i = i % frameCount;
    if (i == 0) {
        //Invulnerability over.
        return false;
    }
    return true;
}

#define CONST_FIRE_MODIFIER 10
/*  shotCooldownCount()
 *  Very similar to invicibilityFrameCount()
 *
 */
bool Character::shotCooldownCount(int t)
{
    static int i = 0;
    static int s = t * CONST_FIRE_MODIFIER;     //calculations to be used in the future.
    if ( t != 0 ) {
        i = 0;
        s = t * CONST_FIRE_MODIFIER;
    }
    ++i;
    i = i % s;
    if (i == 0) {
        //Cooldown over.
        return false;
    }
    return true;
}

/* shoot()
 * Handles player rotation while shooting.
 *
 * Handles firing weapon.
 */
int Character::shoot(QLineF fireLine)
{

    //Face Player Towards Firing.
    //QLineF fireLine = QLineF( myPlayer->pos(), mMousePoint  );
    //myPlayer->setRotation( 90 - fireLine.angle() );
    //^^^^ for the "90 - ..."
    //Consider trying a negative scale factor in "setScale(qreal factor)"

    if (mShotCooldown) {
        //Shot is on Cooldown.
        mShotCooldown = shotCooldownCount(0);
    } else {
        //Shot is not on cooldown.
        //Shoot a bullet.
        //QPointF p = myPlayer->pos();
        //Shot* s = new Shot( mStats->shotSpeed, QLineF(p , mMousePoint) );
        qDebug() << mStats->shotSpeed;
        PlayerShot* s = new PlayerShot( mStats->shotSpeed, fireLine );
        connect(this, SIGNAL(shotTick()), s, SLOT(shotUpdate()));
        connect(this, SIGNAL(shotKill()), s, SLOT(kill()));
        connect(s, SIGNAL(hitEnemy()),this, SLOT(enemyHit()));

        scene->addItem(s);
        mLaser->playSound();
        //mShotCooldown = true;
        mShotCooldown = shotCooldownCount(mStats->fireRate);
    }
    return 0;
}


int Character::getCurrentHealth()
{
    return mStats->currentHealth;
}

int Character::getDamage()
{
    return mStats->damage;
}


void Character::playerLeaveRoom(QString name)
{
    myMap->switchRooms(name);
}

void Character::setPlayerStats(DataBank* p)
{
    mStats = p;
}

void Character::KNStressTest()
{
    mKNStressTest = !mKNStressTest;
}

void Character::BTStressTest()
{
    mBTStressTest = !mBTStressTest;
}

void Character::setMousePoint(QPointF p)
{
    mMousePoint = p;
}

void Character::toggleShooting()
{
    mIsShooting = !mIsShooting;
}

void Character::successPath(QString path)
{
    //static QChar* p = path.begin();
    //static QString::iterator i = path.begin();
    //static QString::iterator = path.begin();
    if (0) qDebug() << path;
}

QPointF Character::getCenter()
{
    return QPointF( (myPlayer->pos().x() + (myPlayer->pixmap().rect().width() / 2)) , (myPlayer->pos().y() + (myPlayer->pixmap().rect().height()/2)) );
}

QRectF Character::getRect()
{
    return myPlayer->pixmap().rect();
}
