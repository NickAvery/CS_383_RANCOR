#include "JAaudio.h"
#include "music.h"
#include "sound.h"
#include "JAaudiosuper.h"
#include <QTime>
#include <QTimer>

/*
AudioAll::AudioAll(QString x){
    name = x;
}
*/

AudioInter::AudioInter(int sound_choice, QString soundpath, QObject* parent) : QObject(parent)
{
        if(sound_choice == 1){
            mClass = new Sound(soundpath);
        }
        else{
            mClass = new Music(soundpath);

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
    AudioAll* mSound1 = new Music("qrc:/sounds/Sounds/Break-Down.mp3");
    AudioAll * mSound2 = new Sound("qrc:/sounds/Sounds/Button.wav");
    AudioAll * mSound3 = new Sound("qrc:/sounds/Sounds/damage1.wav");
    AudioAll * mSound4 = new Sound("qrc:/sounds/Sounds/damage2.wav");
    AudioAll * mSound5 = new Sound("qrc:/sounds/Sounds/damage3.wav");
    AudioAll * mSound6 = new Sound("qrc:/sounds/Sounds/Door_Closing.wav");
    AudioAll * mSound7 = new Sound("qrc:/sounds/Sounds/Door_Opening.wav");
    AudioAll * mSound8 = new Sound("qrc:/sounds/Sounds/Laser.wav");
    AudioAll * mSound9 = new Music("qrc:/sounds/Sounds/Light-Years_v001.mp3");
    AudioAll * mSound10 = new Sound("qrc:/sounds/Sounds/piston.wav");
    AudioAll * mSound11 = new Sound("qrc:/sounds/Sounds/Robot_hit.wav");
    AudioAll * mSound12 = new Sound("qrc:/sounds/Sounds/Robot_less_angry.wav");
    AudioAll * mSound13 = new Sound("qrc:/sounds/Sounds/Robot_more_angry.wav");
    AudioAll * mSound14 = new Music("qrc:/sounds/Sounds/The-Creeping-Blob.mp3");
    AudioAll * mSound15 = new Sound("qrc:/sounds/Sounds/walking.wav");
    AudioAll * mSound16 = new Sound("qrc:/sounds/Sounds/Scream.wav");


    mSound1->setVolume(20);
    mSound9->setVolume(20);
    mSound14->setVolume(20);
    mSound16->setVolume(10);
    mSound1->play();
 //   delay();
    mSound2->play();
   // delay();
    mSound3->play();
   // delay();
    mSound4->play();
   // delay();
    mSound5->play();
    //delay();
    mSound6->play();
    //delay();
    mSound7->play();
    //delay();
    mSound8->play();
    //delay();
    mSound9->play();
    //delay();
    mSound10->play();
    //delay();
    mSound11->play();
    //delay();
    mSound12->play();
    //delay();
    mSound13->play();
    //delay();
    mSound14->play();
    //delay();
    mSound15->play();
    //delay();
    mSound16->play();
}

