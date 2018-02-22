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

class Character : public QWidget
{
    Q_OBJECT

public:
    /* The first constructor calls the second, with a default "characterNum" of 0.
     * The second constructor will create, and intialize the player graphics, and the default stats.
     */
    Character(QWidget *parent = 0); //Initializes Player as temporary character, starts character in
    Character(QWidget *parent = 0, int characterNumber);
    ~Character();

    void setSpeed(int speed);
    QPoint getPosition();   //Returns the position of the center of the
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
private:
    QGraphicsRectItem* player;

    QPoint* position;
    QTimer tick;
    bool moveUp, moveDown, moveRight, moveLeft;
    int speed = 10;
public slots:
    void move();
    void setSpeed(int speed);

};

#endif // PLAYER_H
