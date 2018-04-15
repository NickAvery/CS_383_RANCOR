#include "JAaudio.h"
#include "music.h"
#include "sound.h"
#include "JAaudiosuper.h"
#include <QTime>
#include <QTimer>


AudioAll::AudioAll(QString x){
    name = x;
}


void AudioInter::delay()
{
    QTime dieTime= QTime::currentTime().addSecs(1);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}


AudioInter::AudioInter(int Sound_choice, QString soundpath)
{

    if(Sound_choice == 1){
        mClass = new Sound(soundpath);
    }
    else{
        mClass = new Music(soundpath);

        QTimer* musicManager = new QTimer();
        connect(musicManager,SIGNAL(timeout()),this,SLOT(musicManage()));
        musicManager->start(100);

    }
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
    QMediaPlayer * mSound1 = new QMediaPlayer();
    QMediaPlayer * mSound2 = new QMediaPlayer();
    QMediaPlayer * mSound3 = new QMediaPlayer();
    QMediaPlayer * mSound4 = new QMediaPlayer();
    QMediaPlayer * mSound5 = new QMediaPlayer();
    QMediaPlayer * mSound6 = new QMediaPlayer();
    QMediaPlayer * mSound7 = new QMediaPlayer();
    QMediaPlayer * mSound8 = new QMediaPlayer();
    QMediaPlayer * mSound9 = new QMediaPlayer();
    QMediaPlayer * mSound10 = new QMediaPlayer();
    QMediaPlayer * mSound11 = new QMediaPlayer();
    QMediaPlayer * mSound12 = new QMediaPlayer();
    QMediaPlayer * mSound13 = new QMediaPlayer();
    QMediaPlayer * mSound14 = new QMediaPlayer();
    QMediaPlayer * mSound15 = new QMediaPlayer();
    QMediaPlayer * mSound16 = new QMediaPlayer();

    mSound1->setMedia(QUrl("qrc:/sounds/Sounds/Break-Down.mp3"));
    mSound1->setVolume(20);
    mSound2->setMedia(QUrl("qrc:/sounds/Sounds/Button.wav"));
    mSound3->setMedia(QUrl("qrc:/sounds/Sounds/damage1.wav"));
    mSound4->setMedia(QUrl("qrc:/sounds/Sounds/damage2.wav"));
    mSound5->setMedia(QUrl("qrc:/sounds/Sounds/damage3.wav"));
    mSound6->setMedia(QUrl("qrc:/sounds/Sounds/Door_Closing.wav"));
    mSound7->setMedia(QUrl("qrc:/sounds/Sounds/Door_Opening.wav"));
    mSound8->setMedia(QUrl("qrc:/sounds/Sounds/Laser.wav"));
    mSound9->setMedia(QUrl("qrc:/sounds/Sounds/Light-Years_v001.mp3"));
    mSound9->setVolume(20);
    mSound10->setMedia(QUrl("qrc:/sounds/Sounds/piston.wav"));
    mSound11->setMedia(QUrl("qrc:/sounds/Sounds/Robot_hit.wav"));
    mSound12->setMedia(QUrl("qrc:/sounds/Sounds/Robot_less_angry.wav"));
    mSound13->setMedia(QUrl("qrc:/sounds/Sounds/Robot_more_angry.wav"));
    mSound14->setMedia(QUrl("qrc:/sounds/Sounds/The-Creeping-Blob.mp3"));
    mSound14->setVolume(20);
    mSound15->setMedia(QUrl("qrc:/sounds/Sounds/walking.wav"));
    mSound16->setMedia(QUrl("qrc:/sounds/Sounds/Scream.wav"));
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

