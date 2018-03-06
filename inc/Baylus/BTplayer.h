

#ifndef PLAYER_H
#define PLAYER_H

#include "BTcharacter.h"
#include "JTwalls.h"
#include "JTmap.h"
#include "JAgame.h"

#include <QWidget>
#include <QPoint>
#include <QGraphicsRectItem>

class Walls;
class Character;

struct direction {
    bool moveUp;
    bool moveDown;
    bool moveRight;
    bool moveLeft;
};

class Player: public QGraphicsRectItem {

public:
    Player(Character *parent, struct direction* movement, Game *thegame);
    //QPoint getPosition();   //Returns the position of the center of the
    void move();

    void put(QPointF p); //Puts player in new room.
private:
    int checkCollisions();

    QGraphicsRectItem* ghost;
    Game* myGame;
    Character* mCharacter;
    Walls *myWalls;
    Map* myMap;
    struct direction *Move;
    double speed = 2;
};

#endif // PLAYER_H
