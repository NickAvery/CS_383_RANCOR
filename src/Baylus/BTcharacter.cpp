#include "BTcharacter.h"
#include "JTwalls.h"
#include "KNSkillsManager.h"

#include <iostream.h>
#include <QPoint>
#include <QGraphicsRectItem>
#include <QGraphicsScene>


/*
//No real reason why to have this intermediate constructor, just assume the value is 0 if not given.
Character::Character(QWidget *parent)
    : QWidget(parent)
{
    //tick = new QTimer(this);
    Character( parent, 0 );
}
*/

Character::Character(QWidget *parent = 0, int characterNumber = 0)
{
    int length = 100;

    player = new QGraphicsRectItem();
    player->setRect( 0, 0, length, length );
    //player->setPos( (scene()->width() - length)/2 , (scene()->height() - length)/2 );
    player->setPos( 400, 300 );

    //Get Walls Object
    //https://stackoverflow.com/questions/23533691/qt-collision-detection-with-custom-qgraphicsitem-classes
    QList<QGraphicsItem *> list = player->collidingItems() ;

    foreach(QGraphicsItem * i , list)
    {
        Walls * item= dynamic_cast<Walls *>(i);
        if (item)
        {
            walls = item;
            break;
        }
    }

    skills = new SkillManager( this, characterNumber );

}

Character::~Character()
{
    delete(player);
    player = NULL;
    delete(skills);
    skills = NULL;
}

void Character::setSpeed(int newSpeed)
{
    if (speed >= 0) speed = newSpeed;
}

QPoint Character::getPosition()
{
    return QPoint( player->x() + (player->rect().width()/ 2) , player->y() + (player->rect().height()/2) );
}

void Character::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Up) {
        //qDebug() << "Releasing up.";
        moveUp = true;
    } else if (event->key() == Qt::Key_Down) {
        //qDebug() << "Releasing down.";
        moveDown = true;
    } else if (event->key() == Qt::Key_Down) {
        //qDebug() << "Releasing down.";
        moveRight = true;
    } else if (event->key() == Qt::Key_Down) {
        //qDebug() << "Releasing down.";
        moveLeft = true;
    }
}

void Character::keyReleaseEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Up) {
        //qDebug() << "Releasing up.";
        moveUp = false;
    } else if (event->key() == Qt::Key_Down) {
        //qDebug() << "Releasing down.";
        moveDown = false;
    } else if (event->key() == Qt::Key_Down) {
       // qDebug() << "Releasing down.";
        moveRight = false;
    } else if (event->key() == Qt::Key_Down) {
        //qDebug() << "Releasing down.";
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
        ghost->setRect( player->rect() );
        if (moveUp) {
            ghost->setPos( ghost->x(), ghost->y() - moveDistance );
            QList<QGraphicsItem *> collidingItems = collidingItems(ghost,  )
            if () {

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
    int x = player->pos().x();  //Current x and y values, before moving player.
    int y = player->pos().y();
    if (moveUp) {
        int newY = player->pos().y() - moveDistance;
        int topWall = walls->pos().y();
        if (newY >= topWall) {
            player->setPos( x , newY );
        } else {    //Move to wall edge instead.
            player->setPos( x , topWall );
        }
    }
    if (moveDown) {
        int newY = player->pos().y() + player->rect().height() + moveDistance;
        int botWall = player->pos().y() + player->rect().height();
        if (botWall > newY){
            player->setPos( x, newY );
        } else {    //move to wall edge instead.
            player->setPos( x, botWall );
        }
    }
    if (moveRight) {
        int newX = player->pos().x() + player->rect().width() + moveDistance;
        int rightWall = walls->pos().x() + walls->rect().width();
        if (newX <= rightWall){
            player->setPos( newX, y );
        } else {    //move to wall edge
            player->setPos( rightWall, y ); //move to wall's edge.
        }
    }
    if (moveLeft) { //if not moving past border
        int newX = player->pos().x() - moveDistance;
        int leftWall = player->pos().x();
        if (leftWall <= newX) {
            player->setPos( newX, y );
        } else {    //move to wall edge
            player->setPos( leftWall , y );
        }
    }
}
