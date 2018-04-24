

#ifndef PLAYER_H
#define PLAYER_H

#include "BTcharacter.h"    //Main entity of interaction, relied upon for several functions during setup.
#include "JTwalls.h"        //Might not be necessary in the header file, but is crucial in the source code.
#include "JTmap.h"
#include "JAgame.h"

#include <QWidget>
#include <QPoint>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>

class Walls;
class Character;
class Game;
class Map;


struct direction {
    int dirNum = -1;    //0 for right, 1 for up-right, 2 for up, 3 for up-left, etc.
    //char dirStr[4]; //char represents boolean value. { (Down), (Left), (Up), (Right) }
    bool moveUp;
    bool moveDown;
    bool moveRight;
    bool moveLeft;
};

class Player: public QGraphicsPixmapItem {

public:
    Player(Character *parent, struct direction* movement, Game *thegame);
    //QPoint getPosition();   //Returns the position of the center of the
    void move();
    void dealDamageToPlayer(int damage);  //Deals damage to the player.
    void put(QPointF p); //Puts player in new room.
private:
    int checkCollisions();

    //QGraphicsRectItem* ghost;  //Entirely useless, im pretty sure.
    Game* myGame;
    Character* mCharacter;
    QRectF mPlayerWallsRect;
//    QGraphicsRectItem mPlayerWallsRect;

    Map* myMap;
    struct direction *Move;
    double speed = 2;
};

#endif // PLAYER_H
