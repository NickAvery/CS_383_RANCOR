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

#include <QGraphicsRectItem>

#include <QWidget>

Player::Player(Character *parent, direction *movement, Game* thegame)
    //: QPixmapGraphicsItem(myPixmap)
{
    //int length = 40;
    //myCharacter = parent;

    setCursor(Qt::CrossCursor); //Set cursor to crosshairs.

    Move = movement;
    //setRect( 0, 0, length, length );
    //Draw Graphics
    setPixmap(QPixmap(":/images/Graphics/Player/SmallEngiOnly.png"));
    setPos( 400, 300 );

    //Sets the rotation origin point around center of graphic instead of top left corner.
    setTransformOriginPoint( QPointF( pixmap().rect().width() / 2 , pixmap().rect().height() / 2 ) );
    qDebug() << "player rect = " << pixmap().rect();
    qDebug() << "player transform point " << transformOriginPoint();
    mCharacter = parent;

    //setFlag(QGraphicsItem::ItemIsFocusable);
    //setFocusPolicy(Qt::StrongFocus);
    //setFocus();

    //ghost = new QGraphicsRectItem();
    //ghost->setRect( 0, 0, length, length );

    //myGame = thegame;
    myMap = thegame->getMap();
    //myWalls = myMap->room->walls;

    //Get Walls
    mPlayerWallsRect = QRectF();
    //QList<QGraphicsItem *> list = collidingItems(Qt::ContainsItemShape) ;
    QList<QGraphicsItem *> list = collidingItems() ;
    foreach(QGraphicsItem * i , list)
    {
        Walls * item= dynamic_cast<Walls *>(i);
        if (item) mPlayerWallsRect = item->rect();
    }
    QRectF temp;
    if (mPlayerWallsRect.isNull()) {
        qDebug() << "Failed to find Walls";
        //mPlayerWallsRect = myMap->getWallsRect();
        temp = myMap->getWallsRect();
        qDebug() << "Player Walls (Before change)" << mPlayerWallsRect;

    }
    //mPlayerWallsRect.setPos();
    mPlayerWallsRect.setRect(40, 40, temp.width(), temp.height());
    //mPlayerWallsRect.setPos(40, 40);
    //mPlayerWallsRect.setCoords();
    //mPlayerWallsRect.setX(40);
    //mPlayerWallsRect.setY(40);
    qDebug() << "Player Walls" << mPlayerWallsRect;
}

void Player::move()
{
    assert(Move);
    assert(!mPlayerWallsRect.isNull());

    //qDebug() << "Player Walls." << mPlayerWallsRect;

    double moveDistance = speed * 1;
    //int forwardTime = 10; //# of ticks that the "ghost" is ahead of the player.
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

    double x = pos().x();  //Current x and y values, before moving player.
    double y = pos().y();
    //double y = QGraphicsRectItem::rect().bottom();
    if (Move->moveUp) {
        double newY = y - moveDistance;
        //double topWall = mPlayerWallsRect->pos().y();
        double topWall = mPlayerWallsRect.top();
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
        //double botWall = mPlayerWallsRect->y() + mPlayerWallsRect->rect().height();
        double botWall = mPlayerWallsRect.bottom();
        //qDebug() << "botWall: " << botWall << "\theight: " << rect().height() << "\ttop: " << rect().top();
        if (botWall >= newY + pixmap().rect().height()){    //If not colliding with walls
            setPos( x, newY );
            y = newY;
        } else {              //move to wall edge instead.
            setPos( x, botWall - pixmap().rect().height());
            y = botWall - pixmap().rect().height();
        }
    }
    if (Move->moveRight) {
        double newX = pos().x()  + moveDistance;
        //double rightWall = mPlayerWallsRect->x() + mPlayerWallsRect->rect().width();
        double rightWall = mPlayerWallsRect.right();
        if (newX + pixmap().rect().width() <= rightWall){ //If not colliding with walls
            setPos( newX, y );
        } else {                //move to wall edge intead
            setPos( rightWall - pixmap().rect().width(), y ); //move to wall's edge.
        }
    }
    if (Move->moveLeft) { //if not moving past border
        double newX = pos().x() - moveDistance;
        //double leftWall = mPlayerWallsRect->pos().x();
        double leftWall = mPlayerWallsRect.left();
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
    mPlayerWallsRect = myMap->getWallsRect();
    mPlayerWallsRect.setRect(40, 40, mPlayerWallsRect.width(), mPlayerWallsRect.height());

//    qDebug() << "Player Walls" << mPlayerWallsRect;
}

/*
 * Similar to chmod, this function returns a number with
 *
 *
 */
int Player::checkCollisions()
{
    //Door* d = NULL;
    /* Is the player leaving the room?
     *      This occurs when the player collide with a door.
     */
    bool r = false;
    QList<QGraphicsItem *> list = collidingItems() ;
    QString name;
    foreach(QGraphicsItem * i , list)
    {
        Door * door= dynamic_cast<Door *>(i);
        if (door){
            name = door->name;
            //cant return here, since i want to check all collisions.
            //return 1;
            r = true;
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

            //Release Mouse Control
            //releaseMouse();

            mCharacter->gameWin();
            //Temporary Solution to problem. [exit( EXIT_SUCCESS )]
            exit( EXIT_SUCCESS );
        }
    }
    //return 0;
    if (r) { //Check this condition last, needs to happen
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
