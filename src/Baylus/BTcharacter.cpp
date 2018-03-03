#include "BTcharacter.h"
#include "BTplayer.h"
#include "JTwalls.h"
#include "KNSkillManager.h"
#include "JAgame.h"
#include "JAaudio.h"

#include <iostream>
#include <QPoint>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QDebug>
#include <cmath>

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

Character::Character(int characterNumber , Game *parent, QGraphicsScene *s)
{
    //int length = 40;
    Character::myGame = parent;
    //player = new QGraphicsRectItem();
    mySkillManager = new SkillManager( this, characterNumber );
    myMap = myGame->getMap();  //Get map from the game.
    myWalls = myMap->walls;     //Get Walls from the map.
    //x = 400;
    //y = 300;
    scene = s;
    myMove = new struct direction;
    myMove->moveUp =    false;
    myMove->moveDown =  false;
    myMove->moveRight = false;
    myMove->moveLeft =  false;
    myPlayer = new Player(this, myMove, myGame);
    //myPlayer->setRect( 0, 0, length, length );
    //myPlayer->setPos( 400, 300 );

    scene->addItem(myPlayer);
    //myPlayer->setFlag(QGraphicsItem::ItemIsFocusable);
    setFocusPolicy(Qt::StrongFocus);
    //myPlayer->QGraphicsRectItem::setFocus();

    grabKeyboard();
    //Get Walls Object

    //https://stackoverflow.com/questions/23533691/qt-collision-detection-with-custom-qgraphicsitem-classes
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
    return myPlayer->QGraphicsRectItem::pos();
}

QRectF Character::getRect()
{
    return myPlayer->QGraphicsRectItem::rect();
}

void Character::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "Key was pressed.";
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
qDebug() << "Key was released.";
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

//Obsolete
void Character::move()
{

}


void Character::update()
{
    myPlayer->move();
}

void Character::doDamage(double damage)
{

}
