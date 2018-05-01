#ifndef JTMAP_H
#define JTMAP_H

#include "JTWalls.h"
#include "JTRoom.h"
#include "JAgame.h"
#include "JTGoal.h"
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QPixmap>

class Game;
class EnemyUpdater;

class Map: public QGraphicsView
{
    private:
        QGraphicsScene * mScene;
        Room * mRoom;
        Game * mGame;
        EnemyUpdater * mEnemies;
        QString mSuccessPath;
        static bool sKarstinStressStorage;
        static bool sBaylusStressStorage;
        static bool sDemo;
        static int sRoomX;
        static int sRoomY;
        static int sGoalX;
        static int sGoalY;
        const static int SMAX_X=101;
        const static int SMAX_Y=101;
        int mFloorArray[101][101];
        void selectRoom(int selection);
    public:
        Goal * mGoal;
        Map(QGraphicsScene* scenePointer, bool demoMode, Game * gameObject);
        Map* getMap();
        QString getSuccessPath();
        void switchRooms(QString name);     //Why does Baylus use this one?
        QRectF getWallsRect();
};

#endif // JTMAP_H
