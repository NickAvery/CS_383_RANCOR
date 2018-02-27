/* Baylus Tunnicliff    2/21/2018   CS383: Software Engineering
 * Character class
 *
 *
 *
 */

#ifndef PLAYER_H
#define PLAYER_H

#include <QWidget>
#include <QPoint>
#include <QGraphicsRectItem>
#include "KNSkillManager.h"
#include "JTwalls.h"
#include "JAgame.h"

class SkillManager;
class Game;

class Character : public QWidget, public QGraphicsRectItem
{
    Q_OBJECT

public:
    /* The first constructor calls the second, with a default "characterNum" of 0.
     * The second constructor will create, and intialize the player graphics, and the default stats.
     */
    //Character(QWidget *parent = 0); //Initializes Player as temporary character, starts character in
    Character(int characterNumber = 0, Game* parent = 0);
    ~Character();

    void setSpeed(int speed);
    QPoint getPosition();   //Returns the position of the center of the
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void move();
private:
    //QGraphicsRectItem* player;    //ca

    SkillManager* skills;
    QGraphicsRectItem* walls;   //Stores the walls object that i need to not collide with.
    Game* game; /* Not guaranteed to exist. Check if NULL when used. */

    //QPoint* position;
    //QTimer tick;
    bool moveUp, moveDown, moveRight, moveLeft;
    int speed = 10;
};

#endif // PLAYER_H
