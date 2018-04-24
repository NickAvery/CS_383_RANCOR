/* Baylus Tunnicliff    2/21/2018   CS383: Software Engineering
 * Character class
 *
 *
 *
 */

#ifndef CHARACTER_H
#define CHARACTER_H

#include "autopilot.h"

#include "KNSkillManager.h"
#include "JTmap.h"
#include "JTwalls.h"
#include "JAgame.h"
#include "JAaudio.h"
//#include "BTplayer.h"
#include "BTshot.h"         // "struct weaponStats",


#include <QWidget>
#include <QPoint>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
//#include <QGraphicsItem>

class SkillManager;
class Game;
class Player;       // Player object handles the Pixmap, movement, colision signaling.
class Map;
class Autopilot;    // Handles auto-movement and firing

struct direction;
struct DataBank;
//struct weaponStats;

class Character : public QWidget
{
    Q_OBJECT

public:
    /* The first constructor calls the second, with a default "characterNum" of 0.
     * characterNumber: the integer related to the character that was chosen.
     * inputState: whether or not the player's input will be used in the game. see "Demo Mode"
     */
    Character(int characterNumber = 0, bool autopilot = false, bool successPath = false, Game* parent = 0, QGraphicsScene* s = NULL);
    Character(int characterNumber = 0, Game* parent = NULL, QGraphicsScene* s = NULL) : Character(characterNumber, false, false, parent, s) {}
    ~Character();

    //void setSpeed(double speed);   //Changes The speed
    void setPostition(QPointF point);     //sets the position for the player.
    QPointF getPosition();   //Returns the position of the player
    QPointF getCenter();
    QRectF getRect();  //Gets the rectangle that represents the pixmap of the player.
    int getCurrentHealth();  //Gets the player health
    int getDamage();  //Gets the player damage stat.


    void keyPressEvent(QKeyEvent *event);   //Registers WASD keys, arrow keys, and 'P' for pause.
    void keyReleaseEvent(QKeyEvent *event); //see keyPressEvent();
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    //virtual void move();    //Moves player and ghost to appropriate positions.
    void update();
    void doDamage(double sDamage);

    //Called by outside Classes to give info
    void successPath(QString path);
    void setPlayerStats(DataBank *p );
    void KNStressTest();    //Karstin's (Skill Manager)stress Test.
    void BTStressTest();    //Baylus's (Weapons) Stress Test.
    void setMousePoint(QPointF p);
    void toggleShooting();
    //bool Contains(QPointF &p, bool);

    //Called by player object.
    void playerLeaveRoom(QString name);
    void gameWin();
private:
    bool invincibilityFrameCount(int frames);
    bool shotCooldownCount(int t);
    int shoot(QLineF fireLine);
    //Handles a counter that handles invicibility frames.
    bool isInvulnernable = false;
    bool mIsShooting = false;
    bool mShotCooldown = false;
    bool mKNStressTest = false;
    bool mBTStressTest = false;
    bool mIsAutopilot = false;
    bool mSuccessPath = false;

    QMouseEvent* mMoveEvent = NULL;
    QPointF mMousePoint;

    double speed = 10;     //Speed of player.
    Game* myGame; /* Not guaranteed to exist. Check if NULL when used. */
    Map* myMap;
    SkillManager* mySkillManager;
    QGraphicsScene* scene;
    struct direction* myMove;    //Passing into the Player Object.
    int mNumKeys = 0;

    Player *myPlayer;
    Walls* myWalls;   //Stores the walls object that i need to not collide with.
    EnemyUpdater* mEnemyUpdater;

    //Player Stats
    struct DataBank* mStats;


    //Sounds
    AudioInter* mLaser;
    AudioInter* sDamage;
    //Audiointer* damage[3];

    //Other
    Autopilot* mAP = NULL;
    weaponStats mWeapStats;
    int mTempScore = 0;
    //protected:
    int getMoveDirection();
signals:
    void shotTick();
    void shotKill();
public slots:
    void enemyHit();
};

#endif // CHARACTER_H
