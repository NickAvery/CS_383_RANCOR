#include "JTDoor.h"
#include <string>

Door::Door(bool sides, QString doorName)
{
    mName=doorName;
    if(sides)
    {
        setRect(0,0,10,60);
        setPos(40,40);
    } else
    {
        setRect(0,0,60,10);
        setPos(40,40);
    }
}
