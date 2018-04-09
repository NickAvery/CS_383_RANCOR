#include "JTgoal.h"

Goal::Goal(): QObject(), QGraphicsPixmapItem()
{
    setPixmap(QPixmap(":/images/Stairs.png"));
}
