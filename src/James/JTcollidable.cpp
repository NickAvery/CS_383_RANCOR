#include "JTCollidable.h"

Collidable::Collidable(QPixmap* pic)
{
    setPixmap(*pic);
    this->setPos(360,260);
}
