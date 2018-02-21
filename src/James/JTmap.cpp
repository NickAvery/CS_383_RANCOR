#include <QApplication>
#include <QGraphicsScene>
#include "JTmap.h"
#include "JTwalls.h"
#include "JAgame.h"

Map::Map(QGraphicsScene* scene){
    //add walls
    walls = new Walls();
    scene->addItem(walls);
}
