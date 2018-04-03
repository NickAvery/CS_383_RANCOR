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

class Map: public QGraphicsView
{
    private:
    public:
        QGraphicsScene * scene;
        Room * room;
        Game * game;
        Goal * goal;
        static bool storage;
        EnemyUpdater * enemies;
        static bool demo;
        Map(QGraphicsScene* scenePointer, bool demoMode, Game * gameObject);
        void selectRoom(int selection);
        void switchRooms(QString name);
        QString getSuccessPath();
        QRectF getWallsRect();
        static int roomX;
        static int roomY;
        const static int MAX_X=101;
        const static int MAX_Y=101;
        int floorArray[101][101];
        QString successPath;
};

#endif // JTMAP_H
