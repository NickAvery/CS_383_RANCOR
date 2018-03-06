#ifndef JTMAP_H
#define JTMAP_H

#include "JTwalls.h"
#include "JTroom.h"
#include "JAgame.h"
#include "JTgoal.h"
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>

class Game;
class EnemyUpdater;

class Map: public QGraphicsView{
private:
public:
    QGraphicsScene * scene;
    //Walls * walls;
    Room * room;
    Game * game;
    Goal * goal;
    static bool storage;
    EnemyUpdater * enemies;
    static bool Demo;
    Map(QGraphicsScene* a, bool D, Game * b);
    void selectRoom(int selection, QGraphicsScene* a);
    void switchRooms(QString name);
    QString getSuccessPath();
    static int roomx;
    static int roomy;
    const static int maxx=101;
    const static int maxy=101;
    int floorarray[101][101];
    QString successPath;
};

#endif // JTMAP_H
