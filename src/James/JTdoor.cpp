#include "JTdoor.h"
#include <string>

Door::Door(bool sides, QString n): QObject(), QGraphicsRectItem(){
    n=name;
    if(sides){
        setRect(0,0,30,60);
        setPos(40,40);
    } else {
        setRect(0,0,60,30);
        setPos(40,40);
    }
}
