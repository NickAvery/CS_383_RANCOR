#include "BTcharacter.h"
#include <QPoint>
#include "JTwalls.h"
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include "KNSkillsManager.h"


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
        qDebug() << "Releasing up.";
        moveUp = true;
    } else if (event->key() == Qt::Key_Down) {
        qDebug() << "Releasing down.";
        moveDown = true;
    } else if (event->key() == Qt::Key_Down) {
        qDebug() << "Releasing down.";
        moveRight = true;
    } else if (event->key() == Qt::Key_Down) {
        qDebug() << "Releasing down.";
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
    if (moveUp) {
        int newY = player->pos().y() - moveDistance;
        if (newY > 0) {
            player->setPos( player->pos().x(), newY );
        }
    }
    if (moveDown) {
        int newY = player->pos().y() + player->rect().height() + moveDistance;
        if (walls->rect().height() > newY){
            player->setPos( player->pos().x(), newY );
        }
    }
    if (moveRight) {
        int newX = player->pos().x() + player->rect().width() + moveDistance;
        if (walls->rect().width() > newX){
            player->setPos( newX, player->pos().y() );
        }
    }
    if (moveLeft) { //if not moving past border
        int newX = player->pos().x() - moveDistance;
        if (newX >= 0){
            player->setPos( newX, player->pos().y() );
        }
    }
}
