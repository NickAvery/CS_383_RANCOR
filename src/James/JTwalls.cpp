#include "JTwalls.h"

Walls::Walls(): QObject(), QGraphicsPixmapItem(){
    setPixmap(QPixmap(":/images/Room.ai"));
    setPos(40,40);
}
