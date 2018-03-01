#include "BTcharacter.h"
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

/*
//No real reason why to have this intermediate constructor, just assume the value is 0 if not given.
Character::Character(QWidget *parent)
    : QWidget(parent)
{
    //tick = new QTimer(this);
    Character( parent, 0 );
}
*/

Character::Character(int characterNumber , Game *parent)
{
    int length = 100;
    myGame = parent;
    //player = new QGraphicsRectItem();
    setRect( 0, 0, length, length );
    //player->setPos( (scene()->width() - length)/2 , (scene()->height() - length)/2 );
    setPos( 400, 300 );

    QGraphicsRectItem::setFlag(QGraphicsItem::ItemIsFocusable);
    setFocusPolicy(Qt::StrongFocus);
    QGraphicsRectItem::setFocus();

    //Get Walls Object
    //https://stackoverflow.com/questions/23533691/qt-collision-detection-with-custom-qgraphicsitem-classes
/*    QList<QGraphicsItem *> list = collidingItems() ;

    foreach(QGraphicsItem * i , list)
    {
        Walls * item= dynamic_cast<Walls *>(i);
        if (item)
        {
            walls = item;
            break;
        }
    }
*/
    myMap = myGame->getMap();  //Get map from the game.
    myWalls = myMap->walls;     //Get Walls from the map.
    skills = new SkillManager( this, characterNumber );
    /*
    if (myWalls == NULL) {
        myWalls = new QGraphicsRectItem();
        myWalls->setRect(0,0,720,520);
        myWalls->setPos(40,40);
    }
    */
    moveUp =    false;
    moveDown =  false;
    moveRight = false;
    moveLeft =  false;
}

Character::~Character()
{
    //delete(player);
    //player = NULL;
    delete(skills);
    skills = NULL;
}

void Character::setSpeed(int newSpeed)
{
    if (speed >= 0) speed = newSpeed;
}

QPoint Character::getPosition()
{
    return QPoint( QGraphicsRectItem::x() + (QGraphicsRectItem::rect().width()/ 2) , QGraphicsRectItem::y() + (QGraphicsRectItem::rect().height()/2) );
}

void Character::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Up || event->key() == Qt::Key_W) {
        qDebug() << "Pressing up.";
        moveUp = true;
    }
    if (event->key() == Qt::Key_Down || event->key() == Qt::Key_S) {
        qDebug() << "Pressing down.";
        moveDown = true;
    }
    if (event->key() == Qt::Key_Right || event->key() == Qt::Key_D) {
        qDebug() << "Pressing right.";
        moveRight = true;
    }
    if (event->key() == Qt::Key_Left || event->key() == Qt::Key_A) {
        qDebug() << "Pressing left.";
        moveLeft = true;
    }
    if (event->key() == Qt::Key_P) {
        qDebug() << "Pressing P";
        static bool state = false;
        state = !state;
        if (myGame != NULL) myGame->setPause(state);
    }
}

void Character::keyReleaseEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Up || event->key() == Qt::Key_W) {
        qDebug() << "Releasing up.";
        moveUp = false;
    }
    if (event->key() == Qt::Key_Down || event->key() == Qt::Key_S) {
        qDebug() << "Releasing down.";
        moveDown = false;
    }
    if (event->key() == Qt::Key_Right || event->key() == Qt::Key_D) {
        qDebug() << "Releasing right.";
        moveRight = false;
    }
    if (event->key() == Qt::Key_Left || event->key() == Qt::Key_A) {
        qDebug() << "Releasing left.";
        moveLeft = false;
    }
}

void Character::move()
{
    double moveDistance = speed * 1;

    /* Alternate way that movement can be controlled, uses collisions to ensure that
     * the player always stays within the bounding rectangle object that is created by the
     * Map class. Not sure if i need to include the Map class to ensure that i will be able
     * to detect the object that is colliding with the player.
     */
    /*
    {
        QGraphicsRectItem * ghost = new QGraphicsRectItem();
        ghost->setRect( rect() );
        if (moveUp) {
            ghost->setPos( ghost->x(), ghost->y() - moveDistance );
            QList<QGraphicsItem *> collidingItems = collidingItems( ghost, 0x0 );
            if (  ) {

            }
        }
        if (moveDown) {
            player->setPos( ghost->x(), ghost->y()+moveDistance );
            if () { //if past border

            }
        }
        if (moveRight) {
            player->setPos( ghost->x()+moveDistance, ghost->y() );
            if () { //if past border

            }
        }
        if (moveLeft) {
            player->setPos( ghost->x()-moveDistance, ghost->y() );
            if () { //if past border

            }
        }
    }
    */
//If the above method has issues, just use this one.
    // /*
    int x = QGraphicsRectItem::pos().x();  //Current x and y values, before moving player.
    int y = QGraphicsRectItem::pos().y();
    if (moveUp) {
        int newY = QGraphicsRectItem::pos().y() - moveDistance;
        int topWall = myWalls->pos().y();
        if (newY >= topWall) {  //If not colliding with walls
            setPos( x , newY );
            y = newY;
        } else {                //Move to wall edge instead.
            setPos( x , topWall );
            y = topWall;
        }
    }

    if (moveDown) {
        int newY = QGraphicsRectItem::pos().y() + moveDistance;
        qDebug() << "y = " << QGraphicsRectItem::pos().y() << "\t move = " << newY;
        int botWall = myWalls->pos().y() + myWalls->rect().height();
        if (botWall >= newY + QGraphicsRectItem::rect().height()){    //If not colliding with walls
            setPos( x, newY );
            y = newY;
        } else {              //move to wall edge instead.
            setPos( x, botWall - QGraphicsRectItem::rect().height());
            y = botWall - QGraphicsRectItem::rect().height();
        }
    }
    if (moveRight) {
        int newX = QGraphicsRectItem::pos().x()  + moveDistance;
        int rightWall = myWalls->pos().x() + myWalls->rect().width();
        if (newX + QGraphicsRectItem::rect().width() <= rightWall){ //If not colliding with walls
            setPos( newX, y );
        } else {                //move to wall edge intead
            setPos( rightWall - QGraphicsRectItem::rect().width(), y ); //move to wall's edge.
        }
    }
    if (moveLeft) { //if not moving past border
        int newX = QGraphicsRectItem::pos().x() - moveDistance;
        int leftWall = myWalls->pos().x();
        if (leftWall <= newX) { //If not colliding with walls
            setPos( newX, y );
        } else {                 //move to wall edge instead
            setPos( leftWall , y );
        }
    }
    // */

}
