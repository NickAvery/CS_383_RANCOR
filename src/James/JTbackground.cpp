#include "JTbackground.h"
#include <qdebug.h>


Background::Background(int option)
{
    QPixmap bgPic;
    switch(option){                             //This section handles which graphic will be displayed in background
    case 1:                                     //all
        bgPic = QPixmap(":/images/JTAll.png");
        break;
    case 2:                                     //top
        bgPic = QPixmap(":/images/JTTop.png");
        break;
    case 3:                                     //right
        bgPic = QPixmap(":/images/JTRight.png");
        break;
    case 4:                                     //bottom
        bgPic = QPixmap(":/images/JTBottom.png");
        break;
    case 5:                                     //left
        bgPic = QPixmap(":/images/JTLeft.png");
        break;
    case 6:                                     //top right
        bgPic = QPixmap(":/images/JTTop_Right.png");
        break;
    case 7:                                     //vertical
        bgPic = QPixmap(":/images/JTTwo_Vertical.png");
        break;
    case 8:                                     //top left
        bgPic = QPixmap(":/images/JTTop_Left.png");
        break;
    case 9:                                     //bottom right
        bgPic = QPixmap(":/images/JTBottom_Right.png");
        break;
    case 10:                                    //horizontal
        bgPic = QPixmap(":/images/JTTwo_Horizontal.png");
        break;
    case 11:                                    //bottom left
        bgPic = QPixmap(":/images/JTBottom_Left.png");
        break;
    case 12:                                    //not top
        bgPic = QPixmap(":/images/JTNot_Top.png");
        break;
    case 13:                                    //not right
        bgPic = QPixmap(":/images/JTNot_Right.png");
        break;
    case 14:                                    //not bottom
        bgPic = QPixmap(":/images/JTNot_Bottom.png");
        break;
    case 15:                                    //not left
        bgPic = QPixmap(":/images/JTNot_Left.png");
        break;
    case 16:                                    //none
        bgPic = QPixmap(":/images/JTNone.png");
        break;
    }
    bgPic=bgPic.scaled(800,600,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
    setPixmap(bgPic);
    setPos(0,0);
}
