#include "JTwalls.h"

Walls::Walls(): QObject(), QGraphicsRectItem(){
    setRect(0,0,720,520);
    setPos(40,40);
}
