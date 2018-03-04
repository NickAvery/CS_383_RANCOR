/* Baylus Tunnicliff    2/21/2018   CS383: Software Engineering
 * Character class
 *
 *
 *
 */

#ifndef CHARACTER_H
#define CHARACTER_H


#include "KNSkillManager.h"
#include "JTmap.h"
#include "JTwalls.h"
#include "JAgame.h"
//#include "BTplayer.h"

#include <QWidget>
#include <QPoint>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
//#include <QGraphicsItem>

class SkillManager;
class Game;
class Player;
struct direction;

class Character : public QWidget
{
    Q_OBJECT

public:
    /* The first constructor calls the second, with a default "characterNum" of 0.
     * The second constructor will create, and intialize the player graphics, and the default stats.
     */
    Character(int characterNumber = 0, Game* parent = 0, QGraphicsScene* s = NULL);
    ~Character();

    void setSpeed(double speed);   //Changes The speed
    QPointF getPosition();   //Returns the position of the player
    void setPostition(QPointF point);     //sets the position for the player.
    QRectF getRect();
    void keyPressEvent(QKeyEvent *event);   //Registers WASD keys, arrow keys, and 'P' for pause.
    void keyReleaseEvent(QKeyEvent *event); //see keyPressEvent();
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    virtual void move();    //Moves player and ghost to appropriate positions.
    void update();
    void doDamage(double damage);
    void successPath(QString path);
private:
    double speed = 10;     //Speed of player.
    Game* myGame; /* Not guaranteed to exist. Check if NULL when used. */
    Map* myMap;
    SkillManager* mySkillManager;
    QGraphicsScene* scene;
    struct direction* myMove;    //Passing into the Player Object.
    Player *myPlayer;
    Walls* myWalls;   //Stores the walls object that i need to not collide with.
//protected:
signals:
    void tick();
};

#endif // CHARACTER_H
