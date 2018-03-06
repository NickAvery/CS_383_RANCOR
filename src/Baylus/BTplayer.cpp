/*
 * BTplayer.cpp
 * Baylus Tunnicliff    3/3/2018
 * Team Rancor      Space Shooter X
 * Player Class Implementation
 *
 *
 *
 *
 */
#include "BTplayer.h"
#include "JAgame.h"
#include "JTmap.h"
#include "JTwalls.h"
#include "JTroom.h"
#include "JTgoal.h"

Player::Player(Character *parent, direction *movement, Game* thegame)
{
    int length = 40;
    //myCharacter = parent;
    Move = movement;
    setRect( 0, 0, length, length );
    setPos( 400, 300 );

    mCharacter = parent;

    //setFlag(QGraphicsItem::ItemIsFocusable);
    //setFocusPolicy(Qt::StrongFocus);
    //setFocus();

    ghost = new QGraphicsRectItem();
    ghost->setRect( 0, 0, length, length );

    //myGame = thegame;
    myMap = thegame->getMap();
    //myWalls = myMap->room->walls;

    //Get Walls
    myWalls = NULL;
    //QList<QGraphicsItem *> list = collidingItems(Qt::ContainsItemShape) ;
    QList<QGraphicsItem *> list = collidingItems() ;
    foreach(QGraphicsItem * i , list)
    {
        Walls * item= dynamic_cast<Walls *>(i);
        if (item) myWalls = item;
    }

    if (myWalls == NULL) {
        qDebug() << "Failed to find Walls";
        myWalls = myMap->room->walls;
    }
/*
    if ( collidesWithItem(myWalls, Qt::ContainsItemShape) ) {
//       qDebug() << "Is colliding with wall.";
    }
    if (! (ghost->collidesWithItem(myWalls, Qt::ContainsItemShape)) ) {
//        qDebug() << "ghost Is not colliding with wall.";
    }
    */
}

void Player::move()
{
    if (myWalls == NULL) {
        qDebug() << "Not within Walls.";
        //return;
    }
    double moveDistance = speed * 1;
    int forwardTime = 10; //# of ticks that the "ghost" is ahead of the player.
    /* Alternate way that movement can be controlled, uses collisions to ensure that
     * the player always stays within the bounding rectangle object that is created by the
     * Map class. Not sure if i need to include the Map class to ensure that i will be able
     * to detect the object that is colliding with the player.
     */
   // /*
    if ( Move->moveUp ^ Move->moveDown  && Move->moveRight ^ Move->moveLeft) {
        //qDebug() << "Moving Diagonally!!!!";
        moveDistance /= (double) sqrt(2.0);
//qDebug() << "Move Distance is " << moveDistance;
    }

    double x = QGraphicsRectItem::pos().x();  //Current x and y values, before moving player.
    double y = QGraphicsRectItem::pos().y();
    //double y = QGraphicsRectItem::rect().bottom();
    if (Move->moveUp) {
        double newY = y - moveDistance;
        double topWall = myWalls->pos().y();
        if (newY >= topWall) {  //If not colliding with walls
            setPos( x , newY );
            y = newY;   //To keep track of the real values such that movement isnt inhibited by
        } else {                //Move to wall edge instead.
            setPos( x , topWall );
            y = topWall;
        }
    }

    if (Move->moveDown) {
        double newY = y + moveDistance;
//qDebug() << "y = " << y << "\t move = " << newY;
        double botWall = myWalls->y() + myWalls->rect().height();
        //qDebug() << "botWall: " << botWall << "\theight: " << rect().height() << "\ttop: " << rect().top();
        if (botWall >= newY + QGraphicsRectItem::rect().height()){    //If not colliding with walls
            setPos( x, newY );
            y = newY;
        } else {              //move to wall edge instead.
            setPos( x, botWall - QGraphicsRectItem::rect().height());
            y = botWall - QGraphicsRectItem::rect().height();
        }
    }
    if (Move->moveRight) {
        double newX = QGraphicsRectItem::pos().x()  + moveDistance;
        double rightWall = myWalls->x() + myWalls->rect().width();
        if (newX + QGraphicsRectItem::rect().width() <= rightWall){ //If not colliding with walls
            setPos( newX, y );
        } else {                //move to wall edge intead
            setPos( rightWall - QGraphicsRectItem::rect().width(), y ); //move to wall's edge.
        }
    }
    if (Move->moveLeft) { //if not moving past border
        double newX = QGraphicsRectItem::pos().x() - moveDistance;
        double leftWall = myWalls->pos().x();
        if (leftWall <= newX) { //If not colliding with walls
            setPos( newX, y );
        } else {                 //move to wall edge instead
            setPos( leftWall , y );
        }
    }
    checkCollisions();
}

/* put()
 * sets players position (into new room)
 * finds new walls.
 */
void Player::put(QPointF p)
{
    //Place player in new room.
    setPos(p);


    //Get new Walls
    myWalls = NULL;
    QList<QGraphicsItem *> list = collidingItems() ;

    foreach(QGraphicsItem * i , list)
    {
        Walls * item= dynamic_cast<Walls *>(i);
        if (item) myWalls = item;
    }

    if (myWalls == NULL) {
        qDebug() << "Failed to find Walls";
        myWalls = myMap->room->walls;
    }
}

/*
 * Similar to chmod, this function returns a number with
 *
 *
 */
int Player::checkCollisions()
{
    //Door* d = NULL;
    int r = 0;
    QList<QGraphicsItem *> list = collidingItems() ;
    QString name;
    foreach(QGraphicsItem * i , list)
    {
        Door * door= dynamic_cast<Door *>(i);
        if (door){
            name = door->name;
            //cant return here, since i want to check all collisions.
            //return 1;
            r += 1;
        }

        Enemy *e = dynamic_cast<Enemy *>(i);
        if (e) {
            //Coliding with Enemy.
            int d = e->getAtkValue();
            mCharacter->doDamage(d);
        }

        Goal *g = dynamic_cast<Goal *>(i);
        if (g) {
            //Goal Reached
            //Signal Map Next Level

            //Temporary Solution to problem.
            //display();
            exit( EXIT_SUCCESS );
        }
    }
    //return 0;
    if (r & 1) { //Check this condition last, needs to happen
        mCharacter->playerLeaveRoom(name);
    }
    return r;
}

/*
QPoint Player::getPosition()
{
    return
}
*/
