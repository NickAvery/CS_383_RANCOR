#ifndef JTMAP_H
#define JTMAP_H

#include "JTwalls.h"
#include "JTroom.h"
#include "JAgame.h"
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>

class Game;

class Map: public QGraphicsView{
private:
public:
    QGraphicsScene * scene;
    //Walls * walls;
    Room * room;
    Game * game;
    Map(QGraphicsScene* a, bool Demo, Game * b);
    void selectRoom(int selection, QGraphicsScene* a);
    void switchRooms(QString name);
    static int roomx;
    static int roomy;
    const static int maxx=101;
    const static int maxy=101;
    int floorarray[101][101];
};

#endif // JTMAP_H
