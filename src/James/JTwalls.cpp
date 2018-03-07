#include "JTwalls.h"

Walls::Walls(): QObject(), QGraphicsRectItem(){
    //setPixmap(QPixmap(":/images/Room.png"));
    setRect(0,0,720,520);
    setPos(40,40);
}
