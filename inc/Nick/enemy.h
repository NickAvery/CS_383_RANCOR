#ifndef ENEMY_H
#define ENEMY_H


class Enemy
{
private:
    double mXPos;
    double mYPos;
    int mHealth;
    int mAtkValue;
    int mSize;
public:
    Enemy(double x, double y, int size); //x = x-coordinate, y = y-coordinate, size = size of square
    double getXPos() {return mXPos;} //gets the x-coordinate
    double getYPos() {return mYPos;} //gets the y-coordinate
    int getHealth() {return mHealth;} //gets the health value
    int getAtkValue() {return mAtkValue;} //gets the attack value
    void move(double x, double y){mXPos = x; mYPos = y;} //sets the position to the (x, y) coordinate
    int attack();
};

#endif // ENEMY_H
