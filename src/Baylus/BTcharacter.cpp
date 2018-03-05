#include "BTcharacter.h"
#include "BTplayer.h"
#include "BTshot.h"

#include "JTwalls.h"
#include "KNSkillManager.h"
#include "JAgame.h"
#include "JAaudio.h"

#include <iostream>
#include <QPoint>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QDebug>
#include <cmath>
#include <QString>

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

Character::Character(int characterNumber , int inputState, Game *parent, QGraphicsScene *s)
{
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
        return myPlayer->QGraphicsRectItem::pos();
    } else {
        qDebug() << "Real bad errors.";
    }
}

QPointF Character::getCenter()
{
    return QPointF( (myPlayer->pos().x() + (myPlayer->rect().width() / 2)) , (myPlayer->pos(),y() + (myPlayer->rect().height()/2)) );
}

void Character::setPostition(QPointF point)
{
    //emit(shotKill());
    shotKill(); //Clean room of shots.
    myPlayer->put(point);
}

QRectF Character::getRect()
{
    return myPlayer->QGraphicsRectItem::rect();
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
                //QRectF r = myPlayer->rect();
                //QPointF c = mapToGlobal(r.center().toPoint());
                //QPointF t( c.x(), c.y() + 1 );
                QPointF p = myPlayer->QGraphicsRectItem::pos();
//qDebug() << "Firing a shot" << p << " to " << event->windowPos();
                Shot* s = new Shot( 3, QLineF(p , event->windowPos()) );
                connect(this, SIGNAL(shotTick()), s, SLOT(shotUpdate()));
                connect(this, SIGNAL(shotKill()), s, SLOT(kill()));

                scene->addItem(s);
                mLaser->PlaySound();

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
}

//Obsolete
void Character::move()
{

}


void Character::update()
{
    myPlayer->move();
    //emit(SIGNAL(shotTick()));
    shotTick();
}

void Character::doDamage(double damage)
{
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

}

void Character::playerLeaveRoom(QString name)
{
    myMap->switchRooms(name);
}
