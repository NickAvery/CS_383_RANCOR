#include <QApplication>
#include <QGraphicsScene>
#include "JTmap.h"
#include "JTwalls.h"
#include "JAgame.h"

Map::Map(QGraphicsScene* scene){
    //set the scene
        //scene = new QGraphicsScene();
        //scene->setSceneRect(0,0,800,600);
        //setScene(scene);
        //setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        //setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        //setFixedSize(800,600);

    //add walls
    walls = new Walls();
    walls->setPos(20,20);
    scene->addItem(walls);
    show();
}
