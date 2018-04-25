#include "JAaudio.h"
#include "music.h"
#include "sound.h"
#include "JAaudiosuper.h"
#include <QTime>
#include <QTimer>

AudioInter::AudioInter(int sound_choice, QString soundpath, QObject* parent) : QObject(parent)
{
        if(sound_choice == 1){
            mClass = new Sound(soundpath);
        }
        else{
            Music* mClass2;
            mClass2 = mClass2->getInstance(soundpath);
            //calls getInstance because music follows the singleton pattern.

            mClass = mClass2;

            //timer make sure music doesnt stop
            QTimer* musicManager = new QTimer();
            connect(musicManager,SIGNAL(timeout()),this,SLOT(musicManage()));
            musicManager->start(100);

        }

}

void AudioInter::delay()
{
    QTime dieTime= QTime::currentTime().addSecs(1);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}



void AudioInter::musicManage(){
    mClass->manage();
}

void AudioInter::setSound(QString soundpath){
    mClass->setSound(soundpath);
}

int AudioInter::playSound() //sound effect that you wish to be played
{
    //example of delegation
    mClass->play();
    return 0;
}



int AudioInter::setCharClass(int CharClass)
{
    mCharClass = CharClass;
    return 0;
}


int AudioInter::setVolume(int volume)
{
      mClass->setVolume(volume);
    return 0;
}


void AudioInter::stressTest()
{
    AudioAll* mSound1;
    Music* mSound1temp = mSound1temp->getInstance("qrc:/sounds/Sounds/Break-Down.mp3");
    mSound1 = mSound1temp;
    AudioAll * mSound2 = new Sound("qrc:/sounds/Sounds/Button.wav");
    AudioAll * mSound3 = new Sound("qrc:/sounds/Sounds/damage1.wav");
    AudioAll * mSound4 = new Sound("qrc:/sounds/Sounds/damage2.wav");
    AudioAll * mSound5 = new Sound("qrc:/sounds/Sounds/damage3.wav");
    AudioAll * mSound6 = new Sound("qrc:/sounds/Sounds/Door_Closing.wav");
    AudioAll * mSound7 = new Sound("qrc:/sounds/Sounds/Door_Opening.wav");
    AudioAll * mSound8 = new Sound("qrc:/sounds/Sounds/Laser.wav");
    AudioAll* mSound9;
    Music* mSound2temp = mSound2temp->getInstance("qrc:/sounds/Sounds/Light-Years_v001.mp3");
    mSound9 = mSound2temp;
    AudioAll * mSound10 = new Sound("qrc:/sounds/Sounds/piston.wav");
    AudioAll * mSound11 = new Sound("qrc:/sounds/Sounds/Robot_hit.wav");
    AudioAll * mSound12 = new Sound("qrc:/sounds/Sounds/Robot_less_angry.wav");
    AudioAll * mSound13 = new Sound("qrc:/sounds/Sounds/Robot_more_angry.wav");
    AudioAll* mSound14;
    Music* mSound3temp = mSound3temp->getInstance("qrc:/sounds/Sounds/The-Creeping-Blob.mp3");
    mSound14 = mSound3temp;
    AudioAll * mSound15 = new Sound("qrc:/sounds/Sounds/walking.wav");
    AudioAll * mSound16 = new Sound("qrc:/sounds/Sounds/Scream.wav");


    mSound1->setVolume(20);
    mSound9->setVolume(20);
    mSound14->setVolume(20);
    mSound16->setVolume(10);
    mSound1->play();
 //    ();
    mSound2->play();
   //  ();
    mSound3->play();
   //  ();
    mSound4->play();
   //  ();
    mSound5->play();
    // ();
    mSound6->play();
    // ();
    mSound7->play();
    // ();
    mSound8->play();
    // ();
    mSound9->play();
    // ();
    mSound10->play();
    // ();
    mSound11->play();
    // ();
    mSound12->play();
    // ();
    mSound13->play();
    // ();
    mSound14->play();
    // ();
    mSound15->play();
    // ();
    mSound16->play();
}

