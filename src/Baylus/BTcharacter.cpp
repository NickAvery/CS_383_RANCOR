#include "BTcharacter.h"
#include "BTplayer.h"
#include "BTshot.h"

#include "JTwalls.h"
#include "KNSkillManager.h"
#include "JAgame.h"
#include "JAaudio.h"

#include <iostream>
#include <QPoint>
#include <QWidget>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QDebug>
#include <cmath>
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

    grabKeyboard();
    grabMouse();

    setMouseTracking(true);

    //https://stackoverflow.com/questions/23533691/qt-collision-detection-with-custom-qgraphicsitem-classes

    //Set up Audio Objects
    mLaser = new AudioInter(0, "qrc:/sounds/Sounds/Laser.wav");
    mLaser->SetVolume(5);

    sDamage = new AudioInter(0, "qrc:/sounds/Sounds/damage1.wav");
    sDamage->SetVolume(15);

    //Load the shot image into cache
    //QPixmap::load(":/images/Graphics/Lasers/laserGreen04.png");

    mMousePoint = QPointF(0,0);

    //Fire initial shot to load graphics
    Shot();

    if (autopilot) {
        if (successPath) {
            mAP = new Autopilot(this, myGame, myMap->getSuccessPath(), myMove);
        } else {
            mAP = new Autopilot(this, myGame, QString(), myMove);
        }
    }
}

Character::~Character()
{
    //delete(player);
    //player = NULL;
    delete(mySkillManager);
    mySkillManager = NULL;
    delete(myPlayer);
    myPlayer = NULL;
}

void Character::setSpeed(double newSpeed)
{
    if (speed >= 0) speed = newSpeed;
}

QPointF Character::getPosition()
{
    if( myPlayer ) {
        //return myPlayer->pixmap().rect().center();
        //return QPointF( myPlayer->pixmap().rect().x() , myPlayer->pixmap().rect().y() );
        return myPlayer->pos();
    } else {
        qDebug() << "Real bad errors.";
    }
}

QPointF Character::getCenter()
{
    return QPointF( (myPlayer->pos().x() + (myPlayer->pixmap().rect().width() / 2)) , (myPlayer->pos().y() + (myPlayer->pixmap().rect().height()/2)) );
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

QRectF Character::getRect()
{
    return myPlayer->pixmap().rect();
}

void Character::keyPressEvent(QKeyEvent *event)
{
    switch ( event->key() ) {
        case Qt::Key_Up:
        case Qt::Key_W:
            myMove->moveUp = true;
            break;
        case Qt::Key_Down:
        case Qt::Key_S:
             myMove->moveDown = true;
            break;
        case Qt::Key_Right:
        case Qt::Key_D:
            myMove->moveRight = true;
            break;
        case Qt::Key_Left:
        case Qt::Key_A:
            myMove->moveLeft = true;
            break;
        case Qt::Key_P:
            static bool state = false;
            state = !state;
            if (myGame != NULL) myGame->setPause(state);
            break;
        default:
            event->ignore();
            break;
        }
}

void Character::keyReleaseEvent(QKeyEvent *event)
{
    switch ( event->key() ) {
        case Qt::Key_Up:
        case Qt::Key_W:
            myMove->moveUp = false;
            break;
        case Qt::Key_Down:
        case Qt::Key_S:
             myMove->moveDown = false;
            break;
        case Qt::Key_Right:
        case Qt::Key_D:
            myMove->moveRight = false;
            break;
        case Qt::Key_Left:
        case Qt::Key_A:
            myMove->moveLeft = false;
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
                if ( 0 ) {                              //Temporary Until shooting fix is ensured.
                    QPointF p = myPlayer->pos();
                    //qDebug() << "Firing a shot" << p << " to " << event->windowPos();
                    Shot* s = new Shot( 3, QLineF(p , event->windowPos()) );
                    connect(this, SIGNAL(shotTick()), s, SLOT(shotUpdate()));
                    connect(this, SIGNAL(shotKill()), s, SLOT(kill()));

                    scene->addItem(s);
                    mLaser->PlaySound();
                }

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
void Character::move()
{

}


void Character::update()
{
    if (mAP) {
        mAP->autopilotUpdate();
    }
    myPlayer->move();
    if (isInvulnernable) {
        isInvulnernable = invincibilityFrameCount();
    }
    //emit(SIGNAL(shotTick()));
    if (mIsShooting) {
        //Trying to shoot a bullet.

        //Face Player Towards Firing.
        QLineF fireLine = QLineF( myPlayer->pos(), mMousePoint  );


        myPlayer->setRotation( 90 - fireLine.angle() );

        if (mShotCooldown) {
            //Shot is on Cooldown.
            mShotCooldown = shotCooldownCount();
        } else {
            //Shot is not on cooldown.
            //Shoot a bullet.
            QPointF p = myPlayer->pos();
            //qDebug() << "Firing a shot" << p << " to " << event->windowPos();
            //Shot* s = new Shot( mStats->shotSpeed, QLineF(p , QCursor::pos()) );
            //Shot* s = new Shot( mStats->shotSpeed, QLineF(p , mMoveEvent->windowPos()) );
            Shot* s = new Shot( mStats->shotSpeed, QLineF(p , mMousePoint) );
            connect(this, SIGNAL(shotTick()), s, SLOT(shotUpdate()));
            connect(this, SIGNAL(shotKill()), s, SLOT(kill()));

            scene->addItem(s);
            mLaser->PlaySound();
            mShotCooldown = true;
        }
    } else {
        //Player not trying to shoot.
        //Player faces move direction.

    }
    shotTick();
    //Karstin's stress Test
    if (mKNStressTest) {
        mySkillManager->addExperience(1);
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
    sDamage->PlaySound();
    //qDebug() << "After Damgage: " << mStats->currentHealth;

    isInvulnernable = true;

//scene->removeItem();
}

void Character::successPath(QString path)
{
    //static QChar* p = path.begin();
    static QString::iterator i = path.begin();
    //static QString::iterator = path.begin();

}

void Character::setPlayerStats(DataBank* p)
{
    mStats = p;
}

void Character::KNStressTest()
{
    mKNStressTest = !mKNStressTest;
}

void Character::setMousePoint(QPointF p)
{
    mMousePoint = p;
}

void Character::toggleShooting()
{
    mIsShooting = !mIsShooting;
}

bool Character::Contains(QPointF& p, bool proper)
{
    /*
    //return myPlayer->pixmap().rect().contains(p, proper);
    //return myPlayer->pixmap().rect().contains( p.x(), p.y());
    QLineF line = QLineF ( myPlayer->pos(), QPointF(p.x(), p.y()) );
    if (line.length() < 25) {
        return true;
    }*/
}

void Character::playerLeaveRoom(QString name)
{
    myMap->switchRooms(name);
}

#define INVINC_FRAMES 100
/*  invincFrame()
 *  INVINC_FRAMES represents how many ticks the player
 *      will be invulnerable for (Ticks defined as 10 miliseconds currently).
 *  Intended to be called in update() if the player is invulnerable. Will be called
 *      every tick, and return the boolean value of whether the player is invulnerable.
 */
bool Character::invincibilityFrameCount()
{
    static int i = 0;

    i = ++i % INVINC_FRAMES;
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
bool Character::shotCooldownCount()
{
    static int i = 0;

    i = ++i % (mStats->fireRate * CONST_FIRE_MODIFIER );
    if (i == 0) {
        //Cooldown over.
        return false;
    }
    return true;
}
