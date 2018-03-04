#include "JTdoor.h"
#include <string>

Door::Door(bool sides, QString n){
    n=name;
    if(sides){
        setRect(0,0,10,60);
        setPos(40,40);
    } else {
        setRect(0,0,60,10);
        setPos(40,40);
    }
}
