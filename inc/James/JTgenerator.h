#ifndef JTGENERATOR_H
#define JTGENERATOR_H

#include <iostream>
#include <QString>
#include <string>
#include <algorithm>
#include <list>
#include <time.h>
using namespace std;

struct coord{
    int x;
    int y;
};
typedef struct coord Coord;



class Generator
{
private:
    list<Coord> mPath;
    list<Coord>::iterator it;
    const static int SMAX_SIZE = 101;
    const static int SCENTER = 51;
    int mSeededValue;
    int mRooms[SMAX_SIZE][SMAX_SIZE];
    QString mPathVariable;

    //int initRand();
    int seededRand();
    void initializeGenerator();
    void generatorPrint(string t);
    void checkAdjacent(int x, int y);
    void checkAllAdjacent();
    void printPath();
    bool pathFork();
    time_t systime;

public:
    int mValues[SMAX_SIZE][SMAX_SIZE];
    void getGoal(int &x, int &y);
    QString getPath();
    void generate();

};

#endif // JTGENERATOR_H
