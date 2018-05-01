#include "JTGenerator.h"
#include <QDebug>
#include <JTGenerator.h>

void Generator::getGoal(int &x, int &y)
{
    int a, b;
    for(it = mPath.begin(); it != mPath.end(); it++)
    {
        a = it->x;
        b = it->y;
    }
    x =a;
    y=b;
    qDebug()<<"Path end X:"<<x;
    qDebug()<<"Path end Y:"<<y;
}

QString Generator::getPath()
{
    return mPathVariable;
}

void Generator::generate()
{
     systime = time(NULL);
     systime = systime %10000;
     qDebug()<<"Systime: "<<systime;
   //  srand(systime);
    initializeGenerator();
    checkAllAdjacent();
    generatorPrint("let");
    printPath();
}

/*
int Generator::initRand()
{
    //unsigned int dice = rand()%6;       //This means there are 6 seeds, (0-6) inclusive.
    //srand(dice);
    //mSeededValue = rand();
    return rand();
}*/

int Generator::seededRand()
{
   // systime = time(NULL);
    systime++;
    qDebug()<<"Systime: "<<systime;
    srand(systime);
    //srand(mSeededValue);
    qDebug()<<"rand: "<<rand();
    return rand()+1;
}

bool Generator::pathFork()
{
    int threshold=75;			//in percent
    if(seededRand()%100>threshold) return true;
    else return false;
}

void Generator::printPath()
{
    cout<<"Success Path:\n";
    for(it = mPath.begin(); it != mPath.end(); it++)
    {
        int x = it->x;
        int y = it->y;
        cout<<x<<"\t"<<y<<endl;
    }
}

void Generator::checkAdjacent(int x, int y)
{
    bool right, left, top, bottom;
    right=false;
    left=false;
    bottom=false;
    top=false;
    if(mRooms[x+1][y]==1)
    {
        right=true;
    }
    if(mRooms[x-1][y]==1)
    {
        left=true;
    }
    if(mRooms[x][y+1]==1)
    {
        bottom=true;
    }
    if(mRooms[x][y-1]==1)
    {
        top=true;
    }

    int set;
    if(top && bottom && left && right && mRooms[x][y]==1)
    {
        set=1;
    }			//4 doors
    else if(top && !bottom && !left && !right && mRooms[x][y]==1)
    {
        set=2;
    }		//top
    else if(!top && !bottom && !left && right && mRooms[x][y]==1)
    {
        set=3;
    }		//right
    else if(!top && bottom && !left && !right && mRooms[x][y]==1)
    {
        set=4;
    }		//bottom
    else if(!top && !bottom && left && !right && mRooms[x][y]==1)
    {
        set=5;
    }		//left
    else if(top && !bottom && !left && right && mRooms[x][y]==1)
    {
        set=6;
    }		//top and right
    else if(top && bottom && !left && !right && mRooms[x][y]==1)
    {
        set=7;
    }		//vertical
    else if(top && !bottom && left && !right && mRooms[x][y]==1)
    {
        set=8;
    }		//top and left
    else if(!top && bottom && !left && right && mRooms[x][y]==1)
    {
        set=9;
    }		//right and bottom
    else if(!top && !bottom && left && right && mRooms[x][y]==1)
    {
        set=10;
    }		//horizontal
    else if(!top && bottom && left && !right && mRooms[x][y]==1)
    {
        set=11;
    }		//bottom and left
    else if(!top && bottom && left && right && mRooms[x][y]==1)
    {
        set=12;
    }		//not top
    else if(top && bottom && left && !right && mRooms[x][y]==1)
    {
        set=13;
    }		//not right
    else if(top && !bottom && left && right && mRooms[x][y]==1)
    {
        set=14;
    }		//not bottom
    else if(top && bottom && !left && right && mRooms[x][y]==1)
    {
        set=15;
    }		//not left
    else
    {
        set=0;
    }                                                           //no doors

    mValues[x][y]=set;
}

void Generator::checkAllAdjacent()
{
    for(int y=0; y<SMAX_SIZE; y++)
    {
        for( int x=0; x<SMAX_SIZE; x++)
        {
            checkAdjacent(x,y);
        }
    }
}

void Generator::initializeGenerator()
{
    for(int y=0; y<SMAX_SIZE; y++)
    {
        for(int x=0; x<SMAX_SIZE; x++)
        {
            mRooms[x][y]=0;
            mValues[x][y]=0;
        }
    }

    int startX, startY, goalX, goalY, currentX, currentY;
    startX=SCENTER;
    startY=SCENTER;

    int randX=((seededRand()%24)-12);
    int randY=((seededRand()%24)-12);

    if(randX<=0 && randX>=-7)
    {
        randX=-7;
    }
    else if(randX>0 && randX<=7)
    {
        randX=7;
    }
    if(randY<=0 && randY>=-7)
    {
        randY=-7;
    }
    else if(randY>0 && randY<=7)
    {
        randY=7;
    }

    goalX=startX+randX;
    goalY=startY+randY;

    currentX=startX;
    currentY=startY;

    Coord first;
    first.x = currentX;
    first.y = currentY;
    mPath.push_back(first);
    while(currentX != goalX && currentY != goalY)
    {
        mRooms[currentX][currentY]=1;
        if(currentX<goalX)
        {
            mPathVariable+="R";
            currentX++;
            Coord next;
            next.x = currentX;
            next.y = currentY;
            mPath.push_back(next);
            mRooms[currentX][currentY]=1;
        }
        else if(currentX>goalX)
        {
            mPathVariable+="L";
            currentX--;
            Coord next;
            next.x = currentX;
            next.y = currentY;
            mPath.push_back(next);
            mRooms[currentX][currentY]=1;
        }
        if(currentY<goalY)
        {
            mPathVariable+="D";
            currentY++;
            Coord next;
            next.x = currentX;
            next.y = currentY;
            mPath.push_back(next);
            mRooms[currentX][currentY]=1;
        }
        else if(currentY>goalY)
        {
            mPathVariable+="U";
            currentY--;
            Coord next;
            next.x = currentX;
            next.y = currentY;
            mPath.push_back(next);
            mRooms[currentX][currentY]=1;
        }
    }

    for(it = mPath.begin(); it != mPath.end(); it++)
    {
        int xElement = it->x;
        int yElement = it->y;
        if(pathFork())
        {
            int newGoalX = xElement+((seededRand()%24)-12);
            int newGoalY = yElement+((seededRand()%24)-12);

            currentX = xElement;
            currentY = yElement;
            while(currentX != newGoalX && currentY != newGoalY)
            {
                if(currentX<newGoalX)
                {
                    currentX++;
                    mRooms[currentX][currentY]=1;
                }
                else if(currentX<newGoalX)
                {
                    currentX--;
                    mRooms[currentX][currentY]=1;
                }
                if(currentY<newGoalY)
                {
                    currentY++;
                    mRooms[currentX][currentY]=1;
                }
                else if(currentY>newGoalY)
                {
                    currentY--;
                    mRooms[currentX][currentY]=1;
                }
            }
        }
    }
}

void Generator::generatorPrint(string matrix)
{
    for(int y=0; y<SMAX_SIZE; y++)
    {
        for(int x=0; x<SMAX_SIZE; x++)
        {
            if(matrix=="num")
            {
                cout<<mRooms[x][y];
            }
            if(matrix=="let" &&mValues[x][y] !=0)
            {
                cout<<mValues[x][y]<<"\t";
            }
            if(matrix=="let" &&mValues[x][y] ==0)
            {
                cout<<" \t";
            }
        }
        cout<<endl;
    }
}
