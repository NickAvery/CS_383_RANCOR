/*#include "JTGoal.h"

Goal::Goal(QPixmap* pic, QGraphicsScene *scene): Collidable(pic)
{
    setPixmap(*pic);
    this->setPos(360,260);
    scene->addItem(this);
}*/

#include "JTgoal.h"

Goal::Goal(): QObject(), QGraphicsPixmapItem()
{
    setPixmap(QPixmap(":/images/JTStairs.png"));
}
